#include <bits/stdc++.h>
/*
Một namespace được thiết kế để khắc phục vấn đề này và được sử 
dụng làm thông tin bổ sung để phân biệt các hàm, 
lớp, biến vv với cùng tên có sẵn trong các thư viện khác nhau. 
Sử dụng namespace trong C++, bạn có thể xác định
ngữ cảnh trong đó tên được chỉ định. 
Về bản chất, một namespace định nghĩa một phạm vi.

Định nghĩa namespace
Một định nghĩa namespace trong C++ bắt đầu với từ khóa namespace theo sau là tên namespace như sau:
            namespace namespace_name {
                // code
            }

            https://viettuts.vn/lap-trinh-cpp/namespace-trong-cpp
*/
using namespace std;

namespace functionality1 {
    void display(){
        cout << "This is function of namespace 1" <<endl;
    }
    void getName(){
        cout << "My name is Tuan! " << endl;
    }
}

namespace functionality2{
    void display(){
        cout<<"This is funtion of namespace 2" << endl;
    }
}

int main(){

    functionality1::display();
    functionality2::display();
    functionality1::getName();
    return 0; // default
}