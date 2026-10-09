# BÁO CÁO THIẾT KẾ KIỂM THỬ HỘP TRẮNG (WHITE-BOX TESTING)
## USE CASE 07: PHÂN TÍCH VÀ ĐÁNH GIÁ ỨNG VIÊN BẰNG AI (AnalysisUseCase)

---

### THÔNG TIN CHUNG
- **Môn học:** Kiểm thử và Đảm bảo Chất lượng Phần mềm (CSE462)
- **Học kỳ:** Học kỳ 7 – Năm học 2025–2026
- **Giảng viên hướng dẫn:** TS. Nguyễn Thị Phương Dung
- **Sinh viên thực hiện:** Phùng Văn Duy
- **Mã số sinh viên (MSSV):** 2351170589
- **Nhóm thực hiện:** Nhóm 09
- **Đề tài:** Hệ thống Quản lý Tuyển dụng – Trợ lý Tuyển dụng & Sàng lọc Hồ sơ Tự động
- **Đối tượng kiểm thử:** Lớp `AnalysisUseCase` – Phương thức `execute(input: AnalysisInputDto)`

---

## 1. MÃ NGUỒN ĐÁNH SỐ DÒNG (SOURCE CODE UNDER TEST)

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

| Đỉnh (Node) | Dòng mã nguồn | Nội dung thao tác & Câu lệnh | Loại đỉnh |
| :--- | :--- | :--- | :--- |
| **Node 1** | Dòng 10–13 | Lấy `candidateID`, `jobID`, kiểm tra kết quả phân tích cũ: `getAnalysisByCandidateIdAndJobId()`, điều kiện `if (existingAnalysis)` | Decision (Vị từ) |
| **Node 2** | Dòng 14 | `return existingAnalysis as AnalysisOutputDto;` (Đã phân tích trước đó) | Exit (Normal 1) |
| **Node 3** | Dòng 17–18 | Truy vấn ứng viên: `candidateRepo.getById(candidateID)`, điều kiện `if (!candidate)` | Decision (Vị từ) |
| **Node 4** | Dòng 18 | `throw new Error('Không tìm thấy thông tin ứng viên.')` | Exit (Exception 1) |
| **Node 5** | Dòng 20–21 | Truy vấn công việc: `jobRepo.getById(jobID)`, điều kiện `if (!job)` | Decision (Vị từ) |
| **Node 6** | Dòng 21 | `throw new Error('Không tìm thấy thông tin công việc (Job).')` | Exit (Exception 2) |
| **Node 7** | Dòng 23–27 | Gọi AI phân tích: `geminiService.analyzeCandidateWithJob(...)`, điều kiện `if (!analysisResult)` | Decision (Vị từ) |
| **Node 8** | Dòng 27 | `throw new Error('Lỗi khi gọi AI phân tích dữ liệu.')` | Exit (Exception 3) |
| **Node 9** | Dòng 29–40 | Khởi tạo thực thể `AnalysisEntity.create()`, lưu vào DB: `aiAnalyzeRepo.create(analysis)`, điều kiện `if (!savedAnalysis)` | Decision (Vị từ) |
| **Node 10** | Dòng 40 | `throw new Error('Lỗi khi lưu kết quả phân tích.')` | Exit (Exception 4) |
| **Node 11** | Dòng 42–45 | Cập nhật trạng thái ứng viên `SCREENING`: `candidate.updateStatus()`, `candidateRepo.update(candidate)`, trả về `return savedAnalysis as AnalysisOutputDto;` | Exit (Normal 2) |

---

### 2.2. Đồ thị dòng điều khiển (Control Flow Graph - CFG)

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

---

## 3. TÍNH ĐỘ PHỨC TẠP CYCLOMATIC (CYCLOMATIC COMPLEXITY)

Độ phức tạp Cyclomatic $V(G)$ phản ánh số lượng đường dẫn độc lập tuyến tính trong chương trình. Ta tính toán theo 3 phương pháp độc lập theo tiêu chuẩn Thomas J. McCabe:

### Phương pháp 1: Dựa trên số cung (Edges) và số đỉnh (Nodes)
Công thức:
$$V(G) = E - N + 2P$$
Trong đó:
- Số đỉnh (Nodes) $N = 11$ (Node 1 đến Node 11)
- Số cung (Edges) $E = 15$ (Gồm 1 cung vào Node 1, 5 nhánh True/False rẽ từ 5 node quyết định, 1 cung chuyển tiếp từ Start đến Node 1)
- Số thành phần liên thông (Connected Components) $P = 1$

