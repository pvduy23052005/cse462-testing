# USE-CASE 06: THU THẬP HỒ SƠ

---

## 1. THÔNG TIN CHUNG VỀ BÀI TẬP VÀ USE CASE 06

- **Học phần:** Kiểm thử và Đảm bảo chất lượng phần mềm (CSE462)
- **Đề tài:** Hệ thống Quản lý Tuyển dụng – Trợ lý Tuyển dụng & Sàng lọc Hồ sơ Tự động
- **Giảng viên hướng dẫn:** TS. Nguyễn Thị Phương Dung
- **Nhóm sinh viên thực hiện:** Nhóm 09
- **Sinh viên đảm nhận Use Case:** Phùng Văn Duy (Mã SV: **2351170589**)
- **Mã Use Case:** `UC_06`
- **Tên Use Case:** Thu Thập Hồ Sơ
- **Người tạo:** Phùng Văn Duy
- **Ngày tạo:** 30/01/2026
- **Tác nhân chính:** Chuyên viên tuyển dụng
- **Kích hoạt:**
  - Người dùng nhấn nút "Quét" hiển thị trên trang web tuyển dụng (LinkedIn, TopCV, VietnamWorks).
  - Hoặc người dùng mở Extension và chọn tab "Upload CV".
- **Tiền điều kiện:**
  - Người dùng đã đăng nhập thành công vào Extension (Token còn hiệu lực).
  - Kết nối Internet ổn định.
  - Trang web đang mở là trang hồ sơ ứng viên hợp lệ hoặc có sẵn tệp CV (PDF/Word/Ảnh) trên máy tính.
- **Hậu điều kiện:**
  - Dữ liệu ứng viên được chuẩn hóa và lưu thành công vào CSDL.
  - Dashboard cập nhật số lượng hồ sơ mới thu thập.
- **Mô tả nghiệp vụ:**
  Cho phép Chuyên viên tuyển dụng thu thập thông tin ứng viên từ hai nguồn độc lập:
  1. *Quét tự động trang web:* Phân tích cấu trúc DOM của các trang tuyển dụng lớn (LinkedIn, TopCV, VietnamWorks...) để bóc tách thông tin ứng viên.
  2. *Tải lên tệp CV:* Tải lên tệp CV (PDF/Ảnh/Word) để hệ thống AI (OCR kết hợp LLM) trích xuất thực thể và chuẩn hóa lưu vào CSDL.
- **Tiêu chuẩn học thuật áp dụng:**
  - Giáo trình Kiểm thử và Đảm bảo chất lượng phần mềm (CSE462).
  - Chuẩn kiểm thử quốc tế **ISTQB CTFL 2018 v3.1** (Black-box Test Techniques).
  - Chuẩn quy trình kiểm thử phần mềm **ISO/IEC/IEEE 29119-4**.

---

## 2. PHÂN TÍCH RÀNG BUỘC TỪNG TRƯỜNG DỮ LIỆU

### 1. Bảng phân tích chi tiết từng trường dữ liệu áp dụng phân vùng tương đương và giá trị biên

