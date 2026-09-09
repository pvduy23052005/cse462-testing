KIỂM THỬ
VÀ
ĐẢM BẢO
CHẤT LƯỢNG
PHẦN MỀM

Giới thiệu môn học
• Tên môn học: Kiểm thử và đảm bảo chất lượng phần mềm
• Tên tiếng anh: Software testing and quality assurance
| • Mã | số: CSE462  |                  |     |             |     |
| ----- | ------------ | ---------------- | --- | ----------- | --- |
| • Số | tín chỉ: 3 |                  |     |             |     |
| • Số | tiết: 30    | lý thuyết + 15 |     | thực hành |     |
• Bắt buộc đối với ngành KTPM (tự chọn đối với ngành CNTT)
|     |     |     | Nguyễn Thị | Phương Dung | 2   |
| --- | --- | --- | ------------ | ----------- | --- |

Nội dung học
|  Cơ sở   | kiểm thử        |                         |     |     |     |
| ---------- | ----------------- | ----------------------- | --- | --- | --- |
|  Mức độ |                   | kiểm thử              |     |     |     |
|  Các kỹ | thuật kiểm thử |                         |     |     |     |
|  Độ      | đo và            | tiến trình kiểm thử |     |     |     |

| Cơ sở                    | chất lượng phần mềm |     |                         |     |     |
| ------------------------- | ----------------------- | --- | ----------------------- | --- | --- |
|  Tiến trình quản trị |                         |     | chất lượng phần mềm |     |     |
 Kiểm định và xác nhận
 Chuẩn chất lượng phần mềm
|     |     |     | Nguyễn Thị | Phương Dung | 3   |
| --- | --- | --- | ------------ | ----------- | --- |

Chuẩn đầu ra
• Kiến thức: Nắm được các kiến thức, các kỹ thuật cơ bản trong
quy trình kiểm thử và đánh giá chất lượng phần mềm. Sử dụng
| một số | công cụ | kiểm thử |     | phần mềm tự | động |     |
| -------- | -------- | ---------- | --- | -------------- | ----- | --- |
• Kỹ năng, năng lực: Viết và trình bày các tài liệu kiểm thử, suy
| luận để | đưa ra các tình huống kiểm thử. |     |     |     |     |     |
| --------- | ------------------------------------ | --- | --- | --- | --- | --- |
• Phẩm chất, đạo đức: Có đạo đức, lương tâm nghề nghiệp, có ý
thức tổ chức kỷ luật và trách nhiệm với công việc, cộng đồng
| và xã | hội.  |     |              |             |     |     |
| ------- | ------ | --- | ------------ | ----------- | --- | --- |
|         |        |     | Nguyễn Thị | Phương Dung |     | 4   |

Hình thức đánh giá
• Quá trình: 50% (chuyên cần + bài tập trên lớp + kiểm tra + BTL)
| • Thi kết thúc học phần: 50% (trắc nghiệm + tự |                                   |              |             |     |           | luận)     |            |
| ----------------------------------------------------- | --------------------------------- | ------------ | ----------- | --- | --------- | ---------- | ---------- |
| • Cấu trúc đề                                      | thi theo thang nhận thức Bloom: |              |             |     |           |            |            |
| Mức                                                  | Nhớ                              | Hiểu        | Vận dụng  |     | Phân tích | Tổng hợp | Sáng tạo |
| Tỷ lệ (%)                                           | 25                                | 25           |             | 20  | 10        | 10         | 10         |
|                                                       |                                   | Nguyễn Thị | Phương Dung |     |           |            | 5          |

Tài liệu
• Bài giảng của giảng viên
• Dorothy Graham, Erik van Veenendaal, Isabel Evans, Rex Black,
Foundations of software testing,
• Andreas Spillner, Tilo Linz, Hans Schaefer, Software Testing
Foundations
• Kiểm Thử Nâng Cao, Tilo Linz, NXB Bách Khoa HN.
• Software Testing and Analysis: Process, Principles, and Techniques
Nguyễn Thị Phương Dung https://tinyurl.com/tailieumonKT 6

