# BÁO CÁO KIỂM THỬ HỘP TRẮNG (WHITE-BOX TESTING)

## USE CASE 07: PHÂN TÍCH VÀ ĐÁNH GIÁ ỨNG VIÊN BẰNG AI (AnalysisUseCase)

---

### THÔNG TIN CHUNG VỀ BÀI TẬP VÀ ĐỐI TƯỢNG KIỂM THỬ

- **Học phần:** Kiểm thử và Đảm bảo chất lượng phần mềm (CSE462)
- **Học kỳ:** Học kỳ 7 – Năm học 2025–2026
- **Giảng viên hướng dẫn:** TS. Nguyễn Thị Phương Dung
- **Sinh viên thực hiện:** Phùng Văn Duy
- **Mã số sinh viên (MSSV):** 2351170589
- **Nhóm thực hiện:** Nhóm 09
- **Đề tài:** Hệ thống Quản lý Tuyển dụng – Trợ lý Tuyển dụng & Sàng lọc Hồ sơ Tự động
- **Mã Use Case:** `UC_07` | **Tên Use Case:** Phân tích ứng viên với AI
- **Đối tượng kiểm thử (Target Under Test):** Lớp `AnalysisUseCase` – Phương thức `execute(input: AnalysisInputDto)`
- **Tài liệu lý thuyết tham chiếu:** Slide bài giảng _CSE462 - Các kỹ thuật kiểm thử phần mềm_, ĐH Thủy Lợi (Nội dung: Kiểm thử dòng điều khiển Control Flow Testing, Đồ thị CFG, Độ đo bao phủ C1, C2, C3, Độ phức tạp Cyclomatic $V(G)$ theo McCabe, Kiểm thử dòng dữ liệu Data Flow Testing Def-Use).

---

## 1. MÃ NGUỒN ĐÁNH SỐ DÒNG

```typescript
1:  export class AnalysisUseCase {
2:    constructor(
3:      private readonly candidateRepo: ICandidateReadRepo & ICandidateWriteRepo,
4:      private readonly jobRepo: IJobReadRepo,
5:      private readonly aiAnalyzeRepo: IAnalysisReadRepo & IAnalysisWriteRepo,
6:      private readonly geminiService: IAIService,
7:    ) { }
8:
9:    async execute(input: AnalysisInputDto): Promise<AnalysisOutputDto> {
10:     const { candidateID, jobID } = input;
11:
12:     const existingAnalysis = await this.aiAnalyzeRepo.getAnalysisByCandidateIdAndJobId(candidateID, jobID);
13:     if (existingAnalysis) {
14:       return existingAnalysis as AnalysisOutputDto;
15:     }
16:
17:     const candidate = await this.candidateRepo.getById(candidateID);
18:     if (!candidate) throw new Error('Không tìm thấy thông tin ứng viên.');
19:
20:     const job = await this.jobRepo.getById(jobID);
21:     if (!job) throw new Error('Không tìm thấy thông tin công việc (Job).');
22:
23:     const analysisResult = await this.geminiService.analyzeCandidateWithJob(
24:       candidate.getDetailProfile(),
25:       job.getDetailJob(),
26:     );
27:     if (!analysisResult) throw new Error('Lỗi khi gọi AI phân tích dữ liệu.');
28:
29:     const analysis = AnalysisEntity.create({
30:       jobID,
31:       candidateID,
32:       summary: analysisResult['summary'] as string,
33:       matchingScore: analysisResult['matchingScore'] as number,
34:       redFlags: analysisResult['redFlags'] as string[],
35:       suggestedQuestions: analysisResult['suggestedQuestions'] as string[]
36:     });
37:
38:     const savedAnalysis = await this.aiAnalyzeRepo.create(analysis);
39:
40:     if (!savedAnalysis) throw new Error('Lỗi khi lưu kết quả phân tích.');
41:
42:     candidate.updateStatus(CandidateStatus.SCREENING);
43:     await this.candidateRepo.update(candidate);
44:
45:     return savedAnalysis as AnalysisOutputDto;
46:   }
47: }
```

---

## 2. PHÂN TÍCH KHỐI LỆNH CƠ BẢN VÀ ĐỒ THỊ DÒNG ĐIỀU KHIỂN (CFG)

### 2.1. Phân chia các khối lệnh cơ bản (Basic Blocks / Nodes)

