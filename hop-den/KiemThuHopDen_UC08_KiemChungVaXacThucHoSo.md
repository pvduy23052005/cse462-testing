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
