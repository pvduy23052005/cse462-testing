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
| :---: | :--- | :--- :--- | :--- | :--- | :--- :--- |
| 1 | **Phùng Văn Duy** | **2351170589** | **Thành viên chính**<br>- `USE-CASE 06`: **Thu Thập Hồ Sơ**<br>- `USE-CASE 07`: **Quản lý và Phân tích Hồ sơ Ứng viên**<br>- `USE-CASE 08`: **Kiểm chứng và Xác thực Hồ sơ** | - Phân tích chi tiết Dữ liệu đầu vào và Quy tắc ràng buộc cho 3 Use Case.<br>- Phân tích từng trường theo Phân vùng tương đương và Phân tích giá trị biên.<br>- Xây dựng Bảng quyết định, quan hệ ràng buộc chéo và Sơ đồ trạng thái.<br>- Thiết kế chi tiết **114 ca kiểm thử** định dạng Markdown và CSV. | **Hoàn thành (100%)** |
| 2 | **Lê Quý Dương** | **2351170587** | **Thành viên nhóm** | Đảm nhận các Use Case khác của Nhóm 09 & phối hợp kiểm thử tích hợp. | Đang thực hiện |
| 3 | **Phạm Ngọc Bách** | **2351170576** | **Thành viên nhóm** | Đảm nhận các Use Case khác của Nhóm 09 & phối hợp kiểm thử tích hợp. | Đang thực hiện |
| 4 | **Phạm Văn Hưng** | **2351170598** | **Thành viên nhóm** | Đảm nhận các Use Case khác của Nhóm 09 & phối hợp kiểm thử tích hợp. | Đang thực hiện |

---

### 📑 MỤC LỤC TỔNG THỂ BÁO CÁO

- **THÔNG TIN CHUNG & BẢNG PHÂN CHIA NHIỆM VỤ**
- **USE-CASE 06: THU THẬP HỒ SƠ**
  - `THÔNG TIN CHUNG VỀ BÀI TẬP VÀ USE CASE 06`
  - `1. PHÂN TÍCH LUỒNG SỰ KIỆN`
    - *1.1 Luồng chính*
    - *1.2 Luồng rẽ nhánh và thay thế*
    - *1.3 Luồng ngoại lệ*
  - `2. BẢNG TỔNG HỢP DANH SÁCH DỮ LIỆU ĐẦU VÀO`
  - `3. PHÂN TÍCH RÀNG BUỘC TỪNG TRƯỜNG DỮ LIỆU`
  - `4. BẢNG QUYẾT ĐỊNH CHO TỔ HỢP LOGIC NGHIỆP VỤ`
    - *4.1 Phân tích quan hệ ràng buộc chéo và tiền điều kiện*
    - *4.2 Bảng quyết định logic nghiệp vụ*
  - `5. BẢNG CA KIỂM THỬ CHI TIẾT TỔNG HỢP (TC_UC06_001 - TC_UC06_038)`
- **USE-CASE 07: QUẢN LÝ VÀ PHÂN TÍCH HỒ SƠ ỨNG VIÊN**
  - `THÔNG TIN CHUNG VỀ BÀI TẬP VÀ USE CASE 07`
  - `1. PHÂN TÍCH LUỒNG SỰ KIỆN`
    - *1.1 Luồng chính*
    - *1.2 Luồng rẽ nhánh và thay thế*
    - *1.3 Luồng ngoại lệ*
  - `2. BẢNG TỔNG HỢP DANH SÁCH DỮ LIỆU ĐẦU VÀO`
  - `3. PHÂN TÍCH RÀNG BUỘC TỪNG TRƯỜNG DỮ LIỆU`
  - `4. BẢNG QUYẾT ĐỊNH CHO TỔ HỢP LOGIC NGHIỆP VỤ`
    - *4.1 Phân tích quan hệ ràng buộc chéo và tiền điều kiện*
    - *4.2 Bảng quyết định logic nghiệp vụ*
  - `5. BẢNG CA KIỂM THỬ CHI TIẾT TỔNG HỢP (TC_UC07_001 - TC_UC07_038)`
- **USE-CASE 08: KIỂM CHỨNG VÀ XÁC THỰC HỒ SƠ**
  - `THÔNG TIN CHUNG VỀ BÀI TẬP VÀ USE CASE 08`
  - `1. PHÂN TÍCH LUỒNG SỰ KIỆN`
    - *1.1 Luồng chính*
    - *1.2 Luồng rẽ nhánh và thay thế*
    - *1.3 Luồng ngoại lệ*
  - `2. BẢNG TỔNG HỢP DANH SÁCH DỮ LIỆU ĐẦU VÀO`
  - `3. PHÂN TÍCH RÀNG BUỘC TỪNG TRƯỜNG DỮ LIỆU`
  - `4. BẢNG QUYẾT ĐỊNH CHO TỔ HỢP LOGIC NGHIỆP VỤ`
    - *4.1 Phân tích quan hệ ràng buộc chéo và tiền điều kiện*
    - *4.2 Bảng quyết định logic nghiệp vụ*
  - `5. BẢNG CA KIỂM THỬ CHI TIẾT TỔNG HỢP (TC_UC08_001 - TC_UC08_038)`
- **TỔNG KẾT TOÀN DIỆN VÀ DANH MỤC TỆP DỮ LIỆU (114 CA KIỂM THỬ)**
  - `1. Ma trận tổng hợp phân bổ kỹ thuật hộp đen cho cả 3 Use Case`
  - `2. Danh mục tệp dữ liệu kiểm thử CSV chuẩn Excel đi kèm`
  - `3. Danh mục tệp báo cáo chuẩn Word (.docx) đi kèm`
  - `4. Đánh giá chất lượng và kết luận chung`

---


# USE-CASE 06: THU THẬP HỒ SƠ

---

## THÔNG TIN CHUNG VỀ BÀI TẬP VÀ USE CASE 06

- **Học phần:** Kiểm thử và Đảm bảo chất lượng phần mềm (CSE462)
- **Đề tài:** Hệ thống Quản lý Tuyển dụng – Trợ lý Tuyển dụng & Sàng lọc Hồ sơ Tự động
- **Giảng viên hướng dẫn:** TS. Nguyễn Thị Phương Dung | **Nhóm:** 09
- **Sinh viên thực hiện:** Phùng Văn Duy (Mã SV: **2351170589**)
- **Mã Use Case:** `UC_06` | **Tên Use Case:** Thu Thập Hồ Sơ | **Ngày tạo:** 30/01/2026
- **Tác nhân chính:** Chuyên viên tuyển dụng
- **Kích hoạt:** Nhấn "Quét" trên trang tuyển dụng (LinkedIn, TopCV, VietnamWorks) hoặc chọn "Upload CV" trên Extension.
- **Tiền điều kiện:** Đã đăng nhập Extension (Token JWT hợp lệ); có kết nối Internet; mở đúng trang profile ứng viên hoặc có sẵn tệp CV.
- **Hậu điều kiện:** Hồ sơ được chuẩn hóa và lưu vào CSDL; Dashboard tăng số lượng ứng viên $+1$.
- **Mục tiêu:** Thu thập hồ sơ ứng viên qua 2 nguồn: Quét tự động DOM trang web tuyển dụng hoặc Tải lên tệp CV (PDF/Word/Ảnh qua OCR & LLM).
- **Tiêu chuẩn áp dụng:** Giáo trình CSE462, ISTQB CTFL v3.1 (Black-box Techniques), ISO/IEC/IEEE 29119-4.

---

## 1. PHÂN TÍCH LUỒNG SỰ KIỆN

### 1.1. Luồng chính
1. Chuyên viên đăng nhập Extension, mở trang profile ứng viên trên LinkedIn/TopCV/VietnamWorks.
2. Nhấn nút "Quét" trên trang web.
3. Extension bóc tách cây DOM, trích xuất dữ liệu (Họ tên, Chức danh, Kinh nghiệm, Kỹ năng) và hiển thị Form xem trước ($T \le 10\text{s}$).
4. Chuyên viên rà soát thông tin trích xuất và nhấn "Lưu hồ sơ".
5. Hệ thống lưu thành công vào CSDL, hiển thị thông báo "Lưu hồ sơ thành công" và cập nhật Dashboard $+1$.

### 1.2. Luồng rẽ nhánh và thay thế
- **A1 (Tải lên tệp CV):** Mở tab "Upload CV" $\rightarrow$ Kéo thả/chọn file (.pdf/.docx/.png $\le 10\text{MB}$) $\rightarrow$ OCR/LLM trích xuất dữ liệu $\rightarrow$ Hiện Form xem trước $\rightarrow$ Nhấn "Lưu hồ sơ" $\rightarrow$ Lưu CSDL.
- **A2 (Chỉnh sửa Form xem trước):** Chuyên viên sửa Họ tên/SĐT/Email trên Form xem trước $\rightarrow$ Nhấn "Lưu hồ sơ" $\rightarrow$ CSDL lưu dữ liệu đã chỉnh sửa.
- **A3 (Hủy bỏ):** Nhấn "Hủy bỏ" hoặc biểu tượng (X) trên Form xem trước $\rightarrow$ Đóng form, không lưu dữ liệu vào CSDL.

### 1.3. Luồng ngoại lệ
- **EX_01 (Tệp sai định dạng / quá 10MB):** Chặn tại Client, báo lỗi: *"Định dạng file không hỗ trợ hoặc dung lượng quá lớn"*.
- **EX_02 (Timeout quá 10s):** Quét DOM hoặc AI quá $10.0\text{s} \rightarrow$ Ngắt kết nối, báo lỗi: *"Kết nối đến máy chủ AI bị gián đoạn"*, mở Form trống cho nhập tay.
- **EX_03 (Trang không hỗ trợ):** Quét tại trang ngoài danh mục $\rightarrow$ Báo lỗi: *"Extension chưa hỗ trợ cấu trúc trang web này. Vui lòng nhập tay hoặc Upload file"*.
- **EX_04 (Mất kết nối mạng):** Mất mạng khi gửi lưu $\rightarrow$ Báo lỗi mạng, giữ nguyên dữ liệu trên Form xem trước để thử lại.
- **EX_05 (Trùng lặp hồ sơ):** Email/SĐT đã có trong CSDL $\rightarrow$ Cảnh báo: *"Hồ sơ ứng viên đã tồn tại trong hệ thống. Bạn có muốn cập nhật đè không?"*.

---

## 2. BẢNG TỔNG HỢP DANH SÁCH DỮ LIỆU ĐẦU VÀO

| Tên trường | Kiểu dữ liệu | Bắt buộc | Ràng buộc kỹ thuật & Nghiệp vụ | Giá trị mặc định |
| :--- | :---: | :---: | :--- | :--- |
| **Phương thức thu thập** | Enum | Bắt buộc | Chọn 1 trong 2: `Quét tự động DOM` hoặc `Upload file CV` | `Quét tự động DOM` |
| **URL trang web quét** | URL Text | Bắt buộc (khi Quét DOM) | Domain: `linkedin.com/in/*`, `topcv.vn/*`, `vietnamworks.com/*`; $10 \le L \le 2000$ | URL tab hiện tại |
| **Cấu trúc cây DOM** | Object DOM | Bắt buộc (khi Quét DOM) | Chứa thẻ profile, kinh nghiệm, học vấn hợp lệ của trang nguồn | Không có |
| **Tệp tin CV tải lên** | Binary Blob | Bắt buộc (khi Upload) | Đuôi: `.pdf, .docx, .doc, .png, .jpg`; Dung lượng: $0 < S \le 10\text{MB}$ | Không có |
| **Họ và tên ứng viên** | Text | Bắt buộc | $2 \le L \le 100$; chỉ chữ cái và khoảng trắng; cấm số; khử mã độc XSS/HTML | Trích xuất / Rỗng |
| **Vị trí / Chức danh** | Text | Tùy chọn | $0 \le L \le 150$; tự động khử thẻ HTML | Trích xuất / Rỗng |
| **Số năm kinh nghiệm** | Float | Tùy chọn | $0.0 \le \text{Exp} \le 50.0$ năm; không âm | Trích xuất / `0.0` |
| **Địa chỉ Email** | Email Text | Bắt buộc (nếu thiếu SĐT) | Chuẩn RFC 5322 regex; $6 \le L \le 100$; kiểm tra trùng CSDL | Trích xuất / Rỗng |
| **Số điện thoại** | Phone Text | Bắt buộc (nếu thiếu Email) | Đúng 10 chữ số (đầu số VN: 03, 05, 07, 08, 09); kiểm tra trùng CSDL | Trích xuất / Rỗng |
| **Danh sách kỹ năng** | Array Tags | Tùy chọn | Tối đa 50 kỹ năng; mỗi kỹ năng $\le 50$ ký tự; khử mã độc HTML | Trích xuất / Rỗng |
| **Token phiên làm việc** | JWT Text | Bắt buộc | Token JWT còn hạn trong bộ nhớ Extension Storage | Storage trình duyệt |