| Đỉnh (Node) | Dòng mã nguồn | Nội dung câu lệnh & Thao tác                                                                                                                               | Loại đỉnh                  |
| :---------- | :------------ | :--------------------------------------------------------------------------------------------------------------------------------------------------------- | :------------------------- |
| **Node 1**  | Dòng 10–13    | Lấy `candidateID`, `jobID`, kiểm tra kết quả phân tích cũ: `getAnalysisByCandidateIdAndJobId()`, điều kiện `if (existingAnalysis)`                         | Decision (Điểm quyết định) |
| **Node 2**  | Dòng 14       | `return existingAnalysis as AnalysisOutputDto;` (Tái sử dụng kết quả có sẵn)                                                                               | Exit (Thoát bình thường 1) |
| **Node 3**  | Dòng 17–18    | Truy vấn ứng viên: `candidateRepo.getById(candidateID)`, kiểm tra điều kiện `if (!candidate)`                                                              | Decision (Điểm quyết định) |
| **Node 4**  | Dòng 18       | `throw new Error('Không tìm thấy thông tin ứng viên.')`                                                                                                    | Exit (Ngoại lệ 1)          |
| **Node 5**  | Dòng 20–21    | Truy vấn công việc: `jobRepo.getById(jobID)`, kiểm tra điều kiện `if (!job)`                                                                               | Decision (Điểm quyết định) |
| **Node 6**  | Dòng 21       | `throw new Error('Không tìm thấy thông tin công việc (Job).')`                                                                                             | Exit (Ngoại lệ 2)          |
| **Node 7**  | Dòng 23–27    | Gọi AI phân tích: `geminiService.analyzeCandidateWithJob(...)`, kiểm tra điều kiện `if (!analysisResult)`                                                  | Decision (Điểm quyết định) |
| **Node 8**  | Dòng 27       | `throw new Error('Lỗi khi gọi AI phân tích dữ liệu.')`                                                                                                     | Exit (Ngoại lệ 3)          |
| **Node 9**  | Dòng 29–40    | Khởi tạo thực thể `AnalysisEntity.create()`, lưu vào DB: `aiAnalyzeRepo.create(analysis)`, kiểm tra điều kiện `if (!savedAnalysis)`                        | Decision (Điểm quyết định) |
| **Node 10** | Dòng 40       | `throw new Error('Lỗi khi lưu kết quả phân tích.')`                                                                                                        | Exit (Ngoại lệ 4)          |
| **Node 11** | Dòng 42–45    | Cập nhật trạng thái `CandidateStatus.SCREENING`: `candidate.updateStatus()`, `candidateRepo.update()`, trả về `return savedAnalysis as AnalysisOutputDto;` | Exit (Thoát bình thường 2) |

---

### 2.2. Đồ thị dòng điều khiển ứng với độ đo C1 và C2 (Statement & Decision CFG)

Ở cấp độ độ đo C1 (phủ câu lệnh) và C2 (phủ nhánh quyết định), đồ thị biểu diễn 11 khối lệnh cơ bản và các nhánh rẽ nhị phân:

```mermaid
flowchart TD
    Start(["Bắt đầu: execute(input)"]) --> N1["Node 1: if (existingAnalysis)"]

    N1 -- True --> N2["Node 2: return existingAnalysis"]
    N1 -- False --> N3["Node 3: candidate = getById, if (!candidate)"]

    N3 -- True --> N4["Node 4: throw 'Không tìm thấy thông tin ứng viên.'"]
    N3 -- False --> N5["Node 5: job = getById, if (!job)"]

    N5 -- True --> N6["Node 6: throw 'Không tìm thấy thông tin công việc (Job).'"]
    N5 -- False --> N7["Node 7: analysisResult = analyzeCandidateWithJob, if (!analysisResult)"]

    N7 -- True --> N8["Node 8: throw 'Lỗi khi gọi AI phân tích dữ liệu.'"]
    N7 -- False --> N9["Node 9: savedAnalysis = create, if (!savedAnalysis)"]

    N9 -- True --> N10["Node 10: throw 'Lỗi khi lưu kết quả phân tích.'"]
    N9 -- False --> N11["Node 11: updateStatus(SCREENING) & return savedAnalysis"]
```

### 2.3. Đồ thị dòng điều khiển ứng với độ đo C3 (Condition CFG)

Đối với UC_07, các biểu thức điều kiện đều là biểu thức logic đơn thuần (Simple Booleans: `existingAnalysis != null`, `candidate == null`, `job == null`, `analysisResult == null`, `savedAnalysis == null`). Do đó đồ thị dòng điều khiển ứng với độ đo C3 đẳng cấu với đồ thị C2, trong đó mỗi điểm quyết định kiểm tra chính xác giá trị True/False của biến kiểm tra điều kiện tương ứng.

```mermaid
flowchart TD
    Start(["Bắt đầu: execute(input)"]) --> N1{"Node 1: existingAnalysis != null?"}

    N1 -- "True" --> N2["Node 2: return existingAnalysis (Cache Hit)"]
    N1 -- "False" --> N3{"Node 3: candidate == null?"}

    N3 -- "True" --> N4["Node 4: throw 'Không tìm thấy thông tin ứng viên.'"]
    N3 -- "False" --> N5{"Node 5: job == null?"}

    N5 -- "True" --> N6["Node 6: throw 'Không tìm thấy thông tin công việc (Job).'"]
    N5 -- "False" --> N7{"Node 7: analysisResult == null?"}

    N7 -- "True" --> N8["Node 8: throw 'Lỗi khi gọi AI phân tích dữ liệu.'"]
    N7 -- "False" --> N9{"Node 9: savedAnalysis == null?"}

    N9 -- "True" --> N10["Node 10: throw 'Lỗi khi lưu kết quả phân tích.'"]
    N9 -- "False" --> N11["Node 11: updateStatus(SCREENING) & return savedAnalysis"]
```

---

## 3. TÍNH ĐỘ PHỨC TẠP CYCLOMATIC

Theo lý thuyết bài giảng Thomas J. McCabe, độ phức tạp Cyclomatic $V(G)$ phản ánh số lượng đường dẫn độc lập tuyến tính trong đồ thị dòng điều khiển:

### Phương pháp 1: Dựa trên số cung ($E$) và số đỉnh ($N$)

Công thức:
$$V(G) = E - N + 2P$$
Trong đó:

- Số đỉnh (Nodes) $N = 11$
- Số cung (Edges) $E = 15$
- Số thành phần liên thông $P = 1$

Tính toán:
$$V(G) = 15 - 11 + 2(1) = 6$$

---

