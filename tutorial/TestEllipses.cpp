/*
 *  TestEllipses.cpp
 */
#include <iostream>
#include <cstdarg>
using namespace std;
 
int sum(int, ...);
 

 // Ham main 

int main(){
   cout << "Sum : "<<sum(5,1,2,3,4,5) << endl;  // lu y 5 la so luong bien trong ham sum
   cout<<"Sum of some number: "<<sum(3,0,4,5)<<endl; // tuong tu 3 la so luong bien con 0,4,5 moi dung de cong tong 

   return 0;
}


int sum (int count, ...){
   int sum = 0;

   // Dấu ba chấm được truy cập thông qua va_list
   va_list list;
   // Sử dụng hàm va_start để khởi tạo va_list,
   // với tên danh sách và số lượng tham số. 

   va_start (list, count);

   for(int i=0; i<count; i++){
      // Sử dụng hàm va_arg để đọc từng tham số từ va_list,
      // with the type
      sum += va_arg(list,int);
   }

   // clean up the va_list
   va_end(list);

   return sum;
}
