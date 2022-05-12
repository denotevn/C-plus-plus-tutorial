

// How to use struct in C++ programming language
#include<iostream>

using namespace std;

enum Color{
    BLUE,
    GREEN,
    BLACK,
};

struct Point{
    int x;
    int y;
};

struct Person{
    string name;
    int age;
    string adress;
    double hight;
    Point point;
};




int main(){

    Person emnhaque = {"em nha que",25,"Ha Noi",1.7,2,3};
    cout<<"Name: "<<emnhaque.name<<endl;
    cout<<"adress: "<<emnhaque.adress<<endl;
    cout<<"age: "<<emnhaque.age<<endl;
    cout<<"Hight: "<<emnhaque.hight<<endl;
    cout<<"Location: "<<emnhaque.point.x<<"  "<<emnhaque.point.y<<endl;

    return 0;
}