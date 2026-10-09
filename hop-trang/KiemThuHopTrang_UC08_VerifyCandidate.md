# BÁO CÁO THIẾT KẾ KIỂM THỬ HỘP TRẮNG (WHITE-BOX TESTING)
## USE CASE 08: XÁC THỰC THÔNG TIN ỨNG VIÊN (VerifyCandidateUseCase)

---

### THÔNG TIN CHUNG
- **Môn học:** Kiểm thử và Đảm bảo Chất lượng Phần mềm (CSE462)
- **Học kỳ:** Học kỳ 7 – Năm học 2025–2026
- **Giảng viên hướng dẫn:** TS. Nguyễn Thị Phương Dung
- **Sinh viên thực hiện:** Phùng Văn Duy
- **Mã số sinh viên (MSSV):** 2351170589
- **Nhóm thực hiện:** Nhóm 09
- **Đề tài:** Hệ thống Quản lý Tuyển dụng – Trợ lý Tuyển dụng & Sàng lọc Hồ sơ Tự động
- **Đối tượng kiểm thử:** Lớp `VerifyCandidateUseCase` – Phương thức `execute(candidateID: string, dataVerification: IVerifyCandidateInputDTO)`

---

## 1. MÃ NGUỒN ĐÁNH SỐ DÒNG (SOURCE CODE UNDER TEST)

```typescript
1:  export class VerifyCandidateUseCase {
2:    constructor(
3:      private readonly candidateRepo: IVerificationRepository,
4:    ) { }
5:  
6:    async execute(candidateID: string, dataVerification: IVerifyCandidateInputDTO): Promise<IVerificationProps> {
7:      const verification = VerificationEntity.create({
8:        ...dataVerification,
9:        candidateId: candidateID,
10:     });
11: 
12:     const [result] = await Promise.all([
13:       this.candidateRepo.create(verification),
14:       this.candidateRepo.updateIsVerify(candidateID, true)
15:     ]);
16: 
17:     if (!result) throw new Error("Kiểm chứng lỗi vui lòng thử lại!");
18: 
19:     return result.getDetail();
20:   }
21: }
```

---

## 2. PHÂN TÍCH KHỐI LỆNH CƠ BẢN VÀ ĐỒ THỊ DÒNG ĐIỀU KHIỂN (CFG)

### 2.1. Phân chia các khối lệnh cơ bản (Basic Blocks / Nodes)

| Đỉnh (Node) | Dòng mã nguồn | Nội dung thao tác & Câu lệnh | Loại đỉnh |
| :--- | :--- | :--- | :--- |
| **Node 1** | Dòng 7–15 | - Khởi tạo thực thể kiểm chứng: `VerificationEntity.create(...)`<br>- Gọi đồng thời qua `Promise.all`: `create(verification)` và `updateIsVerify(candidateID, true)`<br>- Trích xuất phần tử đầu tiên: `const [result] = ...` | Process (Xử lý tuần tự) |
| **Node 2** | Dòng 17 | Kiểm tra điều kiện kết quả tạo kiểm chứng: `if (!result)` | Decision (Vị từ rẽ nhánh) |
| **Node 3** | Dòng 17 | Ném ngoại lệ lỗi: `throw new Error("Kiểm chứng lỗi vui lòng thử lại!")` | Exit (Exception / Lỗi) |
| **Node 4** | Dòng 19 | Trích xuất thông tin chi tiết và trả về: `return result.getDetail()` | Exit (Normal / Thành công) |

---

### 2.2. Đồ thị dòng điều khiển (Control Flow Graph - CFG)

```mermaid
flowchart TD
    Start(["Bắt đầu: execute(candidateID, dataVerification)"]) --> N1["Node 1: VerificationEntity.create & Promise.all(create, updateIsVerify)"]
    
    N1 --> N2["Node 2: if (!result)"]
    
    N2 -- True --> N3["Node 3: throw 'Kiểm chứng lỗi vui lòng thử lại!'"]
    N2 -- False --> N4["Node 4: return result.getDetail()"]
```

---

## 3. TÍNH ĐỘ PHỨC TẠP CYCLOMATIC (CYCLOMATIC COMPLEXITY)