---

## 3. PHÂN TÍCH RÀNG BUỘC TỪNG TRƯỜNG DỮ LIỆU

| Tên trường dữ liệu | Ràng buộc tóm tắt | Phân vùng hợp lệ & Giá trị mẫu | Phân vùng không hợp lệ & Giá trị mẫu | Giá trị biên cần test (BVA) |
| :--- | :--- | :--- | :--- | :--- |
| **Phương thức thu thập** | Enum, bắt buộc chọn 1 trong 2 | - `Quét tự động DOM`<br>- `Upload file CV` | - Để trống (`null`)<br>- Giá trị lạ: `API_IMPORT` | Không áp dụng (Enum cố định) |
| **URL trang web quét** | URL domain hỗ trợ, $10 \le L \le 2000$ ký tự | - `https://www.linkedin.com/in/nguyenvana`<br>- `https://topcv.vn/profile/tranvanb` | - Domain lạ: `https://facebook.com/u1`<br>- Sai cú pháp: `htt://invalid`<br>- Rỗng: `""`<br>- Quá 2000 ký tự | - $L = 9$: Lỗi min-1<br>- $L = 10$: Hợp lệ min<br>- $L = 11$: Hợp lệ<br>- $L = 1999$: Hợp lệ<br>- $L = 2000$: Hợp lệ max<br>- $L = 2001$: Lỗi max+1 |
| **Tệp tin CV tải lên** | Đuôi `.pdf/.docx/.png/.jpg`, dung lượng $0 < S \le 10\text{MB}$ | - PDF: `cv_dev.pdf` (2.5MB)<br>- Word: `cv_be.docx` (1.2MB)<br>- Ảnh: `cv.png` (850KB) | - File cấm: `trojan.exe`, `cv.zip`, `data.xlsx`<br>- File rỗng: `empty.pdf` (0B)<br>- Quá 10MB: `heavy.pdf` (15MB)<br>- Đuôi kép: `cv.pdf.exe` | - $S = 0\text{B}$: Lỗi rỗng<br>- $S = 1\text{B}$: Hợp lệ min<br>- $S = 2\text{B}$: Hợp lệ<br>- $S = 10,239\text{KB}$: Hợp lệ<br>- $S = 10,240\text{KB}$: Hợp lệ max (10MB)<br>- $S = 10,241\text{KB}$: Lỗi max+1 (EX_01) |
| **Họ và tên ứng viên** | Chuỗi, bắt buộc, $2 \le L \le 100$, cấm số, cấm XSS | - `"Nguyễn Văn An"`<br>- `"Lê Thị Mai Loan"`<br>- `"Johnathan Edward Doe"` | - Để trống: `""`<br>- Chứa số: `"Van 123"`<br>- Ký tự lạ: `"Tran @#$ Nam"`<br>- XSS: `<script>alert(1)</script>`<br>- Quá ngắn: < 2 kt; Quá dài: > 100 kt | - $L = 1$: `"A"` (Lỗi min-1)<br>- $L = 2$: `"An"` (Hợp lệ min)<br>- $L = 3$: `"Hoa"` (Hợp lệ)<br>- $L = 99$: Hợp lệ<br>- $L = 100$: Hợp lệ max<br>- $L = 101$: Lỗi max+1 |
| **Vị trí / Chức danh** | Chuỗi, tùy chọn, $0 \le L \le 150$, sanitize HTML | - `"Senior Fullstack Developer"`<br>- Để trống: `""` | - Quá 150 ký tự<br>- Chứa script/iframe độc hại | - $L = 149$: Hợp lệ<br>- $L = 150$: Hợp lệ max<br>- $L = 151$: Lỗi quá dài |
| **Số năm kinh nghiệm** | Số thực, không âm: $0.0 \le \text{Exp} \le 50.0$ năm | - `0.0` (Fresher)<br>- `2.5` năm<br>- `10.0` năm | - Số âm: `-1.0`<br>- Quá lớn: `60.0`<br>- Nhập chữ: `"ba năm"` | - $\text{Exp} = -0.1$: Lỗi min-1<br>- $\text{Exp} = 0.0$: Hợp lệ min<br>- $\text{Exp} = 0.1$: Hợp lệ<br>- $\text{Exp} = 49.9$: Hợp lệ<br>- $\text{Exp} = 50.0$: Hợp lệ max<br>- $\text{Exp} = 50.1$: Lỗi max+1 |
| **Địa chỉ Email** | RFC 5322 regex, $6 \le L \le 100$, kiểm tra trùng CSDL | - `nguyen.van.an@gmail.com`<br>- `tuyendung@fpt.com.vn` | - Thiếu `@`: `nguyenvana.gmail.com`<br>- Thiếu domain: `an@.com`<br>- Dấu cách: `an @gmail.com`<br>- SQLi: `' OR 1=1--` | - $L = 5$: `a@b.c` (Lỗi min-1)<br>- $L = 6$: `a@b.co` (Hợp lệ min)<br>- $L = 100$: Hợp lệ max<br>- $L = 101$: Lỗi max+1 |
| **Số điện thoại** | 10 chữ số, đầu số VN (03, 05, 07, 08, 09), kiểm tra trùng | - `0912345678`<br>- `0389998888`<br>- `0701234567` | - 9 số: `091234567`<br>- 11 số: `09123456789`<br>- Chứa chữ: `09123abcde`<br>- Đầu số lạ: `0123456789` | - 9 số: Lỗi thiếu số<br>- 10 số: Hợp lệ chuẩn<br>- 11 số: Lỗi thừa số |
| **Danh sách kỹ năng** | Mảng thẻ, tối đa 50 kỹ năng, mỗi kỹ năng $\le 50$ ký tự | - `["ReactJS", "Node.js", "Docker"]`<br>- Mảng rỗng: `[]` | - Kỹ năng chứa script: `<script>`<br>- Quá 50 kỹ năng | - 0 kỹ năng: Hợp lệ min<br>- 1 kỹ năng: Hợp lệ<br>- 50 kỹ năng: Hợp lệ max<br>- 51 kỹ năng: Lỗi max+1 |
| **Thời gian xử lý** | Thời gian phản hồi DOM/AI: $T \le 10.0\text{s}$ | - $0.1\text{s} \le T \le 10.0\text{s}$ (Thành công) | - $T > 10.0\text{s}$ (Timeout EX_02) | - $T = 9.9\text{s}$: Hợp lệ<br>- $T = 10.0\text{s}$: Hợp lệ max<br>- $T = 10.1\text{s}$: Kích hoạt EX_02 |

---

## 4. BẢNG QUYẾT ĐỊNH CHO TỔ HỢP LOGIC NGHIỆP VỤ

### 4.1. Phân tích quan hệ ràng buộc chéo và tiền điều kiện
- **Ràng buộc theo phương thức:** Khi chọn `Quét DOM` $\rightarrow$ Bắt buộc có URL hợp lệ; khi chọn `Upload CV` $\rightarrow$ Bắt buộc có tệp CV hợp lệ (.pdf/.docx/.png $\le 10\text{MB}$).
- **Định danh tối thiểu:** Bắt buộc có `Họ tên` VÀ (`Email` $\ne \emptyset$ HOẶC `SĐT` $\ne \emptyset$). Nếu vi phạm $\rightarrow$ Khóa nút "Lưu hồ sơ", viền đỏ trường thiếu.
- **Chống spam:** Nút "Lưu hồ sơ" tự động chuyển trạng thái `disabled` ngay sau lần click đầu tiên để chống gửi request trùng lặp.

### 4.2. Bảng quyết định logic nghiệp vụ

| Mã điều kiện / Hành động | Thành phần kiểm tra | $R_1$ | $R_2$ | $R_3$ | $R_4$ | $R_5$ | $R_6$ | $R_7$ | $R_8$ |
| :--- | :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **C1** | Phương thức thu thập được chọn | DOM | DOM | DOM | Upload | Upload | Upload | Upload | DOM |
| **C2** | Nguồn trang web thuộc domain hỗ trợ | Có | Có | Không | - | - | - | - | Có |
| **C3** | Định dạng tệp tin hợp lệ (.pdf/.docx/.png) | - | - | - | Có | Có | Không | Có | - |
| **C4** | Dung lượng tệp tin thỏa mãn $\le 10\text{MB}$ | - | - | - | Có | Có | - | Không | - |
| **C5** | Thời gian xử lý trích xuất $T \le 10.0\text{s}$ | Có | Không | - | Có | Không | - | - | Có |
| **C6** | Dữ liệu định danh tối thiểu: Tên + (Email / SĐT) | Có | - | - | Có | - | - | - | Không |
| **A1** | Trích xuất thành công và hiển thị Form xem trước | **X** | - | - | **X** | - | - | - | **X** |
| **A2** | Lưu hồ sơ thành công vào CSDL | **X** | - | - | **X** | - | - | - | - |
| **A3** | Báo lỗi ngoại lệ EX_01 (Tệp sai định dạng/quá 10MB) | - | - | - | - | - | **X** | **X** | - |
| **A4** | Báo lỗi ngoại lệ EX_02 (Timeout quá 10s, mở Form tay) | - | **X** | - | - | **X** | - | - | - |
| **A5** | Báo lỗi ngoại lệ EX_03 (Trang web không hỗ trợ) | - | - | **X** | - | - | - | - | - |
| **A6** | Khóa nút Lưu, yêu cầu bổ sung thông tin định danh | - | - | - | - | - | - | - | **X** |

---

## 5. BẢNG CA KIỂM THỬ CHI TIẾT TỔNG HỢP

