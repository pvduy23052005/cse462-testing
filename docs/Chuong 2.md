KIỂM THỬ VÀ
ĐẢM BẢO
CHẤT LƯỢNG
PHẦNMỀM
Nguyễn Thị Phương Dung

CHƯƠNG II
KIỂM THỬ TRONG VÒNG ĐỜI
PHÁT TRIỂN HỆ THỐNG PHẦN MỀM
2

Nội dung
Phát triển phần mềm và kiểm thử phần mềm
•
Các mô hình phát triển phần mềm
•
Mức độ kiểm thử
•
Các loại kiểm thử
•
Kiểm thử và bảo trì
•
3

Phát triển phần mềm và kiểm thử phần mềm
Mô hình phát triển phần mềm mô tả các loại hoạt động
•
được thực hiện ở mỗi giai đoạn trong một dự án phát triển
phần mềm và cách các hoạt động liên quan với nhau theo
một trình tự thời gian hợp lý.
Mô hình vòng đời phát triển được áp dụng cho dự án sẽ có
•
tác động lớn đến quá trình thử nghiệm dự án.
Cách tổ chức thử nghiệm phải phù hợp với vòng đời phát
•
triển nếu không sẽ không mang lại lợi ích.
4

Đặc điểm của kiểm thử tốt
Đối với mỗi hoạt động phát triển cần có một hoạt động
•
kiểm thử tương ứng.
Mỗi cấp độ kiểm thử cần có các mục tiêu kiểm tra cụ thể
•
và phải được phân tích và thiết kế rõ ràng.
Người kiểm thử cần tham gia thảo luận để xác định và
•
tinh chỉnh các yêu cầu, thiết kế, đồng thời tham gia vào
việc xem xét các sản phẩm ngay khi có bản nháp.
5

Các mô hình phát triển phần mềm
6

Mô hình phát triển phần mềm
Theo hướng phát triển tuần tự:
•
Waterfall model – Mô hình thác nước
o
V model – Mô hình V
o
Incremental model – Mô hình gia tăng
o
RAD model – Mô hình RAD (Rapid Application Development)
o
Theo hướng phát triển lặp
•
Spiral model – Mô hình xoắn ốc
o
Rational Unified Process Mode – Mô hình RUP
o
Agile mode – Mô hình phát triển nhanh
o
7

Mô hình thác nước
8

Mô hình thác nước
Là mô hình phát triển tuần tự
•
Mô tả quá trình phát triển phần mềm như một luồng tuyến tính
•
Bất kỳ giai đoạn nào trong quá trình phát triển đều sẽ bắt đầu khi
•
giai đoạn trước đó được hoàn tất. Về lý thuyết, không có sự chồng
chéo của các giai đoạn, nhưng trong thực tế, sẽ có lợi nếu có phản
hồi sớm từ giai đoạn sau.
Hoạt động kiểm thử chỉ xảy ra sau khi tất cả các bước phát triển
•
khác đã được hoàn thành.
9

Mô hình thác nước
Ưu điểm Nhược điểm
Đơn giản, dễ hiểu và dễ sử dụng Khi đang trong giai đoạn thử nghiệm, rất khó
• •
để quay lại và thay đổi
Dễ quản lý do độ cứng của mô
•
hình Có nhiều rủi ro và không chắc chắn vì không
•
có phần mềm nào được sản xuất cho đến cuối
Các giai đoạn được xử lý và hoàn
•
vòng đời.
thành độc lập, không trùng lặp.
Không phải là một mô hình tốt cho các dự án
•
Hoạt động tốt cho các dự án nhỏ
•
phức tạp và hướng đối tượng.
hơn, nơi các yêu cầu được hiểu rất
rõ. Mô hình kém cho các dự án dài và đang diễn
•
ra.
Không phù hợp với các dự án có yêu cầu từ
•
trung bình đến cao
10

Mô hình V
11

Mô hình V
• Tích hợp quy trình kiểm tra trong suốt quá trình phát triển
• Thực hiện nguyên tắc kiểm tra sớm.
• Bao gồm các cấp độ kiểm tra được liên kết với mỗi giai đoạn phát
triển tương ứng.
• Bên trái là các hoạt động phát triển và bên tay phải là các hoạt động
kiểm thử với các mức:
Kiểm thử thành phần ( Component testing ).
•
Kiểm thử tích hợp (integration testing ).
•
Kiểm thử hệ thống (system testing).
•
Kiểm thử chấp nhận ( acceptance testing).
•
12