Hình thức học thụ động
• GV:
– Thuyết trình
– Làm bài tập minh họa
– Nêu vấn đề
| – Hướng dẫn SV tự |     | nghiên cứu  |     |     |
| -------------------- | --- | ------------ | --- | --- |
• SV:
– Nghe giảng
– Làm bài tập theo mẫu
– Thảo luận các vấn đề
| – Tự | nghiên cứu và | làm bài tập nâng cao |             |     |
| ----- | --------------- | ----------------------- | ----------- | --- |
|       |                 | Nguyễn Thị            | Phương Dung | 7   |

Hình thức học chủ động
• SV:
– Tìm hiểu về nội dung mà GV đã giao từ buổi trước
– Thuyết trình nội dung đã tìm
– Thảo luận về những nội dung chưa hiểu rõ
– Làm bài tập
• GV:
– Tổng kết những nội dung của SV đã tìm hiểu
– Giải đáp các thắc mắc
– Nêu vấn đề
– Hướng dẫn SV tự nghiên cứu
Nguyễn Thị Phương Dung 8

| Chương I - | Cơ sở | kiểm thử |
| ---------- | ------ | ---------- |

Nội dung
• Kiểm thử là gì?
| • Vì | sao kiểm thử | là cần thiết? |     |     |     |
| ----- | -------------- | ---------------- | --- | --- | --- |
• Các nguyên tắc trong kiểm thử
| • Quá | trình kiểm thử |     |     |     |     |
| ------ | ----------------- | --- | --- | --- | --- |
• Tâm lý học kiểm thử
|     |     |     | Nguyễn Thị | Phương Dung | 10  |
| --- | --- | --- | ------------ | ----------- | --- |

|     |     | Kiểm thử |     | là gì? |     |
| --- | --- | ---------- | --- | -------- | --- |
• Kiểm thử là một quy trình chứ không phải là một hoạt động đơn
lẻ – bao gồm một loạt các hoạt động liên quan như:
– Tất cả các hoạt động trong vòng đời phát triển phần mềm
| – Kiểm thử   | tĩnh và          | động: |             |                    |     |
| -------------- | ------------------ | ------ | ----------- | ------------------ | --- |
| • Xem xét cả | các đặc tả, mã |        | nguồn, và | phân tích tĩnh.  |     |
• Chạy thử chương trình để xem kết quả thực thi với đặc tả yêu cầu
– Xây dựng phương án kiểm thử
– Lập kế hoạch các hoạt động diễn ra trước và sau khi thử nghiệm, kiểm
soát các hoạt động thử nghiệm, viết báo cáo tiến độ và trạng thái của
phần mềm
|     |     | Nguyễn Thị | Phương Dung |     | 11  |
| --- | --- | ------------ | ----------- | --- | --- |

|       |              | Vì                                   | sao kiểm thử |     |     | là cần thiết? |     |
| ----- | ------------ | ------------------------------------- | -------------- | --- | --- | ---------------- | --- |
| • Ví | dụ một số | thảm họa do lỗi phần mềm gây ra: |                |     |     |                  |     |
o Trong những năm 1980, rất nhiều người đã tử vong do lỗi trong mã
|     | điều khiển máy xạ |     | trị | Therac-25. |     |     |     |
| --- | --------------------- | --- | ---- | ---------- | --- | --- | --- |
o 1996, tên lửa nguyên mẫu Ariane5 trị giá 1 tỷ USD đã bị phá hủy
chưa đầy 1 phút sau khi phóng do lỗi trong chương trình máy tính hoa
tiêu cài đặt trên tàu.
o 1994, 29 người thiệt mạng do lỗi điều khiển động cơ máy bay
Chinook.
o 2002, một cuộc điều tra của Bộ thương mại Mỹ cho thấy lỗi phần
|     | mềm đã | tiêu tốn khoảng 59 |     |              | tỷ USD mỗi năm. |     |     |
| --- | -------- | -------------------- | --- | ------------ | ----------------- | --- | --- |
|     |          |                      |     | Nguyễn Thị | Phương Dung       |     | 12  |