| Test Case ID | Tên ca kiểm thử / Mục đích test | Phân loại kiểm thử | Tiền điều kiện | Các bước thực hiện | Dữ liệu kiểm thử cụ thể | Kết quả mong đợi | Mức độ ưu tiên |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :---: |
| `TC_UC06_001` | Quét thành công hồ sơ trên LinkedIn | Use Case Flow | Login Extension; mở profile LinkedIn | 1. Nhấn nút "Quét"<br>2. Kiểm tra Form xem trước<br>3. Nhấn "Lưu hồ sơ" | URL: `https://www.linkedin.com/in/nguyenvana` | Trích xuất đúng thông tin; Form điền tự động; Lưu CSDL trạng thái "Mới" | High |
| `TC_UC06_002` | Quét thành công hồ sơ trên TopCV | Use Case Flow | Login Extension; mở profile TopCV | 1. Nhấn nút "Quét"<br>2. Kiểm tra Form xem trước<br>3. Nhấn "Lưu hồ sơ" | URL: `https://topcv.vn/profile/tran-thi-b` | Điền đúng thông tin; Lưu CSDL thành công; Dashboard tăng $+1$ | High |
| `TC_UC06_003` | Quét thành công hồ sơ trên VietnamWorks | Use Case Flow | Login Extension; mở profile VietnamWorks | 1. Nhấn nút "Quét"<br>2. Nhấn "Lưu hồ sơ" | URL: `https://vietnamworks.com/ung-vien/le-van-c` | Trích xuất chính xác; Lưu CSDL thành công | High |
| `TC_UC06_004` | Quét hồ sơ bị khuyết số năm kinh nghiệm | Field Validation | Mở profile LinkedIn khuyết kinh nghiệm | 1. Nhấn "Quét"<br>2. Nhập bổ sung số năm kinh nghiệm<br>3. Nhấn "Lưu hồ sơ" | Họ tên: `"Trần Nam"`, Exp: Nhập tay `3.0` | Form điền sẵn phần có dữ liệu; ô thiếu cho nhập tay; Lưu CSDL thành công | Medium |
| `TC_UC06_005` | Chỉnh sửa thông tin trên Form trước khi lưu | Business Logic | Form xem trước đang mở | 1. Sửa lại Họ tên và SĐT<br>2. Nhấn "Lưu hồ sơ" | Tên mới: `"Nguyễn Văn An Khang"`, SĐT: `0988776655` | CSDL lưu chính xác dữ liệu mới vừa chỉnh sửa | Medium |
| `TC_UC06_006` | Hủy bỏ lưu hồ sơ tại Form xem trước | Use Case Flow | Form xem trước đang mở | 1. Nhấn nút "Hủy bỏ" hoặc (X) | Thao tác nhấn Hủy | Đóng form; không lưu bản ghi rác vào CSDL | Medium |
| `TC_UC06_007` | Nhấn "Lưu hồ sơ" liên tiếp chống spam click | Business Logic | Form xem trước đủ dữ liệu | 1. Nhấn liên tiếp 5 lần nút "Lưu hồ sơ" trong 1s | Thao tác click liên tục 5 lần | Nút Lưu chuyển `disabled` ngay lần đầu; chỉ gửi 1 request; lưu đúng 1 bản ghi | High |
| `TC_UC06_008` | Upload tệp CV định dạng PDF hợp lệ | Field Validation | Tab Upload CV | 1. Kéo thả file PDF vào Drop Zone<br>2. Chờ OCR xử lý | File: `CV_Fullstack.pdf` (2.5 MB) | Tiếp nhận file; OCR trích xuất thành công; hiện Form xem trước | High |
| `TC_UC06_009` | Upload tệp CV định dạng Word (.docx) hợp lệ | Field Validation | Tab Upload CV | 1. Chọn file Word từ File Dialog<br>2. Chờ xử lý | File: `CV_Backend.docx` (1.2 MB) | Bóc tách thực thể chính xác; hiện Form xem trước | High |
| `TC_UC06_010` | Upload tệp CV định dạng Ảnh (.png) hợp lệ | Field Validation | Tab Upload CV | 1. Tải lên file ảnh CV<br>2. Chờ OCR xử lý | File: `CV_Scan.png` (3.8 MB) | OCR nhận diện tiếng Việt; trích xuất và hiện Form xem trước | High |
| `TC_UC06_011` | Kéo thả tệp CV vào vùng Drop Zone | Use Case Flow | Tab Upload CV | 1. Kéo file từ Desktop vào Drop Zone<br>2. Thả chuột | File: `CV_Mau.pdf` (1.0 MB) | Vùng Drop Zone đổi màu active; tiếp nhận file bình thường | Medium |
| `TC_UC06_012` | Mở File Dialog chọn file CV tải lên | Use Case Flow | Tab Upload CV | 1. Click vào vùng Upload<br>2. Chọn file từ File Dialog | File: `CV_Mau.pdf` | Mở hộp thoại tệp; chọn file thành công và gửi xử lý | Medium |
| `TC_UC06_013` | Upload file CV dung lượng nhỏ nhất hợp lệ (1 KB) | Field Validation | Tab Upload CV | 1. Chọn file CV 1 KB | File: `CV_Tiny.pdf` (1,024 Bytes = 1 KB) | Tiếp nhận bình thường; xử lý trích xuất thành công | Medium |
| `TC_UC06_014` | Upload file CV cận biên trên hợp lệ (9.9 MB) | Field Validation | Tab Upload CV | 1. Tải lên file CV 9.9 MB | File: `CV_Large.pdf` (10,137 KB = 9.9 MB) | Tiếp nhận thành công; trích xuất hoàn tất | High |
| `TC_UC06_015` | Upload file CV đúng ngưỡng tối đa (10.0 MB) | Field Validation | Tab Upload CV | 1. Tải lên file CV đúng 10.0 MB | File: `CV_Max.pdf` (10,240 KB = 10.0 MB) | Tiếp nhận thành công; gửi AI phân tích bình thường | High |
| `TC_UC06_016` | Upload file CV vượt biên trên tối thiểu (10.01 MB) | Field Validation | Tab Upload CV | 1. Chọn file CV 10.01 MB | File: `CV_Over.pdf` (10,250 KB = 10.01 MB) | Chặn tại Client; báo lỗi EX_01: "Định dạng file không hỗ trợ hoặc dung lượng quá lớn" | High |
| `TC_UC06_017` | Upload file CV dung lượng cực lớn (50 MB) | Field Validation | Tab Upload CV | 1. Kéo thả file 50 MB vào Drop Zone | File: `CV_Huge.pdf` (50.0 MB) | Từ chối tiếp nhận; hiển thị lỗi EX_01 rõ ràng | Medium |
| `TC_UC06_018` | Upload file rỗng dung lượng 0 Byte | Field Validation | Tab Upload CV | 1. Tải lên file 0 Byte | File: `CV_Empty.pdf` (0 Byte) | Chặn tải lên; báo lỗi: "File rỗng, vui lòng chọn file hợp lệ" | Medium |
| `TC_UC06_019` | Upload file thực thi độc hại (.exe) giả mạo | Field Validation | Tab Upload CV | 1. Tải lên file .exe | File: `CV_Trojan.exe` (1.5 MB) | Chặn ngay tại Client; báo lỗi EX_01; không gửi lên server | High |
| `TC_UC06_020` | Upload file script shell (.sh) độc hại | Field Validation | Tab Upload CV | 1. Tải lên file script Linux | File: `install.sh` (4 KB) | Chặn ngay lập tức; báo lỗi định dạng không hỗ trợ (EX_01) | High |
| `TC_UC06_021` | Upload file nén (.zip) | Field Validation | Tab Upload CV | 1. Tải lên file .zip | File: `All_CV.zip` (3.0 MB) | Báo lỗi định dạng file không hỗ trợ (EX_01) | Medium |
| `TC_UC06_022` | Upload file bảng tính Excel (.xlsx) | Field Validation | Tab Upload CV | 1. Tải lên file Excel | File: `DanhSach.xlsx` (500 KB) | Báo lỗi định dạng file không hỗ trợ (EX_01) | Medium |
| `TC_UC06_023` | Upload file ngụy trang đuôi kép (.pdf.exe) | Field Validation | Tab Upload CV | 1. Tải lên file đuôi kép độc hại | File: `CV_NguyenVanA.pdf.exe` (2.0 MB) | Kiểm tra magic bytes; chặn file; cảnh báo tệp nguy hiểm | High |
| `TC_UC06_024` | Đổi đuôi file virus .exe thành .pdf rồi upload | Field Validation | Tab Upload CV | 1. Tải file virus đổi đuôi .pdf | File đổi tên: `Trojan.pdf` (2.0 MB) | Kiểm tra cấu trúc file PDF; phát hiện sai header; từ chối file | High |
| `TC_UC06_025` | Upload file không có phần mở rộng (đuôi file) | Field Validation | Tab Upload CV | 1. Tải lên file không có đuôi | File không đuôi: `CV_NguyenVanA` | Chặn tải lên; yêu cầu chọn file có định dạng hỗ trợ | Low |
| `TC_UC06_026` | Quét tại trang mạng xã hội không hỗ trợ (Facebook) | Use Case Flow | Mở Facebook cá nhân | 1. Nhấn nút "Quét" trên Extension | URL: `https://facebook.com/profile.php?id=123` | Báo lỗi EX_03: "Extension chưa hỗ trợ cấu trúc trang web này..." | High |
| `TC_UC06_027` | Quét tại trang báo tin tức tổng hợp | Use Case Flow | Mở trang tin tức | 1. Nhấn nút "Quét" | URL: `https://vnexpress.net` | Báo lỗi EX_03; không trích xuất dữ liệu rác | Medium |
| `TC_UC06_028` | Quét tại trang chủ LinkedIn (Feed chung) | Use Case Flow | Mở Feed chung LinkedIn | 1. Nhấn nút "Quét" | URL: `https://www.linkedin.com/feed/` | Báo lỗi EX_03 không nhận diện được profile cá nhân | Medium |
| `TC_UC06_029` | Quét tại trang tìm việc làm chung TopCV | Use Case Flow | Mở trang tìm việc TopCV | 1. Nhấn nút "Quét" | URL: `https://topcv.vn/tim-viec-lam` | Báo lỗi EX_03; hướng dẫn mở đúng trang hồ sơ ứng viên | Medium |
| `TC_UC06_030` | Timeout khi máy chủ AI bị nghẽn (> 10.0s) | Business Logic | Server AI nghẽn (phản hồi > 10s) | 1. Upload file CV hợp lệ<br>2. Chờ phản hồi quá 10s | File: `CV_PhucTap.pdf` (xử lý > 10s) | Ngắt kết nối tại mốc 10s; báo lỗi EX_02; tự động mở Form trống nhập tay | High |
| `TC_UC06_031` | Timeout khi quét DOM mạng chập chờn (> 10.0s) | Business Logic | Trang web phản hồi chậm | 1. Nhấn nút "Quét"<br>2. Chờ quét quá 10s | Phản hồi DOM kéo dài > 10s | Báo lỗi timeout EX_02; hiển thị Form trống để nhập tay | High |
| `TC_UC06_032` | Mất kết nối Internet khi đang quét hồ sơ | Business Logic | Mất mạng đột ngột | 1. Ngắt WiFi<br>2. Nhấn nút "Quét" | Không có kết nối mạng Internet | Báo lỗi: "Lỗi kết nối mạng, vui lòng kiểm tra Internet và thử lại" | High |
| `TC_UC06_033` | Bỏ trống trường bắt buộc Họ và tên khi lưu | Field Validation | Form xem trước đang mở | 1. Xóa sạch trường Họ tên<br>2. Nhấn "Lưu hồ sơ" | Họ tên: `""`, Email: `an@gmail.com` | Chặn lưu; viền đỏ ô Họ tên; báo lỗi: "Vui lòng nhập họ và tên ứng viên" | High |
| `TC_UC06_034` | Nhập Họ tên chỉ 1 ký tự (Dưới ngưỡng biên min) | Field Validation | Form xem trước đang mở | 1. Nhập Họ tên 1 ký tự<br>2. Nhấn "Lưu hồ sơ" | Họ tên: `"A"`, Email: `an@gmail.com` | Báo lỗi: "Họ và tên phải có tối thiểu 2 ký tự" | Medium |
| `TC_UC06_035` | Bỏ trống cả Email và Số điện thoại khi lưu | Field Validation | Form xem trước đang mở | 1. Xóa sạch cả Email và SĐT<br>2. Nhấn "Lưu hồ sơ" | Họ tên: `"Lê Văn B"`, Email: `""`, SĐT: `""` | Báo lỗi: "Vui lòng nhập ít nhất một kênh liên lạc (Email hoặc Số điện thoại)" | High |
| `TC_UC06_036` | Chèn mã độc XSS vào Họ tên và Kỹ năng | Business Logic | Form xem trước đang mở | 1. Nhập mã script XSS<br>2. Nhấn "Lưu hồ sơ" | Tên: `<script>alert('XSS')</script>`, Skill: `<img src=x onerror=alert(1)>` | Tự động sanitize dữ liệu; lưu dưới dạng text an toàn; không thực thi script | High |
| `TC_UC06_037` | Cảnh báo trùng lặp Email đã có trong CSDL | Business Logic | Form xem trước đang mở | 1. Nhập Email đã có trong DB<br>2. Nhấn "Lưu hồ sơ" | Email: `da_ton_tai@gmail.com` | Hiện popup cảnh báo: "Hồ sơ ứng viên đã tồn tại trong hệ thống. Bạn có muốn cập nhật đè không?" | High |
| `TC_UC06_038` | Hết hạn Token đăng nhập khi thao tác Quét | Business Logic | Token JWT hết hạn | 1. Nhấn nút "Quét" hoặc Upload | Token JWT hết hạn trong Storage | Chuyển hướng ngay về màn hình Đăng nhập; yêu cầu đăng nhập lại | High |


---

# USE-CASE 07: QUẢN LÝ VÀ PHÂN TÍCH HỒ SƠ ỨNG VIÊN

---

## THÔNG TIN CHUNG VỀ BÀI TẬP VÀ USE CASE 07

- **Học phần:** Kiểm thử và Đảm bảo chất lượng phần mềm (CSE462)
- **Đề tài:** Hệ thống Quản lý Tuyển dụng – Trợ lý Tuyển dụng & Sàng lọc Hồ sơ Tự động
- **Giảng viên hướng dẫn:** TS. Nguyễn Thị Phương Dung | **Nhóm:** 09
- **Sinh viên thực hiện:** Phùng Văn Duy (Mã SV: **2351170589**)
- **Mã Use Case:** `UC_07` | **Tên Use Case:** Quản lý và Phân tích Hồ sơ Ứng viên | **Ngày tạo:** 30/01/2026
- **Tác nhân chính:** Chuyên viên tuyển dụng
- **Kích hoạt:** Chọn menu "Danh sách ứng viên" trên Dashboard hoặc Extension.
- **Tiền điều kiện:** Đã đăng nhập hệ thống; CSDL có ít nhất 01 hồ sơ ứng viên; đã có sẵn JD đang mở tuyển để so khớp.
- **Hậu điều kiện:** Kết quả phân tích AI (Score, Gap, Summary) được lưu vào CSDL; trạng thái hồ sơ được cập nhật.
- **Mục tiêu:** Quản lý danh sách ứng viên (phân trang 10/trang, bộ lọc đa tiêu chí, quick view) và kích hoạt AI so khớp CV với JD để hỗ trợ quyết định tuyển dụng.
- **Tiêu chuẩn áp dụng:** Giáo trình CSE462, ISTQB CTFL v3.1 (Black-box Techniques), ISO/IEC 25010.