Mô hình chữ V
Ưu điểm Nhược điểm
Đơn giản dễ sử dụng. Rất cứng nhắc và kém linh hoạt.
• •
Có hoạt động, kế hoạch cụ Phần mềm được phát triển trong
• •
thể cho quá trình test. giai đoạn triển khai, do đó không
có nguyên mẫu ban đầu của phần
Tiết kiệm được thời gian, và
•
mềm được sản xuất.
có cơ hội thành công cao hơn
waterfall. Nếu bất kỳ thay đổi nào xảy ra
•
giữa chừng xảy ra giữa chừng, thì
Chủ động trong việc phát
•
các tài liệu kiểm tra cùng với các
hiện bug, sớm tìm ra bug
tài liệu yêu cầu phải được cập
ngay từ những bước đầu.
nhật.
13

Mô hình gia tăng
14

Mô hình gia tăng
• Với phương pháp chia nhỏ thành từng bản khác nhau, thì từ một chu
kỳ lớn sẽ được phân chia thành nhiều chu kỳ nhỏ ứng với từng bản, và
do đó dự án là một đa chu kỳ phát triển.
• Mỗi chu kỳ nhỏ ứng với một bản phân chia gọi là module đơn giản
hơn và dễ dàng quản lý hơn, mỗi module cũng được xây dựng theo
từng bước như là phân tích, đọc yêu cầu dự án, viết thiết kế, tiền hành
coding và thực hiện test.
• Nguyên lý của mô hình gia tăng này giống như việc xếp một bức tranh
từ các miếng ghép, miếng ghép nào được hoàn thành trước thì sẽ cho
ra một phần bức tranh được thể hiện trước, theo thời gian, số miếng
ghép được hoàn thành sẽ gia tăng và sản phầm ngày càng đi vào hoàn
thiện.
15

Mô hình gia tăng
Ưu điểm Nhược điểm
Phát triển nhanh chóng, sau khi hoàn Cần lập kế hoạch và thiết kế tốt.
• •
thành 1 mô đun là có thể chuyển giao
Tổng chi phí là cao hơn so với mô
•
cho khách hàng.
hình thác nước.
Mô hình này linh hoạt hơn, ít tốn kém
•
hơn khi thay đổi phạm vi và yêu cầu.
Dễ dàng hơn trong việc kiểm tra và
•
sửa lỗi.
Giảm chi phí cho lần đầu giao sản
•
phẩm.
16

Mô hình gia tăng
Mô hình này có thể được sử dụng khi các yêu cầu của hệ thống
•
hoàn chỉnh được xác định và hiểu rõ ràng.
Các yêu cầu chính phải được xác định; tuy nhiên, một số chi tiết
•
có thể phát triển theo thời gian.
Cần có sản phẩm ra thị trường sớm.
•
Công nghệ mới đang được sử dụng
•
Không có sẵn các nguồn lực với bộ kỹ năng cần thiết
•
Có một số tính năng và mục tiêu rủi ro cao.
•
17

Mô hình RAD
(Rapid Application Development)
18

Mô hình RAD
Là một phương pháp phát triển phần mềm sử dụng quy hoạch tối
•
thiểu có lợi cho việc tạo mẫu nhanh.
Tương tự mô hình gia tăng, dự án được chia thành nhiều modul
•
nhỏ
Khác với mô hình gia tăng, các modun trong mô hình này được
•
phát triển song song,
19

Mô hình RAD
Ưu điểm Nhược điểm
Cho phép xác định sớm rủi ro công Chỉ áp dụng mô hình RAD khi dự án
• •
nghệ. có thời gian gấp rút từ 2 đến 3 tháng.
Đáp ứng nhanh chóng với sự thay đổi Chỉ được sử dụng khi thiết kế có sẵn
• •
yêu cầu của khách hàng. các module.
Giảm được thời gian phát triển của Các yêu cầu dự án rõ ràng.
• •
sản phẩm.
Có đủ nguồn lực cả về công cụ, con
•
Sớm đưa ra được những đánh giá, người, tài liệu, phần mềm hỗ trợ.
•
nhận xét, phản hồi từ khách hàng nên
Tốn chi phí khi xây dựng nhiều team
•
dễ dàng điều chỉnh.
phát triển song song.
20

Mô hình lặp
21

Mô hình lặp
Phát triển lặp đi lặp lại xảy ra khi các nhóm tính năng được chỉ
•
định, thiết kế, xây dựng và thử nghiệm cùng nhau trong một loạt
chu kỳ, thường có thời hạn cố định.
Lặp lại có thể liên quan đến các thay đổi đối với các tính năng
•
được phát triển trong các lần lặp trước đó, cùng với các thay đổi
trong phạm vi dự án.
Mỗi lần lặp lại cung cấp phần mềm hoạt động ngày càng tăng tập
•
hợp con của tập hợp tính năng tổng thể cho đến khi phần mềm
cuối cùng được phân phối.
22

Một số mô hình phát triển lặp
Spiral model – Mô hình xoắn ốc
•
Rational Unified Process Mode – Mô hình RUP
•
Agile mode:
•
Scrum model – Mô hình Scrum
o
Kanban model – Mô hình Kanban
o
23

