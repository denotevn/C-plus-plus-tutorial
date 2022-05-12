// Toán tử phân giải phạm vi
#include <iostream>
using namespace std;
 
// Global variable
int x = 5;
 
// sd :: để truy xuat bien toan cucj tức là biên bên ngoài hàm main

int main() {
   // A local variable having the Same name as a global variable,
   // which hides the global variable
   float x = 55.5f;
 
   // Local
   cout << x << endl;
 
   // Use unary scope resolution operator to retrieve the global variable
   cout << ::x << endl;
 
   return 0;
}