Độ phức tạp Cyclomatic $V(G)$ được tính toán độc lập theo 3 phương pháp chuẩn Thomas J. McCabe:

### Phương pháp 1: Dựa trên số cung (Edges) và số đỉnh (Nodes)
Công thức:
$$V(G) = E - N + 2P$$
Trong đó:
- Số đỉnh (Nodes) $N = 4$ (Node 1, Node 2, Node 3, Node 4)
- Số cung (Edges) $E = 4$ (Start $\rightarrow$ N1, N1 $\rightarrow$ N2, N2 $\xrightarrow{\text{True}}$ N3, N2 $\xrightarrow{\text{False}}$ N4)
- Số thành phần liên thông $P = 1$

Tính toán:
$$V(G) = 4 - 4 + 2(1) = 2$$

---

### Phương pháp 2: Dựa trên số nút quyết định vị từ (Predicate Nodes)
Công thức:
$$V(G) = P_n + 1$$
Trong đó:
- $P_n$ là số nút vị từ đưa ra quyết định rẽ nhánh nhị phân.
- Trong mã nguồn chỉ có duy nhất 1 điểm rẽ nhánh tại **Node 2**: `if (!result)`.
- Vậy $P_n = 1$.

Tính toán:
$$V(G) = 1 + 1 = 2$$

---

### Phương pháp 3: Dựa trên số miền khép kín (Enclosed Regions)
Công thức:
$$V(G) = R$$
Trong đó $R$ là tổng số miền phẳng khép kín cộng với miền vô hạn bên ngoài:
- 1 miền rẽ nhánh tạo bởi 2 nhánh kết thúc True/False ($R_1$).
- 1 miền vô hạn bao quanh đồ thị ($R_2$).

Tổng số miền $R = 2 \implies V(G) = 2$.

> **Kết luận:** Cả 3 phương pháp đều cho kết quả: **Độ phức tạp Cyclomatic $V(G) = 2$**.  
> Do đó, tập đường dẫn cơ sở (Basis Paths) gồm tối thiểu **2 đường dẫn độc lập**.

---

## 4. TẬP ĐƯỜNG DẪN CƠ SỞ (BASIS PATHS)

| Đường dẫn (Path) | Chuỗi Node thực thi | Điều kiện kích hoạt luồng | Kết quả đầu ra mong đợi |
| :--- | :--- | :--- | :--- |
| **Path 1** (Exception Flow) | Node 1 $\rightarrow$ Node 2 $\rightarrow$ Node 3 | `result == null` hoặc `undefined` (Tạo bản ghi kiểm chứng thất bại tại CSDL) | Ném lỗi: `"Kiểm chứng lỗi vui lòng thử lại!"` |
| **Path 2** (Happy Path) | Node 1 $\rightarrow$ Node 2 $\rightarrow$ Node 4 | `result != null` (Tạo bản ghi kiểm chứng thành công và cập nhật cờ `isVerify` thành công) | Trả về đối tượng `IVerificationProps` chi tiết (`result.getDetail()`) |

---

## 5. MỞ RỘNG KIỂM THỬ NGOẠI LỆ BẤT ĐỒNG BỘ (ASYNCHRONOUS PROMISE REJECTION)

Ngoài 2 đường dẫn cơ sở chuẩn, hàm `execute` sử dụng `Promise.all([create, updateIsVerify])`. Trong môi trường thực thi thực tế của JavaScript/TypeScript, nếu một trong hai tác vụ bất đồng bộ bị từ chối (`rejected`), `Promise.all` sẽ ném trực tiếp lỗi ra ngoài. Do đó, cần bổ sung 2 ca kiểm thử biên bất đồng bộ để đảm bảo khả năng bao phủ toàn diện 100% rủi ro:
1. `candidateRepo.create` bị Reject (Lỗi kết nối CSDL khi ghi log kiểm chứng).
2. `candidateRepo.updateIsVerify` bị Reject (Lỗi khi cập nhật trạng thái ứng viên).

---

## 6. BẢNG CA KIỂM THỬ HỘP TRẮNG CHI TIẾT (TEST CASES SPECIFICATION)