Mô hình xoắn ốc
24

Mô hình xoắn ốc
Mô hình xoán ốc là cải tiến của mô hình tuần tự và mẫu thử, thêm vào phân
•
tích rủi ro.
Là quá trình lặp hướng mở rộng, hoàn thiện dần.
•
Sau mỗi lần tăng vòng thì có thể chuyển giao kết quả thực hiện được cho
•
khách hành nên các chức năng của hệ thống có thể nhìn thấy sớm hơn.
Các vòng trước đóng vai trò là mẫu thử để giúp tìm hiểu thêm các yêu cầu ở
•
những vòng tiếp theo.
25

Mô hình Xoắn ốc
Ưu điểm Nhược điểm
Là mô hình kết hợp giữa các tính năng của Chi phí cao và thời
• •
mô hình prototyping và mô hình thác nước. gian dài để có sản
phẩm cuối cùng
Mô hình xoắn ốc được ưa chuộng cho các dự
•
án lớn, đắt tiền và phức tạp. Phải có kỹ năng tốt để
•
đánh giá rủi ro và giả
Mô hình này sử dụng nhiều những giai đoạn
•
định
tương tự như mô hình thác nước, về thứ tự,
plan, đánh giá rủi ro, …
26

Mô hình RUP – Mô hình RUP
27

Mô hình RUP – Mô hình RUP
Bắt nguồn từ mô hình xoắn ốc
•
Phát triển theo hướng đối tượng
•
Yêu cầu việc phát triển ứng dụng một cách chặt chẽ và nghiêm
•
ngặt với việc đưa ra các mẫu được thực hiện nhanh chóng qua các
cuộc làm việc với khách hàng và nhóm dự án, việc lập kế hoạch
và đưa ra các chức năng hệ thống một cách tích cực. Kết quả sẽ
đưa ra một ứng dụng đáp ứng các yêu cầu của người sử dụng và
giúp cho quá trình lên kế hoạch và thực thi nhanh chóng.
28

Mô hình Agile
29

Mô hình Agile
Phát triển dựa trên mô hình lặp và gia tăng
•
Hệ thống được chia thành các mô đun nhỏ, mỗi lần lặp liên quan
•
đến các quy trình: lập kế hoạch, phân tích yêu cầu, thiết kế, code,
kiểm thử.
Vào cuối mỗi vòng lặp sẽ hoàn thành được một module hoặc chức
•
năng và có thể đưa cho khách hàng đánh giá và phản hồi.
Các yêu cầu và giải pháp phát triển sẽ dựa vào sự kết hợp của các
•
chức năng đã hoàn thành
30

Mô hình Agile
Ưu điểm Nhược điểm
Thường xuyên chuyển giao sản phẩm Không thích hợp để xử lý các phụ thuộc
• •
chất lượng tốt tới khách hàng trong thời phức tạp.
gian ngắn.
Có nhiều rủi ro về tính bền vững, khả
•
Khách hàng, nhà phát triển và người thử năng bảo trì và khả năng mở rộng.
•
nghiệm liên tục trao đổi với nhau.
Cần một team có kinh nghiệm và am hiểu
•
Tiếp nhận, xử lý những phản hồi và thay về Agile.
•
đổi của khách hàng một cách linh hoạt
Phụ thuộc rất nhiều vào sự tương tác rõ
•
trong suốt quá trình phát triển.
ràng của khách hàng.
Đạt được sự hài lòng của khách hàng.
•
Chuyển giao công nghệ cho các thành
•
viên mới trong nhóm có thể khá khó khăn
do thiếu tài liệu.
31

Ngữ cảnh áp dụng vòng đời phát triển phần mềm
Việc lựa chọn mô hình vòng đời phát triển phần mềm nào tùy
•
thuộc vào:
Mục tiêu của dự án
•
Các ưu tiên về kinh doanh
•
Các rủi ro có thể xảy ra
•
Đôi khi, tùy thuộc vào bối cảnh của dự án, có thể cần kết hợp
•
hoặc tổ chức lại các mô hình phát triển phần mềm.
32

Mức độ kiểm thử
33

Mức độ kiểm thử
Là các nhóm hoạt động kiểm tra được tổ chức và quản lý
•
cùng nhau.
Mỗi mức độ kiểm thử là một ví dụ của quá trình thử
•
nghiệm được thực hiện liên quan đến phần mềm ở cấp độ
phát triển nhất định, từ các đơn vị hoặc thành phần riêng
lẻ đến hệ thống hoàn chỉnh hoặc, nếu có, các hệ thống
nhỏ trong hệ thống lớn.
Mỗi mức độ kiểm thử có liên quan đến các hoạt động
•
khác nhau trong vòng đời phát triển phần mềm.
34

