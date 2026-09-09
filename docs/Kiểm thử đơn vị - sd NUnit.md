KIỂM THỬ VÀ ĐẢM BẢO CHẤT LƯỢNG PHẦN MỀM
SỬ DỤNG CÔNG CỤ KIỂM THỬ ĐƠN VỊ

06/11/2019

Nguyễn Thị Phương Dung - Khoa CNTT – ĐH Thủy lợi

1

Kiểm thử đơn vị
• Là phương pháp kiểm thử phần mềm trên từng modul

nhỏ của chương trình.

• Trong các ngôn ngữ hướng đối tượng (ví dụ C#), các
đơn vị kiểm thử này có thể là các hàm/ phương thức
hay lớp.

• Một đơn vị kiểm thử được dùng để kiểm tra một đơn vị

công việc với một kết quả giả định nào đó

• Nếu kết quả thực thi của đơn vị công việc cần kiểm tra
khác với kết quả giả định thì đơn vị kiểm thử thất bại.

06/11/2019

Nguyễn Thị Phương Dung - Khoa CNTT – ĐH Thủy lợi

2

Một số đặc điểm của unit test:

• Code unit test phải ngắn gọn, dễ hiểu, dễ đọc.
• Mỗi unit test là 1 đơn vi riêng biệt, độc lập, không phụ thuộc vào unit khác.
• Mỗi unit test là 1 method trong test class, tên method cũng là tên UnitTest.

Do đó ta nên đặt tên hàm rõ ràng, nói rõ unit test này test cái gì
(Test_A_Do_B), tên method có thể rất dàiii cũng không sao.

• Unit Test phải nhanh, vì nó sẽ được chạy để kiểm định lỗi mỗi lần build.
Do đó trong unit test nên hạn chế các task tốn thời gian như gọi I/O,
database, network,…
 Unit Test nên test từng đối tượng riêng biệt. Vd: Unit Test cho Business
Class thì chỉ test chính BusinessClass đó, không nên dụng tới các class móc
nối với nó (DataAccess Class chẳng hạn).

•

06/11/2019

Nguyễn Thị Phương Dung - Khoa CNTT – ĐH Thủy lợi

3

Framework cho Unit Testing

• Unit Testing có thể được thực hiện dễ dàng

nhờ các framework.

• Một số Framework phổ biến hỗ trợ cho các

nhà phát triển .Net:
– NUnit
– xUnit
– MSTest

06/11/2019

Nguyễn Thị Phương Dung - Khoa CNTT – ĐH Thủy lợi

5

Sử dụng NUnit

Các bước sử dụng NUnit

• Tạo dự án cần kiểm thử
• Tạo dự án kiểm thử
• Tạo liên kết giữa 2 dự án trên
• Cài đặt Nunit để được hỗ trợ framework test
• Cài đặt NUnit3TestAdapter để sử dụng các phương

thức thực thi các đơn vị kiểm thử.

• Thực hiện viết lệnh
• Thực hiện test

Tạo dự án cần kiểm thử

• Sử dụng Visual Studio tạo một solution
• Trong solution tạo một project cần kiểm thử
• Trong project tạo các hàm cần kiểm thử, đây

chính là các đơn vị cần kiểm thử

06/11/2019

Nguyễn Thị Phương Dung - Khoa CNTT – ĐH Thủy lợi

8

06/11/2019

Nguyễn Thị Phương Dung - Khoa CNTT – ĐH Thủy lợi

9

Tạo dự án kiểm thử

• Tạo project kiểm thử đơn vị trong cùng

solution với project cần kiểm thử
• Kiểu của project là Class Library

06/11/2019

Nguyễn Thị Phương Dung - Khoa CNTT – ĐH Thủy lợi

10

06/11/2019

Nguyễn Thị Phương Dung - Khoa CNTT – ĐH Thủy lợi

11

Tạo liên kết giữa 2 dự án

• Trong cửa sổ solution, nhấn chuột phải vào dự

án kiểm thử, chọn Add > Reference.

• Trong cửa sổ Reference Manager chọn dự án

cần kiểm thử

06/11/2019

Nguyễn Thị Phương Dung - Khoa CNTT – ĐH Thủy lợi

12

06/11/2019

Nguyễn Thị Phương Dung - Khoa CNTT – ĐH Thủy lợi

13

06/11/2019

Nguyễn Thị Phương Dung - Khoa CNTT – ĐH Thủy lợi

15

Cài đặt NUnit

• Chọn Tool/NuGet Package Manager/Manage

NuGet Packages for Solution

06/11/2019

Nguyễn Thị Phương Dung - Khoa CNTT – ĐH Thủy lợi

16

Cài đặt NUnit

• Trong cửa sổ NuGet – Solution chọn tab Browse và
gõ cụm từ ‘nunit’ trong ô tìm kiếm và chọn Nunit
• Bên khung cửa sổ NUnit bên phải chọn Project (bao

gồm hai dự án) và nhấn Install:

06/11/2019

Nguyễn Thị Phương Dung - Khoa CNTT – ĐH Thủy lợi

17

06/11/2019

Nguyễn Thị Phương Dung - Khoa CNTT – ĐH Thủy lợi

18

• Nếu xuất hiện cửa sổ preview changes thì ấn

nút OK

06/11/2019

Nguyễn Thị Phương Dung - Khoa CNTT – ĐH Thủy lợi

19

Kiểm tra cài đặt NUnit

• Trong References của mỗi dự

án sẽ thấy xuất hiện
nunit.framework

06/11/2019

Nguyễn Thị Phương Dung - Khoa CNTT – ĐH Thủy lợi

20

Cài đặt NUnit3TestAdapter

• Mục đích: để sử dụng các phương thức thực
thi các đơn vị kiểm thử NUnit trong Visual
Studio.

06/11/2019

Nguyễn Thị Phương Dung - Khoa CNTT – ĐH Thủy lợi

21

Các thuộc tính TestFixture, Test

• NUnit chứa hai thuộc tính TestFixture và Test
dùng để đánh dấu lớp và phương thức sẽ là
các đơn vị kiểm thử (unit tests).

• Trước khi sử dụng hai thuộc tính này, cần khai

báo thư viện Nunit

    using NUnit.Framework;

06/11/2019

Nguyễn Thị Phương Dung - Khoa CNTT – ĐH Thủy lợi

22

Các thuộc tính TestFixture, Test

• Thuộc tính TestFixture được đặt trong cặp dấu

ngoặc vuông [] trước tên lớp kiểm thử

• Thuộc tính Test được đặt trong cặp dấu ngoặc

vuông [] trước tên phương thức kiểm thử

06/11/2019

Nguyễn Thị Phương Dung - Khoa CNTT – ĐH Thủy lợi

23

Các thuộc tính TestFixture, Test

06/11/2019

Nguyễn Thị Phương Dung - Khoa CNTT – ĐH Thủy lợi

24

Lớp Assert

• Lớp Assert như chiếc cầu nối giữa mã chương

trình cần kiểm thử và NUnit

• Mỗi đơn vị kiểm thử sẽ dùng lớp này với mục
đích khai báo một giả định nào đó là tồn tại.
• Nếu các đối số được chuyển vào lớp Assert thực
hiện cho ra kết quả khác với giả định thì đơn vị
kiểm thử này tìm ra lỗi, ngược lại chương trình
không bị lỗi.

06/11/2019

Nguyễn Thị Phương Dung - Khoa CNTT – ĐH Thủy lợi

25

Các phương thức của lớp Assert

Phương thức

Assert.AreEqual(expected,
actual [, string message])

Mô tả

Là phương thức thường xuyên được dùng trong quá trình
kiểm thử. expected là giá trị kỳ vọng; actual là giá trị
thực; message là thông điệp sẽ hiển thị nếu kiểm thử thất
bại.

Assert.Less(x, y)

Xác nhận x < y

Assert.Greater(x,y)

Xác nhận x > y

06/11/2019

Nguyễn Thị Phương Dung - Khoa CNTT – ĐH Thủy lợi

26

Các phương thức của lớp Assert

Phương thức

Mô tả

Assert.GreaterOrEqual(x, y)
Assert.LessOrEqual(x,y)

Xác nhận x <= y
Xác nhận x >= y

Assert.IsNull(object [, string
message])

Assert.IsNotNull(object [, string
message])

Xác nhận một đối tượng là null, ngược lại kiểm
thử thất bại.
Xác nhận một đối tượng là khác null, ngược lại
kiểm thử thất bại.

06/11/2019

Nguyễn Thị Phương Dung - Khoa CNTT – ĐH Thủy lợi

27

Các phương thức của lớp Assert

Phương thức

Mô tả

Assert.IsTrue(bool condition [,
string message])

Xác nhận điều kiện đã cho là đúng, ngược lại
kiểm thử thất bại.

Assert.IsFalse(bool condition [,
string message])

Xác nhận điều kiện đã cho là sai, ngược lại
kiểm thử thất bại.

06/11/2019

Nguyễn Thị Phương Dung - Khoa CNTT – ĐH Thủy lợi

28

Ví dụ

06/11/2019

Nguyễn Thị Phương Dung - Khoa CNTT – ĐH Thủy lợi

29

Thực hiện kiểm thử

• Sử dụng cửa sổ Test Explorer để thực thi các

unit test

• Mở cửa sổ Test Explorer bằng cách vào menu

Test/Windows/Test Explorer

06/11/2019

Nguyễn Thị Phương Dung - Khoa CNTT – ĐH Thủy lợi

30

Thực hiện kiểm thử

• Tại cửa sổ Test Explorer

– Bấm chuột phải vào đơn vị

test cần chạy

– Chọn Run Selected Tests
– Kết quả sẽ được hiển thị ở

bên dưới cửa sổ Test
Explorer

06/11/2019

Nguyễn Thị Phương Dung - Khoa CNTT – ĐH Thủy lợi

31