| Test Case ID | Mục tiêu kiểm thử | Đường dẫn bao phủ | Tiền điều kiện & Dữ liệu đầu vào (Test Data) | Giả lập hệ thống (Mock Setup) | Kết quả mong đợi (Expected Output) | Mức độ ưu tiên |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **TC_WB_01** | Bắt lỗi khi việc lưu bản ghi kiểm chứng thất bại (`result` là falsy) | **Path 1**<br>(1 $\rightarrow$ 2 $\rightarrow$ 3) | - `candidateID`: `"CAN_01"`<br>- `dataVerification`: `{ status: "VERIFIED", notes: "Bằng cấp hợp lệ", verifiedBy: "HR_ADMIN" }` | - `candidateRepo.create` $\rightarrow$ Trả về `null`<br>- `candidateRepo.updateIsVerify` $\rightarrow$ Trả về `true` | - Ném ngoại lệ lỗi:<br>`"Kiểm chứng lỗi vui lòng thử lại!"`<br>- Không gọi đến `result.getDetail()` | High |
| **TC_WB_02** | Luồng thành công hoàn chỉnh: Tạo kiểm chứng và cập nhật trạng thái đã xác thực | **Path 2**<br>(1 $\rightarrow$ 2 $\rightarrow$ 4) | - `candidateID`: `"CAN_01"`<br>- `dataVerification`: `{ status: "VERIFIED", notes: "Hồ sơ đạt chuẩn", verifiedBy: "HR_ADMIN" }` | - `mockVerificationResult` có phương thức `.getDetail()` trả về `{ id: "VER_01", candidateId: "CAN_01", status: "VERIFIED" }`<br>- `candidateRepo.create` $\rightarrow$ Trả về `mockVerificationResult`<br>- `candidateRepo.updateIsVerify` $\rightarrow$ Trả về `true` | - Trả về đúng object từ `result.getDetail()`<br>- Cả hai hàm `create` và `updateIsVerify("CAN_01", true)` đều được gọi đúng tham số | High |
| **TC_WB_03** | Kiểm tra lỗi bất đồng bộ khi hàm `create` bị sập CSDL (Promise Reject) | Bất đồng bộ<br>(Promise.all) | - `candidateID`: `"CAN_01"`<br>- `dataVerification`: `{ status: "VERIFIED", notes: "Lỗi DB", verifiedBy: "HR_ADMIN" }` | - `candidateRepo.create` $\rightarrow$ Reject lỗi: `new Error("Database connection error")`<br>- `candidateRepo.updateIsVerify` $\rightarrow$ Resolved | - Ném ngoại lệ lỗi:<br>`"Database connection error"` | Medium |
| **TC_WB_04** | Kiểm tra lỗi bất đồng bộ khi cập nhật cờ `isVerify` thất bại (Promise Reject) | Bất đồng bộ<br>(Promise.all) | - `candidateID`: `"CAN_01"`<br>- `dataVerification`: `{ status: "VERIFIED", notes: "Lỗi update", verifiedBy: "HR_ADMIN" }` | - `candidateRepo.create` $\rightarrow$ Resolved `mockVerificationResult`<br>- `candidateRepo.updateIsVerify` $\rightarrow$ Reject lỗi: `new Error("Update status failed")` | - Ném ngoại lệ lỗi:<br>`"Update status failed"` | Medium |

---

## 7. MA TRẬN ĐỘ BAO PHỦ KIỂM THỬ (TEST COVERAGE MATRIX)

| Tiêu chuẩn bao phủ | Đối tượng trong mã nguồn | Các ca kiểm thử bao phủ | Tỷ lệ bao phủ đạt được |
| :--- | :--- | :--- | :--- |
| **Statement Coverage (Bao phủ dòng lệnh)** | 4/4 Basic Blocks (100% dòng lệnh) | Bao phủ hoàn toàn bởi `TC_WB_01` và `TC_WB_02` | **100%** |
| **Branch Coverage (Bao phủ nhánh quyết định)** | 1 cặp nhánh True / False (Node 2) | - Nhánh True: `TC_WB_01`<br>- Nhánh False: `TC_WB_02` | **100% (2/2 nhánh)** |
| **Basis Path Coverage (Bao phủ đường cơ sở)** | 2 Đường dẫn độc lập ($V(G) = 2$) | Ánh xạ 1-1 với `TC_WB_01` và `TC_WB_02` | **100% (2/2 Paths)** |
| **Async Robustness Coverage (Ngoại lệ bất đồng bộ)** | 2 Promises chạy song song | `TC_WB_03`, `TC_WB_04` | **100%** |