Phân loại mức độ kiểm thử
Kiểm thử thành phần
•
Kiểm thử tích hợp
•
Kiểm thử hệ thống
•
Kiểm thử chấp nhận
•
35

Đặc trưng chung của các mức độ kiểm thử
Mục tiêu cụ thể
•
Cơ sở kiểm thử, được tham chiếu để rút ra các trường hợp
•
kiểm thử
Đối tượng kiểm tra (tức là những gì đang được kiểm tra)
•
Các khiếm khuyết và hư hỏng điển hình
•
Các cách tiếp cận và trách nhiệm cụ thể
•
36

Kiểm thử Kiểm thử Kiểm thử Kiểm thử
thành phần tích hợp hệ thống chấp nhận
Kiểm thử thành phần (còn được gọi là kiểm thử đơn vị hoặc mô-
•
đun) tập trung vào các thành phần riêng biệt có thể kiểm tra được.
Mục tiêu của kiểm thử thành phần bao gồm:
•
Giảm rủi ro
o
Xác minh xem các hành vi chức năng và phi chức năng của
o
thành phần có đúng như thiết kế không.
Xây dựng niềm tin vào chất lượng của thành phần
o
Tìm ra các khuyết tật trong thành phần
o
Ngăn chặn các khuyết tật tiềm ẩn có thể xảy ra ở các mức kiểm
o
thử cao hơn.
37

| Kiểm thử    |               | Kiểm thử  |     | Kiểm thử  | Kiểm thử  |
| ----------- | ------------- | --------- | --- | --------- | --------- |
| thành phần  |               | tích hợp  |     | hệ thống  | chấp nhận |
| Cơ sở      | thử nghiệm: |           |     |           |           |
•
Thiết kế chi tiết
o
| o Mã | nguồn |     |     |     |     |
| ---- | ----- | --- | --- | --- | --- |
Mô hình dữ liệu
o
Thông số kỹ thuật của thành phần
o
| Đối tượng thử |     | nghiệm: |     |     |     |
| ---------------- | --- | -------- | --- | --- | --- |
•
Thành phần, đơn vị hoặc các mô dun nhỏ
o
| o Mã | nguồn và | cấu trúc dữ | liệu |     |     |
| ---- | --------- | ------------ | ---- | --- | --- |
Lớp
o
Cơ sở dữ liệu
o
38

| Kiểm thử    |     | Kiểm thử  |     | Kiểm thử  | Kiểm thử  |
| ----------- | --- | --------- | --- | --------- | --------- |
| thành phần  |     | tích hợp  |     | hệ thống  | chấp nhận |
Các khuyết tật điển hình
•
o Chức năng không chính xác
| Các vấn đề | về luồng dữ |     | liệu không đúng |     |     |
| ------------ | ------------- | --- | --------------- | --- | --- |
o
Mã nguồn không chính xác
o
tính logic không phù hợp
o
39

| Kiểm thử             | Kiểm thử          | Kiểm thử  | Kiểm thử  |
| -------------------- | ----------------- | --------- | --------- |
| thành phần           | tích hợp          | hệ thống  | chấp nhận |
| Cách tiếp cận và | trách nhiệm cụ | thể      |           |
•
o Thực hiện bởi người lập trình
Chạy thử sau khi viết mã nguồn, sửa chữa ngay khi thấy lỗi
o
Trong mô hình Agile, các trường hợp kiểm thử ở mức này có thể
o
được viết trước khi viết mã nguồn.
40

Kiểm thử Kiểm thử Kiểm th Kiểm thử
thành phần tích hợp ửhệ thống chấp nhận
Là kiểm thử tương tác giữa các thành phần trong hệ thống.
•
Mục tiêu của kiểm thử tích hợp:
•
Giảm rủi ro
o
Xác minh và chỉ ra các hành vi không đúng thiết kế của các
o
chức năng và phi chức năng của các giao diện
Xây dựng niềm tin vào chất lượng của các giao diện
o
Tìm ra khiếm khuyết (trong chính giao diện đang kiểm thử hoặc
o
trong các thành phần tích hợp khác)
Ngăn chặn các khiếm khuyết tiềm ẩn có thể xảy ra ở các mức
o
kiểm thử cao hơn.
41

Kiểm thử Kiểm thử Kiểm thử Kiểm thử
thành phần tích hợp hệ thống chấp nhận
Cơ sở thử nghiệm:
•
Bản thiết kế phần mềm và hệ thống
o
Biểu đồ trình tự
o
Đặc điểm giao diện và giao thức truyền thông
o
Kiến trúc ở cấp thành phần hoặc hệ thống
o
Quy trình làm việc
o
Định nghĩa giao diện bên ngoài
o
42

