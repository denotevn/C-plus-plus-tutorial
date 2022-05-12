#include<bits/stdc++.h>

using namespace std;

class DatasetClass
{
private:
    int year;
    int month;
    int day;
public:
    DatasetClass(int y, int m, int d){
        this->year = y;
        this -> month = m;
        this -> day = d;
    }
    void print_dataset(){
        cout<< "Year: "<< year<< " month: "<< month<<" Day: "<<day<<endl;
    }
};

int main(){
    DatasetClass time = DatasetClass(3,2,1);
    time.print_dataset();
    return 0;
}