Nguyên nhân tạo ra lỗi phần mềm
• Do áp lực thời gian
• Do người tham gia dự án thiếu kinh nghiệm hoặc thiếu kỹ năng
• Do thông tin sai giữa những người tham gia dự án
• Do các độ phức tạp của mã, thiết kế, kiến trúc và các công nghệ
• Do hậu quả tiềm ẩn của các lỗi trước đó
• Do tương tác sai với phần mềm
• Do xung đột giữa các phần mềm với nhau
• Do môi trường: bức xạ, trường điện từ, ô nhiễm, …
• Do cố ý hủy hoại phần mềm
Nguyễn Thị Phương Dung 13

Thời điểm xuất hiện lỗi
Đặc tả đúng
|     | Đặc tả | đúng yêu cầu |     |     | Đặc tả | đúng yêu cầu |     |
| --- | -------- | -------------- | --- | --- | -------- | -------------- | --- |
Đặc tả sai yêu cầu
yêu cầu
Thiết kế đúng  Thiết kế đúng theo yêu  Có sai sót trong
Thiết kế đúng theo đặc tả
| theo yêu cầu |     | cầu |     |     |     | thiết kế |     |
| ------------- | --- | ---- | --- | --- | --- | ---------- | --- |
Xây dựng đúng  Mắc lỗi trong quá Xây dựng đúng với thiết
Xây dựng đúng với thiết kế
| theo thiết kế | trình xây dựng        |     |     |     |                         | kế |     |
| --------------- | ----------------------- | --- | --- | --- | ----------------------- | --- | --- |
| Sản phẩm      | Sản phẩm không đúng  |     |     |     | Sản phẩm không đúng  |     |     |
Sản phẩm không dùng được
| chuẩn |     | với thiết kế |              |             |     | với yêu cầu |     |
| ------ | --- | --------------- | ------------ | ----------- | --- | ------------- | --- |
|        |     |                 | Nguyễn Thị | Phương Dung |     |               | 14  |

| Chi phí |      | cho việc sửa lỗi       |     |                  |     |
| -------- | ---- | ------------------------- | --- | ---------------- | --- |
| • Có    | thể | dễ dàng phát hiện và |     | sửa chữa trong  |     |
Đặc tả đúng yêu cầu
| quá | trình thử |     | nghiệm  |     |     |
| ---- | ----------- | --- | -------- | --- | --- |
Thiết kế đúng theo yêu
cầu
Mắc lỗi trong quá
trình xây dựng
Sản phẩm không đúng
với thiết kế
|     | Nguyễn Thị | Phương Dung |     |     | 17  |
| --- | ------------ | ----------- | --- | --- | --- |

| Chi phí |                  | cho việc sửa lỗi |                                  |     |
| -------- | ---------------- | ------------------- | -------------------------------- | --- |
| • Khó   | phát hiện: vì |                     | đã xây dựng theo đúng thiết  |     |
Đặc tả đúng yêu cầu
kế.
| • Khó | sửa chữa: Muốn sửa chữa được đúng thì |     |     |     |
| ------ | ------------------------------------------- | --- | --- | --- |
Có sai sót trong
thiết kế phải thay đổi thiết kế
| => Chi phí |     | cao hơn  |     |     |
| ----------- | --- | -------- | --- | --- |
Xây dựng đúng với thiết
kế
Sản phẩm không đúng
với yêu cầu
|     | Nguyễn Thị | Phương Dung |     | 18  |
| --- | ------------ | ----------- | --- | --- |

| Chi phí                 |     | cho việc sửa lỗi |                       |     |
| ------------------------ | --- | ------------------- | --------------------- | --- |
| • Sản phẩm làm ra có |     | thể                | không mắc lỗi gì,  |     |
Đặc tả sai yêu cầu
nhưng không được khách hàng chấp nhận.
| • Chi phí |     | cho lỗi này là | bao nhiêu??? |     |
| ---------- | --- | ----------------- | ------------ | --- |
Thiết kế đúng theo đặc tả
Xây dựng đúng với thiết kế
Sản phẩm không dùng được
|     | Nguyễn Thị | Phương Dung |     | 19  |
| --- | ------------ | ----------- | --- | --- |

