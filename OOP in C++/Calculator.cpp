#include <bits/stdc++.h>

class Calculator{
    public:
        using number_type = int; // this is nested type alias

        std::vector<number_type> m_resultHistory;

        number_type add(number_type a, number_type b){
            auto result{a+b};

            m_resultHistory.push_back(result);

            return result;
        }
};
int main(){
    Calculator calculator{};
    calculator.add(3,6)<<'\n';
    calculator.add(12,32)<<'\n';
    for(Calculator::number_type num : calculator.m_resultHistory){
        std::cout << num <<'\n';
    }
    return 0;
}