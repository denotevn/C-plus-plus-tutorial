#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    int tmp;
    while(b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}


int main (){
    long n, m, a, b;
    cin >> n >> m;
    cout << (n/gcd(a,b)) / (m/gcd(a,b));
    return 0;
}