|            | Chi phí           |     | cho việc sửa lỗi |     |     |
| ---------- | ------------------ | --- | ------------------- | --- | --- |
| • Chi phí | cho việc tìm và |     | sửa lỗi           | á  |     |
i
G
tăng theo thời gian
| • Làm thế | nào để | giảm chi phí |     |     |     |
| ----------- | -------- | -------------- | --- | --- | --- |
này?
| o Sớm phát hiện ra lỗi và |     |     | thời điểm  |     |     |
| ------------------------------ | --- | --- | ------------ | --- | --- |
xảy ra lỗi
o
Xác định nguyên nhân gốc rễ của
Thời gian
lỗi.
|     |     | Nguyễn Thị | Phương Dung |     | 20  |
| --- | --- | ------------ | ----------- | --- | --- |

Nguyên nhân gốc rễ là gì?
• Ví dụ: Một cơ quan gặp sự cố liên tục bị lỗi khi in. Vậy nguyên
nhân ở đâu?
o Máy in hết nguồn cung cấp (hết mực và giấy)
o Trình điều khiển máy in bị lỗi
o Phòng in quá nóng đối với máy in và máy in bị kẹt giấy
 Đây chỉ là nguyên nhân trước mắt.
Nguyễn Thị Phương Dung 21

Phân tích nguyên nhân gốc rễ
• Nguyên nhân gốc rễ của việc máy in hết mực và giấy là gì?
– Là do không ai chịu trách nhiệm kiểm tra giấy và mực trong máy in.
• Nguyên nhân gốc rễ của việc không ai chịu trách nhiệm là gì?
– Là vì không có quy trình kiểm tra mực/ giấy in trước khi sử dụng.
• Hoặc do nhân viên không biết thay hộp mực.
– Nguyên nhân của điều này có thể là vì nhân viên không được đào tạo
hoặc hướng dẫn chăm sóc máy in.
Nguyễn Thị Phương Dung 22

Mục đích của việc chạy thử nghiệm
• Thông qua chạy thử nghiệm để tìm ra các lỗi tiềm ẩn và phân
tích nguyên nhân gốc rễ để việc khắc phục, sửa chữa được hiệu
quả hơn.
• Rút ra những bài học kinh nghiệm cho các dự án khác trong
tương lai, cải thiện quy trình, ngăn ngừa sự tái phát của các
khiếm khuyết tươnǵ tự.
=> Nên sử dụng việc thử nghiệm như một phần của chiến lược
phát triển phần mềm
Nguyễn Thị Phương Dung 23

| Vai trò | của kiểm thử |     | trong phát triển phần mềm |     |
| -------- | --------------- | --- | ----------------------------- | --- |
• Kiểm thử nghiêm ngặt giúp xác định các khuyết tật, tìm kiếm các
điểm yếu tiềm ẩn có khả năng bị tấn công, mang lại sự tin tưởng về
chất lượng của phần mềm.
• Bài kiểm thử kém có thể cho ra ít lỗi, điều này làm tăng tính chủ quan
| của đội ngũ | phát triển phần mềm. |     |     |     |
| -------------- | ------------------------ | --- | --- | --- |
• Bài kiểm thử tốt sẽ đưa ra nhiều khiếm khuyết hơn, giúp phần mềm
được sửa chữa kỹ hơn, giảm mức độ rủi ro tổng thể khi sử dụng hệ
thống.
• Kiểm thử giúp đo lường chất lượng sản phẩm thông qua kết quả đánh
giá của kiểm thử.
|     |     | Nguyễn Thị | Phương Dung | 27  |
| --- | --- | ------------ | ----------- | --- |

Chất lượng phần mềm là gì?
• Chất lượng phần mềm phụ thuộc vào việc đáp ứng các đặc điểm
kỹ thuật đã xác định thông qua sự thỏa thuận của nhà sản xuất
và khách hàng. Chất lượng có thể được đo theo các cách sau:
o Xem xét các thuộc tính của sản phẩm
o Khả năng tương thích của sản phẩm
o Dựa trên quy trình sản xuất tốt và đáp ứng các yêu cầu xác định
o Kỳ vọng về giá trị đồng tiền, khả năng chi trả và sự đánh đổi dựa trên
giá trị giữa các khía cạnh thời gian, công sức và chi phí.
Nguyễn Thị Phương Dung 28