---

## 1. PHÂN TÍCH LUỒNG SỰ KIỆN

### 1.1. Luồng chính
1. Chuyên viên đăng nhập và chọn menu "Danh sách ứng viên".
2. Bảng danh sách hiển thị với 10 ứng viên/trang và thanh điều hướng phân trang.
3. Chuyên viên nhập từ khóa kỹ năng `"ReactJS"`, chọn kinh nghiệm `"> 2 năm"`, chọn trạng thái `"Tất cả"`.
4. Hệ thống lọc và hiển thị danh sách các ứng viên thỏa mãn điều kiện.
5. Chuyên viên click chọn ứng viên `"Nguyễn Văn An"`, hệ thống mở màn hình Chi tiết và đổi trạng thái sang "Đã xem".
6. Chuyên viên chọn JD `"Senior Frontend Engineer"`, nhấn nút "Phân tích AI".
7. Sau $3.2\text{s}$, hệ thống hiển thị: Matching Score $88\%$, Gap Analysis và Summary thế mạnh.
8. Chuyên viên nhấn "Lưu kết quả" và cập nhật trạng thái ứng viên sang "Phỏng vấn".
9. Hệ thống lưu CSDL và thông báo: *"Cập nhật thành công"*.

### 1.2. Luồng rẽ nhánh và thay thế
- **A1 (Xóa bộ lọc):** Nhấn nút "Xóa bộ lọc" $\rightarrow$ Toàn bộ ô lọc reset về mặc định $\rightarrow$ Danh sách tải lại toàn bộ ứng viên.
- **A2 (Xem nhanh - Quick View):** Rê chuột (hover) vào avatar ứng viên $\rightarrow$ Popup Quick Card hiển thị trong $0.3\text{s}$ (Tên, Chức danh, Số năm KN, Link mở CV).
- **A3 (Xuất báo cáo PDF):** Tại hồ sơ đã phân tích, nhấn "In / Xuất PDF" $\rightarrow$ Hệ thống xuất và tải file PDF báo cáo kết quả đánh giá.

### 1.3. Luồng ngoại lệ
- **EX_01 (Không tìm thấy kết quả phù hợp):** Lọc tiêu chí không có ứng viên thỏa mãn $\rightarrow$ Báo: *"Không tìm thấy ứng viên phù hợp với tiêu chí đã chọn"*, hiển thị nút "Xóa bộ lọc".
- **EX_02 (Chưa chọn JD để phân tích):** Nhấn "Phân tích AI" khi chưa chọn JD $\rightarrow$ Báo lỗi: *"Vui lòng chọn JD (Mô tả công việc) để thực hiện so khớp"*, tự động mở dropdown JD.
- **EX_03 (Timeout AI quá 10 giây):** AI xử lý quá $10.0\text{s} \rightarrow$ Ngắt kết nối, báo lỗi: *"Máy chủ AI phản hồi chậm, vui lòng thử lại sau"*.
- **EX_04 (CSDL chưa có ứng viên):** CSDL trống $\rightarrow$ Hiển thị màn hình Empty State kèm liên kết điều hướng sang "Thu thập hồ sơ".

---

## 2. BẢNG TỔNG HỢP DANH SÁCH DỮ LIỆU ĐẦU VÀO

| Tên trường | Kiểu dữ liệu | Bắt buộc | Ràng buộc kỹ thuật & Nghiệp vụ | Giá trị mặc định |
| :--- | :---: | :---: | :--- | :--- |
| **Từ khóa lọc kỹ năng** | Text / String | Tùy chọn | $0 \le L \le 100$; không phân biệt hoa/thường; tự động trim; khử mã độc XSS/SQLi | Rỗng (`""`) |
| **Khoảng số năm kinh nghiệm** | Dropdown | Tùy chọn | Giá trị: `Tất cả`, `< 1 năm`, `1-3 năm`, `3-5 năm`, `> 5 năm` | `"Tất cả"` |
| **Trạng thái hồ sơ lọc** | Dropdown | Tùy chọn | Giá trị: `Tất cả`, `Mới`, `Đã xem`, `Phù hợp`, `Phỏng vấn`, `Trúng tuyển`, `Từ chối` | `"Tất cả"` |
| **Số thứ tự trang (Page)** | Integer | Bắt buộc | Số nguyên dương: $1 \le \text{Page} \le \text{TotalPages}$; kích thước cố định: 10 hồ sơ/trang | `1` |
| **Mã ứng viên (Candidate ID)** | Integer / UUID | Bắt buộc (khi xem) | ID hợp lệ tồn tại trong bảng `Candidates` của CSDL | Không có |
| **Mã JD (Job Description ID)** | Dropdown | Bắt buộc (khi phân tích) | ID bản JD hợp lệ đang ở trạng thái `Active` (mở tuyển) | `null` (Chưa chọn) |
| **Trạng thái cập nhật mới** | Dropdown | Bắt buộc (khi đổi TT) | Tuân thủ luồng: `Mới` $\rightarrow$ `Đã xem` $\rightarrow$ `Phù hợp` $\rightarrow$ `Phỏng vấn` $\rightarrow$ `Trúng tuyển`/`Từ chối`. Không chuyển ngược từ `Trúng tuyển` về `Mới` | Trạng thái hiện tại |
| **Lệnh xuất báo cáo PDF** | Button | Tùy chọn | Chỉ kích hoạt khi hồ sơ đã có kết quả phân tích AI (Score, Gap, Summary) | Bị khóa (`disabled`) |

---

## 3. PHÂN TÍCH RÀNG BUỘC TỪNG TRƯỜNG DỮ LIỆU

| Tên trường dữ liệu | Ràng buộc tóm tắt | Phân vùng hợp lệ & Giá trị mẫu | Phân vùng không hợp lệ & Giá trị mẫu | Giá trị biên cần test (BVA) |
| :--- | :--- | :--- | :--- | :--- |
| **Từ khóa lọc kỹ năng** | Chuỗi ký tự, $0 \le L \le 100$, không phân biệt hoa thường, khử XSS | - `"Java"` / `"java"`<br>- `"ReactJS, Node.js"`<br>- Rỗng: `""` | - Quá 100 ký tự<br>- Mã XSS: `<script>alert(1)</script>`<br>- Mã SQLi: `' OR '1'='1` | - $L = 0$: Rỗng (Hợp lệ min)<br>- $L = 1$: `"C"` (Hợp lệ)<br>- $L = 99$: Hợp lệ<br>- $L = 100$: Hợp lệ max<br>- $L = 101$: Lỗi max+1 |
| **Khoảng kinh nghiệm** | Dropdown lựa chọn 1 giá trị enum | - `Tất cả`<br>- `1-3 năm`<br>- `> 5 năm` | - Giá trị không thuộc danh sách (`"10-20 năm"`) | Không áp dụng (Dropdown hữu hạn) |
| **Trạng thái hồ sơ lọc** | Dropdown lựa chọn 1 trạng thái | - `Tất cả`<br>- `Mới`<br>- `Phù hợp`<br>- `Phỏng vấn` | - Trạng thái không tồn tại (`"Pending"`) | Không áp dụng (Dropdown hữu hạn) |
| **Số thứ tự trang phân trang** | Số nguyên dương: $1 \le \text{Page} \le \text{TotalPages}$ | - $\text{Page} = 1$<br>- $\text{Page} = 3$ | - $\text{Page} \le 0$<br>- Vượt quá trang cuối: $\text{Page} > \text{TotalPages}$<br>- Ký tự chữ: `"abc"` | - $P = 0$: Lỗi min-1<br>- $P = 1$: Trang đầu (Hợp lệ min)<br>- $P = 2$: Hợp lệ<br>- $P = \text{TotalPages}$: Trang cuối (Hợp lệ max)<br>- $P = \text{TotalPages} + 1$: Lỗi max+1 |
| **Mã JD so khớp AI** | Bắt buộc chọn JD hợp lệ đang Active | - `JD_Frontend_Senior`<br>- `JD_Tester_01` | - Bỏ trống (`null`) khi bấm Phân tích (EX_02)<br>- JD đã đóng tuyển (`Inactive`) | Không áp dụng (Danh mục chọn) |
| **Thời gian phân tích AI** | Phản hồi từ mô hình AI: $T \le 10.0\text{s}$ | - $0.5\text{s} \le T \le 10.0\text{s}$ | - $T > 10.0\text{s}$ (Timeout EX_03) | - $T = 9.9\text{s}$: Hợp lệ<br>- $T = 10.0\text{s}$: Hợp lệ max<br>- $T = 10.1\text{s}$: Kích hoạt EX_03 |
| **Điểm phù hợp (Matching Score)** | Số nguyên phần trăm: $0\% \le S \le 100\%$ | - $S = 0\%$ (Không khớp)<br>- $S = 75\%$<br>- $S = 100\%$ (Khớp hoàn hảo) | - $S < 0\%$ hoặc $S > 100\%$ | - $S = 0\%$: Biên min<br>- $S = 1\%$: Hợp lệ<br>- $S = 99\%$: Hợp lệ<br>- $S = 100\%$: Biên max |
| **Chuyển đổi trạng thái** | Tuân thủ state machine tuyển dụng | - `Mới` $\rightarrow$ `Đã xem`<br>- `Đã xem` $\rightarrow$ `Phù hợp`<br>- `Phù hợp` $\rightarrow$ `Phỏng vấn` | - Chuyển ngược: `Trúng tuyển` $\rightarrow$ `Mới`<br>- Nhảy cóc phi lý: `Từ chối` $\rightarrow$ `Trúng tuyển` | Trạng thái bắt đầu: `Mới`<br>Trạng thái kết thúc: `Trúng tuyển` / `Từ chối` |

---

## 4. BẢNG QUYẾT ĐỊNH CHO TỔ HỢP LOGIC NGHIỆP VỤ

### 4.1. Phân tích quan hệ ràng buộc chéo và tiền điều kiện
- **Ràng buộc phân tích AI:** Bắt buộc phải chọn 1 bản JD hợp lệ (đang Active) trước khi nhấn nút "Phân tích AI". Nếu để trống $\rightarrow$ Báo lỗi EX_02 và bung mở dropdown chọn JD.
- **Ràng buộc xuất báo cáo PDF:** Nút "In / Xuất PDF" chỉ mở kích hoạt khi hồ sơ đã hoàn thành phân tích AI (đã có Matching Score, Gap, Summary). Nếu chưa phân tích $\rightarrow$ Nút ở trạng thái `disabled`.
- **Ràng buộc logic chuyển trạng thái:** Không cho phép chuyển ngược trạng thái từ giai đoạn cuối (`Trúng tuyển`) về giai đoạn khởi tạo (`Mới`).

### 4.2. Bảng quyết định logic nghiệp vụ