| Tên trường | Ràng buộc nghiệp vụ và kỹ thuật | Phân vùng hợp lệ và Giá trị đại diện | Phân vùng không hợp lệ và Giá trị đại diện | Các giá trị biên cần kiểm thử |
| :--- | :--- | :--- | :--- | :--- |
| **Phương thức thu thập** | - Kiểu: `Enum`<br>- Bắt buộc chọn 1 trong 2 phương thức:<br>  + Quét tự động DOM trang web<br>  + Tải lên tệp tin CV | - Phân vùng hợp lệ:<br>  + `Quét tự động DOM`<br>  + `Upload file CV` | - Phân vùng không hợp lệ:<br>  + Không chọn phương thức nào (`null`)<br>  + Gửi mã phương thức lạ (`API_IMPORT`) | - Không áp dụng giá trị biên (Trường lựa chọn hữu hạn) |
| **URL trang web quét dữ liệu** | - Kiểu: `String / URL`<br>- Bắt buộc khi dùng phương thức Quét DOM<br>- Domain hợp lệ: `linkedin.com/in/*`, `topcv.vn/*`, `vietnamworks.com/*`<br>- Độ dài: $10 \le L \le 2000$ ký tự | - Phân vùng hợp lệ:<br>  + `https://www.linkedin.com/in/nguyenvana`<br>  + `https://topcv.vn/profile/tranvanb`<br>  + `https://vietnamworks.com/ung-vien/lethic` | - Phân vùng không hợp lệ:<br>  + Domain lạ: `https://facebook.com/user1`<br>  + URL sai cú pháp: `htt://invalid-url`<br>  + URL rỗng: `""`<br>  + URL vượt 2000 ký tự | - Biên dưới độ dài:<br>  + $L = 9$ (Lỗi)<br>  + $L = 10$ (Hợp lệ)<br>  + $L = 11$ (Hợp lệ)<br>- Biên trên độ dài:<br>  + $L = 1999$ (Hợp lệ)<br>  + $L = 2000$ (Hợp lệ)<br>  + $L = 2001$ (Lỗi URL quá dài) |
| **Tệp tin CV tải lên** | - Kiểu: `Binary File Blob`<br>- Bắt buộc khi dùng phương thức Upload<br>- Định dạng cho phép: `.pdf`, `.docx`, `.doc`, `.png`, `.jpg`, `.jpeg`<br>- Cấm: `.exe`, `.bat`, `.zip`, `.rar`, `.xlsx`, tệp không đuôi hoặc đuôi kép<br>- Dung lượng: $0 < S \le 10\text{ MB}$ ($10,240\text{ KB}$) | - Phân vùng hợp lệ:<br>  + Tệp PDF: `cv_developer.pdf` (2.5 MB)<br>  + Tệp Word: `cv_backend.docx` (1.2 MB)<br>  + Tệp Ảnh: `cv_scan.png` (850 KB) | - Phân vùng không hợp lệ:<br>  + File `.exe`: `trojan.exe` (1.0 MB)<br>  + File nén: `cv_all.zip` (3.0 MB)<br>  + Bảng tính: `bang_diem.xlsx` (500 KB)<br>  + Tệp rỗng: `empty.pdf` (0 Byte)<br>  + Quá 10MB: `cv_heavy.pdf` (15.0 MB)<br>  + Đuôi kép: `cv_hack.pdf.exe` | - Biên dưới dung lượng:<br>  + $S = 0\text{ Byte}$ (Lỗi file rỗng)<br>  + $S = 1\text{ Byte}$ (Hợp lệ)<br>  + $S = 2\text{ Bytes}$ (Hợp lệ)<br>- Biên trên dung lượng:<br>  + $S = 10,239\text{ KB}$ (Hợp lệ)<br>  + $S = 10,240\text{ KB}$ (10 MB chuẩn - Hợp lệ)<br>  + $S = 10,241\text{ KB}$ (Lỗi quá 10MB EX_01) |
| **Họ và tên ứng viên** | - Kiểu: `String`<br>- Bắt buộc phải có khi lưu hồ sơ<br>- Độ dài: $2 \le L \le 100$ ký tự<br>- Chữ cái tiếng Việt, tiếng Anh, khoảng trắng. Cấm chữ số, ký tự đặc biệt nguy hiểm, mã độc XSS/HTML | - Phân vùng hợp lệ:<br>  + `"Nguyễn Văn An"`<br>  + `"Lê Thị Mai Loan"`<br>  + `"Johnathan Edward Doe"` | - Phân vùng không hợp lệ:<br>  + Để trống: `""`<br>  + Chứa chữ số: `"Nguyen Van 123"`<br>  + Ký tự lạ: `"Tran @#$ Nam"`<br>  + Mã độc: `<script>alert('XSS')</script>`<br>  + Quá ngắn (< 2 ký tự)<br>  + Quá dài (> 100 ký tự) | - Biên dưới độ dài:<br>  + $L = 1$: `"A"` (Lỗi quá ngắn)<br>  + $L = 2$: `"An"` (Hợp lệ tối thiểu)<br>  + $L = 3$: `"Hoa"` (Hợp lệ)<br>- Biên trên độ dài:<br>  + $L = 99$ ký tự (Hợp lệ)<br>  + $L = 100$ ký tự (Hợp lệ tối đa)<br>  + $L = 101$ ký tự (Lỗi vượt giới hạn) |
| **Vị trí / Chức danh công việc** | - Kiểu: `String`<br>- Không bắt buộc (Tuỳ chọn)<br>- Độ dài: $0 \le L \le 150$ ký tự<br>- Chống chèn mã HTML độc hại | - Phân vùng hợp lệ:<br>  + `"Senior Fullstack Developer"`<br>  + `"Chuyên viên Tuyển dụng IT"`<br>  + Để trống: `""` | - Phân vùng không hợp lệ:<br>  + Quá 150 ký tự<br>  + Chứa script: `<iframe src="...">` | - Biên trên độ dài:<br>  + $L = 149$ ký tự (Hợp lệ)<br>  + $L = 150$ ký tự (Hợp lệ)<br>  + $L = 151$ ký tự (Cắt ngắn hoặc báo lỗi) |
| **Số năm kinh nghiệm** | - Kiểu: `Float / Number`<br>- Không bắt buộc<br>- Giá trị số thực không âm: $0.0 \le \text{Exp} \le 50.0$ năm | - Phân vùng hợp lệ:<br>  + $0.0$ (Mới tốt nghiệp/Fresher)<br>  + $2.5$ năm<br>  + $10.0$ năm | - Phân vùng không hợp lệ:<br>  + Số âm: $-1.0$<br>  + Quá lớn: $60.0$ năm<br>  + Chuỗi chữ: `"ba năm"` | - Biên dưới:<br>  + $\text{Exp} = -0.1$ (Lỗi số âm)<br>  + $\text{Exp} = 0.0$ (Hợp lệ tối thiểu)<br>  + $\text{Exp} = 0.1$ (Hợp lệ)<br>- Biên trên:<br>  + $\text{Exp} = 49.9$ (Hợp lệ)<br>  + $\text{Exp} = 50.0$ (Hợp lệ tối đa)<br>  + $\text{Exp} = 50.1$ (Lỗi vượt 50 năm) |
| **Địa chỉ Email liên hệ** | - Kiểu: `String (Email)`<br>- Bắt buộc nếu hồ sơ không có Số điện thoại<br>- Định dạng chuẩn RFC 5322<br>- Độ dài: $6 \le L \le 100$ ký tự | - Phân vùng hợp lệ:<br>  + `nguyen.van.an@gmail.com`<br>  + `tuyendung@fpt.com.vn` | - Phân vùng không hợp lệ:<br>  + Thiếu `@`: `nguyenvana.gmail.com`<br>  + Thiếu domain: `an@.com`<br>  + Dấu cách: `an @gmail.com`<br>  + Mã SQLi: `' OR 1=1--` | - Biên dưới độ dài:<br>  + $L = 5$: `a@b.c` (Lỗi)<br>  + $L = 6$: `a@b.co` (Hợp lệ tối thiểu)<br>- Biên trên độ dài:<br>  + $L = 100$ ký tự (Hợp lệ tối đa)<br>  + $L = 101$ ký tự (Lỗi) |
| **Số điện thoại liên hệ** | - Kiểu: `String (Phone)`<br>- Bắt buộc nếu hồ sơ không có Email<br>- Đầu số di động Việt Nam (03, 05, 07, 08, 09)<br>- Độ dài cố định đúng 10 chữ số | - Phân vùng hợp lệ:<br>  + `0912345678`<br>  + `0389998888`<br>  + `0701234567` | - Phân vùng không hợp lệ:<br>  + 9 chữ số: `091234567`<br>  + 11 chữ số: `09123456789`<br>  + Chứa chữ: `09123abcde`<br>  + Đầu số cố định lạ: `0123456789` | - Biên độ dài chữ số:<br>  + 9 chữ số (Lỗi thiếu số)<br>  + 10 chữ số (Hợp lệ chuẩn)<br>  + 11 chữ số (Lỗi thừa số) |
| **Danh sách kỹ năng** | - Kiểu: `Array of Strings`<br>- Tùy chọn<br>- Tối đa 50 kỹ năng, mỗi kỹ năng tối đa 50 ký tự | - Phân vùng hợp lệ:<br>  + `["ReactJS", "Node.js", "Docker"]`<br>  + Mảng rỗng: `[]` | - Phân vùng không hợp lệ:<br>  + Kỹ năng chứa script: `<script>`<br>  + Danh sách vượt quá 50 kỹ năng | - Biên số lượng kỹ năng:<br>  + 0 kỹ năng (Hợp lệ)<br>  + 1 kỹ năng (Hợp lệ)<br>  + 50 kỹ năng (Hợp lệ tối đa)<br>  + 51 kỹ năng (Lỗi/chặn bớt) |
| **Thời gian phản hồi AI / DOM** | - Kiểu: `Duration (Giây)`<br>- Ngưỡng tối đa cho phép: $10.0$ giây | - Phân vùng hợp lệ:<br>  + $0.1\text{s} \le T \le 10.0\text{s}$ (Thành công) | - Phân vùng không hợp lệ:<br>  + $T > 10.0\text{s}$ (Timeout EX_02) | - Biên thời gian:<br>  + $T = 9.9\text{s}$ (Hợp lệ)<br>  + $T = 10.0\text{s}$ (Hợp lệ tối đa)<br>  + $T = 10.1\text{s}$ (Ngắt kết nối, kích hoạt EX_02) |

