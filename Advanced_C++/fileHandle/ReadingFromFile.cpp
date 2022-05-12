#include <bits/stdc++.h>

using namespace std;
#define PATH "text.txt"
int main(){

    fstream newFile;
    newFile.open("newText.txt",ios::in);
    if(!newFile){
        cerr << "No such file" << std::endl;
    }
    else
    {
        char ch;
        while(newFile.eof()){
            newFile >> ch;
            cout << ch;
        } 
    }

    return 0;
}