Tính toán:
$$V(G) = 15 - 11 + 2(1) = 6$$

---

### Phương pháp 2: Dựa trên số nút quyết định vị từ (Predicate Nodes)
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

### Phương pháp 3: Dựa trên số miền khép kín (Enclosed Regions)
Công thức:
$$V(G) = R$$
Trong đó $R$ là tổng số miền đóng (vùng khép kín tạo bởi các chu trình phẳng) cộng với 1 miền vô hạn bên ngoài:
- Đồ thị có 5 nhánh rẽ thoát ra các điểm kết thúc độc lập tạo thành 5 miền mặt phẳng cục bộ $R_1, R_2, R_3, R_4, R_5$.
- Miền hở bao quanh đồ thị là $R_6$.

Tổng số miền $R = 6 \implies V(G) = 6$.

> **Kết luận:** Cả 3 phương pháp đều cho kết quả nhất quán: **Độ phức tạp Cyclomatic $V(G) = 6$**.  
> Do đó, tập đường dẫn cơ sở (Basis Paths) cần xây dựng tối thiểu là **6 đường dẫn độc lập**.

---

## 4. TẬP ĐƯỜNG DẪN CƠ SỞ (BASIS PATHS)

| Đường dẫn (Path) | Chuỗi các Node thực thi | Điều kiện kích hoạt luồng | Kết quả đầu ra mong đợi |
| :--- | :--- | :--- | :--- |
| **Path 1** | Node 1 $\rightarrow$ Node 2 | `existingAnalysis != null` (Tìm thấy kết quả đã phân tích từ trước) | Trả về trực tiếp bản ghi phân tích cũ (`existingAnalysis`), không gọi lại AI |
| **Path 2** | Node 1 $\rightarrow$ Node 3 $\rightarrow$ Node 4 | `existingAnalysis == null` VÀ `candidate == null` (Không tìm thấy ứng viên trong DB) | Ném ngoại lệ lỗi: `"Không tìm thấy thông tin ứng viên."` |
| **Path 3** | Node 1 $\rightarrow$ Node 3 $\rightarrow$ Node 5 $\rightarrow$ Node 6 | `existingAnalysis == null`, `candidate != null` VÀ `job == null` (Không tìm thấy Job) | Ném ngoại lệ lỗi: `"Không tìm thấy thông tin công việc (Job)."` |
| **Path 4** | Node 1 $\rightarrow$ Node 3 $\rightarrow$ Node 5 $\rightarrow$ Node 7 $\rightarrow$ Node 8 | `existingAnalysis == null`, `candidate != null`, `job != null` VÀ `analysisResult == null` (Gemini AI gặp lỗi hoặc sập kết nối) | Ném ngoại lệ lỗi: `"Lỗi khi gọi AI phân tích dữ liệu."` |
| **Path 5** | Node 1 $\rightarrow$ Node 3 $\rightarrow$ Node 5 $\rightarrow$ Node 7 $\rightarrow$ Node 9 $\rightarrow$ Node 10 | Đầy đủ dữ liệu, AI trả về kết quả nhưng lưu DB thất bại: `savedAnalysis == null` | Ném ngoại lệ lỗi: `"Lỗi khi lưu kết quả phân tích."` |
| **Path 6** (Happy Path) | Node 1 $\rightarrow$ Node 3 $\rightarrow$ Node 5 $\rightarrow$ Node 7 $\rightarrow$ Node 9 $\rightarrow$ Node 11 | Chưa có kết quả cũ, tìm thấy candidate, tìm thấy job, AI phân tích thành công, lưu DB thành công, cập nhật trạng thái `SCREENING` | Trả về đối tượng `savedAnalysis` mới, trạng thái ứng viên chuyển sang `SCREENING` |

---

## 5. BẢNG CA KIỂM THỬ HỘP TRẮNG CHI TIẾT (TEST CASES SPECIFICATION)