---

## 3. PHÂN TÍCH QUAN HỆ CHÉO VÀ LOGIC NGHIỆP VỤ

### 1. Ràng buộc phụ thuộc giữa các trường dữ liệu
1. **Phụ thuộc giữa Phương thức thu thập và Trường dữ liệu tương ứng:**
   - Khi `Phương thức = Quét tự động DOM` $\rightarrow$ Bắt buộc trường `URL trang web` phải hợp lệ thuộc danh sách hỗ trợ (`linkedin.com/in/*`, `topcv.vn/*`, `vietnamworks.com/*`). Trường `Tệp CV tải lên` không được kích hoạt.
   - Khi `Phương thức = Upload file CV` $\rightarrow$ Bắt buộc trường `Tệp CV tải lên` phải có dữ liệu hợp lệ (định dạng `.pdf/.docx/.png` và dung lượng $\le 10\text{MB}$). Trường `URL trang web` không được kích hoạt.
2. **Quy tắc toàn vẹn thông tin định danh ứng viên:**
   - Để hoàn tất lưu hồ sơ, hệ thống bắt buộc phải có `Họ và tên` VÀ ít nhất một trong hai kênh liên lạc: `Email` HOẶC `Số điện thoại`.
   - Biểu thức logic: $\text{CanSave} = (\text{Name} \ne \emptyset) \land (\text{Email} \ne \emptyset \lor \text{Phone} \ne \emptyset)$.
   - Nếu vi phạm (thiếu cả Email và Số điện thoại) $\rightarrow$ Hệ thống tô đỏ các trường bắt buộc và khóa nút "Lưu hồ sơ".
3. **Quy tắc phát hiện trùng lặp hồ sơ:**
   - Khi chuyên viên bấm "Lưu hồ sơ", hệ thống tự động kiểm tra đối chiếu `Email` và `Số điện thoại` trong CSDL:
     + Nếu chưa tồn tại $\rightarrow$ Tạo mới hồ sơ với trạng thái "Mới".
     + Nếu đã tồn tại $\rightarrow$ Bật hộp thoại cảnh báo: *"Hồ sơ ứng viên đã tồn tại trong hệ thống. Bạn có muốn cập nhật đè hay tạo bản ghi mới?"*.
4. **Ràng buộc tương tranh và chống spam request:**
   - Nút "Lưu hồ sơ" tự động chuyển sang trạng thái disabled (vô hiệu hóa) ngay sau khi nhận cú click đầu tiên và hiển thị spinner loading cho đến khi nhận phản hồi từ CSDL.

### 2. Bảng quyết định cho tổ hợp logic nghiệp vụ

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

### 3. Phân tích điều kiện tiên quyết và hậu điều kiện
- **Điều kiện tiên quyết (Pre-conditions):**
  - Chuyên viên tuyển dụng đã đăng nhập Extension (Token JWT hợp lệ trong Extension Storage). Nếu Token hết hạn hoặc chưa đăng nhập $\rightarrow$ Chuyển hướng về màn hình Đăng nhập.
  - Kết nối Internet khả dụng. Nếu ngắt mạng $\rightarrow$ Thông báo lỗi kết nối và bảo lưu dữ liệu đang nhập trên giao diện.
- **Hậu điều kiện (Post-conditions):**
  - Khi lưu thành công: Bản ghi ứng viên mới được thêm vào bảng `Candidates` trong CSDL với trạng thái ban đầu là "Mới".
  - Dashboard cập nhật số lượng hồ sơ mới thu thập thêm $+1$.
  - Mẫu xem trước đóng lại và quay về trạng thái sẵn sàng.