| Mã điều kiện / Hành động | Thành phần kiểm tra | $R_1$ | $R_2$ | $R_3$ | $R_4$ | $R_5$ | $R_6$ | $R_7$ | $R_8$ |
| :--- | :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **C1** | CSDL có ít nhất 01 hồ sơ ứng viên | Có | Có | Có | Có | Có | Có | Không | Có |
| **C2** | Có kết quả hồ sơ thỏa mãn bộ lọc | Có | Không | Có | Có | Có | Có | - | Có |
| **C3** | Bản JD được chọn hợp lệ và đang Active | - | - | Có | Không | Có | Có | - | - |
| **C4** | Thời gian phản hồi AI thỏa mãn $T \le 10.0\text{s}$ | - | - | Có | - | Không | Có | - | - |
| **C5** | Hồ sơ đã hoàn tất phân tích AI (có Score/Gap) | - | - | Có | - | - | Không | - | - |
| **C6** | Chuyển đổi trạng thái hồ sơ hợp lệ theo quy trình | - | - | - | - | - | - | - | Sai |
| **A1** | Hiển thị danh sách kết quả lọc ứng viên | **X** | - | **X** | - | - | - | - | - |
| **A2** | Báo ngoại lệ EX_01 (Không tìm thấy ứng viên phù hợp) | - | **X** | - | - | - | - | - | - |
| **A3** | Hiển thị kết quả phân tích AI (Score, Gap, Summary) | - | - | **X** | - | - | - | - | - |
| **A4** | Báo lỗi EX_02 (Yêu cầu chọn JD trước khi phân tích) | - | - | - | **X** | - | - | - | - |
| **A5** | Báo lỗi timeout EX_03 (Máy chủ AI phản hồi chậm) | - | - | - | - | **X** | - | - | - |
| **A6** | Mở khóa nút Xuất PDF và xuất file thành công | - | - | **X** | - | - | - | - | - |
| **A7** | Khóa nút Xuất PDF (`disabled`) | - | - | - | - | - | **X** | - | - |
| **A8** | Hiển thị giao diện trạng thái trống EX_04 (Empty State) | - | - | - | - | - | - | **X** | - |
| **A9** | Chặn chuyển trạng thái, cảnh báo sai luồng quy trình | - | - | - | - | - | - | - | **X** |

---

## 5. BẢNG CA KIỂM THỬ CHI TIẾT TỔNG HỢP

| Test Case ID | Tên ca kiểm thử / Mục đích test | Phân loại kiểm thử | Tiền điều kiện | Các bước thực hiện | Dữ liệu kiểm thử cụ thể | Kết quả mong đợi | Mức độ ưu tiên |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :---: |
| `TC_UC07_001` | Lọc ứng viên thành công theo kỹ năng đơn lẻ | Use Case Flow | Đang ở trang Danh sách ứng viên | 1. Nhập từ khóa vào ô kỹ năng<br>2. Nhấn Enter hoặc nút Tìm kiếm | Kỹ năng: `"ReactJS"` | Hiển thị các ứng viên có kỹ năng ReactJS; highlight từ khóa | High |
| `TC_UC07_002` | Lọc ứng viên theo tổ hợp kỹ năng và kinh nghiệm | Use Case Flow | Đang ở trang Danh sách ứng viên | 1. Nhập kỹ năng<br>2. Chọn khoảng kinh nghiệm<br>3. Bấm Lọc | Skill: `"Java"`, Exp: `"3-5 năm"` | Hiển thị ứng viên thỏa mãn đồng thời cả kỹ năng Java và KN 3-5 năm | High |
| `TC_UC07_003` | Lọc ứng viên theo trạng thái hồ sơ cụ thể | Use Case Flow | Đang ở trang Danh sách ứng viên | 1. Chọn Trạng thái từ dropdown<br>2. Quan sát kết quả | Trạng thái: `"Phù hợp"` | Chỉ hiển thị các hồ sơ đang có trạng thái "Phù hợp" | High |
| `TC_UC07_004` | Xóa bộ lọc quay về danh sách mặc định | Use Case Flow | Đang áp dụng bộ lọc có kết quả | 1. Nhấn nút "Xóa bộ lọc" (Clear Filter) | Thao tác nhấn Clear | Các ô lọc reset về mặc định; danh sách hiển thị lại toàn bộ ứng viên | Medium |
| `TC_UC07_005` | Xem nhanh hồ sơ ứng viên qua thao tác hover | UI / Quick View | Đang ở trang Danh sách ứng viên | 1. Rê chuột vào avatar ứng viên | Hover avatar ứng viên `"Trần Văn B"` | Popup Quick Card hiển thị trong 0.3s gồm: Tên, Chức danh, Exp, link xem CV | Medium |
| `TC_UC07_006` | Mở xem chi tiết hồ sơ ứng viên | Use Case Flow | Đang ở trang Danh sách ứng viên | 1. Click vào tên ứng viên | Click ứng viên ID: `CAND_001` | Mở trang Chi tiết; trạng thái tự động cập nhật từ "Mới" sang "Đã xem" | High |
| `TC_UC07_007` | Phân tích AI so khớp thành công CV với JD | Business Logic | Tại trang Chi tiết hồ sơ | 1. Chọn JD<br>2. Nhấn nút "Phân tích AI" | JD: `"Senior Frontend Engineer"` | Sau 3.2s hiển thị: Matching Score 88%, Gap kỹ năng, Summary thế mạnh | High |
| `TC_UC07_008` | Lưu kết quả phân tích AI vào CSDL | Business Logic | Đã có kết quả phân tích AI | 1. Nhấn nút "Lưu kết quả phân tích" | Dữ liệu Score 88%, Gap, Summary | Lưu CSDL thành công; thông báo "Đã lưu kết quả phân tích"; ghi Audit Log | High |
| `TC_UC07_009` | Xuất báo cáo kết quả phân tích ra file PDF | Use Case Flow | Hồ sơ đã phân tích AI hoàn tất | 1. Nhấn nút "In / Xuất PDF" | File tải: `BaoCao_NguyenVanAn.pdf` | Tải xuống file PDF chứa đầy đủ thông tin ứng viên, điểm số và bảng phân tích | Medium |
| `TC_UC07_010` | Chuyển đổi trạng thái từ "Đã xem" sang "Phỏng vấn" | Business Logic | Hồ sơ đang ở trạng thái "Đã xem" | 1. Chọn trạng thái "Phỏng vấn"<br>2. Nhấn Cập nhật | Trạng thái mới: `"Phỏng vấn"` | CSDL cập nhật trạng thái "Phỏng vấn"; badge trạng thái đổi màu vàng cam | High |
| `TC_UC07_011` | Lọc kỹ năng không phân biệt chữ hoa và chữ thường | Field Validation | Đang ở trang Danh sách ứng viên | 1. Nhập từ khóa viết thường chữ hoa xen kẽ | Kỹ năng: `"rEaCtJs"` | Trả về kết quả chính xác như khi tìm `"ReactJS"` | Medium |
| `TC_UC07_012` | Lọc kỹ năng có khoảng trắng thừa ở hai đầu | Field Validation | Đang ở trang Danh sách ứng viên | 1. Nhập từ khóa chứa dấu cách thừa | Kỹ năng: `"   NodeJS   "` | Hệ thống tự động trim khoảng trắng; trả về đúng ứng viên có NodeJS | Medium |
| `TC_UC07_013` | Lọc từ khóa kỹ năng độ dài tối đa biên trên (100 ký tự) | Field Validation | Đang ở trang Danh sách ứng viên | 1. Nhập chuỗi 100 ký tự kỹ năng | Chuỗi: `"ReactJS, Node, Python..."` (100 kt) | Tiếp nhận trọn vẹn 100 ký tự; thực hiện tìm kiếm bình thường | Medium |
| `TC_UC07_014` | Lọc từ khóa kỹ năng vượt biên trên (101 ký tự) | Field Validation | Đang ở trang Danh sách ứng viên | 1. Nhập chuỗi 101 ký tự kỹ năng | Chuỗi dài 101 ký tự | Tự động cắt ngắn tại ký tự thứ 100 hoặc báo lỗi vượt độ dài cho phép | Medium |
| `TC_UC07_015` | Chèn mã độc XSS vào ô tìm kiếm kỹ năng | Security / Field | Đang ở trang Danh sách ứng viên | 1. Nhập mã script vào ô kỹ năng<br>2. Bấm Lọc | `<script>alert('XSS_Filter')</script>` | Khử mã độc; hiển thị dưới dạng văn bản an toàn; không kích hoạt script | High |
| `TC_UC07_016` | Chèn mã SQL Injection vào ô tìm kiếm kỹ năng | Security / Field | Đang ở trang Danh sách ứng viên | 1. Nhập payload SQLi vào ô kỹ năng | Payload: `' OR 1=1--` | Sử dụng Parameterized Query; không gây lỗi cú pháp CSDL; không lộ dữ liệu | High |
| `TC_UC07_017` | Lọc ứng viên với mốc kinh nghiệm "< 1 năm" | Field Validation | Đang ở trang Danh sách ứng viên | 1. Chọn kinh nghiệm "< 1 năm" | Exp: `"< 1 năm"` | Chỉ hiển thị các ứng viên có số năm kinh nghiệm từ 0.0 đến dưới 1.0 năm | Medium |
| `TC_UC07_018` | Lọc ứng viên với mốc kinh nghiệm "> 5 năm" | Field Validation | Đang ở trang Danh sách ứng viên | 1. Chọn kinh nghiệm "> 5 năm" | Exp: `"> 5 năm"` | Chỉ hiển thị các ứng viên có kinh nghiệm từ 5.1 năm trở lên | Medium |
| `TC_UC07_019` | Điều hướng sang trang 2 trong danh sách phân trang | Use Case Flow | Danh sách có tổng cộng 25 ứng viên (3 trang) | 1. Nhấn nút chuyển sang trang 2 | Số trang: `Page = 2` | Hiển thị đúng 10 ứng viên từ vị trí 11 đến 20; nút phân trang 2 đổi active | Medium |
| `TC_UC07_020` | Kiểm tra nút "Trang trước" bị vô hiệu hóa ở trang đầu | UI / Boundary | Đang ở trang đầu tiên (`Page = 1`) | 1. Quan sát trạng thái nút "Trang trước" | `Page = 1` | Nút "Trang trước" (Previous) bị mờ và khóa `disabled`, không thể click | Low |
| `TC_UC07_021` | Kiểm tra nút "Trang sau" bị vô hiệu hóa ở trang cuối | UI / Boundary | Đang ở trang cuối cùng (`Page = 3`) | 1. Quan sát trạng thái nút "Trang sau" | `Page = TotalPages` | Nút "Trang sau" (Next) bị mờ và khóa `disabled`, không thể click | Low |
| `TC_UC07_022` | Nhập trực tiếp số trang âm vào URL phân trang | Boundary / URL | Hệ thống có phân trang | 1. Đổi URL thành `?page=-1` | URL param: `page=-1` | Tự động điều hướng về `page=1`; hiển thị danh sách trang đầu tiên | Medium |
| `TC_UC07_023` | Nhập số trang vượt quá tổng số trang vào URL | Boundary / URL | Tổng cộng có 3 trang | 1. Đổi URL thành `?page=999` | URL param: `page=999` | Tự động điều hướng về trang cuối cùng (`page=3`) hoặc báo trang không tồn tại | Medium |
| `TC_UC07_024` | Nhập số trang là ký tự chữ vào URL | Field Validation | Hệ thống có phân trang | 1. Đổi URL thành `?page=abc` | URL param: `page=abc` | Bắt lỗi parse số nguyên; tự động quay về `page=1` | Low |
| `TC_UC07_025` | Phân tích AI khi chưa chọn JD (Ngoại lệ EX_02) | Business Logic | Tại trang Chi tiết hồ sơ | 1. Để trống ô chọn JD<br>2. Nhấn nút "Phân tích AI" | JD: `null` (Chưa chọn) | Báo lỗi EX_02: "Vui lòng chọn JD... để thực hiện so khớp"; tự mở dropdown JD | High |
| `TC_UC07_026` | Phân tích AI với bản JD đã hết hạn tuyển dụng | Business Logic | Tại trang Chi tiết hồ sơ | 1. Chọn JD đã đóng tuyển<br>2. Nhấn "Phân tích AI" | JD: `JD_Inactive_02` (Đã đóng) | Báo lỗi: "JD này đã đóng tuyển dụng. Vui lòng chọn JD đang mở tuyển" | Medium |
| `TC_UC07_027` | Xử lý timeout khi máy chủ AI quá tải (> 10.0s) | Business Logic | Máy chủ AI phản hồi chậm > 10s | 1. Nhấn nút "Phân tích AI"<br>2. Chờ phản hồi quá 10s | Thời gian xử lý: 11.5s | Ngắt kết nối tại mốc 10s; báo lỗi EX_03: "Máy chủ AI phản hồi chậm..."; không mất dữ liệu | High |
| `TC_UC07_028` | Phản hồi AI ở cận trên thời gian cho phép (10.0s) | Boundary / AI | Máy chủ AI xử lý gần chạm biên | 1. Nhấn nút "Phân tích AI"<br>2. Phản hồi trả về tại đúng 10.0s | Thời gian xử lý: Đúng 10.0s | Tiếp nhận kết quả thành công; hiển thị đầy đủ bảng phân tích và điểm số | High |
| `TC_UC07_029` | Kết quả phân tích AI khớp 100% hoàn hảo | Boundary / AI | CV có đầy đủ 100% yêu cầu JD | 1. Thực hiện phân tích AI | CV trùng khớp toàn bộ kỹ năng JD | Matching Score hiển thị đúng `100%`; Gap ghi nhận "Không có khoảng cách kỹ năng" | High |
| `TC_UC07_030` | Kết quả phân tích AI không khớp 0% | Boundary / AI | CV ngành Kế toán so khớp JD AI Engineer | 1. Thực hiện phân tích AI | CV hoàn toàn lệch chuyên môn JD | Matching Score hiển thị `0%`; Gap liệt kê thiếu toàn bộ các kỹ năng cốt lõi | High |
| `TC_UC07_031` | Kiểm tra nút "Xuất PDF" bị khóa khi chưa phân tích | UI / Business | Hồ sơ mới thu thập, chưa phân tích AI | 1. Mở trang Chi tiết hồ sơ<br>2. Quan sát nút "In / Xuất PDF" | Chưa có kết quả phân tích AI | Nút "In / Xuất PDF" ở trạng thái `disabled`, hiển thị tooltip giải thích | Medium |
| `TC_UC07_032` | Chuyển trạng thái ngược phi lý từ "Trúng tuyển" về "Mới" | Business Logic | Hồ sơ đang ở trạng thái "Trúng tuyển" | 1. Chọn đổi trạng thái về "Mới"<br>2. Nhấn Lưu | Chuyển ngược: `Trúng tuyển` $\rightarrow$ `Mới` | Chặn lưu; báo lỗi: "Không thể chuyển ngược trạng thái từ Trúng tuyển về Mới" | High |
| `TC_UC07_033` | Chuyển trạng thái từ "Phỏng vấn" sang "Từ chối" kèm lý do | Business Logic | Hồ sơ đang ở trạng thái "Phỏng vấn" | 1. Chọn trạng thái "Từ chối"<br>2. Nhập lý do<br>3. Nhấn Lưu | Lý do: `"Không đạt bài kiểm tra chuyên môn"` | CSDL lưu trạng thái "Từ chối" kèm lý do chi tiết; gửi thông báo nội bộ | High |
| `TC_UC07_034` | Lọc với tiêu chí không có kết quả (Ngoại lệ EX_01) | Use Case Flow | Đang ở trang Danh sách ứng viên | 1. Nhập kỹ năng không tồn tại | Kỹ năng: `"Fortran_1977_Rare"` | Báo lỗi EX_01: "Không tìm thấy ứng viên phù hợp..."; hiển thị nút Xóa bộ lọc | Medium |
| `TC_UC07_035` | Xem danh sách khi CSDL chưa có ứng viên (EX_04) | Use Case Flow | CSDL hoàn toàn rỗng | 1. Đăng nhập và mở Danh sách ứng viên | CSDL trống (0 ứng viên) | Hiển thị giao diện Empty State với hình minh họa và nút "Thu thập hồ sơ ngay" | Medium |
| `TC_UC07_036` | Lọc kết hợp 3 tiêu chí: Kỹ năng, Kinh nghiệm, Trạng thái | Business Logic | CSDL có 50 ứng viên đa dạng | 1. Nhập Kỹ năng<br>2. Chọn KN<br>3. Chọn TT<br>4. Lọc | Skill: `"Python"`, Exp: `"> 2 năm"`, TT: `"Mới"` | Trả về danh sách chính xác của phép giao (AND) giữa cả 3 điều kiện | High |
| `TC_UC07_037` | Nhấn nút "Phân tích AI" liên tục nhiều lần chống spam | Business Logic | Tại trang Chi tiết hồ sơ | 1. Bấm liên tiếp 4 lần vào nút "Phân tích AI" | Spam click nút Phân tích | Nút đổi trạng thái `disabled` kèm spinner "Đang phân tích..."; chỉ gửi 1 request | High |
| `TC_UC07_038` | Kiểm tra tải xuống file PDF báo cáo khi mất mạng | Exception Flow | Hồ sơ đã phân tích AI | 1. Ngắt WiFi<br>2. Nhấn nút "In / Xuất PDF" | Mất kết nối Internet | Báo lỗi: "Không thể kết nối máy chủ để kết xuất PDF, vui lòng kiểm tra mạng" | Medium |