Kiểm thử Kiểm thử Kiểm thử Kiểm thử
thành phần tích hợp hệ thống chấp nhận
Đối tượng kiểm thử
•
Các thành phần hoặc hệ thống con
o
Cơ sở dữ liệu
o
Cơ sở hạ tầng
o
Giao diện
o
API
o
Microservices
o
43

Kiểm thử Kiểm thử Kiểm thử Kiểm thử
thành phần tích hợp hệ thống chấp nhận
Các khuyết tật và hư hỏng điển hình trong cấp độ thành phần:
•
Dữ liệu không chính xác, thiếu dữ liệu hoặc mã hóa dữ liệu
o
không đúng
Trình tự hoặc thời gian gọi giao diện không chính xác
o
Giao diện không khớp
o
Lỗi trong giao tiếp giữa các thành phần
o
Lỗi giao tiếp không được xử lý hoặc xử lý không đúng giữa các
o
thành phần
Các giả định không chính xác về ý nghĩa, đơn vị hoặc ranh giới
o
của dữ liệu được chuyển giữa các thành phần
44

Kiểm thử Kiểm thử Kiểm thử Kiểm thử
thành phần tích hợp hệ thống chấp nhận
Các khuyết tật và hư hỏng điển hình trong cấp độ hệ thống:
•
Cấu trúc thông báo không nhất quán giữa các hệ thống
o
Dữ liệu không chính xác, dữ liệu bị thiếu hoặc mã hóa dữ liệu
o
không đúng
Giao diện không khớp
o
Lỗi trong giao tiếp giữa các hệ thống
o
Lỗi giao tiếp không được xử lý hoặc xử lý không đúng giữa các
o
hệ thống
Các giả định không chính xác về ý nghĩa, đơn vị hoặc ranh giới
o
của dữ liệu được chuyển giữa các hệ thống
Không tuân thủ các quy định bảo mật bắt buộc
o
45

Kiểm thử Kiểm thử Kiểm thử Kiểm thử
thành phần tích hợp hệ thống chấp nhận
Cách tiếp cận và trách nhiệm cụ thể:
•
Tùy thuộc vào cấp độ tích hợp để tiếp cận vào đúng đối tượng của
o
cấp độ đó.
Tích hợp thành phần: tập trung vào kiểm thử giao tiếp giữa các thành phần,

các module
Tích hợp hệ thống: tập trung vào kiểm thử giao tiếp giữa các hệ thống

Các loại kiểm thử cần tiếp cận: chức năng, phi chức năng và kết cấu
o
Trách nhiệm trong tích hợp thành phần là các nhà phát triển
o
Trách nhiệm trong tích hợp hệ thống là của các nhà kiểm thử
o
46

Kiểm thử Kiểm thử Kiểm thử Kiểm thử
thành phần tích hợp hệ thống chấp nhận
Kiểm thử hệ thống tập trung vào hành vi và khả năng của toàn bộ hệ
•
thống hoặc sản phẩm, thường xem xét các tác vụ từ đầu đến cuối mà hệ
thống có thể thực hiện và các hành vi phi chức năng mà hệ thống thể
hiện khi thực hiện các nhiệm vụ đó.
Mục tiêu của kiểm thử hệ thống bao gồm:
•
Giảm rủi ro
o
Xác minh xem các hành vi chức năng và phi chức năng của hệ thống
o
có đúng như thiết kế
Xác nhận rằng hệ thống đã hoàn tất và sẽ hoạt động như mong đợi
o
Xây dựng niềm tin vào chất lượng của toàn hệ thống
o
Tìm ra các khiếm khuyết
o
Ngăn ngừa các khiếm khuyết tiềm ẩn có khả năng thoát ra các cấp
o
kiểm tra cao hơn hoặc sản xuất
47

Kiểm thử Kiểm thử Kiểm thử Kiểm thử
thành phần tích hợp hệ thống chấp nhận
Cơ sở thử nghiệm
•
Đặc tả yêu cầu hệ thống và phần mềm (chức năng và phi chức năng)
o
Báo cáo phân tích rủi ro
o
Kịch bản các ca sử dụng
o
Mô hình hành vi của hệ thống
o
Biểu đồ trạng thái
o
Hướng dẫn sử dụng hệ thống
o
48

Kiểm thử Kiểm thử Kiểm thử Kiểm thử
thành phần tích hợp hệ thống chấp nhận
Đối tượng thử nghiệm
•
Ứng dụng
o
Hệ thống phần cứng / phần mềm
o
Hệ điều hành
o
Hệ thống đang kiểm tra (SUT)
o
Cấu hình dữ liệu và cấu hình hệ thống
o
49