### 4. Sơ đồ và bảng chuyển trạng thái

```mermaid
stateDiagram-v2
    [*] --> S0_ChuaDangNhap
    S0_ChuaDangNhap --> S1_SanSang : Đăng nhập thành công
    S1_SanSang --> S2_DangQuetDOM : Bấm nút "Quét" (Domain hợp lệ)
    S1_SanSang --> S11_LoiEX03 : Bấm nút "Quét" (Domain lạ)
    S1_SanSang --> S4_DangXuLyAI : Upload tệp hợp lệ (<= 10MB)
    S1_SanSang --> S9_LoiEX01 : Upload tệp lỗi (.exe / > 10MB)
    S2_DangQuetDOM --> S5_FormXemTruoc : Quét xong (T <= 10s)
    S2_DangQuetDOM --> S10_LoiEX02 : Quá 10s (Timeout)
    S4_DangXuLyAI --> S5_FormXemTruoc : OCR/LLM xong (T <= 10s)
    S4_DangXuLyAI --> S10_LoiEX02 : Máy chủ AI timeout (> 10s)
    S5_FormXemTruoc --> S7_DangLuuCSDL : Bấm "Lưu hồ sơ" (Dữ liệu hợp lệ)
    S5_FormXemTruoc --> S1_SanSang : Bấm "Hủy bỏ"
    S7_DangLuuCSDL --> S8_LuuThanhCong : Database phản hồi thành công
    S8_LuuThanhCong --> S1_SanSang : Đóng thông báo
    S9_LoiEX01 --> S1_SanSang : Chọn lại tệp khác
    S10_LoiEX02 --> S5_FormXemTruoc : Mở Form rỗng cho nhập tay
    S11_LoiEX03 --> S1_SanSang : Đóng cảnh báo
```

| Trạng thái hiện tại | Sự kiện kích hoạt | Điều kiện bảo vệ | Trạng thái tiếp theo | Hành động thực hiện |
| :--- | :--- | :--- | :--- | :--- |
| `S0_ChuaDangNhap` | Mở Extension | Chưa có token hợp lệ | `S0_ChuaDangNhap` | Hiển thị màn hình đăng nhập |
| `S0_ChuaDangNhap` | Đăng nhập thành công | Tài khoản hợp lệ | `S1_SanSang` | Lưu Token JWT, hiển thị giao diện chính |
| `S1_SanSang` | Nhấn nút "Quét" | Trang thuộc LinkedIn/TopCV | `S2_DangQuetDOM` | Kích hoạt trích xuất cấu trúc DOM |
| `S1_SanSang` | Nhấn nút "Quét" | Trang web lạ không hỗ trợ | `S11_LoiEX03` | Xuất thông báo lỗi ngoại lệ EX_03 |
| `S1_SanSang` | Kéo thả tệp CV | Định dạng hợp lệ và dung lượng $\le 10\text{MB}$ | `S4_DangXuLyAI` | Tải tệp lên máy chủ OCR/LLM |
| `S1_SanSang` | Kéo thả tệp CV | Tệp `.exe` hoặc dung lượng $> 10\text{MB}$ | `S9_LoiEX01` | Chặn tệp, hiển thị lỗi EX_01 |
| `S2_DangQuetDOM` | Xử lý hoàn tất | Thời gian $T \le 10.0\text{s}$ | `S5_FormXemTruoc` | Đổ dữ liệu trích xuất vào Form xem trước |
| `S2_DangQuetDOM` | Hết thời gian chờ | Thời gian $T > 10.0\text{s}$ | `S10_LoiEX02` | Ngắt kết nối, báo lỗi EX_02, mở Form trống |
| `S4_DangXuLyAI` | Phân tích xong | Thời gian $T \le 10.0\text{s}$ | `S5_FormXemTruoc` | Hiển thị Form với thông tin trích xuất |
| `S4_DangXuLyAI` | Quá thời gian | Thời gian $T > 10.0\text{s}$ | `S10_LoiEX02` | Báo lỗi gián đoạn AI, mở Form trống nhập tay |
| `S5_FormXemTruoc` | Nhấn "Lưu hồ sơ" | Có Họ tên và (Email hoặc SĐT) | `S7_DangLuuCSDL` | Gửi request lưu dữ liệu vào CSDL |
| `S5_FormXemTruoc` | Nhấn "Hủy bỏ" | Người dùng xác nhận hủy | `S1_SanSang` | Đóng Form, dọn dẹp bộ nhớ tạm |
| `S7_DangLuuCSDL` | CSDL phản hồi | Lưu thành công | `S8_LuuThanhCong` | Thông báo thành công, cập nhật số lượng |
| `S8_LuuThanhCong` | Đóng thông báo | Sau 2 giây hoặc bấm Đóng | `S1_SanSang` | Quay về trạng thái sẵn sàng ban đầu |

---

## 4. PHÂN TÍCH LUỒNG SỰ KIỆN

### 1. Luồng chính thành công chuẩn
- **Mục tiêu:** Thu thập thành công thông tin hồ sơ ứng viên thông qua quét DOM trực tiếp trên trang cá nhân LinkedIn/TopCV.
- **Kịch bản thực hiện:**
  1. Chuyên viên đăng nhập vào Extension trên trình duyệt Chrome.
  2. Mở trang profile ứng viên: `https://www.linkedin.com/in/nguyenvana`.
  3. Nhấn nút "Quét" hiển thị góc phải trên trang web.
  4. Extension phân tích cây DOM, trích xuất: Họ tên, Chức danh, Số năm kinh nghiệm, Kỹ năng, Học vấn trong thời gian $2.5\text{s}$.
  5. Form xem trước hiển thị với đầy đủ các trường thông tin tự động điền sẵn.
  6. Chuyên viên rà soát thông tin và nhấn nút "Lưu hồ sơ".
  7. Hệ thống lưu thành công vào CSDL, hiển thị thông báo "Lưu hồ sơ thành công" và Dashboard tăng số lượng ứng viên lên $+1$.

