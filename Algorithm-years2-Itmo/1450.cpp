#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> int_pair;
int maxCost[505];

int main(){
    int n,m;
    cin >> n >> m;  
    vector<int_pair> nodes[505];

    for(int i = 1; i <= m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        nodes[a].push_back({b,c});
    }

    int s,t;
    cin >> s >> t;
    queue<int> points;
    points.push(s);

    while(!points.empty()) {
        int a = points.front();
        points.pop();
        for(auto& point : nodes[a]){
            int b = point.first, c = point.second;
            if(maxCost[b] < maxCost[a] + c){
                maxCost[b] = maxCost[a] + c;
                points.push(b);
            }
        }
    }

    if(maxCost[t] != 0) cout << maxCost[t];
    else cout << "No solution";

    return 0;

}