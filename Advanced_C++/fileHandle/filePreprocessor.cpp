#include<bits/stdc++.h>
#define path "text.txt"
using namespace std;

int main(){
    fstream newFileStream;

    newFileStream.open("newText.txt",ios::out);

    if(newFileStream){
        cout<<"Success created new text file!" <<endl;
    }
    else{
        cout << "Something went wrong when created file !" <<endl;
    }
    // ghi vao file
    newFileStream << "Tuan Dinh iu Khanh Ngoc";
   
    
    newFileStream.close();
}