### Phương pháp 2: Dựa trên số điểm quyết định vị từ ($P_n$)

Công thức:
$$V(G) = P_n + 1$$
Trong đó $P_n$ là số nút vị từ (chứa điều kiện rẽ nhánh nhị phân True/False):

1. **Node 1:** `if (existingAnalysis)`
2. **Node 3:** `if (!candidate)`
3. **Node 5:** `if (!job)`
4. **Node 7:** `if (!analysisResult)`
5. **Node 9:** `if (!savedAnalysis)`

Tổng số nút vị từ $P_n = 5$.  
Tính toán:
$$V(G) = 5 + 1 = 6$$

---

### Phương pháp 3: Dựa trên số miền khép kín ($R$)

Công thức:
$$V(G) = R$$
Trong đó $R$ là tổng số miền phẳng khép kín (5 miền rẽ nhánh cục bộ $R_1, R_2, R_3, R_4, R_5$) cộng 1 miền vô hạn bao quanh ngoài ($R_6$).  
$\Rightarrow V(G) = R = 6$.

> **Kết luận:** Độ phức tạp Cyclomatic của hàm `execute` là **$V(G) = 6$**. Do đó, cần tối thiểu **6 đường dẫn cơ sở (Basis Paths)** độc lập tuyến tính để bao phủ đồ thị.

---

## 4. TẬP ĐƯỜNG DẪN CƠ SỞ

| Đường dẫn (Basis Path)  | Chuỗi các Node thực thi                                                    | Điều kiện kích hoạt luồng                                                              | Kết quả đầu ra mong đợi                                                 |
| :---------------------- | :------------------------------------------------------------------------- | :------------------------------------------------------------------------------------- | :---------------------------------------------------------------------- |
| **Path 1**              | $1 \rightarrow 2$                                                          | `existingAnalysis != null` (Đã có bản ghi phân tích từ trước)                          | Trả về ngay `existingAnalysis` (Cache hit), không gọi lại AI            |
| **Path 2**              | $1 \rightarrow 3 \rightarrow 4$                                            | `existingAnalysis == null` VÀ `candidate == null`                                      | Ném lỗi (Exception 1): `"Không tìm thấy thông tin ứng viên."`           |
| **Path 3**              | $1 \rightarrow 3 \rightarrow 5 \rightarrow 6$                              | `existingAnalysis == null`, `candidate != null` VÀ `job == null`                       | Ném lỗi (Exception 2): `"Không tìm thấy thông tin công việc (Job)."`    |
| **Path 4**              | $1 \rightarrow 3 \rightarrow 5 \rightarrow 7 \rightarrow 8$                | Có candidate, có job, nhưng gọi AI thất bại: `analysisResult == null`                  | Ném lỗi (Exception 3): `"Lỗi khi gọi AI phân tích dữ liệu."`            |
| **Path 5**              | $1 \rightarrow 3 \rightarrow 5 \rightarrow 7 \rightarrow 9 \rightarrow 10$ | Dữ liệu đầy đủ, AI phân tích thành công nhưng lưu DB thất bại: `savedAnalysis == null` | Ném lỗi (Exception 4): `"Lỗi khi lưu kết quả phân tích."`               |
| **Path 6** (Happy Path) | $1 \rightarrow 3 \rightarrow 5 \rightarrow 7 \rightarrow 9 \rightarrow 11$ | Dữ liệu hợp lệ, phân tích thành công, lưu DB thành công, chuyển status `SCREENING`     | Trả về `savedAnalysis` mới, trạng thái ứng viên chuyển sang `SCREENING` |

### 4.1. Sơ đồ cây phân nhánh các đường dẫn cơ sở (Basis Paths Tree Diagram)

```mermaid
graph TD
    Root["Bắt đầu: execute(input)"] --> N1{"Node 1: Đã phân tích trước đó?"}
    
    N1 -- "Có (existingAnalysis)" --> P1["Path 1: Trả về kết quả cũ (Cache Hit)"]
    N1 -- "Chưa có" --> N3{"Node 3: Tìm thấy Candidate?"}
    
    N3 -- "Không thấy (!candidate)" --> P2["Path 2: Ném lỗi 'Không tìm thấy ứng viên'"]
    N3 -- "Tìm thấy" --> N5{"Node 5: Tìm thấy Job?"}
    
    N5 -- "Không thấy (!job)" --> P3["Path 3: Ném lỗi 'Không tìm thấy công việc'"]
    N5 -- "Tìm thấy" --> N7{"Node 7: Gọi Gemini AI thành công?"}
    
    N7 -- "Thất bại (!result)" --> P4["Path 4: Ném lỗi 'Lỗi gọi AI phân tích'"]
    N7 -- "Thành công" --> N9{"Node 9: Lưu DB thành công?"}
    
    N9 -- "Thất bại (!saved)" --> P5["Path 5: Ném lỗi 'Lỗi khi lưu kết quả'"]
    N9 -- "Thành công" --> P6["Path 6: Cập nhật status SCREENING & Trả về kết quả (Happy Path)"]
```

---

## 5. SINH ĐƯỜNG ĐI VÀ CÁC CA KIỂM THỬ THEO ĐỘ ĐO C1, C2, C3

Theo tài liệu slide giảng dạy *CSE462 - Các kỹ thuật kiểm thử phần mềm*:

### A. Sinh đường đi và ca kiểm thử ứng với độ đo C1 (Phủ câu lệnh)
Mục tiêu độ đo C1: Tất cả các câu lệnh/khối lệnh (Node 1 đến Node 11) được thực thi ít nhất một lần với số lượng ca kiểm thử tối thiểu.

