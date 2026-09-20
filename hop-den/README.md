# BÁO CÁO TỔNG HỢP BÀI TẬP KIỂM THỬ HỘP ĐEN
## HỌC PHẦN: KIỂM THỬ VÀ ĐẢM BẢO CHẤT LƯỢNG PHẦN MỀM (CSE462)

---

### 📌 THÔNG TIN ĐỀ TÀI & NHÓM THỰC HIỆN
- **Đề tài:** **HỆ THỐNG QUẢN LÝ TUYỂN DỤNG – TRỢ LÝ TUYỂN DỤNG & SÀNG LỌC HỒ SƠ TỰ ĐỘNG**
- **Người hướng dẫn:** **TS. Nguyễn Thị Phương Dung**
- **Nhóm sinh viên thực hiện:** **Nhóm 09**
- **Thời gian thực hiện:** Học kỳ 7

---

### 👥 BẢNG PHÂN CHIA NHIỆM VỤ THÀNH VIÊN NHÓM 09

| STT | Họ và tên sinh viên | Mã sinh viên | Vai trò & Use Case đảm nhận | Nhiệm vụ cụ thể | Trạng thái |
| :---: | :--- | :---: | :--- | :--- | :---: |
| 1 | **Phùng Văn Duy** | **2351170589** | **Thành viên chính**<br>- `UC_06`: **Thu Thập Hồ Sơ**<br>- `UC_07`: **Quản lý và Phân tích Hồ sơ Ứng viên**<br>- `UC_08`: **Kiểm chứng và Xác thực Hồ sơ** | - Thiết kế bộ ca kiểm thử hộp đen cho `UC_06`, `UC_07`, `UC_08`.<br>- Lập bảng phân vùng tương đương, phân tích giá trị biên, bảng quyết định, sơ đồ chuyển trạng thái.<br>- Xuất 114 ca kiểm thử chi tiết dạng Markdown và CSV. | **Hoàn thành (100%)** |
| 2 | **Lê Quý Dương** | **2351170587** | **Thành viên nhóm** | Đảm nhận các Use Case khác của nhóm 09 & phối hợp kiểm thử tích hợp. | Đang thực hiện |
| 3 | **Phạm Ngọc Bách** | **2351170576** | **Thành viên nhóm** | Đảm nhận các Use Case khác của nhóm 09 & phối hợp kiểm thử tích hợp. | Đang thực hiện |
| 4 | **Phạm Văn Hưng** | **2351170598** | **Thành viên nhóm** | Đảm nhận các Use Case khác của nhóm 09 & phối hợp kiểm thử tích hợp. | Đang thực hiện |

---

### 📑 KHUNG CẤU TRÚC TIÊU ĐỀ TRONG BÁO CÁO HỘP ĐEN

#### 1. Khung cấu trúc tổng quan (`hop-den/README.md`):
- `📌 THÔNG TIN ĐỀ TÀI & NHÓM THỰC HIỆN`
- `👥 BẢNG PHÂN CHIA NHIỆM VỤ THÀNH VIÊN NHÓM 09`
- `📑 KHUNG CẤU TRÚC TIÊU ĐỀ TRONG BÁO CÁO HỘP ĐEN`
- `📂 DANH MỤC HỒ SƠ KIỂM THỬ HỘP ĐEN (MARKDOWN & CSV)`
- `🔬 4 KỸ THUẬT KIỂM THỬ HỘP ĐEN CỐT LÕI ÁP DỤNG`
  - `1. Phương pháp Phân vùng tương đương (Equivalence Partitioning)`
  - `2. Phương pháp Phân tích giá trị biên (Boundary Value Analysis)`
  - `3. Phương pháp Bảng quyết định (Decision Table Testing)`
  - `4. Phương pháp Kiểm thử chuyển trạng thái (State Transition Testing)`
- `📊 THỐNG KÊ TỔNG HỢP VÀ PHÂN BỔ ĐỘ BAO PHỦ`
- `🛠️ HƯỚNG DẪN MỞ VÀ TRA CỨU DỮ LIỆU TRÊN EXCEL`

#### 2. Khung cấu trúc chuẩn mực 8 phần của từng tài liệu Use Case:
- **`PHẦN 1: THÔNG TIN CHUNG VỀ BÀI TẬP VÀ USE CASE`**
- **`PHẦN 2: PHÂN TÍCH CƠ SỞ KIỂM THỬ`**
  - *1. Phân rã luồng sự kiện nghiệp vụ (Luồng chính, Luồng thay thế, Luồng ngoại lệ)*
  - *2. Xác định các biến đầu vào và miền giá trị*