Các nguyên tắc trong kiểm thử
| 1. Kiểm thử | chỉ ra sự | hiện diện của lỗi |     |     |
| ------------- | ----------- | --------------------- | --- | --- |
2. Kiểm thử toàn bộ, đầy đủ là không thể.
3. Cần bắt đầu giai đoạn kiểm thử càng sớm càng tốt
4. Phân nhóm lỗi để xác định một số module tập trung lỗi nhiều nhất.
| 5. Nghịch lý | thuốc trừ | sâu |     |     |
| -------------- | ---------- | --- | --- | --- |
6. Kiểm thử được thực hiện khác nhau trong những bối cảnh khác
nhau.
7. Suy nghĩ "Không có lỗi" là một sai lầm.
|     |     | Nguyễn Thị | Phương Dung | 29  |
| --- | --- | ------------ | ----------- | --- |

Quá trình kiểm thử
| • Lập kế hoạch kiểm thử |     |     |     |     |     |
| ---------------------------- | --- | --- | --- | --- | --- |
• Kiểm soát kế hoạch kiểm thử
• Phân tích và thiết kế
• Thực hiện
| • Đánh giá                  | các tiêu chí | rút lui và |             | báo cáo |     |
| ----------------------------- | -------------- | ------------ | ----------- | --------- | --- |
| • Các hoạt động đóng thử |                |              | nghiệm     |           |     |
|                               |                | Nguyễn Thị | Phương Dung |           | 30  |

Lập kế hoạch kiểm thử
• Xác định phạm vi, mục tiêu và rủi ro của kiểm thử
• Xác định cách tiếp cận tổng thể của kiểm thử
• Lập lịch trình cụ thể cho các hoạt động phân tích, thiết kế, triển
khai, thực hiện và đánh giá thử nghiệm
• Xác định tài nguyên cần thiết: con người, môi trường thử nghiệm
• Xác định tiêu chí rút lui
• Lựa chọn các số liệu để giám sát và kiểm soát thử nghiệm
• Lập ngân sách cho các hoạt động thử nghiệm
Nguyễn Thị Phương Dung 31

Kiểm soát kế hoạch kiểm thử
• Kiểm tra kết quả thử nghiệm và nhật ký theo tiêu chí phạm vi được
chỉ định
• Đánh giá mức chất lượng của thành phần hoặc hệ thống dựa trên kết
quả và nhật ký thử nghiệm
• Xác định xem có cần thêm thử nghiệm
• Báo cáo tiến độ thực tế so với kế hoạch cho các bên liên quan
Nguyễn Thị Phương Dung 32

Phân tích thử nghiệm
• Phân tích cơ sở thử nghiệm phù hợp với mức độ thử nghiệm đang
được xem xét
o Đặc tả yêu cầu (yêu cầu nghiệp vụ, yêu cầu chức năng, yêu cầu hệ thống)
o Thông tin thiết kế và triển khai
o Báo cáo phân tích rủi ro, có thể xem xét chức năng, phi chức năng và cấu
trúc các khía cạnh của thành phần hoặc hệ thống
• Đánh giá cơ sở thử nghiệm và các hạng mục thử nghiệm để xác
định các khuyết tật thuộc nhiều loại khác nhau (Sự mơ hồ, Sự thiếu
sót, Sự không nhất quán, Sự thiếu chính xác, Sự mâu thuẫn )
Nguyễn Thị Phương Dung 33

| Thiết kế |     | thử | nghiệm |     |
| ---------- | --- | ---- | ------- | --- |
• Thiết kế và ưu tiên các trường hợp thử nghiệm và tập hợp các
trường hợp thử nghiệm
• Xác định dữ liệu thử nghiệm cần thiết để hỗ trợ các điều kiện
thử nghiệm và trường hợp thử nghiệm
• Thiết kế môi trường thử nghiệm và xác định bất kỳ cơ sở hạ
tầng và công cụ cần thiết nào
|     | Nguyễn Thị | Phương Dung |     | 34  |
| --- | ------------ | ----------- | --- | --- |