| TT | Đường đi theo Node | Dữ liệu đầu vào (Input) | Đầu ra mong đợi | Đầu ra thực tế | Ghi chú |
| :---: | :--- | :--- | :--- | :---: | :--- |
| **C1_01** | $1 \rightarrow 2$ | `candidateID = "CAN_01"`, `jobID = "JOB_01"`, đã có bản ghi cũ | Trả về `existingAnalysis` (Cache Hit) | Đạt | Phủ Node 1, 2 |
| **C1_02** | $1 \rightarrow 3 \rightarrow 4$ | `candidateID = "CAN_INVALID"`, `jobID = "JOB_01"`, chưa có bản ghi cũ | Ném lỗi: `"Không tìm thấy thông tin ứng viên."` | Đạt | Phủ Node 3, 4 |
| **C1_03** | $1 \rightarrow 3 \rightarrow 5 \rightarrow 6$ | `candidateID = "CAN_01"`, `jobID = "JOB_INVALID"` | Ném lỗi: `"Không tìm thấy thông tin công việc (Job)."` | Đạt | Phủ Node 5, 6 |
| **C1_04** | $1 \rightarrow 3 \rightarrow 5 \rightarrow 7 \rightarrow 8$ | Candidate & Job hợp lệ, Gemini AI trả về `null` | Ném lỗi: `"Lỗi khi gọi AI phân tích dữ liệu."` | Đạt | Phủ Node 7, 8 |
| **C1_05** | $1 \rightarrow 3 \rightarrow 5 \rightarrow 7 \rightarrow 9 \rightarrow 10$ | Dữ liệu hợp lệ, AI trả về kết quả nhưng lưu DB trả về `null` | Ném lỗi: `"Lỗi khi lưu kết quả phân tích."` | Đạt | Phủ Node 9, 10 |
| **C1_06** | $1 \rightarrow 3 \rightarrow 5 \rightarrow 7 \rightarrow 9 \rightarrow 11$ | Dữ liệu hợp lệ, AI phân tích thành công, lưu DB thành công | Cập nhật status `SCREENING`, trả về `savedAnalysis` | Đạt | Phủ Node 11 (Happy Path) |

$\Rightarrow$ **Kết quả:** 6 ca kiểm thử phủ 100% các câu lệnh (11/11 Node) ứng với độ đo C1.

---

### B. Sinh đường đi và ca kiểm thử ứng với độ đo C2 (Phủ nhánh quyết định)
Mục tiêu độ đo C2: Mỗi điểm quyết định trong đồ thị đều được duyệt qua cả hai nhánh Đúng (True) và Sai (False).

#### Bảng ma trận điều kiện rẽ nhánh C2:
| Điểm quyết định | Biểu thức điều kiện tương ứng | Nhánh Đúng (True) | Nhánh Sai (False) | Ca kiểm thử Đúng | Ca kiểm thử Sai |
| :---: | :--- | :---: | :---: | :---: | :---: |
| **Node 1** | `existingAnalysis != null` | Sang Node 2 | Sang Node 3 | C1_01 | C1_02 |
| **Node 3** | `!candidate` | Sang Node 4 | Sang Node 5 | C1_02 | C1_03 |
| **Node 5** | `!job` | Sang Node 6 | Sang Node 7 | C1_03 | C1_04 |
| **Node 7** | `!analysisResult` | Sang Node 8 | Sang Node 9 | C1_04 | C1_05 |
| **Node 9** | `!savedAnalysis` | Sang Node 10 | Sang Node 11 | C1_05 | C1_06 |

$\Rightarrow$ Tất cả 5 cặp nhánh rẽ (10 nhánh) đều được thực thi đầy đủ 100% thông qua 6 ca kiểm thử `C1_01` $\rightarrow$ `C1_06`.

---

### C. Sinh đường đi và ca kiểm thử ứng với độ đo C3 (Phủ điều kiện)
Trong `AnalysisUseCase`, cả 5 điểm quyết định đều là biểu thức logic đơn nhị phân (Simple Condition). Do đó, bảng kiểm thử C3 tương ứng với tập hợp các giá trị chân lý cho từng biến điều kiện:

| TT | Biểu thức điều kiện kiểm tra | Giá trị Chân/Giả | Ca kiểm thử tương ứng | Nhánh thực thi |
| :---: | :--- | :---: | :---: | :---: |
| **TC_C3_01** | `existingAnalysis != null` | **True** | C1_01 | Node 1 $\rightarrow$ Node 2 |
| **TC_C3_02** | `existingAnalysis != null` | **False** | C1_02 | Node 1 $\rightarrow$ Node 3 |
| **TC_C3_03** | `candidate == null` | **True** | C1_02 | Node 3 $\rightarrow$ Node 4 |
| **TC_C3_04** | `candidate == null` | **False** | C1_03 | Node 3 $\rightarrow$ Node 5 |
| **TC_C3_05** | `job == null` | **True** | C1_03 | Node 5 $\rightarrow$ Node 6 |
| **TC_C3_06** | `job == null` | **False** | C1_04 | Node 5 $\rightarrow$ Node 7 |
| **TC_C3_07** | `analysisResult == null` | **True** | C1_04 | Node 7 $\rightarrow$ Node 8 |
| **TC_C3_08** | `analysisResult == null` | **False** | C1_05 | Node 7 $\rightarrow$ Node 9 |
| **TC_C3_09** | `savedAnalysis == null` | **True** | C1_05 | Node 9 $\rightarrow$ Node 10 |
| **TC_C3_10** | `savedAnalysis == null` | **False** | C1_06 | Node 9 $\rightarrow$ Node 11 |