### 2. Các luồng thay thế và nhánh rẽ
- **Luồng thay thế B (Upload file CV):**
  1. Tại giao diện Extension, chuyên viên chuyển sang tab "Upload CV".
  2. Kéo thả tệp `cv_fullstack.pdf` (dung lượng 2.5 MB) vào Drop Zone.
  3. Hệ thống kiểm tra hợp lệ và gửi tệp lên máy chủ OCR kết hợp LLM.
  4. Sau $4.2\text{s}$, máy chủ trả về dữ liệu chuẩn hóa và hiển thị trên Form xem trước.
  5. Chuyên viên kiểm tra và nhấn "Lưu hồ sơ" $\rightarrow$ Lưu thành công vào CSDL.
- **Luồng nhánh 3a (Chỉnh sửa thông tin xem trước):**
  - Chuyên viên phát hiện số điện thoại bị trích xuất thiếu 1 số $\rightarrow$ Tự tay sửa lại số điện thoại trên Form xem trước $\rightarrow$ Nhấn "Lưu hồ sơ" $\rightarrow$ CSDL lưu chính xác dữ liệu đã sửa.
- **Luồng nhánh 3b (Hủy bỏ lưu hồ sơ):**
  - Chuyên viên xem thông tin trên Form xem trước và nhận thấy ứng viên không liên quan $\rightarrow$ Nhấn nút "Hủy bỏ" hoặc biểu tượng đóng (X) $\rightarrow$ Form đóng lại, không có bản ghi nào được ghi vào CSDL.

### 3. Các luồng ngoại lệ và xử lý sự cố
- **Ngoại lệ EX_01 (Tệp tải lên không hợp lệ hoặc quá 10MB):**
  - Người dùng tải lên tệp `virus.exe` hoặc tệp `cv_huge.pdf` (dung lượng 15.0 MB).
  - Hệ thống chặn ngay tại tầng Client, hiển thị thông báo lỗi: *"Định dạng file không hỗ trợ hoặc dung lượng quá lớn"*, giữ nguyên vùng tải lên để người dùng chọn lại tệp khác.
- **Ngoại lệ EX_02 (Timeout quá 10 giây khi xử lý AI / DOM):**
  - Máy chủ trích xuất phản hồi chậm quá $10.0$ giây.
  - Hệ thống ngắt kết nối an toàn, hiển thị thông báo: *"Kết nối đến máy chủ AI bị gián đoạn"*, đồng thời tự động mở Form trống để người dùng nhập tay thông tin.
- **Ngoại lệ EX_03 (Trang web không hỗ trợ quét):**
  - Người dùng nhấn nút "Quét" trên trang `https://facebook.com/messages` hoặc trang chủ tìm việc không có cấu trúc hồ sơ cá nhân.
  - Hệ thống hiển thị thông báo: *"Extension chưa hỗ trợ cấu trúc trang web này. Vui lòng nhập tay hoặc Upload file"*.
- **Ngoại lệ mất kết nối mạng:**
  - Trong quá trình gửi dữ liệu lưu lên CSDL, kết nối Internet bị mất.
  - Hệ thống báo lỗi kết nối và giữ nguyên dữ liệu trên Form xem trước để người dùng thử lưu lại khi có mạng.

---

## 5. BẢNG CA KIỂM THỬ CHI TIẾT TỔNG HỢP

