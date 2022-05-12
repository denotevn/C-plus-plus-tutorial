#include "bits/stdc++.h"

using namespace std;
int square(int x){
    return x*x;
}
int main(){

    vector<int> v;
    v.push_back(2);
    v.push_back(-3);
    v.push_back(4);
    v.push_back(3);

    ostream_iterator<int,char> output(cout," ");
    copy(v.begin(), v.end(), output);
    cout << endl;

    transform(v.begin(), v.end(),square);
    copy(v.begin(), v.end(),output);
    cout<<endl;

    return 0;
}