---

## 5.4. KIỂM THỬ VÒNG LẶP (LOOP TESTING) CHO USE CASE 07

Theo giáo trình kiểm thử phần mềm CSE462, việc kiểm thử vòng lặp được áp dụng cho các cấu trúc xử lý danh sách tuần tự để kiểm tra tính ổn định của hệ thống trước các kích thước dữ liệu khác nhau theo **7 trường hợp chuẩn**:
1. Vòng lặp 0 lần
2. Vòng lặp 1 lần
3. Vòng lặp 2 lần
4. Vòng lặp $k$ lần ($2 < k < n - 1$)
5. Vòng lặp $n - 1$ lần
6. Vòng lặp $n$ lần (Tối đa)
7. Vòng lặp $n + 1$ lần (Vượt giới hạn)

### Áp dụng vào UC_07:
Trong `AnalysisUseCase`, kết quả từ AI phân tích trả về hai mảng dữ liệu quan trọng được khởi tạo và lưu trữ vào thực thể:
- Mảng cờ cảnh báo rủi ro `redFlags: string[]` (Quy định tối đa $n = 10$ cảnh báo).
- Mảng câu hỏi phỏng vấn đề xuất `suggestedQuestions: string[]` (Quy định tối đa $n = 10$ câu hỏi).

#### Bảng ca kiểm thử vòng lặp duyệt danh sách câu hỏi phỏng vấn (`suggestedQuestions`, $n = 10$):
| TT | Trường hợp kiểm thử vòng lặp | Số lần lặp ($m$) | Dữ liệu đầu vào kiểm thử cụ thể | Kết quả mong đợi |
| :---: | :--- | :---: | :--- | :--- |
| **LOOP_01** | Vòng lặp 0 lần (Không có câu hỏi) | $m = 0$ | AI trả về `suggestedQuestions = []` | Lưu entity thành công với mảng rỗng, không phát sinh lỗi |
| **LOOP_02** | Vòng lặp 1 lần (1 câu hỏi) | $m = 1$ | `suggestedQuestions = ["Hỏi về NestJS"]` | Lưu 1 câu hỏi vào CSDL thành công |
| **LOOP_03** | Vòng lặp 2 lần (2 câu hỏi) | $m = 2$ | `suggestedQuestions = ["Hỏi về NestJS", "Kinh nghiệm Docker"]` | Lưu 2 câu hỏi vào CSDL thành công |
| **LOOP_04** | Vòng lặp $k$ lần ($2 < k < n-1$) | $m = 5$ | Mảng gồm 5 câu hỏi phỏng vấn tiêu chuẩn | Xử lý mảng 5 phần tử ổn định |
| **LOOP_05** | Vòng lặp $n - 1$ lần | $m = 9$ | Mảng gồm 9 câu hỏi phỏng vấn | Xử lý mảng 9 phần tử ổn định |
| **LOOP_06** | Vòng lặp $n$ lần (Tối đa cấu hình) | $m = 10$ | Mảng gồm đúng 10 câu hỏi phỏng vấn | Lưu đủ 10 câu hỏi vào CSDL |
| **LOOP_07** | Vòng lặp $n + 1$ lần (Vượt giới hạn) | $m = 11$ | AI trả về 11 câu hỏi phỏng vấn | Hệ thống tự động cắt tỉa (slice) lấy 10 câu hoặc cảnh báo |

---

## 6. PHÂN TÍCH KIỂM THỬ DÒNG DỮ LIỆU (DATA FLOW TESTING: DEF-USE)

Theo lý thuyết bài giảng CSE462 (Trang 749-850), kiểm thử dòng dữ liệu tập trung kiểm tra chu kỳ sống của các biến từ điểm gán giá trị (**def**) đến điểm sử dụng tính toán (**c-use**) và điểm sử dụng trong điều kiện rẽ nhánh (**p-use**):

| Tên biến           | Điểm định nghĩa (def) | Điểm sử dụng tính toán (c-use)                                                              | Điểm sử dụng điều kiện (p-use)            | Kiểm tra bất thường (Data Flow Anomalies)                                 |
| :----------------- | :-------------------- | :------------------------------------------------------------------------------------------ | :---------------------------------------- | :------------------------------------------------------------------------ |
| `candidateID`      | Node 1 (Dòng 10)      | Node 1 (Dòng 12: `getAnalysis...`), Node 3 (Dòng 17: `getById`), Node 9 (Dòng 31: `create`) | Không                                     | Không có bất thường. Được gán từ tham số đầu vào và sử dụng hợp lệ.       |
| `jobID`            | Node 1 (Dòng 10)      | Node 1 (Dòng 12: `getAnalysis...`), Node 5 (Dòng 20: `getById`), Node 9 (Dòng 30: `create`) | Không                                     | Không có bất thường. Được gán và sử dụng đầy đủ.                          |
| `existingAnalysis` | Node 1 (Dòng 12)      | Node 2 (Dòng 14: `return`)                                                                  | Node 1 (Dòng 13: `if (existingAnalysis)`) | Hợp lệ. Có `p-use` kiểm tra ngay sau `def`, nếu có thì `c-use` để return. |
| `candidate`        | Node 3 (Dòng 17)      | Node 7 (Dòng 24: `candidate.getDetailProfile()`), Node 11 (Dòng 42, 43: `updateStatus`)     | Node 3 (Dòng 18: `if (!candidate)`)       | An toàn. `p-use` bảo vệ chống lỗi null pointer trước khi `c-use`.         |
| `job`              | Node 5 (Dòng 20)      | Node 7 (Dòng 25: `job.getDetailJob()`)                                                      | Node 5 (Dòng 21: `if (!job)`)             | An toàn. `p-use` bảo vệ trước khi `c-use`.                                |
| `analysisResult`   | Node 7 (Dòng 23)      | Node 9 (Dòng 32–35: trích xuất `summary`, `matchingScore`...)                               | Node 7 (Dòng 27: `if (!analysisResult)`)  | An toàn. `p-use` bảo vệ trước khi trích xuất object.                      |
| `savedAnalysis`    | Node 9 (Dòng 38)      | Node 11 (Dòng 45: `return savedAnalysis`)                                                   | Node 9 (Dòng 40: `if (!savedAnalysis)`)   | Hợp lệ.                                                                   |

