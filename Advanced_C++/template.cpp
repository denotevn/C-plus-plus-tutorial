#include <bits/stdc++.h>

/*Template trong C++ là nền tảng của lập trình tổng quát (generic programming), 
tức là viết code theo các mà độc lập với bất kỳ kiểu cụ thể nào.

nó một kiểu dữ liệu trừu tượng, đặc trưng cho các kiểu dữ liệu cơ bản

Có hai kiểu Template trong C++:

Function Template: là một khuôn mẫu hàm, cho phép định nghĩa các hàm tổng quát thao tác cho nhiều kiểu dữ liệu.
Class template: là một khuôn mẫu lớp, cho phép định nghĩa các lớp tổng quát cho nhiều kiểu dữ liệu

            https://viettuts.vn/lap-trinh-cpp/template-trong-cpp
*/


using namespace std;
// function template

template<typename T>
inline T const& Min(T const&a, T const&b){
    return a < b ? a : b;
}

// class template in C++ là
/**----------------------------------------------------------------
            template <class kieu_du_lieu> class ten_lop {
                .
                .
                .
            }
*/

template <class T> class Stack{
    private:
        vector<T> array;
    public:
        void push(T const&); // push phann tu vao stack
        void pop(); // pop
        T top() const; // tra ve phan tu tren cung
        bool isEmpty(){
            return array.size() == 0; // tra ve true neu trong
        }
};

template <class T> 
void Stack<T> :: push(T const& element){
    array.push_back(element);
}

template<class T>
void Stack<T> :: pop(){
    if(array.empty()){
        throw out_of_range("Stack<>::pop(): Empty stack");
    }
    array.pop_back(); // xoa phan tu cuoi cung
}

template <class T> 
T Stack<T> :: top() const{
    if(array.empty()){
        throw out_of_range("Stack<>::pop(): Empty stack");
    }
    return array.back();
}

int main(){

    int a = 2;
    int b = 5;
    cout << "Min(a,b) = " << Min(a,b) << endl;
    
    float a1 = 2.3;
    float b1 = 3.4242;
    cout << "Min(a,b) = "<< Min(a,b) <<endl;

    string str1 = " Hello ";
    string str2 = "Goodbye !";
    cout << "Min(str1, str2) = " << Min(str1, str2) << endl;

    // class Template trong C++

    try {
      cout << "_______Class Template IN C++___________" << endl;
      Stack<int> intStack;
      Stack<string> stringStack;
 
      // push int vao stack 
      intStack.push(7); 
      cout << intStack.top() <<endl; 
 
      // push string vao stack 
      stringStack.push("hello"); 
      cout << stringStack.top() << std::endl; 
      stringStack.pop(); 
      stringStack.pop(); 
   } catch (exception const& ex) { 
      cerr << "Exception: " << ex.what() <<endl; 
      return -1;
   } 



    return 0;
}