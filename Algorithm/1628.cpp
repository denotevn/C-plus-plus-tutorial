#include<bits/stdc++.h>

using namespace std;

bool commpare(pair<int,int> &a, pair<int,int> &b){
    if(a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}

int main(){
    
    int m,n,k;
    int result = 0;
    cin >> m >> n >> k;
    int x,y;

    map<pair<int, int>,bool> isBlack;
    vector<pair<int, int>> blackList;


    for(int i = 0; i < k; i++){
        cin >> x >> y;
        blackList.push_back({x,y});
        isBlack[{x,y}] = true;
    }

    for(int i = 0; i <= n+1; i++){
        blackList.push_back({0,i});
        blackList.push_back({n+1, i});
        isBlack[{0,i}] = true;
        isBlack[{n+1,i}] = true;
    }

    // boi den ow dau va cuoi
    for(int i = 0; i <= m+1; i++){
        blackList.push_back({i,0});
        blackList.push_back({i,m+1});
        isBlack[{i,0}] = true;
        isBlack[{i,m+1}] = true;
    }
     sort(blackList.begin(), blackList.end(), [](pair<int,int> &p, pair<int,int> &q){
        if(p.second != q.second) return p.second < q.second;
        return p.first < q.first;
    });
    // sort(blackList.begin(), blackList.end());

    for(int i = 0; i < blackList.size() - 1; i++){
        if(blackList[i + 1].second - blackList[i].second > 2 ){
            ++result;
        }
    }

    sort(blackList.begin(), blackList.end(), commpare);
    for(int i = 0; i < blackList.size() - 1; i++){
        if(blackList[i + 1].first - blackList[i].first > 2){
            ++result;
        }
        if(blackList[i+1].first - blackList[i].first == 2){
            int index = blackList[i].second;
            int a1 = blackList[i].first + 1;
            int b1 = index - 1; // hang truoc do
            int b2 = index + 1; // hang sau do
            if(isBlack[{a1,b2}] && isBlack[{a1, b1}]){
                ++result;
            }
        }
    }

    cout << result <<endl;

    return 0;
}