### 6.1. Sơ đồ dòng dữ liệu Def-Use của các biến chính (Data Flow Diagram)

```mermaid
flowchart LR
    subgraph DefStep ["1. Điểm định nghĩa (def)"]
        D1["def: candidateID, jobID (Input)"]
        D2["def: existingAnalysis (getAnalysis)"]
        D3["def: candidate (getById)"]
        D4["def: job (getById)"]
        D5["def: analysisResult (analyzeCandidateWithJob)"]
        D6["def: savedAnalysis (create)"]
    end

    subgraph PUseStep ["2. Kiểm tra điều kiện (p-use)"]
        P1{"p-use: if (existingAnalysis)"}
        P2{"p-use: if (!candidate)"}
        P3{"p-use: if (!job)"}
        P4{"p-use: if (!analysisResult)"}
        P5{"p-use: if (!savedAnalysis)"}
    end

    subgraph CUseStep ["3. Sử dụng xử lý (c-use)"]
        C1["c-use: return existingAnalysis"]
        C2["c-use: geminiService(candidate, job)"]
        C3["c-use: AnalysisEntity.create"]
        C4["c-use: candidate.updateStatus(SCREENING)"]
    end

    D1 --> D2 --> P1 -- "True" --> C1
    P1 -- "False" --> D3 --> P2 -- "False" --> D4 --> P3 -- "False" --> D5
    D5 --> P4 -- "False" --> C2 --> C3 --> D6 --> P5 -- "False" --> C4
```

---

## 7. BẢNG CA KIỂM THỬ HỘP TRẮNG CHI TIẾT

| Test Case ID | Mục tiêu kiểm thử / Đường phủ                                                                 | Kỹ thuật kiểm thử    | Tiền điều kiện (Mock Repositories & Services)                                                                                                                              | Dữ liệu đầu vào (Input Parameters)                  | Kết quả mong đợi (Expected Output)                                                                        |   Trạng thái bao phủ   | Mức độ ưu tiên |
| :----------- | :-------------------------------------------------------------------------------------------- | :------------------- | :------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :-------------------------------------------------- | :-------------------------------------------------------------------------------------------------------- | :--------------------: | :------------: |
| **TC_WB_01** | Kiểm tra cơ chế Cache: Trả về kết quả phân tích có sẵn (`Path 1`)                             | C1, C2, Basis Path 1 | `aiAnalyzeRepo.getAnalysisByCandidateIdAndJobId` trả về `mockExistingAnalysis`<br>Các mock khác không được gọi                                                             | `candidateID = "CAN_01"`<br>`jobID = "JOB_01"`      | - Trả về `mockExistingAnalysis`<br>- Không gọi `candidateRepo.getById`<br>- Không gọi `geminiService`     |       Node 1, 2        |      High      |
| **TC_WB_02** | Bắt lỗi khi không tìm thấy ứng viên trong CSDL (`Path 2`)                                     | C1, C2, Basis Path 2 | `existingAnalysis` trả về `null`<br>`candidateRepo.getById("CAN_INVALID")` trả về `null`                                                                                   | `candidateID = "CAN_INVALID"`<br>`jobID = "JOB_01"` | - Ném ngoại lệ lỗi:<br>`"Không tìm thấy thông tin ứng viên."`<br>- Dừng ngay tại Node 4                   |      Node 1, 3, 4      |      High      |
| **TC_WB_03** | Bắt lỗi khi không tìm thấy thông tin công việc (`Path 3`)                                     | C1, C2, Basis Path 3 | `existingAnalysis` trả về `null`<br>`candidateRepo.getById` trả về `mockCandidate`<br>`jobRepo.getById("JOB_INVALID")` trả về `null`                                       | `candidateID = "CAN_01"`<br>`jobID = "JOB_INVALID"` | - Ném ngoại lệ lỗi:<br>`"Không tìm thấy thông tin công việc (Job)."`<br>- Dừng ngay tại Node 6            |    Node 1, 3, 5, 6     |      High      |
| **TC_WB_04** | Bắt lỗi khi dịch vụ Gemini AI sập kết nối hoặc trả về null (`Path 4`)                         | C1, C2, Basis Path 4 | `candidateRepo.getById` hợp lệ<br>`jobRepo.getById` hợp lệ<br>`geminiService.analyzeCandidateWithJob` trả về `null`                                                        | `candidateID = "CAN_01"`<br>`jobID = "JOB_01"`      | - Ném ngoại lệ lỗi:<br>`"Lỗi khi gọi AI phân tích dữ liệu."`<br>- Không gọi `aiAnalyzeRepo.create`        |   Node 1, 3, 5, 7, 8   |      High      |
| **TC_WB_05** | Bắt lỗi khi lưu kết quả phân tích vào CSDL thất bại (`Path 5`)                                | C1, C2, Basis Path 5 | AI phân tích thành công trả về object điểm số<br>`aiAnalyzeRepo.create` trả về `null` (Lỗi DB)                                                                             | `candidateID = "CAN_01"`<br>`jobID = "JOB_01"`      | - Ném ngoại lệ lỗi:<br>`"Lỗi khi lưu kết quả phân tích."`<br>- Không cập nhật status candidate            | Node 1, 3, 5, 7, 9, 10 |     Medium     |
| **TC_WB_06** | Luồng thành công hoàn chỉnh (Happy Path): Phân tích mới, lưu DB và cập nhật status (`Path 6`) | C1, C2, Basis Path 6 | Toàn bộ dữ liệu hợp lệ<br>AI trả về `{ summary: "...", matchingScore: 92, ... }`<br>`aiAnalyzeRepo.create` trả về `mockSavedAnalysis`<br>`candidateRepo.update` thành công | `candidateID = "CAN_01"`<br>`jobID = "JOB_01"`      | - Trả về `mockSavedAnalysis`<br>- Gọi `candidate.updateStatus(SCREENING)`<br>- Gọi `candidateRepo.update` | Node 1, 3, 5, 7, 9, 11 |      High      |