---

# USE-CASE 08: KIỂM CHỨNG VÀ XÁC THỰC HỒ SƠ

---

## THÔNG TIN CHUNG VỀ BÀI TẬP VÀ USE CASE 08

- **Học phần:** Kiểm thử và Đảm bảo chất lượng phần mềm (CSE462)
- **Đề tài:** Hệ thống Quản lý Tuyển dụng – Trợ lý Tuyển dụng & Sàng lọc Hồ sơ Tự động
- **Giảng viên hướng dẫn:** TS. Nguyễn Thị Phương Dung | **Nhóm:** 09
- **Sinh viên thực hiện:** Phùng Văn Duy (Mã SV: **2351170589**)
- **Mã Use Case:** `UC_08` | **Tên Use Case:** Kiểm chứng và Xác thực Hồ sơ | **Ngày tạo:** 30/01/2026
- **Tác nhân chính:** Chuyên viên tuyển dụng
- **Kích hoạt:** Nhấn nút "Kiểm chứng" tại màn hình Chi tiết hồ sơ ứng viên.
- **Tiền điều kiện:** Đã đăng nhập hệ thống; đang xem hồ sơ có tối thiểu 1 kênh định danh (Email hoặc SĐT kèm Họ tên); kết nối mạng ổn định.
- **Hậu điều kiện:** Báo cáo kiểm chứng dấu vết số và đối chiếu chéo được lưu CSDL; cập nhật trạng thái kiểm chứng hồ sơ.
- **Mục tiêu:** Tự động tìm kiếm dấu vết số (Google, LinkedIn, GitHub) và đối chiếu chéo thời gian công tác, kỹ năng thực tế với CV để phát hiện gian lận hoặc sai lệch thông tin.
- **Tiêu chuẩn áp dụng:** Giáo trình CSE462, ISTQB CTFL v3.1 (Black-box Techniques), ISO/IEC 25010.

---

## 1. PHÂN TÍCH LUỒNG SỰ KIỆN

### 1.1. Luồng chính
1. Chuyên viên mở Chi tiết hồ sơ ứng viên `"Nguyễn Văn An"` (Email: `an.nguyen@gmail.com`, SĐT: `0987654321`).
2. Nhấn nút "Kiểm chứng" (Verify) trên thanh công cụ.
3. Hệ thống hiển thị spinner "Đang kiểm tra..." và khởi động worker ngầm truy vết số ($T \le 30\text{s}$).
4. Worker truy quét profile LinkedIn và GitHub của ứng viên dựa trên Email, SĐT, Họ tên.
5. Hệ thống đối chiếu dữ liệu: Thời gian làm việc tại công ty cũ trùng khớp LinkedIn; kỹ năng công nghệ trùng khớp commit/repo GitHub.
6. Màn hình hiển thị Báo cáo kiểm chứng: Bảng liên kết xã hội, thời gian công tác xanh an toàn, kỹ năng xác thực.
7. Chuyên viên đánh giá và nhấn nút "Xác thực uy tín" (Mark as Verified).
8. Hệ thống lưu kết quả CSDL, ghi Audit Log và thông báo: *"Cập nhật trạng thái kiểm chứng thành công"*.

### 1.2. Luồng rẽ nhánh và thay thế
- **A1 (Nhập liên kết thủ công):** Agent không tự tìm thấy profile $\rightarrow$ Chuyên viên nhấn "Thêm link thủ công", dán URL (LinkedIn/GitHub) $\rightarrow$ Hệ thống cào dữ liệu URL đó và tiến hành đối chiếu.
- **A2 (Không tìm thấy dấu vết công khai):** Ứng viên không có tài khoản công khai $\rightarrow$ Hệ thống báo: *"Không tìm thấy dấu vết số công khai của ứng viên này"*, cho phép Bỏ qua hoặc Nhập từ khóa mở rộng để quét lại.

### 1.3. Luồng ngoại lệ
- **EX_01 (Bị chặn bởi Captcha):** Google/LinkedIn kích hoạt chống bot $\rightarrow$ Tạm dừng worker, hiện popup yêu cầu chuyên viên giải Captcha thủ công.
- **EX_02 (Mất kết nối mạng):** Mất mạng khi worker đang quét bên ngoài $\rightarrow$ Dừng an toàn, báo lỗi: *"Lỗi kết nối. Vui lòng kiểm tra mạng và thử lại"*.
- **EX_03 (Hồ sơ thiếu định danh tối thiểu):** Hồ sơ thiếu cả Email và SĐT $\rightarrow$ Chặn ngay khi bấm Kiểm chứng, báo lỗi: *"Không đủ thông tin định danh để thực hiện kiểm chứng. Vui lòng cập nhật Email hoặc SĐT"*.
- **EX_04 (Timeout worker quá 30 giây):** Quét mạng ngoài kéo dài quá $30.0\text{s} \rightarrow$ Ngắt tiến trình an toàn, báo lỗi timeout và cho phép thử lại.

---

## 2. BẢNG TỔNG HỢP DANH SÁCH DỮ LIỆU ĐẦU VÀO

| Tên trường | Kiểu dữ liệu | Bắt buộc | Ràng buộc kỹ thuật & Nghiệp vụ | Giá trị mặc định |
| :--- | :---: | :---: | :--- | :--- |
| **Họ và tên ứng viên** | Text / String | Bắt buộc | $2 \le L \le 100$; chỉ chữ cái và khoảng trắng; kết hợp tạo truy vấn tìm kiếm | Lấy từ hồ sơ |
| **Địa chỉ Email** | Text / Email | Bắt buộc (nếu thiếu SĐT) | Khóa định danh số 1 để truy vết LinkedIn, GitHub; chuẩn RFC 5322 regex; $6 \le L \le 100$ | Lấy từ hồ sơ |
| **Số điện thoại** | Text / Phone | Bắt buộc (nếu thiếu Email) | Khóa định danh số 2; đúng 10 chữ số, đầu số di động VN (03, 05, 07, 08, 09) | Lấy từ hồ sơ |
| **Tên công ty gần nhất** | Text / String | Tùy chọn | Dùng kết hợp truy vấn tìm kiếm chéo: `Họ tên + Tên công ty` | Lấy từ hồ sơ |
| **Trường đại học đào tạo** | Text / String | Tùy chọn | Dùng kết hợp truy vấn tìm kiếm chéo: `Họ tên + Trường học` | Lấy từ hồ sơ |
| **URL mạng xã hội thủ công** | Text / URL | Bắt buộc (khi nhập tay) | Bắt buộc thuộc domain: `linkedin.com` hoặc `github.com`; tự cắt bỏ query tracking | Rỗng (`""`) |
| **Từ khóa quét mở rộng** | Text / String | Tùy chọn (khi quét lại) | $2 \le L \le 100$; nhập nickname, dự án cá nhân khi lần đầu không có kết quả | Rỗng (`""`) |
| **Hành động thẩm định** | Dropdown | Bắt buộc (khi xác nhận) | Giá trị: `Xác thực uy tín`, `Gắn cờ rủi ro`, `Bỏ qua`, `Kiểm chứng lại`; bắt buộc ghi Audit Log | `"Chưa kiểm chứng"` |
| **Thao tác giải Captcha** | Human Action | Bắt buộc (khi gặp EX_01) | Tương tác giải Captcha khi dịch vụ ngoài yêu cầu | Không có |

---

## 3. PHÂN TÍCH RÀNG BUỘC TỪNG TRƯỜNG DỮ LIỆU