| Test Case ID | Module / Feature | Test Type | Pre-conditions | Test Steps | Test Data | Expected Result | Priority |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :---: |
| `TC_UC06_001` | Thu thập hồ sơ / Quét DOM | Business Logic | Đã đăng nhập Extension, mở trang profile LinkedIn | 1. Nhấn nút "Quét"<br>2. Chờ trích xuất DOM<br>3. Kiểm tra Form xem trước<br>4. Nhấn "Lưu hồ sơ" | URL: `https://www.linkedin.com/in/nguyenvana` (Hồ sơ đầy đủ) | Trích xuất chuẩn xác họ tên, chức danh; Form điền đúng dữ liệu; CSDL lưu thành công bản ghi mới với trạng thái "Mới" | High |
| `TC_UC06_002` | Thu thập hồ sơ / Quét DOM | Business Logic | Đã đăng nhập Extension, mở trang hồ sơ TopCV | 1. Nhấn nút "Quét"<br>2. Chờ trích xuất dữ liệu<br>3. Rà soát Form xem trước<br>4. Nhấn "Lưu hồ sơ" | URL: `https://topcv.vn/profile/tran-thi-b` | Điền đúng các trường thông tin; lưu CSDL thành công; Dashboard tăng số lượng ứng viên $+1$ | High |
| `TC_UC06_003` | Thu thập hồ sơ / Quét DOM | Business Logic | Đã đăng nhập Extension, mở trang hồ sơ VietnamWorks | 1. Nhấn nút "Quét"<br>2. Chờ trích xuất DOM<br>3. Nhấn "Lưu hồ sơ" | URL: `https://vietnamworks.com/ung-vien/le-van-c` | Trích xuất chính xác dữ liệu; lưu CSDL thành công | High |
| `TC_UC06_004` | Thu thập hồ sơ / Quét DOM | Field Validation | Đang ở profile LinkedIn chỉ có Tên và Chức danh, không có Kinh nghiệm | 1. Nhấn nút "Quét"<br>2. Quan sát Form xem trước<br>3. Nhập bổ sung số năm kinh nghiệm<br>4. Nhấn "Lưu hồ sơ" | Họ tên: `"Trần Nam"`, Exp: Nhập tay `3.0` | Form điền sẵn phần có dữ liệu; trường thiếu để trống cho nhập tay; lưu CSDL thành công | Medium |
| `TC_UC06_005` | Thu thập hồ sơ / Form xem trước | Business Logic | Form xem trước đang mở với dữ liệu quét được | 1. Sửa lại Họ tên và Số điện thoại<br>2. Nhấn nút "Lưu hồ sơ" | Tên mới: `"Nguyễn Văn An Khang"`, SĐT mới: `0988776655` | CSDL cập nhật và lưu chính xác thông tin mới do chuyên viên chỉnh sửa | Medium |
| `TC_UC06_006` | Thu thập hồ sơ / Form xem trước | UI | Đang hiển thị Form xem trước | 1. Nhấn nút "Hủy bỏ" hoặc biểu tượng đóng (X) | Thao tác nhấn Hủy | Form xem trước đóng lại; không có bản ghi rác nào được lưu vào CSDL; quay về trạng thái sẵn sàng | Medium |
| `TC_UC06_007` | Thu thập hồ sơ / Form xem trước | Security | Form xem trước đã điền đủ dữ liệu | 1. Nhấn liên tiếp 5 lần vào nút "Lưu hồ sơ" trong 1 giây | Thao tác double click / spam click | Nút Lưu bị khóa disabled ngay lần bấm đầu tiên; chỉ gửi đúng 1 request lên server và tạo 1 bản ghi duy nhất | High |
| `TC_UC06_008` | Thu thập hồ sơ / Upload CV | Field Validation | Tại tab Upload CV của Extension | 1. Kéo thả tệp PDF vào khu vực Drop Zone<br>2. Chờ OCR/LLM xử lý | Tệp `CV_Fullstack.pdf` (Dung lượng 2.5 MB) | Tiếp nhận tệp; OCR trích xuất thành công; tự động hiển thị Form xem trước với dữ liệu đã điền | High |
| `TC_UC06_009` | Thu thập hồ sơ / Upload CV | Field Validation | Tại tab Upload CV của Extension | 1. Chọn tệp Word từ hộp thoại tệp tin<br>2. Chờ AI xử lý | Tệp `CV_Backend.docx` (Dung lượng 1.2 MB) | Đọc văn bản Word; bóc tách thực thể chính xác; hiển thị Form xem trước | High |
| `TC_UC06_010` | Thu thập hồ sơ / Upload CV | Field Validation | Tại tab Upload CV của Extension | 1. Kéo thả tệp ảnh CV vào khu vực tải lên<br>2. Chờ AI xử lý | Tệp `CV_Scan.png` (Dung lượng 3.8 MB) | Kích hoạt OCR nhận diện chữ tiếng Việt; trích xuất thực thể và hiển thị Form xem trước | High |
| `TC_UC06_011` | Thu thập hồ sơ / Upload CV | UI | Tại tab Upload CV | 1. Kéo tệp từ màn hình vào khu vực Drop Zone<br>2. Thả chuột | Tệp `CV_Mau.pdf` (1.0 MB) | Khu vực nhận tệp đổi hiệu ứng màu sắc nổi bật; tiếp nhận tệp bình thường | Medium |
| `TC_UC06_012` | Thu thập hồ sơ / Upload CV | UI | Tại tab Upload CV | 1. Nhấn vào vùng tải lên<br>2. Chọn tệp từ File Dialog hệ điều hành | Tệp `CV_Mau.pdf` | Hộp thoại chọn tệp mở ra; chọn tệp thành công và gửi đi xử lý | Medium |
| `TC_UC06_013` | Thu thập hồ sơ / Upload CV | Field Validation | Tại tab Upload CV | 1. Chọn tệp PDF dung lượng nhỏ nhất hợp lệ | Tệp `CV_Tiny.pdf` (Kích thước 1,024 Bytes = 1 KB) | Hệ thống tiếp nhận bình thường; xử lý trích xuất thành công | Medium |
| `TC_UC06_014` | Thu thập hồ sơ / Upload CV | Field Validation | Tại tab Upload CV | 1. Tải lên tệp PDF dung lượng cận biên trên | Tệp `CV_Large.pdf` (Kích thước 10,137 KB = 9.9 MB) | Hệ thống tiếp nhận; tải lên hoàn tất và trích xuất thành công | High |
| `TC_UC06_015` | Thu thập hồ sơ / Upload CV | Field Validation | Tại tab Upload CV | 1. Tải lên tệp PDF dung lượng đúng ngưỡng tối đa | Tệp `CV_Max.pdf` (Kích thước chính xác 10,240 KB = 10.0 MB) | Tiếp nhận thành công; không báo lỗi; gửi lên máy chủ AI phân tích | High |
| `TC_UC06_016` | Thu thập hồ sơ / Upload CV | Field Validation | Tại tab Upload CV | 1. Chọn tệp PDF dung lượng vượt biên trên tối thiểu | Tệp `CV_Over.pdf` (Kích thước 10,250 KB = 10.01 MB) | Chặn ngay tại Client; hiển thị thông báo lỗi ngoại lệ EX_01: "Định dạng file không hỗ trợ hoặc dung lượng quá lớn" | High |
| `TC_UC06_017` | Thu thập hồ sơ / Upload CV | Field Validation | Tại tab Upload CV | 1. Kéo thả tệp dung lượng cực lớn vào Drop Zone | Tệp `CV_Huge.pdf` (Dung lượng 50.0 MB) | Từ chối tiếp nhận tải lên; hiển thị lỗi EX_01 rõ ràng | Medium |
| `TC_UC06_018` | Thu thập hồ sơ / Upload CV | Field Validation | Tại tab Upload CV | 1. Tải lên tệp rỗng 0 Byte | Tệp `CV_Empty.pdf` (Kích thước 0 Byte) | Chặn tải lên; báo lỗi: "File rỗng, vui lòng chọn file hợp lệ" | Medium |
| `TC_UC06_019` | Thu thập hồ sơ / Upload CV | Security | Tại tab Upload CV | 1. Tải lên tệp thực thi độc hại giả mạo CV | Tệp `CV_Trojan.exe` (Dung lượng 1.5 MB) | Chặn ngay lập tức; báo lỗi ngoại lệ EX_01; không cho phép tải lên server | High |
| `TC_UC06_020` | Thu thập hồ sơ / Upload CV | Security | Tại tab Upload CV | 1. Tải lên tệp thực thi hệ điều hành Linux/Mac | Tệp `install.sh` (Kích thước 4 KB) | Chặn ngay lập tức; báo lỗi định dạng không hỗ trợ EX_01 | High |
| `TC_UC06_021` | Thu thập hồ sơ / Upload CV | Field Validation | Tại tab Upload CV | 1. Tải lên tệp nén | Tệp `All_CV.zip` (Dung lượng 3.0 MB) | Báo lỗi định dạng không hỗ trợ EX_01 | Medium |
| `TC_UC06_022` | Thu thập hồ sơ / Upload CV | Field Validation | Tại tab Upload CV | 1. Tải lên tệp bảng tính Excel | Tệp `DanhSach.xlsx` (Dung lượng 500 KB) | Báo lỗi định dạng không hỗ trợ EX_01 | Medium |
| `TC_UC06_023` | Thu thập hồ sơ / Upload CV | Security | Tại tab Upload CV | 1. Tải lên tệp ngụy trang đuôi kép độc hại | Tệp `CV_NguyenVanA.pdf.exe` (Dung lượng 2.0 MB) | Kiểm tra byte header thực tế; chặn tải lên; cảnh báo tệp nguy hiểm | High |
| `TC_UC06_024` | Thu thập hồ sơ / Upload CV | Security | Tại tab Upload CV | 1. Đổi đuôi tệp virus `.exe` thành `.pdf` rồi tải lên | Tệp thực thi đổi tên: `Trojan.pdf` (Dung lượng 2.0 MB) | Kiểm tra MIME type/Magic bytes; phát hiện sai cấu trúc PDF; từ chối tệp | High |
| `TC_UC06_025` | Thu thập hồ sơ / Upload CV | Field Validation | Tại tab Upload CV | 1. Tải lên tệp không có phần mở rộng | Tệp không đuôi: `CV_NguyenVanA` | Chặn tải lên; yêu cầu tệp có định dạng hỗ trợ | Low |
| `TC_UC06_026` | Thu thập hồ sơ / Quét DOM | Integration | Mở trang Facebook cá nhân | 1. Nhấn nút "Quét" trên Extension | URL: `https://facebook.com/profile.php?id=123` | Hiển thị thông báo ngoại lệ EX_03: "Extension chưa hỗ trợ cấu trúc trang web này. Vui lòng nhập tay hoặc Upload file" | High |
| `TC_UC06_027` | Thu thập hồ sơ / Quét DOM | Integration | Mở trang tin tức tổng hợp | 1. Nhấn nút "Quét" | URL: `https://vnexpress.net` | Báo lỗi ngoại lệ EX_03; không thực hiện trích xuất dữ liệu rác | Medium |
| `TC_UC06_028` | Thu thập hồ sơ / Quét DOM | Integration | Mở trang chủ LinkedIn (Bảng tin chung, không phải Profile) | 1. Nhấn nút "Quét" | URL: `https://www.linkedin.com/feed/` | Báo lỗi không nhận diện được cấu trúc hồ sơ cá nhân (EX_03) | Medium |
| `TC_UC06_029` | Thu thập hồ sơ / Quét DOM | Integration | Mở trang tìm kiếm việc làm TopCV | 1. Nhấn nút "Quét" | URL: `https://topcv.vn/tim-viec-lam` | Báo lỗi ngoại lệ EX_03; hướng dẫn chuyên viên mở trang hồ sơ ứng viên | Medium |
| `TC_UC06_030` | Thu thập hồ sơ / Xử lý ngoại lệ | Integration | Máy chủ AI đang bị nghẽn (Thời gian phản hồi > 10.0s) | 1. Tải lên tệp CV hợp lệ<br>2. Chờ đồng hồ đếm lùi quá 10 giây | Tệp `CV_PhucTap.pdf` (Xử lý mất 12s) | Ngắt kết nối tại mốc 10.0s; kích hoạt ngoại lệ EX_02: "Kết nối đến máy chủ AI bị gián đoạn"; tự động mở Form trống nhập tay | High |
| `TC_UC06_031` | Thu thập hồ sơ / Xử lý ngoại lệ | Integration | Mạng chập chờn khi quét DOM profile | 1. Bấm nút "Quét"<br>2. Phản hồi DOM kéo dài quá 10 giây | Trang web phản hồi chậm (> 10s) | Báo lỗi timeout EX_02; hiển thị Form trống để người dùng tự nhập | High |
| `TC_UC06_032` | Thu thập hồ sơ / Xử lý ngoại lệ | Integration | Mạng Internet bị ngắt đột ngột ngay khi nhấn "Quét" | 1. Ngắt kết nối WiFi<br>2. Nhấn nút "Quét" | Không có kết nối mạng | Hiển thị thông báo: "Lỗi kết nối mạng, vui lòng kiểm tra Internet và thử lại" | High |
| `TC_UC06_033` | Thu thập hồ sơ / Form xem trước | Field Validation | Form xem trước đang mở | 1. Xóa sạch trường Họ tên<br>2. Nhấn nút "Lưu hồ sơ" | Họ tên: `""` (Rỗng), Email: `an@gmail.com` | Chặn lưu; viền đỏ trường Họ tên; thông báo: "Vui lòng nhập họ và tên ứng viên" | High |
| `TC_UC06_034` | Thu thập hồ sơ / Form xem trước | Field Validation | Form xem trước đang mở | 1. Nhập họ tên chỉ có 1 ký tự<br>2. Nhấn "Lưu hồ sơ" | Họ tên: `"A"`, Email: `an@gmail.com` | Báo lỗi: "Họ và tên phải có tối thiểu 2 ký tự" | Medium |
| `TC_UC06_035` | Thu thập hồ sơ / Form xem trước | Field Validation | Form xem trước đang mở | 1. Xóa sạch cả Email và Số điện thoại<br>2. Nhấn "Lưu hồ sơ" | Họ tên: `"Lê Văn B"`, Email: `""`, SĐT: `""` | Báo lỗi: "Vui lòng nhập ít nhất một kênh liên lạc (Email hoặc Số điện thoại)" | High |
| `TC_UC06_036` | Thu thập hồ sơ / Form xem trước | Security | Form xem trước đang mở | 1. Nhập mã script XSS vào trường Họ tên và Kỹ năng<br>2. Nhấn "Lưu hồ sơ" | Họ tên: `<script>alert('XSS')</script>`, Kỹ năng: `<img src=x onerror=alert(1)>` | Hệ thống tự động làm sạch (Sanitize) dữ liệu; lưu dưới dạng text an toàn; không kích hoạt script | High |
| `TC_UC06_037` | Thu thập hồ sơ / Form xem trước | Business Logic | Form xem trước đang mở | 1. Nhập thông tin ứng viên có Email đã có trong CSDL<br>2. Nhấn "Lưu hồ sơ" | Email: `da_ton_tai@gmail.com` | Hiển thị hộp thoại cảnh báo: "Hồ sơ ứng viên đã tồn tại trong hệ thống. Bạn có muốn cập nhật đè không?" | High |
| `TC_UC06_038` | Thu thập hồ sơ / Form xem trước | Business Logic | Mở Extension nhưng Token đăng nhập đã hết hạn | 1. Nhấn nút "Quét" hoặc chọn Upload CV | Token JWT hết hạn | Chuyển hướng ngay về màn hình Đăng nhập; yêu cầu chuyên viên đăng nhập lại | High |