Thực hiện kiểm thử
• Thực hiện tạo bộ thử nghiệm từ các kịch bản kiểm thử
• Sắp xếp các bộ kiểm thử trong lịch trình thực hiện kiểm thử sao cho kết quả đạt
mục đích cao hơn
• Xây dựng môi trường thử nghiệm
• Chuẩn bị dữ liệu thử nghiệm và đảm bảo dữ liệu được tải đúng cách trong môi
trường thử nghiệm
• Thực thi các bộ thử nghiệm, ghi lại kết quả thử nghiệm, phiên bản phần mềm,
công cụ thử nghiệm.
• So sánh kết quả thực tế với kết quả mong đợi, báo cáo nếu thấy có sự khác nhau
• Lặp lại hoạt động kiểm tra với mỗi sự kiện lỗi
Nguyễn Thị Phương Dung 36

Thực hiện kiểm thử
• Báo cáo lỗi dựa trên các lỗi được quan sát thấy
• Ghi lại kết quả của việc thực hiện kiểm tra
• Lặp lại các hoạt động kiểm tra như kết quả của hành động được
thực hiện cho một sự bất thường hoặc là một phần của kiểm tra
theo kế hoạch
Nguyễn Thị Phương Dung 38

| Đánh giá | các tiêu chí |     | rút lui và | báo cáo |     |
| ---------- | -------------- | --- | ------------ | --------- | --- |
• Kiểm tra nhật ký theo các tiêu chí thoát đã chỉ định ở khâu lập
kế hoạch
• Đánh giá xem có cần nhiều bài kiểm tra hơn nữa hay không
• Viết báo cáo tóm tắt thử nghiệm cho các bên liên quan
|     | Nguyễn Thị | Phương Dung |     |     | 39  |
| --- | ------------ | ----------- | --- | --- | --- |

Các hoạt động đóng thử nghiệm
• Đảm bảo sản phẩm giao cho khách hàng đã được kiểm thử và
| sửa lỗi theo đúng kế | hoạch. |     |     |     |
| ------------------------ | ------- | --- | --- | --- |
• Hoàn thiện và lưu trữ phần mềm thử nghiệm, giúp giảm thời
| gian, công sức trong bảo trì |     | sau này.       |                 |     |
| ------------------------------- | --- | --------------- | --------------- | --- |
| • Bàn giao phần mềm thử     |     | nghiệm cho tổ | chức bảo trì |     |
• Đánh giá cách kiểm tra và phân tích bài học kính nghiệm cho
các dự án khác trong tương lai
|     | Nguyễn Thị | Phương Dung |     | 40  |
| --- | ------------ | ----------- | --- | --- |

| Tâm lý | thử | nghiệm |     |
| ------- | ---- | ------- | --- |
• Bắt đầu bằng sự hợp tác hơn là trận chiến. Nhắc nhở mọi người
về mục tiêu chung là chất lượng tốt hơn các hệ thống.
• Nhấn mạnh lợi ích của việc kiểm tra. Ví dụ, đối với các tác giả,
thông tin khiếm khuyết có thể giúp họ cải thiện sản phẩm công
việc và kỹ năng của họ. Đối với tổ chức, các khiếm khuyết
được tìm thấy và sửa chữa trong thử nghiệm sẽ tiết kiệm thời
gian và tiền bạc và giảm rủi ro tổng thể đối với chất lượng sản
phẩm.
| Nguyễn Thị | Phương Dung |     | 41  |
| ------------ | ----------- | --- | --- |

| Tâm lý | thử | nghiệm |     |
| ------- | ---- | ------- | --- |
• Truyền đạt kết quả thử nghiệm và các phát hiện khác theo cách
trung lập, tập trung vào thực tế mà không chỉ trích người tạo ra
mặt hàng bị lỗi. Viết báo cáo khiếm khuyết khách quan và thực
tế và xem xét những phát hiện.
• Cố gắng hiểu cảm giác của người kia và lý do họ có thể phản
ứng tiêu cực với thông tin.
• Xác nhận rằng người kia đã hiểu những gì đã được nói và
ngược lại.
| Nguyễn Thị | Phương Dung |     | 42  |
| ------------ | ----------- | --- | --- |

Tóm tắt chương
• Tại sao kiểm thử là cần thiết
• Kiểm thử là gì?
• Mục tiêu của thử nghiệm
• Các nguyên tắc cơ bản của kiểm thử
• Các hoạt động kiểm thử
• Tâm lý kiểm thử
Nguyễn Thị Phương Dung 44