---

## 8. MA TRẬN ĐO LƯỜNG ĐỘ BAO PHỦ KIỂM THỬ `

### 8.1. Ma trận đối chiếu đường đi và ca kiểm thử

| Đường thực thi (Basis Path) | Nút bao phủ (Nodes Covered)                                                | Ca kiểm thử tương ứng | Trạng thái bao phủ |
| :-------------------------- | :------------------------------------------------------------------------- | :-------------------: | :----------------: |
| **Path 1**                  | $1 \rightarrow 2$                                                          |      `TC_WB_01`       | **Covered (100%)** |
| **Path 2**                  | $1 \rightarrow 3 \rightarrow 4$                                            |      `TC_WB_02`       | **Covered (100%)** |
| **Path 3**                  | $1 \rightarrow 3 \rightarrow 5 \rightarrow 6$                              |      `TC_WB_03`       | **Covered (100%)** |
| **Path 4**                  | $1 \rightarrow 3 \rightarrow 5 \rightarrow 7 \rightarrow 8$                |      `TC_WB_04`       | **Covered (100%)** |
| **Path 5**                  | $1 \rightarrow 3 \rightarrow 5 \rightarrow 7 \rightarrow 9 \rightarrow 10$ |      `TC_WB_05`       | **Covered (100%)** |
| **Path 6** (Happy Path)     | $1 \rightarrow 3 \rightarrow 5 \rightarrow 7 \rightarrow 9 \rightarrow 11$ |      `TC_WB_06`       | **Covered (100%)** |

### 8.2. Tổng kết tỷ lệ bao phủ theo tiêu chuẩn môn học

$$\text{Độ bao phủ câu lệnh (C1)} = \frac{11 \text{ Nodes}}{11 \text{ Nodes}} = 100\%$$

$$\text{Độ bao phủ nhánh (C2)} = \frac{10 \text{ Nhánh (True/False)}}{10 \text{ Nhánh}} = 100\%$$

$$\text{Độ bao phủ điều kiện (C3)} = 100\%$$

$$\text{Độ bao phủ đường cơ sở (Basis Path)} = \frac{6 \text{ Paths}}{6 \text{ Paths}} = 100\%$$

---

## 9. MÃ NGUỒN KIỂM THỬ TỰ ĐỘNG MINH HỌA (JEST / UNIT TEST)

Dưới đây là tệp mã nguồn kiểm thử đơn vị mẫu sử dụng framework **Jest** mô phỏng đầy đủ các ca kiểm thử hộp trắng ở trên:

