#include <bits/stdc++.h>

using namespace std;

#define MIN(a,b) (((a) < (b)) ? (a) : (b))


/**
 *
 * Biên dịch có điều kiện trong C++
Có một số chỉ thị tiền xử lý có thể sử dụng để biên dịch 
có sự tuyển chọn giữa các phần trong source code của bạn. 
Tiến trình này được gọi là biên dịch có điều kiện.
 * 
            #ifndef NULL 
            #define NULL 0 
            #endif
 * @return int 
 */



int main(){
    int i, j;
    i = 5;
    j = 6;

    cout << "Min (i,j) = " << MIN(i,j) << endl;
    return 0;
}