- **`PHẦN 3: ÁP DỤNG PHƯƠNG PHÁP PHÂN VÙNG TƯƠNG ĐƯƠNG`**
  - *1. Phân tích miền tương đương hợp lệ và không hợp lệ*
  - *2. Bảng định nghĩa các phân vùng tương đương (Mã EP)*
  - *3. Thiết kế ca kiểm thử theo lớp tương đương yếu và lớp tương đương mạnh*
- **`PHẦN 4: ÁP DỤNG PHƯƠNG PHÁP PHÂN TÍCH GIÁ TRỊ BIÊN`**
  - *1. Nguyên lý và trục số xác định điểm biên*
  - *2. Phân tích giá trị biên 2 điểm, 3 điểm và biên mở rộng (Robustness)*
- **`PHẦN 5: ÁP DỤNG PHƯƠNG PHÁP BẢNG QUYẾT ĐỊNH`**
  - *1. Danh sách Điều kiện (Conditions) và Hành động (Actions)*
  - *2. Bảng quyết định rút gọn (Reduced Decision Table)*
- **`PHẦN 6: ÁP DỤNG PHƯƠNG PHÁP KIỂM THỬ CHUYỂN TRẠNG THÁI`**
  - *1. Danh sách các trạng thái hệ thống*
  - *2. Sơ đồ chuyển trạng thái Mermaid (State Diagram)*
  - *3. Bảng chuyển trạng thái (State Transition Table)*
- **`PHẦN 7: BẢNG TỔNG HỢP CÁC CA KIỂM THỬ HỘP ĐEN`**
- **`PHẦN 8: ĐÁNH GIÁ ĐỘ BAO PHỦ VÀ KẾT LUẬN`**

---

### 📂 DANH MỤC HỒ SƠ KIỂM THỬ HỘP ĐEN

Thư mục này bao gồm toàn bộ tài liệu đặc tả kiểm thử định dạng Markdown (`.md`) và bảng dữ liệu kiểm thử định dạng CSV chuẩn (`.csv`, mã hóa **UTF-8 with BOM** mở trực tiếp không lỗi font trên Excel) cho 3 Use Case do sinh viên **Phùng Văn Duy** đảm nhận:

| Mã Use Case | Tên Use Case | Tài liệu đặc tả hộp đen (.md) | Bảng ca kiểm thử (.csv) | Số lượng ca kiểm thử |
| :---: | :--- | :--- | :--- | :---: |
| **UC_06** | **Thu Thập Hồ Sơ** | [KiemThuHopDen_UC06_ThuThapHoSo.md](file:///Users/macbook/Documents/hk7/cse462-testing/cse462-testing/hop-den/KiemThuHopDen_UC06_ThuThapHoSo.md) | [KiemThuHopDen_UC06_ThuThapHoSo.csv](file:///Users/macbook/Documents/hk7/cse462-testing/cse462-testing/hop-den/KiemThuHopDen_UC06_ThuThapHoSo.csv) | **38 Test Cases** |
| **UC_07** | **Quản lý và Phân tích Hồ sơ** | [KiemThuHopDen_UC07_QuanLyVaPhanTichHoSo.md](file:///Users/macbook/Documents/hk7/cse462-testing/cse462-testing/hop-den/KiemThuHopDen_UC07_QuanLyVaPhanTichHoSo.md) | [KiemThuHopDen_UC07_QuanLyVaPhanTichHoSo.csv](file:///Users/macbook/Documents/hk7/cse462-testing/cse462-testing/hop-den/KiemThuHopDen_UC07_QuanLyVaPhanTichHoSo.csv) | **38 Test Cases** |
| **UC_08** | **Kiểm chứng và Xác thực Hồ sơ** | [KiemThuHopDen_UC08_KiemChungVaXacThucHoSo.md](file:///Users/macbook/Documents/hk7/cse462-testing/cse462-testing/hop-den/KiemThuHopDen_UC08_KiemChungVaXacThucHoSo.md) | [KiemThuHopDen_UC08_KiemChungVaXacThucHoSo.csv](file:///Users/macbook/Documents/hk7/cse462-testing/cse462-testing/hop-den/KiemThuHopDen_UC08_KiemChungVaXacThucHoSo.csv) | **38 Test Cases** |
| **TỔNG CỘNG**| **3 Use Case Nghiệp vụ** | **3 Báo cáo học thuật chi tiết** | **3 File dữ liệu Excel chuẩn** | **114 Test Cases** |

---

### 🔬 4 KỸ THUẬT KIỂM THỬ HỘP ĐEN CỐT LÕI ÁP DỤNG

Theo đúng giáo trình giảng dạy học phần **CSE462** và chuẩn quốc tế **ISTQB CTFL 2018 v3.1**, các ca kiểm thử trong bài tập đều được thiết kế chặt chẽ dựa trên 4 kỹ thuật kiểm thử hộp đen chuẩn tắc:

1. **Phương pháp Phân vùng tương đương (Equivalence Partitioning):**
   - Phân tích và chia không gian đầu vào thành các lớp tương đương hợp lệ (Valid Partitions) và không hợp lệ (Invalid Partitions).
   - Thiết kế các bộ kiểm thử theo cả hai cấp độ: **Lớp tương đương yếu (Weak Equivalence)** và **Lớp tương đương mạnh (Strong Equivalence)**.
   - Ứng dụng cho định dạng tệp tin, tiêu chí lọc kỹ năng, số năm kinh nghiệm, thông tin định danh và phản hồi mạng.
2. **Phương pháp Phân tích giá trị biên (Boundary Value Analysis):**
   - Rà soát các điểm biên định lượng 2 điểm và 3 điểm biên (Biên dưới, Cận biên, Ngay tại biên, Vượt biên tối thiểu, Vượt biên cực lớn - Robust Boundary).
   - Ứng dụng cho: Ngưỡng dung lượng tệp tin (10 MB = 10,240 KB), Thời gian chờ xử lý AI (10 giây / 30 giây), Độ lệch thời gian làm việc (6 tháng), Điểm phù hợp (0% và 100%), Kích thước phân trang (10 bản ghi).
3. **Phương pháp Bảng quyết định (Decision Table Testing):**
   - Mô hình hóa các quy tắc logic nghiệp vụ kết hợp giữa nhiều điều kiện (Conditions) và hành động tương ứng (Actions).
   - Xây dựng bảng quyết định rút gọn để loại trừ các tổ hợp không thể xảy ra hoặc điều kiện không phụ thuộc ("Don't care").
   - Ứng dụng cho việc phân luồng xử lý quét trang web vs upload CV, kiểm soát ngoại lệ thiếu JD so sánh, và kiểm tra điều kiện kích hoạt tiến trình ngầm.
4. **Phương pháp Kiểm thử chuyển trạng thái (State Transition Testing):**
   - Xây dựng sơ đồ máy trạng thái hữu hạn (FSM) trực quan dạng Mermaid.
   - Lập bảng chuyển trạng thái để kiểm soát các chuyển đổi hợp lệ và phát hiện các chuyển đổi bất thường / trái phép.
   - Ứng dụng cho vòng đời trạng thái ứng viên (Mới $ightarrow$ Đã xem $ightarrow$ Phù hợp $ightarrow$ Phỏng vấn $ightarrow$ Trúng tuyển / Từ chối) và vòng đời tiến trình kiểm chứng dấu vết số.

---

### 📊 THỐNG KÊ TỔNG HỢP VÀ PHÂN BỔ ĐỘ BAO PHỦ

```
Phân bổ 114 Test Cases theo Kỹ thuật Hộp đen:
┌────────────────────────────────────────────────────────┬────────┬──────────┐
│ Kỹ thuật kiểm thử hộp đen áp dụng                      │ Số TC  │ Tỷ lệ %  │
├────────────────────────────────────────────────────────┼────────┼──────────┤
│ 1. Phân vùng tương đương (Equivalence Partitioning)    │ 40     │ 35.1%    │
│ 2. Phân tích giá trị biên (Boundary Value Analysis)    │ 23     │ 20.2%    │
│ 3. Bảng quyết định (Decision Table Testing)            │ 18     │ 15.8%    │
│ 4. Kiểm thử chuyển trạng thái (State Transition)       │ 17     │ 14.9%    │
│ 5. Kiểm thử hộp đen mở rộng (Bảo mật, Đoán lỗi)        │ 16     │ 14.0%    │
├────────────────────────────────────────────────────────┼────────┼──────────┤
│ TỔNG CỘNG:                                             │ 114    │ 100%     │
└────────────────────────────────────────────────────────┴────────┴──────────┘
```

---

### 🛠️ HƯỚNG DẪN MỞ VÀ TRA CỨU DỮ LIỆU TRÊN EXCEL
1. **Xem trực tiếp trên GitHub / IDE:**
   - Mở các tệp Markdown `.md` tương ứng để xem đầy đủ lý thuyết, phân tích cơ sở, sơ đồ Mermaid và bảng đặc tả chi tiết.
2. **Mở trên Microsoft Excel:**
   - Nhấp đúp chuột trực tiếp vào các tệp `.csv` trong thư mục `hop-den/`.
   - File đã được cấu hình mã hóa sẵn **UTF-8 with BOM (`utf-8-sig`)**, đảm bảo hiển thị 100% tiếng Việt có dấu chuẩn xác mà không cần qua bước import dữ liệu.
