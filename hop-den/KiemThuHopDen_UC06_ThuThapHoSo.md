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