---

## 6. ĐÁNH GIÁ ĐỘ BAO PHỦ VÀ KẾT LUẬN USE CASE 06

### 1. Ma trận bao phủ các phương pháp kiểm thử hộp đen

| Phương pháp kiểm thử | Số lượng ca kiểm thử bao phủ | Danh sách các Test Case tương ứng | Tỷ lệ bao phủ (%) |
| :--- | :---: | :--- | :---: |
| **Phân vùng tương đương** | 18 ca | `TC_UC06_001` - `TC_UC06_004`, `TC_UC06_008` - `TC_UC06_012`, `TC_UC06_021`, `TC_UC06_022`, `TC_UC06_026` - `TC_UC06_029`, `TC_UC06_033`, `TC_UC06_035` | 47.4% |
| **Phân tích giá trị biên** | 9 ca | `TC_UC06_013` - `TC_UC06_018`, `TC_UC06_025`, `TC_UC06_030`, `TC_UC06_034` | 23.7% |
| **Bảng quyết định** | 8 ca | `TC_UC06_001`, `TC_UC06_008`, `TC_UC06_016`, `TC_UC06_019`, `TC_UC06_026`, `TC_UC06_030`, `TC_UC06_035`, `TC_UC06_037` | 21.1% |
| **Kiểm thử chuyển trạng thái** | 7 ca | `TC_UC06_005`, `TC_UC06_006`, `TC_UC06_007`, `TC_UC06_011`, `TC_UC06_031`, `TC_UC06_032`, `TC_UC06_038` | 18.4% |
| **Bảo mật và đoán lỗi** | 6 ca | `TC_UC06_007`, `TC_UC06_019`, `TC_UC06_020`, `TC_UC06_023`, `TC_UC06_024`, `TC_UC06_036` | 15.8% |

*(Ghi chú: Một số Test Case kết hợp nhiều kỹ thuật để tối ưu hóa độ bao phủ nghiệp vụ và rủi ro thực tế).*

### 2. Kết luận đánh giá chất lượng bộ kiểm thử USE CASE 06
- **Độ bao phủ nghiệp vụ:** Đạt **100%** các luồng sự kiện (Luồng chính, Luồng thay thế B, Luồng 3a, Luồng 3b) và toàn bộ 3 mã ngoại lệ (`EX_01`, `EX_02`, `EX_03`).
- **Độ bao phủ dữ liệu & biên:** Đã kiểm thử triệt để các biên dung lượng tệp ($0\text{ B}, 1\text{ KB}, 9.9\text{ MB}, 10.0\text{ MB}, 10.01\text{ MB}, 50\text{ MB}$), biên thời gian ($10.0\text{s}$) và biên độ dài trường ký tự.
- **Tính khả thi thực thi:** Dữ liệu thử nghiệm cụ thể 100%, các bước rõ ràng, tiêu chí pass/fail minh bạch, sẵn sàng import vào Jira/Xray và bàn giao cho đội ngũ kiểm thử thực thi.