```typescript
import { AnalysisUseCase } from "./analysis.use-case";
import { CandidateStatus } from "../../../domain/candidate";

describe("AnalysisUseCase - White-Box Unit Testing (UC_07)", () => {
  let useCase: AnalysisUseCase;
  let mockCandidateRepo: any;
  let mockJobRepo: any;
  let mockAiAnalyzeRepo: any;
  let mockGeminiService: any;

  beforeEach(() => {
    mockCandidateRepo = {
      getById: jest.fn(),
      update: jest.fn(),
    };
    mockJobRepo = {
      getById: jest.fn(),
    };
    mockAiAnalyzeRepo = {
      getAnalysisByCandidateIdAndJobId: jest.fn(),
      create: jest.fn(),
    };
    mockGeminiService = {
      analyzeCandidateWithJob: jest.fn(),
    };

    useCase = new AnalysisUseCase(
      mockCandidateRepo,
      mockJobRepo,
      mockAiAnalyzeRepo,
      mockGeminiService,
    );
  });

  // TC_WB_01: Basis Path 1 (Node 1 -> 2)
  it("TC_WB_01: Path 1 - Nên trả về phân tích có sẵn nếu đã tồn tại", async () => {
    const existing = { id: "ANALYSIS_01", matchingScore: 85 };
    mockAiAnalyzeRepo.getAnalysisByCandidateIdAndJobId.mockResolvedValue(
      existing,
    );

    const result = await useCase.execute({
      candidateID: "CAN_01",
      jobID: "JOB_01",
    });

    expect(result).toEqual(existing);
    expect(mockCandidateRepo.getById).not.toHaveBeenCalled();
    expect(mockGeminiService.analyzeCandidateWithJob).not.toHaveBeenCalled();
  });

  // TC_WB_02: Basis Path 2 (Node 1 -> 3 -> 4)
  it("TC_WB_02: Path 2 - Nên ném lỗi khi không tìm thấy thông tin ứng viên", async () => {
    mockAiAnalyzeRepo.getAnalysisByCandidateIdAndJobId.mockResolvedValue(null);
    mockCandidateRepo.getById.mockResolvedValue(null);

    await expect(
      useCase.execute({ candidateID: "CAN_INVALID", jobID: "JOB_01" }),
    ).rejects.toThrow("Không tìm thấy thông tin ứng viên.");
  });

  // TC_WB_03: Basis Path 3 (Node 1 -> 3 -> 5 -> 6)
  it("TC_WB_03: Path 3 - Nên ném lỗi khi không tìm thấy công việc (Job)", async () => {
    mockAiAnalyzeRepo.getAnalysisByCandidateIdAndJobId.mockResolvedValue(null);
    mockCandidateRepo.getById.mockResolvedValue({ id: "CAN_01" });
    mockJobRepo.getById.mockResolvedValue(null);

    await expect(
      useCase.execute({ candidateID: "CAN_01", jobID: "JOB_INVALID" }),
    ).rejects.toThrow("Không tìm thấy thông tin công việc (Job).");
  });

  // TC_WB_04: Basis Path 4 (Node 1 -> 3 -> 5 -> 7 -> 8)
  it("TC_WB_04: Path 4 - Nên ném lỗi khi gọi AI phân tích thất bại", async () => {
    const mockCandidate = { getDetailProfile: jest.fn().mockReturnValue({}) };
    const mockJob = { getDetailJob: jest.fn().mockReturnValue({}) };

    mockAiAnalyzeRepo.getAnalysisByCandidateIdAndJobId.mockResolvedValue(null);
    mockCandidateRepo.getById.mockResolvedValue(mockCandidate);
    mockJobRepo.getById.mockResolvedValue(mockJob);
    mockGeminiService.analyzeCandidateWithJob.mockResolvedValue(null);

    await expect(
      useCase.execute({ candidateID: "CAN_01", jobID: "JOB_01" }),
    ).rejects.toThrow("Lỗi khi gọi AI phân tích dữ liệu.");
  });

  // TC_WB_05: Basis Path 5 (Node 1 -> 3 -> 5 -> 7 -> 9 -> 10)
  it("TC_WB_05: Path 5 - Nên ném lỗi khi lưu kết quả phân tích thất bại", async () => {
    const mockCandidate = { getDetailProfile: jest.fn().mockReturnValue({}) };
    const mockJob = { getDetailJob: jest.fn().mockReturnValue({}) };

    mockAiAnalyzeRepo.getAnalysisByCandidateIdAndJobId.mockResolvedValue(null);
    mockCandidateRepo.getById.mockResolvedValue(mockCandidate);
    mockJobRepo.getById.mockResolvedValue(mockJob);
    mockGeminiService.analyzeCandidateWithJob.mockResolvedValue({
      summary: "Tốt",
      matchingScore: 80,
      redFlags: [],
      suggestedQuestions: [],
    });
    mockAiAnalyzeRepo.create.mockResolvedValue(null);

    await expect(
      useCase.execute({ candidateID: "CAN_01", jobID: "JOB_01" }),
    ).rejects.toThrow("Lỗi khi lưu kết quả phân tích.");
  });

  // TC_WB_06: Basis Path 6 (Node 1 -> 3 -> 5 -> 7 -> 9 -> 11) - Happy Path
  it("TC_WB_06: Path 6 - Phân tích thành công, cập nhật trạng thái ứng viên sang SCREENING", async () => {
    const mockCandidate = {
      getDetailProfile: jest.fn().mockReturnValue({ id: "CAN_01" }),
      updateStatus: jest.fn(),
    };
    const mockJob = {
      getDetailJob: jest.fn().mockReturnValue({ id: "JOB_01" }),
    };
    const mockAIOutput = {
      summary: "Ứng viên tiềm năng",
      matchingScore: 92,
      redFlags: [],
      suggestedQuestions: ["Kinh nghiệm Docker?"],
    };
    const mockSaved = { id: "ANALYSIS_NEW", ...mockAIOutput };

    mockAiAnalyzeRepo.getAnalysisByCandidateIdAndJobId.mockResolvedValue(null);
    mockCandidateRepo.getById.mockResolvedValue(mockCandidate);
    mockJobRepo.getById.mockResolvedValue(mockJob);
    mockGeminiService.analyzeCandidateWithJob.mockResolvedValue(mockAIOutput);
    mockAiAnalyzeRepo.create.mockResolvedValue(mockSaved);
    mockCandidateRepo.update.mockResolvedValue(mockCandidate);

    const result = await useCase.execute({
      candidateID: "CAN_01",
      jobID: "JOB_01",
    });

    expect(result).toEqual(mockSaved);
    expect(mockCandidate.updateStatus).toHaveBeenCalledWith(
      CandidateStatus.SCREENING,
    );
    expect(mockCandidateRepo.update).toHaveBeenCalledWith(mockCandidate);
  });
});
```