---

## 8. MÃ NGUỒN KIỂM THỬ TỰ ĐỘNG MINH HỌA (JEST UNIT TEST SUITE)

```typescript
import { VerifyCandidateUseCase } from './verify-candidate.use-case';
import { VerificationEntity } from '../../../domain/verifycation';

describe('VerifyCandidateUseCase - White-Box Testing Suite (UC_08)', () => {
  let useCase: VerifyCandidateUseCase;
  let mockCandidateRepo: any;

  beforeEach(() => {
    mockCandidateRepo = {
      create: jest.fn(),
      updateIsVerify: jest.fn(),
    };
    useCase = new VerifyCandidateUseCase(mockCandidateRepo);
  });

  // TC_WB_01: Path 1 (Node 1 -> 2 -> 3)
  it('TC_WB_01: Path 1 - Nên ném lỗi khi kết quả tạo kiểm chứng là null hoặc falsy', async () => {
    mockCandidateRepo.create.mockResolvedValue(null);
    mockCandidateRepo.updateIsVerify.mockResolvedValue(true);

    const inputData = {
      status: 'VERIFIED',
      notes: 'Hồ sơ kiểm tra thông tin',
      verifiedBy: 'HR_01',
    } as any;

    await expect(
      useCase.execute('CAN_01', inputData)
    ).rejects.toThrow('Kiểm chứng lỗi vui lòng thử lại!');

    expect(mockCandidateRepo.create).toHaveBeenCalled();
    expect(mockCandidateRepo.updateIsVerify).toHaveBeenCalledWith('CAN_01', true);
  });

  // TC_WB_02: Path 2 (Node 1 -> 2 -> 4) - Happy Path
  it('TC_WB_02: Path 2 - Nên tạo kiểm chứng thành công và trả về thông tin chi tiết', async () => {
    const mockDetail = {
      id: 'VER_01',
      candidateId: 'CAN_01',
      status: 'VERIFIED',
      notes: 'Thông tin hợp lệ',
    };

    const mockResult = {
      getDetail: jest.fn().mockReturnValue(mockDetail),
    };

    mockCandidateRepo.create.mockResolvedValue(mockResult);
    mockCandidateRepo.updateIsVerify.mockResolvedValue(true);

    const inputData = {
      status: 'VERIFIED',
      notes: 'Thông tin hợp lệ',
      verifiedBy: 'HR_01',
    } as any;

    const result = await useCase.execute('CAN_01', inputData);

    expect(result).toEqual(mockDetail);
    expect(mockCandidateRepo.create).toHaveBeenCalled();
    expect(mockCandidateRepo.updateIsVerify).toHaveBeenCalledWith('CAN_01', true);
    expect(mockResult.getDetail).toHaveBeenCalled();
  });

  // TC_WB_03: Async Exception - create throws Error
  it('TC_WB_03: Nên ném lỗi khi candidateRepo.create bị reject', async () => {
    mockCandidateRepo.create.mockRejectedValue(new Error('Database connection error'));
    mockCandidateRepo.updateIsVerify.mockResolvedValue(true);

    await expect(
      useCase.execute('CAN_01', {} as any)
    ).rejects.toThrow('Database connection error');
  });

  // TC_WB_04: Async Exception - updateIsVerify throws Error
  it('TC_WB_04: Nên ném lỗi khi candidateRepo.updateIsVerify bị reject', async () => {
    const mockResult = { getDetail: jest.fn() };
    mockCandidateRepo.create.mockResolvedValue(mockResult);
    mockCandidateRepo.updateIsVerify.mockRejectedValue(new Error('Update status failed'));

    await expect(
      useCase.execute('CAN_01', {} as any)
    ).rejects.toThrow('Update status failed');
  });
});
```