| Test Case ID | Mục tiêu kiểm thử | Đường dẫn bao phủ (Basis Path) | Tiền điều kiện & Dữ liệu đầu vào (Test Data) | Giả lập hệ thống (Mocking/Stubs Setup) | Kết quả mong đợi (Expected Output) | Mức độ ưu tiên |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **TC_WB_01** | Kiểm tra cơ chế Cache/Tái sử dụng: Trả về kết quả phân tích có sẵn | **Path 1**<br>(1 $\rightarrow$ 2) | - `input`: `{ candidateID: "CAN_01", jobID: "JOB_01" }` | - `aiAnalyzeRepo.getAnalysisByCandidateIdAndJobId("CAN_01", "JOB_01")` $\rightarrow$ Trả về `mockExistingAnalysis`<br>- Không gọi các repo và AI còn lại | - Hàm trả về `mockExistingAnalysis`<br>- `geminiService.analyzeCandidateWithJob` không được gọi | High |
| **TC_WB_02** | Bắt lỗi ứng viên không tồn tại trong CSDL | **Path 2**<br>(1 $\rightarrow$ 3 $\rightarrow$ 4) | - `input`: `{ candidateID: "CAN_INVALID", jobID: "JOB_01" }` | - `aiAnalyzeRepo.getAnalysisByCandidateIdAndJobId` $\rightarrow$ `null`<br>- `candidateRepo.getById("CAN_INVALID")` $\rightarrow$ `null` | - Ném lỗi (Exception):<br>`"Không tìm thấy thông tin ứng viên."`<br>- Tiến trình dừng ngay tại Node 4 | High |
| **TC_WB_03** | Bắt lỗi vị trí công việc (Job) không tồn tại | **Path 3**<br>(1 $\rightarrow$ 3 $\rightarrow$ 5 $\rightarrow$ 6) | - `input`: `{ candidateID: "CAN_01", jobID: "JOB_INVALID" }` | - `aiAnalyzeRepo.getAnalysisByCandidateIdAndJobId` $\rightarrow$ `null`<br>- `candidateRepo.getById("CAN_01")` $\rightarrow$ `mockCandidate`<br>- `jobRepo.getById("JOB_INVALID")` $\rightarrow$ `null` | - Ném lỗi (Exception):<br>`"Không tìm thấy thông tin công việc (Job)."`<br>- Dừng ngay tại Node 6 | High |
| **TC_WB_04** | Bắt lỗi khi dịch vụ Gemini AI gặp sự cố (trả về null/undefined) | **Path 4**<br>(1 $\rightarrow$ 3 $\rightarrow$ 5 $\rightarrow$ 7 $\rightarrow$ 8) | - `input`: `{ candidateID: "CAN_01", jobID: "JOB_01" }` | - `existingAnalysis` $\rightarrow$ `null`<br>- `candidateRepo.getById` $\rightarrow$ `mockCandidate`<br>- `jobRepo.getById` $\rightarrow$ `mockJob`<br>- `geminiService.analyzeCandidateWithJob` $\rightarrow$ `null` (hoặc timeout/error) | - Ném lỗi (Exception):<br>`"Lỗi khi gọi AI phân tích dữ liệu."`<br>- Không thực hiện tạo entity mới | High |
| **TC_WB_05** | Bắt lỗi khi không lưu được kết quả phân tích vào DB | **Path 5**<br>(1 $\rightarrow$ 3 $\rightarrow$ 5 $\rightarrow$ 7 $\rightarrow$ 9 $\rightarrow$ 10) | - `input`: `{ candidateID: "CAN_01", jobID: "JOB_01" }` | - AI phân tích thành công: trả về `{ summary: "Tốt", matchingScore: 85, redFlags: [], suggestedQuestions: [] }`<br>- `aiAnalyzeRepo.create(analysis)` $\rightarrow$ `null` (Lỗi DB kết nối) | - Ném lỗi (Exception):<br>`"Lỗi khi lưu kết quả phân tích."`<br>- Trạng thái ứng viên KHÔNG bị cập nhật | Medium |
| **TC_WB_06** | Luồng thành công hoàn chỉnh (Happy Path): Phân tích mới, lưu DB và chuyển status `SCREENING` | **Path 6**<br>(1 $\rightarrow$ 3 $\rightarrow$ 5 $\rightarrow$ 7 $\rightarrow$ 9 $\rightarrow$ 11) | - `input`: `{ candidateID: "CAN_01", jobID: "JOB_01" }` | - `existingAnalysis` $\rightarrow$ `null`<br>- `candidateRepo.getById` $\rightarrow$ `mockCandidate`<br>- `jobRepo.getById` $\rightarrow$ `mockJob`<br>- `geminiService.analyzeCandidateWithJob` $\rightarrow$ `{ summary: "Hồ sơ phù hợp...", matchingScore: 90, redFlags: [], suggestedQuestions: ["Hỏi về NestJS"] }`<br>- `aiAnalyzeRepo.create` $\rightarrow$ `mockSavedAnalysis`<br>- `candidateRepo.update` $\rightarrow$ `mockCandidateUpdated` | - Trả về `mockSavedAnalysis`<br>- Gọi `candidate.updateStatus(CandidateStatus.SCREENING)`<br>- Gọi `candidateRepo.update(candidate)` thành công | High |

