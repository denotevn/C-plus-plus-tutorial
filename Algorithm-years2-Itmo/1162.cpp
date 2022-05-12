#include<bits/stdc++.h>

using namespace std;

struct Edges{
    int a,b;
    double r,c; // Exchange rates and commissions
};

int N;// N-the number of currencies
int M; // the number of exchange points
int S; // S - the number of currency Nick has 
double V; // V - the quantity of currency units he has

vector<Edges> edges;

double nodes[101];

int main(){

    cin >> N >> M >> S >> V;
    nodes[S] = V;
    edges.reserve(M);
    for(int i = 0; i < M; i++){
        int a, b; 
        double rab, cab, rba, cba; // exchange rates and commissions
        // when exchanging A to B and B to A respectively.
        cin >> a >> b >> rab >> cab >> rba >> cba; 
        edges.push_back({a,b,rab,cab});
        edges.push_back({b,a,rba, cba});
    }

    for(int i = 0; i < N - 1; i++){
        for(int j = 0; j < edges.size(); j++){
            nodes[edges[j].b] = max(nodes[edges[j].b], (nodes[edges[j].a] - edges[j].c)*edges[j].r);
        }
    }
    int count = 0;
    for(int i = 0; i < edges.size(); i++){
        if ((nodes[edges[i].a] - edges[i].c) * edges[i].r > nodes[edges[i].b]){
            count++;
        }
    }
    if(count) cout << "YES";
    else cout << "NO";
    
    return 0;
}