Kiểm thử Kiểm thử Kiểm thử Kiểm thử
thành phần tích hợp hệ thống chấp nhận
Các khuyết tật và hư hỏng điển hình
•
Tính toán không chính xác
o
Hành vi chức năng hoặc phi chức năng của hệ thống không chính
o
xác hoặc không mong muốn
Kiểm soát không chính xác luồng dữ liệu trong hệ thống
o
Không thực hiện đúng và đầy đủ các chức năng, nhiệm vụ
o
Hệ thống không hoạt động bình thường trong (các) môi trường hệ
o
thống
Hệ thống không hoạt động như mô tả trong hướng dẫn sử dụng
o
50

| Kiểm thử    | Kiểm thử  | Kiểm thử  | Kiểm thử  |
| ----------- | --------- | --------- | --------- |
| thành phần  | tích hợp  | hệ thống  | chấp nhận |
Các cách tiếp cận và trách nhiệm cụ thể
Tiếp cận tập trung vào hành vi tổng thể, từ đầu đến cuối của hệ thống
•
| nói chung, cả về | chức năng và phi chức năng.  |     |     |
| ------------------ | ------------------------------- | --- | --- |
Thường được thực hiện bởi những người kiểm tra độc lập, những
•
người phụ thuộc nhiều vào các thông số kỹ thuật.
Khuyết tật trong thông số kỹ thuật có thể dẫn đến thiếu hiểu biết hoặc
•
bất đồng về hành vi hệ thống mong đợi. Tạo ra những kết quả lỗi giả,
làm lãng phí thời gian và giảm hiệu quả phát hiện khuyết tật.
51

Kiểm thử Kiểm thử Kiểm thử Kiểm thử
thành phần tích hợp hệ thống chấp nhận
Kiểm thử chấp nhận, giống như kiểm thử hệ thống, thường tập trung
•
vào hành vi và khả năng của toàn bộ hệ thống hoặc sản phẩm.
Mục tiêu của kiểm thử chấp nhận bao gồm:
•
Thiết lập niềm tin vào chất lượng của toàn bộ hệ thống
o
Xác nhận hệ thống đã hoàn thiện và sẽ hoạt động như mong đợi
o
Xác minh các hành vi chức năng và phi chức năng của hệ thống như
o
mong đợi
52

Kiểm thử Kiểm thử Kiểm thử Kiểm thử
thành phần tích hợp hệ thống chấp nhận
Các hình thức kiểm thử chấp nhận phổ biến bao gồm:
•
Kiểm tra chấp nhận của người dùng
o
Kiểm tra chấp nhận hoạt động
o
Kiểm tra chấp nhận theo hợp đồng và quy định
o
Kiểm tra alpha và beta.
o
53

Kiểm thử Kiểm thử Kiểm thử Kiểm thử
thành phần tích hợp hệ thống chấp nhận
Kiểm tra sự chấp nhận của người dùng:
Tập trung vào việc xác nhận tính phù hợp để sử dụng hệ thống trong
•
một môi trường hoạt động thực tế hoặc mô phỏng.
Mục tiêu chính là xây dựng tin tưởng rằng người dùng có thể sử dụng
•
hệ thống để đáp ứng nhu cầu của họ, đáp ứng các yêu cầu và thực hiện
quy trình kinh doanh với khó khăn, chi phí và rủi ro tối thiểu.
54

Kiểm thử Kiểm thử Kiểm thử Kiểm thử
thành phần tích hợp hệ thống chấp nhận
Kiểm tra chấp nhận hoạt động:
Thực hiện bởi nhân viên vận hành hoặc quản trị hệ thống trong một
•
môi trường sản xuất (hoặc mô phỏng).
Mục tiêu chính của thử nghiệm chấp nhận vận hành là xây dựng niềm
•
tin rằng các nhà điều hành hoặc hệ thống quản trị viên có thể giữ cho
hệ thống hoạt động bình thường cho người dùng trong môi trường hoạt
động, thậm chí trong những điều kiện đặc biệt hoặc khó khăn.
55

Kiểm thử Kiểm thử Kiểm thử Kiểm thử
thành phần tích hợp hệ thống chấp nhận
Kiểm tra chấp nhận hoạt động:
Các bài kiểm tra tập trung vào các khía cạnh hoạt động bao gồm:
•
Kiểm tra sao lưu và khôi phục
o
Cài đặt, gỡ cài đặt và nâng cấp
o
Khôi phục sau thảm họa
o
Quản lý người dùng
o
Tác vụ bảo trì
o
Nhiệm vụ tải và di chuyển dữ liệu
o
Kiểm tra lỗ hổng bảo mật
o
Kiểm tra hiệu suất
o
56