---

## 6. MA TRẬN ĐỘ BAO PHỦ KIỂM THỬ (TEST COVERAGE MATRIX)

| Thành phần kiểm thử | Số lượng trong Code | Ca kiểm thử bao phủ (Test Cases) | Tỷ lệ bao phủ đạt được |
| :--- | :--- | :--- | :--- |
| **Statement Coverage (Bao phủ dòng lệnh)** | 11/11 Basic Blocks (100% dòng lệnh logic) | Bao phủ bởi tập hợp 6 Test Cases `TC_WB_01` $\rightarrow$ `TC_WB_06` | **100%** |
| **Branch Coverage (Bao phủ nhánh quyết định)** | 5 cặp nhánh True / False (10 nhánh) | - Node 1: True (TC_WB_01), False (TC_WB_02..06)<br>- Node 3: True (TC_WB_02), False (TC_WB_03..06)<br>- Node 5: True (TC_WB_03), False (TC_WB_04..06)<br>- Node 7: True (TC_WB_04), False (TC_WB_05..06)<br>- Node 9: True (TC_WB_05), False (TC_WB_06) | **100% (10/10 nhánh)** |
| **Basis Path Coverage (Bao phủ đường cơ sở)** | 6 Đường dẫn độc lập ($V(G) = 6$) | 6 ca kiểm thử ánh xạ 1-1 với 6 Basis Paths | **100% (6/6 Paths)** |

---

## 7. MÃ NGUỒN KIỂM THỬ TỰ ĐỘNG MINH HỌA (JEST UNIT TEST SUITE)

Dưới đây là bộ Unit Test tự động viết bằng Jest/TypeScript thực thi chính xác 6 ca kiểm thử trên:

```typescript
import { AnalysisUseCase } from './analysis.use-case';
import { CandidateStatus } from '../../../domain/candidate';
import { AnalysisEntity } from '../../../domain/analysis';

describe('AnalysisUseCase - White-Box Testing Suite (UC_07)', () => {
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

  // TC_WB_01: Path 1 (Node 1 -> 2)
  it('TC_WB_01: Path 1 - Nên trả về phân tích có sẵn nếu đã tồn tại', async () => {
    const existing = { id: 'ANALYSIS_01', matchingScore: 85 };
    mockAiAnalyzeRepo.getAnalysisByCandidateIdAndJobId.mockResolvedValue(existing);

    const result = await useCase.execute({ candidateID: 'CAN_01', jobID: 'JOB_01' });

    expect(result).toEqual(existing);
    expect(mockCandidateRepo.getById).not.toHaveBeenCalled();
    expect(mockGeminiService.analyzeCandidateWithJob).not.toHaveBeenCalled();
  });

  // TC_WB_02: Path 2 (Node 1 -> 3 -> 4)
  it('TC_WB_02: Path 2 - Nên ném lỗi khi không tìm thấy thông tin ứng viên', async () => {
    mockAiAnalyzeRepo.getAnalysisByCandidateIdAndJobId.mockResolvedValue(null);
    mockCandidateRepo.getById.mockResolvedValue(null);

    await expect(
      useCase.execute({ candidateID: 'CAN_INVALID', jobID: 'JOB_01' })
    ).rejects.toThrow('Không tìm thấy thông tin ứng viên.');
  });

  // TC_WB_03: Path 3 (Node 1 -> 3 -> 5 -> 6)
  it('TC_WB_03: Path 3 - Nên ném lỗi khi không tìm thấy công việc (Job)', async () => {
    mockAiAnalyzeRepo.getAnalysisByCandidateIdAndJobId.mockResolvedValue(null);
    mockCandidateRepo.getById.mockResolvedValue({ id: 'CAN_01' });
    mockJobRepo.getById.mockResolvedValue(null);

    await expect(
      useCase.execute({ candidateID: 'CAN_01', jobID: 'JOB_INVALID' })
    ).rejects.toThrow('Không tìm thấy thông tin công việc (Job).');
  });

  // TC_WB_04: Path 4 (Node 1 -> 3 -> 5 -> 7 -> 8)
  it('TC_WB_04: Path 4 - Nên ném lỗi khi gọi AI phân tích thất bại', async () => {
    const mockCandidate = { getDetailProfile: jest.fn().mockReturnValue({}) };
    const mockJob = { getDetailJob: jest.fn().mockReturnValue({}) };

    mockAiAnalyzeRepo.getAnalysisByCandidateIdAndJobId.mockResolvedValue(null);
    mockCandidateRepo.getById.mockResolvedValue(mockCandidate);
    mockJobRepo.getById.mockResolvedValue(mockJob);
    mockGeminiService.analyzeCandidateWithJob.mockResolvedValue(null);

    await expect(
      useCase.execute({ candidateID: 'CAN_01', jobID: 'JOB_01' })
    ).rejects.toThrow('Lỗi khi gọi AI phân tích dữ liệu.');
  });

  // TC_WB_05: Path 5 (Node 1 -> 3 -> 5 -> 7 -> 9 -> 10)
  it('TC_WB_05: Path 5 - Nên ném lỗi khi lưu kết quả phân tích thất bại', async () => {
    const mockCandidate = { getDetailProfile: jest.fn().mockReturnValue({}) };
    const mockJob = { getDetailJob: jest.fn().mockReturnValue({}) };

    mockAiAnalyzeRepo.getAnalysisByCandidateIdAndJobId.mockResolvedValue(null);
    mockCandidateRepo.getById.mockResolvedValue(mockCandidate);
    mockJobRepo.getById.mockResolvedValue(mockJob);
    mockGeminiService.analyzeCandidateWithJob.mockResolvedValue({
      summary: 'Tốt',
      matchingScore: 80,
      redFlags: [],
      suggestedQuestions: []
    });
    mockAiAnalyzeRepo.create.mockResolvedValue(null);

    await expect(
      useCase.execute({ candidateID: 'CAN_01', jobID: 'JOB_01' })
    ).rejects.toThrow('Lỗi khi lưu kết quả phân tích.');
  });

  // TC_WB_06: Path 6 (Node 1 -> 3 -> 5 -> 7 -> 9 -> 11) - Happy Path
  it('TC_WB_06: Path 6 - Phân tích thành công, cập nhật trạng thái ứng viên sang SCREENING', async () => {
    const mockCandidate = {
      getDetailProfile: jest.fn().mockReturnValue({ id: 'CAN_01' }),
      updateStatus: jest.fn(),
    };
    const mockJob = {
      getDetailJob: jest.fn().mockReturnValue({ id: 'JOB_01' }),
    };
    const mockAIOutput = {
      summary: 'Ứng viên tiềm năng',
      matchingScore: 92,
      redFlags: [],
      suggestedQuestions: ['Kinh nghiệm Docker?']
    };
    const mockSaved = { id: 'ANALYSIS_NEW', ...mockAIOutput };

    mockAiAnalyzeRepo.getAnalysisByCandidateIdAndJobId.mockResolvedValue(null);
    mockCandidateRepo.getById.mockResolvedValue(mockCandidate);
    mockJobRepo.getById.mockResolvedValue(mockJob);
    mockGeminiService.analyzeCandidateWithJob.mockResolvedValue(mockAIOutput);
    mockAiAnalyzeRepo.create.mockResolvedValue(mockSaved);
    mockCandidateRepo.update.mockResolvedValue(mockCandidate);

    const result = await useCase.execute({ candidateID: 'CAN_01', jobID: 'JOB_01' });

    expect(result).toEqual(mockSaved);
    expect(mockCandidate.updateStatus).toHaveBeenCalledWith(CandidateStatus.SCREENING);
    expect(mockCandidateRepo.update).toHaveBeenCalledWith(mockCandidate);
  });
});
```
