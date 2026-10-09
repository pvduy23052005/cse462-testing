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