Kiểm thử Kiểm thử Kiểm thử Kiểm thử
thành phần tích hợp hệ thống chấp nhận
Kiểm tra chấp nhận theo hợp đồng và quy định
Kiểm tra chấp nhận hợp đồng được thực hiện dựa trên các tiêu chí chấp
•
nhận của hợp đồng, khi các bên đồng ý với hợp đồng và thường được thực
hiện bởi người dùng hoặc bởi những người kiểm tra độc lập.
Thử nghiệm chấp nhận theo quy định được thực hiện dựa trên bất kỳ quy
•
định nào phải tuân thủ, chẳng hạn như các quy định của chính phủ, luật pháp
hoặc an toàn. Và thường được thực hiện bởi người dùng hoặc bởi những
người kiểm tra độc lập, đôi khi kết quả được chứng kiến ​​hoặc kiểm toán bởi
các cơ quan quản lý.
Mục tiêu chính của kiểm tra chấp nhận theo hợp đồng và quy định là xây
•
dựng niềm tin rằng cần phải tuân thủ theo hợp đồng hoặc quy định.
57

Kiểm thử Kiểm thử Kiểm thử Kiểm thử
thành phần tích hợp hệ thống chấp nhận
Thử nghiệm alpha và beta
Thử nghiệm alpha được thực hiện tại tổ chức đang phát triển, không
•
phải bởi nhóm phát triển, nhưng bởi khách hàng tiềm năng hoặc khách
hàng hiện tại, hoặc nhà điều hành hoặc nhóm kiểm tra độc lập.
Thử nghiệm beta được thực hiện bởi khách hàng tiềm năng hoặc hiện
•
tại hoặc các nhà khai thác tại địa điểm của chính họ. Beta thử nghiệm
có thể đến sau thử nghiệm alpha, hoặc có thể xảy ra mà không xảy ra
bất kỳ thử nghiệm alpha nào trước đó.
58

Kiểm thử Kiểm thử Kiểm thử Kiểm thử
thành phần tích hợp hệ thống chấp nhận
Thử nghiệm alpha và beta
Mục tiêu của thử nghiệm alpha và beta là:
•
Xây dựng niềm tin cho khách hàng tiềm năng hoặc hiện tại, hoặc
•
người vận hành mà họ có thể sử dụng hệ thống trong các điều kiện
bình thường, hàng ngày và trong hoạt động các môi trường để đạt
được mục tiêu với khó khăn, chi phí và rủi ro tối thiểu.
Phát hiện các khiếm khuyết liên quan đến các điều kiện và môi
•
trường mà hệ thống sẽ được sử dụng, đặc biệt là khi các điều kiện và
môi trường đó khó có thể tái tạo bởi nhóm phát triển.
59

Kiểm thử Kiểm thử Kiểm thử Kiểm thử
thành phần tích hợp hệ thống chấp nhận
Cơ sở thử nghiệm
•
Quy trình nghiệp vụ
o
Yêu cầu của người dùng hoặc doanh nghiệp
o
Quy định, hợp đồng pháp lý và tiêu chuẩn
o
Các trường hợp sử dụng của người dùng
o
Yêu cầu hệ thống
o
Tài liệu hệ thống hoặc tài liệu người dùng
o
Quy trình cài đặt
o
Báo cáo phân tích rủi ro
o
60

Kiểm thử Kiểm thử Kiểm thử Kiểm thử
thành phần tích hợp hệ thống chấp nhận
Cơ sở thử nghiệm
•
Ngoài ra, cơ sở thử nghiệm chấp nhận vận hành có thể sử dụng các sản
•
phẩm công việc sau:
Quy trình sao lưu và khôi phục
o
Quy trình khôi phục sau thảm họa
o
Yêu cầu phi chức năng
o
Tài liệu vận hành
o
Hướng dẫn triển khai và cài đặt
o
Mục tiêu hiệu suất
o
Gói cơ sở dữ liệu
o
Các tiêu chuẩn hoặc quy định bảo mật
o
61

Kiểm thử Kiểm thử Kiểm thử Kiểm thử
thành phần tích hợp hệ thống chấp nhận
Đối tượng thử nghiệm điển hình
•
Hệ thống đang kiểm thử
•
Cấu hình dữ liệu và cấu hình hệ thống
•
Quy trình nghiệp vụ cho một hệ thống tích hợp đầy đủ
•
Hệ thống khôi phục
•
Quy trình vận hành và bảo trì
•
Biểu mẫu
•
Báo cáo
•
Dữ liệu sản xuất hiện có và được chuyển đổi
•
62

Kiểm thử Kiểm thử Kiểm thử Kiểm thử
thành phần tích hợp hệ thống chấp nhận
Các khuyết tật và hư hỏng điển hình
•
Quy trình làm việc của hệ thống không đáp ứng các yêu cầu của
•
doanh nghiệp hoặc người dùng
Các quy tắc nghiệp vụ không được thực hiện đúng
•
Hệ thống không đáp ứng các yêu cầu theo hợp đồng hoặc quy định
•
Các lỗi phi chức năng như lỗ hổng bảo mật, hiệu suất không đầy đủ
•
hiệu quả dưới tải cao hoặc hoạt động không đúng trên nền tảng được
hỗ trợ
63