| Tên trường dữ liệu | Ràng buộc tóm tắt | Phân vùng hợp lệ & Giá trị mẫu | Phân vùng không hợp lệ & Giá trị mẫu | Giá trị biên cần test (BVA) |
| :--- | :--- | :--- | :--- | :--- |
| **Dữ liệu định danh tối thiểu** | Bắt buộc có Tên VÀ (Email HOẶC SĐT) | - Có Tên + Email<br>- Có Tên + SĐT<br>- Có đủ cả 3 thông tin | - Chỉ có Tên (Thiếu cả Email và SĐT - EX_03)<br>- Không có tên (`null`) | Tổ hợp tối thiểu 2 trường dữ liệu |
| **URL nhập thủ công** | URL thuộc LinkedIn/GitHub, $15 \le L \le 500$ | - `https://linkedin.com/in/annguyen`<br>- `https://github.com/an-dev` | - Domain lạ: `https://facebook.com/u1`<br>- Sai cú pháp: `invalid-url`<br>- Chứa script: `javascript:alert(1)` | - $L = 14$: Lỗi min-1<br>- $L = 15$: Hợp lệ min<br>- $L = 500$: Hợp lệ max<br>- $L = 501$: Lỗi max+1 |
| **Thời gian quét worker ngầm** | Phản hồi truy vết ngoài: $T \le 30.0\text{s}$ | - $1.0\text{s} \le T \le 30.0\text{s}$ (Thành công) | - $T > 30.0\text{s}$ (Timeout EX_04) | - $T = 29.9\text{s}$: Hợp lệ<br>- $T = 30.0\text{s}$: Hợp lệ max<br>- $T = 30.1\text{s}$: Kích hoạt EX_04 |
| **Độ lệch thời gian công tác** | Khoảng lệch tháng làm việc giữa CV và MXH | - Lệch $\le 1$ tháng (Chấp nhận được)<br>- Trùng khớp 100% (Lệch 0 tháng) | - Lệch $\ge 3$ tháng (Cảnh báo sai lệch)<br>- Trùng lặp công tác cùng lúc 2 cty toàn thời gian | - Lệch 0 tháng: Khớp hoàn hảo<br>- Lệch 1 tháng: Ngưỡng an toàn<br>- Lệch 2 tháng: Ngưỡng chú ý<br>- Lệch 3 tháng: Ngưỡng gắn cờ cảnh báo |
| **Trạng thái kiểm chứng** | Enum quy định mức độ tin cậy của hồ sơ | - `Đã xác thực`<br>- `Có rủi ro`<br>- `Không tìm thấy dữ liệu` | - Giá trị lạ không nằm trong enum | Trạng thái ban đầu: `Chưa kiểm chứng` |
| **Xử lý Captcha bên ngoài** | Phát hiện chống bot của bên thứ 3 | - Không xuất hiện Captcha<br>- Giải Captcha thành công | - Giải Captcha sai nhiều lần<br>- Đóng popup bỏ qua Captcha | Thời gian chờ giải Captcha: Tối đa 60 giây |

---

## 4. BẢNG QUYẾT ĐỊNH CHO TỔ HỢP LOGIC NGHIỆP VỤ

### 4.1. Phân tích quan hệ ràng buộc chéo và tiền điều kiện
- **Ràng buộc định danh bắt đầu:** Chỉ kích hoạt worker kiểm chứng khi hồ sơ có đủ `Họ tên` VÀ (`Email` $\ne \emptyset$ HOẶC `SĐT` $\ne \emptyset$). Nếu thiếu $\rightarrow$ Chặn kích hoạt, báo lỗi ngoại lệ EX_03.
- **Ràng buộc đối chiếu:** Khi tìm thấy profile mạng xã hội hợp lệ $\rightarrow$ Hệ thống tự động kích hoạt thuật toán so sánh thời gian làm việc và kỹ năng; nếu độ lệch $\ge 3$ tháng $\rightarrow$ Tự động gắn cờ "Có rủi ro".
- **Ràng buộc ghi Audit Log:** Bất kỳ thao tác chuyển trạng thái kiểm chứng nào (`Xác thực uy tín`, `Gắn cờ rủi ro`) đều bắt buộc ghi nhận ID chuyên viên, mốc thời gian và lý do xác nhận vào bảng Audit Log.

### 4.2. Bảng quyết định logic nghiệp vụ

| Mã điều kiện / Hành động | Thành phần kiểm tra | $R_1$ | $R_2$ | $R_3$ | $R_4$ | $R_5$ | $R_6$ | $R_7$ | $R_8$ |
| :--- | :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **C1** | Đủ định danh tối thiểu: Tên + (Email / SĐT) | Có | Có | Có | Có | Có | Có | Có | Không |
| **C2** | Worker tìm thấy dấu vết số công khai | Có | Có | Không | Có | Có | Có | Có | - |
| **C3** | Dịch vụ ngoài yêu cầu giải Captcha | Không | Không | Không | Có | Có | Không | Không | - |
| **C4** | Chuyên viên giải Captcha thành công | - | - | - | Có | Không | - | - | - |
| **C5** | Thời gian phản hồi worker $T \le 30.0\text{s}$ | Có | Có | Có | Có | - | Không | Có | - |
| **C6** | Kết quả đối chiếu chéo (Lệch thời gian $\ge 3$ tháng) | Không | Có | - | Không | - | - | - | - |
| **A1** | Báo cáo kiểm chứng hiển thị trạng thái An toàn | **X** | - | - | **X** | - | - | - | - |
| **A2** | Báo cáo kiểm chứng gắn cờ cảnh báo Rủi ro | - | **X** | - | - | - | - | - | - |
| **A3** | Báo ngoại lệ 5a (Không tìm thấy dấu vết số công khai) | - | - | **X** | - | - | - | - | - |
| **A4** | Tạm dừng worker, yêu cầu giải Captcha (EX_01) | - | - | - | - | **X** | - | - | - |
| **A5** | Báo lỗi timeout EX_04 (Thời gian quét quá 30 giây) | - | - | - | - | - | **X** | - | - |
| **A6** | Mất mạng Internet, báo lỗi EX_02 | - | - | - | - | - | - | **X** | - |
| **A7** | Chặn kiểm chứng, báo lỗi thiếu định danh EX_03 | - | - | - | - | - | - | - | **X** |

---

## 5. BẢNG CA KIỂM THỬ CHI TIẾT TỔNG HỢP

