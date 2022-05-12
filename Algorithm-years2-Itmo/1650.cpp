#include <bits/stdc++.h>

using namespace std;

unordered_map <string, string> personLocation; // location and person
unordered_map <string, long long> personMoney; // money and person
unordered_map <string, long long> cityMoney; // city and sum money of city
map <long long, set<string>> moneyCities; // money and cities have the same money
map <string, long long> topCitiesState; // result
 
void addPerson(string name, string location, long long money);
void changeLocationOfPerson(string name, string locationNew);
// Returns the city with the highest state at the moment
string getTopCity();
//  If a billionaire comes to a city, 
// increase the amount of money in that city, store the data in map
void increaseCityMoney(string city, long long money);

int main(){

    long long n; // number billionaire
    cin >> n;

    for(long long i = 0; i < n; i++){
        string name;
        string location;
        long long money;
        cin >> name >> location >> money;
        addPerson(name,location, money); // person with name , city and money
        increaseCityMoney(location,money);
    }

    long long days, k;
    long long prevDay = 0;
    cin >> days >> k;
    for(long long i = 0; i  < k; i++){
        long long day;
        string name, newLocation;
        cin >> day >> name >> newLocation;
        string topCity = getTopCity();
        if(topCity.length() != 0 && day - prevDay != 0){
            topCitiesState[topCity] += day - prevDay;
        }
        changeLocationOfPerson(name, newLocation);
        prevDay = day;
    }
    
    // ngay cuoi ghi lai su di chuyen cua ty phu
    // ta lay so ngay co du lieu tru di 
    // ngay cuoi cung ghi duoc du si chuyen cua ty phu 
    // nay de tinh so ngay o trang thai cao nhat cua thanh pho do
    if(days - prevDay != 0){
        string topCity = getTopCity();
        if(topCity.length() != 0){
            topCitiesState[topCity] += days - prevDay;
        }
    }

    for(auto position = topCitiesState.begin(); position != topCitiesState.end(); position++){
        cout << position -> first << " " << position->second << endl;
    }

    getchar();
    getchar();
    return 0;
}


void addPerson(string name, string location, long long money){

    personLocation[name] = location;
    personMoney[name] = money;

}

void changeLocationOfPerson(string name, string locationNew){

    string prevLocation = personLocation[name]; // prevlocation of billionaire
    long long prevMoneyCity = cityMoney[prevLocation]; // previous money of this city

    // xoa thanh pho voi so tien cu
    // roi thanh pho thi tru so tien pw vi tri cu va luu lai vao map
    moneyCities[prevMoneyCity].erase(prevLocation);
    if(moneyCities[prevMoneyCity].size() == 0){
        moneyCities.erase(prevMoneyCity);
    }

    cityMoney[prevLocation] -= personMoney[name];
    moneyCities[cityMoney[prevLocation]].insert(prevLocation);

    // Thanh pho moi den 
    long long newCityMoney = cityMoney[locationNew]; 
    moneyCities[newCityMoney].erase(locationNew); // co nguoi den nen so tien trong thanh pho thay doi
    // nen xoa thanh pho tuong ung voi so tien do di
    if(moneyCities[newCityMoney].size() == 0){
        moneyCities.erase(newCityMoney);
    }

    cityMoney[locationNew] += personMoney[name];
    // them vao danh sach dia diem den voi mot muc tien moi 
    moneyCities[cityMoney[locationNew]].insert(locationNew);
    personLocation[name] = locationNew; // cho o moi cua ty phu

} 

string getTopCity(){
    map <long long, set<string> > :: reverse_iterator it = moneyCities.rbegin();
    if(it != moneyCities.rend() && it -> second.size() == 1){
        return *(it-> second.begin());
    }
    return "";
}

void increaseCityMoney(string city, long long money){
    if(cityMoney.find(city) != cityMoney.end()){
        moneyCities[cityMoney[city]].erase(city);

        if(moneyCities[cityMoney[city]].size() == 0){
            moneyCities.erase(cityMoney[city]);
        }
    }
    cityMoney[city] += money;
    moneyCities[cityMoney[city]].insert(city);
}