Kiểm thử Kiểm thử Kiểm thử Kiểm thử
thành phần tích hợp hệ thống chấp nhận
Các cách tiếp cận và trách nhiệm cụ thể
•
Kiểm tra chấp nhận thường là trách nhiệm của khách hàng, người
•
dùng doanh nghiệp, chủ sở hữu sản phẩm hoặc người vận hành hệ
thống và các bên liên quan khác cũng có thể tham gia.
Kiểm thử chấp nhận thường được coi là cấp kiểm tra cuối cùng trong
•
vòng đời phát triển tuần tự, nhưng nó cũng có thể xảy ra vào những
thời điểm khác, ví dụ: khi nó được cài đặt hoặc tích hợp hoặc kiểm
tra chấp nhận một cải tiến chức năng mới có thể xảy ra trước khi
kiểm tra hệ thống
64

Các loại kiểm thử
65

Các loại kiểm thử
Loại kiểm thử là một nhóm các hoạt động kiểm tra nhằm mục
•
đích kiểm tra các đặc tính cụ thể của hệ thống phần mềm, hoặc
một phần của hệ thống, dựa trên các mục tiêu thử nghiệm cụ thể.
Phân loại mục tiêu kiểm thử:
•
Đánh giá các đặc điểm chất lượng chức năng
o
Đánh giá các đặc điểm chất lượng phi chức năng
o
Đánh giá xem cấu trúc hoặc kiến trúc của thành phần hoặc hệ
o
thống có đúng, đầy đủ, và theo quy định
Đánh giá tác động của các thay đổi
o
66

| Kiểm thử                | chức năng |                     |     |     |            |
| ------------------------- | ---------- | ------------------- | --- | --- | ---------- |
| Là kiểm tra, đánh giá |            | các chức năng mà |     |     | hệ thống  |
•
cần thực hiện
| Cần được thực hiện ở |     | tất cả | các mức thử |     | nghiệm  |
| --------------------- | --- | ------- | -------------- | --- | ------- |
•
| Thường sử | dụng kỹ | thuật kiểm thử |     | hộp đen |     |
| ---------- | -------- | ---------------- | --- | -------- | --- |
•
Đôi khi cần nắm vững kiến thức chuyên môn,
•
nghiệp vụ
Tính kỹ lưỡng được đo lường thông qua phạm vi
•
bao phủ chức năng
67

| Kiểm thử                | phi chức năng |                    |     |             |     |
| ------------------------- | -------------- | ------------------ | --- | ----------- | --- |
| Là kiểm tra, đánh giá |                | đặc điểm của hệ |     | thống qua  |     |
•
| cách thức hoạt động của hệ |     |     | thống. Ví | dụ: khả | năng  |
| ------------------------------- | --- | --- | ---------- | --------- | ----- |
sử dụng, hiệu quả hoạt động, tính bảo mật, …
| Thường dựa theo các tiêu chí |     |     | của các tiêu chuẩn  |     |     |
| ----------------------------- | --- | --- | --------------------- | --- | --- |
•
ISO (ISO/ IEC-25010)
| Sử dụng kỹ | thuật kiểm thử |     | hộp đen |     |     |
| ------------ | ---------------- | --- | -------- | --- | --- |
•
Tính kỹ lưỡng được đo lường thông qua phạm vi
•
bao phủ phi chức năng
68

Kiểm thử kiến trúc, cấu trúc hệ thống
Là việc kiểm tra các cấu trúc bên trong của hệ
•
thống như: mã nguồn, kiến ​​trúc, luồng công việc và
luồng dữ liệu trong hệ thống
Tính kỹ lưỡng của thử nghiệm hộp trắng có thể
•
được đo lường thông qua độ bao phủ của cấu trúc
Thường sử dụng kỹ thuật kiểm thử hộp trắng
•
69

Kiểm thử thay đổi
Được thực hiện sau mỗi lần sửa lỗi.
•
Bao gồm:
•
Kiểm thử xác nhận: xác nhận xem lỗi ban đầu đã được sửa thành
•
công hay chưa.
Kiểm thử hồi quy: chạy lại các bài kiểm tra trước để đảm bảo lỗi
•
vừa sửa không làm ảnh hưởng đến các chức năng khác hay các
hoạt động khác của hệ thống
Được thực hiện ở tất cả các cấp độ kiểm thử.
•
70

Tổng kết chương
Kiểm thử trong vòng đời phát triển hệ thống phần mềm
•
Mức độ kiểm thử
•
Các loại kiểm thử
•
71

Bài tập
Chuẩn bị một hệ thống phần mềm bao gồm:
•
Các đặc tả chi tiết của hệ thống
•
Tài liệu phân tích thiết kế hệ thống
•
Code hệ thống
•
72