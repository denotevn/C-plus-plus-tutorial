// ham don gian va ngan 
//su dung ham noi tuyen de loai bo chi phi goi ham
// su dung inline de tao ham noi tuyen de loai bo chi phi
#include<iostream>

using namespace std;


// ham noi tuyen 

inline int max(int a1,int a2){
    return (a1 > a2) ? a1 : a2;
}


int main(){

    int a1 = 5, a2 = 100;
    cout<<"Max : "<<max(a1,a2)<<endl;
    
    return 0;
}