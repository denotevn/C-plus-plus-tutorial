#include<bits/stdc++.h>

using namespace std;

int main(){
    int *p;
    cout<<p<<endl;

    int n = 5;

    for(int i = 0; i < n; i++){
        *(p+i) = i;
    }
    cout<<(p+0)<<endl;
    cout<<(p+2)<<endl;

    cout<<(p+3)<<endl;
    cout<<(p+4)<<endl;

    cout<<*(p+2)<<endl;
    return 0;
}