| Test Case ID | Tên ca kiểm thử / Mục đích test | Phân loại kiểm thử | Tiền điều kiện | Các bước thực hiện | Dữ liệu kiểm thử cụ thể | Kết quả mong đợi | Mức độ ưu tiên |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :---: |
| `TC_UC08_001` | Kiểm chứng tự động thành công khớp dữ liệu LinkedIn | Use Case Flow | Tại trang Chi tiết hồ sơ | 1. Nhấn nút "Kiểm chứng"<br>2. Chờ worker quét hoàn tất | Hồ sơ: `"Nguyễn Văn An"`, Email: `an.nguyen@gmail.com` | Quét thấy profile LinkedIn; thời gian khớp 100%; hiển thị Báo cáo an toàn | High |
| `TC_UC08_002` | Kiểm chứng đối chiếu thành công kỹ năng qua GitHub | Use Case Flow | Tại trang Chi tiết hồ sơ | 1. Nhấn nút "Kiểm chứng"<br>2. Xem bảng đối chiếu kỹ năng | Email: `dev.an@gmail.com` | Tìm thấy GitHub; xác nhận kho mã nguồn khớp kỹ năng Java, React trên CV | High |
| `TC_UC08_003` | Cảnh báo sai lệch thời gian công tác giữa CV và MXH | Business Logic | Tại trang Chi tiết hồ sơ | 1. Nhấn "Kiểm chứng"<br>2. Kiểm tra phần đối chiếu kinh nghiệm | CV ghi 3 năm (2021-2024); LinkedIn ghi 1 năm (2023-2024) | Phát hiện lệch $\ge 3$ tháng; tự động gắn cờ cảnh báo đỏ "Khai khống kinh nghiệm" | High |
| `TC_UC08_004` | Phát hiện trùng lặp thời gian làm 2 công ty toàn thời gian | Business Logic | Tại trang Chi tiết hồ sơ | 1. Nhấn "Kiểm chứng"<br>2. Xem biểu đồ thời gian công tác | Công ty A: 2022-2024 (Full-time); Cty B: 2023-2024 (Full-time) | Biểu đồ highlight vùng trùng lặp; cảnh báo rủi ro làm song song 2 công ty | High |
| `TC_UC08_005` | Thêm liên kết mạng xã hội thủ công bằng URL hợp lệ | Use Case Flow | Đang mở tab Nhập link thủ công | 1. Dán URL profile LinkedIn<br>2. Nhấn "Xác thực link" | URL: `https://www.linkedin.com/in/annguyen-dev` | Tiếp nhận link; bóc tách thông tin profile; chuyển sang bước đối chiếu | Medium |
| `TC_UC08_006` | Thêm liên kết GitHub thủ công hợp lệ | Use Case Flow | Đang mở tab Nhập link thủ công | 1. Dán URL GitHub cá nhân<br>2. Nhấn "Xác thực link" | URL: `https://github.com/annguyen-coder` | Tiếp nhận link; cào danh sách repositories và ngôn ngữ lập trình | Medium |
| `TC_UC08_007` | Không tìm thấy dấu vết số công khai của ứng viên | Use Case Flow | Ứng viên không có MXH công khai | 1. Nhấn nút "Kiểm chứng" | Email: `ong_ba_gia_khong_mxh@gmail.com` | Báo kết quả 5a: "Không tìm thấy dấu vết số..."; cho phép Bỏ qua hoặc Thử lại | Medium |
| `TC_UC08_008` | Quét lại thành công với từ khóa tìm kiếm mở rộng | Use Case Flow | Lần 1 không tìm thấy kết quả | 1. Nhập nickname vào ô mở rộng<br>2. Nhấn "Quét lại" | Từ khóa: `"An_Coder_HUST"` | Tìm thấy tài khoản diễn đàn công nghệ; bổ sung dữ liệu vào báo cáo | Medium |
| `TC_UC08_009` | Chuyên viên xác nhận "Xác thực uy tín" cho hồ sơ | Business Logic | Đã có báo cáo kiểm chứng an toàn | 1. Nhấn nút "Xác thực uy tín" (Mark Verified) | Hồ sơ hợp lệ, không có dấu hiệu gian lận | Trạng thái đổi thành "Đã xác thực" (tích xanh); lưu Audit Log | High |
| `TC_UC08_010` | Chuyên viên xác nhận "Gắn cờ rủi ro" kèm ghi chú | Business Logic | Báo cáo phát hiện sai lệch | 1. Nhấn "Gắn cờ rủi ro"<br>2. Nhập lý do<br>3. Xác nhận | Lý do: `"Sai lệch 2 năm kinh nghiệm thực tế"` | Trạng thái đổi thành "Có rủi ro" (cờ đỏ); lưu lý do và ID chuyên viên vào CSDL | High |
| `TC_UC08_011` | Hồ sơ chỉ có Email mà không có Số điện thoại | Field Validation | Hồ sơ ứng viên chỉ có Email | 1. Nhấn nút "Kiểm chứng" | Tên: `"Trần B"`, Email: `tranb@gmail.com`, SĐT: `""` | Vẫn kích hoạt kiểm chứng bình thường bằng khóa Email | High |
| `TC_UC08_012` | Hồ sơ chỉ có Số điện thoại mà không có Email | Field Validation | Hồ sơ ứng viên chỉ có SĐT | 1. Nhấn nút "Kiểm chứng" | Tên: `"Lê C"`, Email: `""`, SĐT: `0912345678` | Vẫn kích hoạt kiểm chứng bình thường bằng khóa SĐT | High |
| `TC_UC08_013` | Hồ sơ thiếu cả Email và Số điện thoại (Ngoại lệ EX_03) | Field Validation | Hồ sơ thiếu cả Email và SĐT | 1. Nhấn nút "Kiểm chứng" | Tên: `"Phạm D"`, Email: `""`, SĐT: `""` | Chặn ngay tại giao diện; báo lỗi EX_03: "Không đủ thông tin định danh..."; không khởi động worker | High |
| `TC_UC08_014` | Nhập URL thủ công không thuộc domain được hỗ trợ | Field Validation | Tab Nhập link thủ công | 1. Dán URL Facebook cá nhân<br>2. Nhấn Xác thực | URL: `https://facebook.com/annguyen.profile` | Báo lỗi: "Hệ thống chỉ hỗ trợ liên kết từ LinkedIn hoặc GitHub" | Medium |
| `TC_UC08_015` | Nhập URL thủ công sai cú pháp đường dẫn | Field Validation | Tab Nhập link thủ công | 1. Dán chuỗi URL sai cú pháp | Chuỗi: `htt://invalid_linkedin_url` | Bắt lỗi định dạng; yêu cầu nhập URL hợp lệ bắt đầu bằng https:// | Low |
| `TC_UC08_016` | Dán URL thủ công chứa tham số tracking rác (UTM) | Field Validation | Tab Nhập link thủ công | 1. Dán URL có tham số tracking rác | URL: `https://linkedin.com/in/an?utm_source=share&utm_medium=ios` | Tự động làm sạch URL (cắt bỏ phần ?utm_...); tiếp nhận đường dẫn gốc | Medium |
| `TC_UC08_017` | Chèn mã độc javascript vào ô nhập link thủ công | Security / Field | Tab Nhập link thủ công | 1. Dán payload script vào ô URL | Payload: `javascript:alert('XSS_Link')` | Chặn tải link; báo lỗi giao thức URL không an toàn; khử mã độc | High |
| `TC_UC08_018` | Nhập URL thủ công độ dài biên trên tối đa (500 ký tự) | Field Validation | Tab Nhập link thủ công | 1. Dán URL hợp lệ dài đúng 500 ký tự | URL hợp lệ độ dài 500 ký tự | Tiếp nhận bình thường; gửi worker xử lý | Medium |
| `TC_UC08_019` | Nhập URL thủ công vượt quá biên trên (501 ký tự) | Field Validation | Tab Nhập link thủ công | 1. Dán URL dài 501 ký tự | URL dài 501 ký tự | Báo lỗi: "Độ dài đường dẫn không được vượt quá 500 ký tự" | Low |
| `TC_UC08_020` | Nhập từ khóa mở rộng chỉ có 1 ký tự (Dưới biên min) | Field Validation | Ô nhập từ khóa mở rộng | 1. Nhập 1 ký tự<br>2. Nhấn Quét lại | Từ khóa: `"A"` | Báo lỗi: "Từ khóa tìm kiếm phải có tối thiểu 2 ký tự" | Low |
| `TC_UC08_021` | Nhập từ khóa mở rộng độ dài 2 ký tự (Hợp lệ tối thiểu) | Field Validation | Ô nhập từ khóa mở rộng | 1. Nhập 2 ký tự<br>2. Nhấn Quét lại | Từ khóa: `"AI"` | Tiếp nhận từ khóa; khởi động quét lại với từ khóa "AI" | Medium |
| `TC_UC08_022` | Nhập từ khóa mở rộng độ dài 100 ký tự (Hợp lệ tối đa) | Field Validation | Ô nhập từ khóa mở rộng | 1. Nhập chuỗi 100 ký tự | Từ khóa độ dài 100 ký tự | Tiếp nhận hợp lệ; thực hiện tìm kiếm mở rộng | Medium |
| `TC_UC08_023` | Nhập từ khóa mở rộng vượt quá 100 ký tự (101 ký tự) | Field Validation | Ô nhập từ khóa mở rộng | 1. Nhập chuỗi 101 ký tự | Từ khóa dài 101 ký tự | Cắt bớt tại ký tự 100 hoặc báo lỗi vượt giới hạn độ dài | Low |
| `TC_UC08_024` | Chèn mã độc SQL Injection vào ô tìm kiếm mở rộng | Security / Field | Ô nhập từ khóa mở rộng | 1. Nhập payload SQLi<br>2. Bấm Quét lại | Payload: `' UNION SELECT 1, user(), version()--` | Xử lý an toàn với Parameterized Query; không phát sinh lỗi cú pháp CSDL | High |
| `TC_UC08_025` | Xử lý ngoại lệ bị chặn bởi Captcha (Ngoại lệ EX_01) | Exception Flow | Google kích hoạt Captcha chống bot | 1. Nhấn Kiểm chứng<br>2. Chờ phát hiện Captcha | Google/LinkedIn kích hoạt Captcha | Tạm dừng worker; hiện popup: "Hệ thống bị chặn bởi Captcha. Vui lòng xác thực thủ công" | High |
| `TC_UC08_026` | Chuyên viên giải Captcha thành công trên popup | Exception Flow | Đang hiển thị popup Captcha | 1. Giải Captcha thành công trên popup | Hoàn thành xác thực Captcha | Worker tiếp tục tiến trình quét dữ liệu; hoàn tất báo cáo kiểm chứng | High |
| `TC_UC08_027` | Đóng popup Captcha mà không giải xác thực | Exception Flow | Đang hiển thị popup Captcha | 1. Nhấn nút "Hủy / Đóng" popup Captcha | Đóng popup xác thực | Dừng quy trình kiểm chứng; đưa trạng thái về "Chưa hoàn tất kiểm chứng" | Medium |
| `TC_UC08_028` | Xử lý timeout khi mạng bên ngoài phản hồi chậm (> 30s) | Business Logic | Dịch vụ mạng ngoài phản hồi chậm > 30s | 1. Nhấn Kiểm chứng<br>2. Chờ phản hồi quá 30 giây | Thời gian xử lý: 32.0s | Ngắt worker tại mốc 30s; báo lỗi EX_04: "Quá thời gian phản hồi..."; cho phép thử lại | High |
| `TC_UC08_029` | Phản hồi worker ở cận trên thời gian cho phép (30.0s) | Boundary / Flow | Mạng ngoài phản hồi đúng mốc biên | 1. Nhấn Kiểm chứng<br>2. Kết quả trả về đúng 30.0s | Thời gian xử lý: Đúng 30.0s | Tiếp nhận kết quả thành công; hiển thị báo cáo bình thường | High |
| `TC_UC08_030` | Mất kết nối Internet khi worker đang quét dữ liệu (EX_02) | Exception Flow | Mất mạng đột ngột khi đang quét | 1. Ngắt WiFi khi worker đang quét | Ngắt mạng Internet | Báo lỗi EX_02: "Lỗi kết nối. Vui lòng kiểm tra mạng và thử lại"; dừng an toàn | High |
| `TC_UC08_031` | Độ lệch thời gian công tác ở ngưỡng an toàn (Lệch 1 tháng) | Business Logic | CV lệch 1 tháng so với LinkedIn | 1. Kiểm tra báo cáo thời gian | CV ghi kết thúc T5/2023, LinkedIn ghi T6/2023 | Đánh giá ở mức chấp nhận được (xanh); giải thích sai số do cập nhật chậm | Medium |
| `TC_UC08_032` | Độ lệch thời gian công tác chạm ngưỡng cảnh báo (3 tháng) | Business Logic | CV lệch đúng 3 tháng so với MXH | 1. Kiểm tra báo cáo thời gian | CV ghi kết thúc T3/2023, LinkedIn ghi T6/2023 | Kích hoạt cảnh báo màu vàng: "Thời gian công tác lệch 3 tháng, cần xác minh" | High |
| `TC_UC08_033` | Độ lệch thời gian công tác nghiêm trọng (> 6 tháng) | Business Logic | CV lệch 8 tháng so với thực tế | 1. Kiểm tra báo cáo thời gian | CV ghi làm 2020-2023, LinkedIn ghi 2020-2022 | Kích hoạt cảnh báo đỏ rủi ro cao: "Sai lệch nghiêm trọng về thời gian kinh nghiệm" | High |
| `TC_UC08_034` | Kiểm tra bắt buộc nhập lý do khi Gắn cờ rủi ro | Business Logic | Tại popup Gắn cờ rủi ro | 1. Nhấn "Gắn cờ rủi ro"<br>2. Để trống ô lý do<br>3. Nhấn Xác nhận | Lý do: `""` (Rỗng) | Chặn xác nhận; viền đỏ ô lý do; yêu cầu: "Vui lòng nhập lý do khi gắn cờ rủi ro" | High |
| `TC_UC08_035` | Ghi nhận đầy đủ thông tin Audit Log khi thẩm định | Business Logic | Thực hiện thẩm định hồ sơ | 1. Chuyên viên xác nhận kiểm chứng | Chuyên viên: `USER_09`, Thao tác: "Mark Verified" | CSDL bảng `AuditLogs` ghi nhận đúng User ID, Action, Timestamp, IP Address | High |
| `TC_UC08_036` | Kiểm tra nút "Kiểm chứng lại" cập nhật dữ liệu mới | Use Case Flow | Hồ sơ đã kiểm chứng trước đó | 1. Nhấn nút "Kiểm chứng lại" | Chạy lại quy trình quét mới | Xóa cache kết quả cũ; quét lại toàn bộ dữ liệu mới nhất trên mạng | Medium |
| `TC_UC08_037` | Nhấn nút "Kiểm chứng" liên tục nhiều lần chống spam | Business Logic | Tại trang Chi tiết hồ sơ | 1. Bấm liên tiếp 4 lần vào nút "Kiểm chứng" | Thao tác spam click | Nút Kiểm chứng đổi sang `disabled` kèm hiệu ứng đang chạy; chỉ tạo đúng 1 job worker | High |
| `TC_UC08_038` | Kiểm tra bảo vệ quyền riêng tư (Không lưu cookie cá nhân) | Security / Flow | Quá trình worker quét mạng xã hội | 1. Phân tích gói tin request của worker | Quét các trang công khai | Worker không gửi kèm cookie đăng nhập cá nhân của chuyên viên; đảm bảo ẩn danh | High |


---

# TỔNG KẾT TOÀN DIỆN VÀ DANH MỤC TỆP DỮ LIỆU (114 CA KIỂM THỬ)

### 1. Ma trận tổng hợp phân bổ kỹ thuật hộp đen cho cả 3 Use Case

| STT | Mã Use Case | Tên Use Case | Phân vùng tương đương | Phân tích giá trị biên | Bảng quyết định | Kiểm thử chuyển trạng thái | Bảo mật & Đoán lỗi | Tổng số ca kiểm thử |
| :---: | :---: | :--- | :---: | :---: | :---: | :---: | :---: | :---: |
| 1 | `UC_06` | Thu Thập Hồ Sơ | 18 ca | 9 ca | 8 ca | 6 ca | 7 ca | **38 ca** |
| 2 | `UC_07` | Quản lý và Phân tích Hồ sơ Ứng viên | 19 ca | 9 ca | 9 ca | 8 ca | 6 ca | **38 ca** |
| 3 | `UC_08` | Kiểm chứng và Xác thực Hồ sơ | 18 ca | 9 ca | 9 ca | 8 ca | 7 ca | **38 ca** |
| **TỔNG CỘNG** | | **3 Use Case hoàn chỉnh** | **55 lượt** | **27 lượt** | **26 lượt** | **22 lượt** | **20 lượt** | **114 CA KIỂM THỬ** |

### 2. Danh mục tệp dữ liệu kiểm thử CSV chuẩn Excel đi kèm
- Tệp CSV tổng hợp: `hop-den/KiemThuHopDen_TongHop_114TC.csv`
- Bảng mã: `UTF-8 with BOM` (`utf-8-sig`) đảm bảo hiển thị hoàn hảo dấu tiếng Việt trên Microsoft Excel, Google Sheets và Jira / Xray.
- Bao gồm 8 cột chuẩn quốc tế:
  1. `Test Case ID`
  2. `Tên ca kiểm thử / Mục đích test`
  3. `Phân loại kiểm thử`
  4. `Tiền điều kiện`
  5. `Các bước thực hiện`
  6. `Dữ liệu kiểm thử cụ thể`
  7. `Kết quả mong đợi`
  8. `Mức độ ưu tiên`

### 3. Danh mục tệp báo cáo chuẩn Word (.docx) đi kèm
- Báo cáo tổng hợp cả 3 Use Case: `hop-den/BaoCao_KiemThuHopDen_TongHop_3UC.docx`
- Báo cáo Use Case 06: `hop-den/KiemThuHopDen_UC06_ThuThapHoSo.docx`
- Báo cáo Use Case 07: `hop-den/KiemThuHopDen_UC07_QuanLyVaPhanTichHoSo.docx`
- Báo cáo Use Case 08: `hop-den/KiemThuHopDen_UC08_KiemChungVaXacThucHoSo.docx`
*(Định dạng chuẩn học thuật: Phông chữ Arial / Times New Roman, tiêu đề bảng nền xanh Navy `#1F4E79`, dòng xen kẽ `#F8FAFC`, lề A4 chuẩn 1.8cm, hỗ trợ xuống dòng chuẩn `<w:br/>` trong bảng test case).*

### 4. Đánh giá chất lượng và kết luận chung
- **Độ bao phủ nghiệp vụ:** Đạt **100%** tất cả các luồng chính, luồng thay thế và các luồng ngoại lệ đã mô tả trong tài liệu đặc tả của cả 3 Use Case.
- **Tính khả thi và độ chi tiết:** 100% các ca kiểm thử đều có dữ liệu đầu vào cụ thể (Concrete Test Data), các bước thao tác tuần tự rõ ràng, kết quả mong đợi chi tiết và mức độ ưu tiên xác định.
- **Tiêu chuẩn học thuật & công nghiệp:** Tuân thủ đầy đủ giáo trình Kiểm thử phần mềm CSE462, tiêu chuẩn quốc tế **ISTQB CTFL v3.1** và quy trình **ISO/IEC/IEEE 29119**.
