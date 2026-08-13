#include<iostream>
#include<vector>
using namespace std;

int find(vector<int>& ldr, int a){
    if(ldr[a] == a) return a;
    return ldr[a] = find(ldr, ldr[a]);
}

void join(vector<int>& ldr, int a, int b){
    ldr[find(ldr, a)] = find(ldr, b);
}

int main(){
    int N, E;
    cin >> N >> E;

    vector<int> ldr(N + 1);
    vector<pair<int,int>> edges(E);

    for(int node = 1; node <= N; node++){
        ldr[node] = node;
    }

    for(int node = 0; node < E; node++){
        int a, b;
        cin >> a >> b;
        edges[node] = make_pair(a, b);
        join(ldr, a, b);
    }

    vector<int> gcount(N + 1, 0);
    vector<int> ecount(N + 1, 0);

    for(int node = 1; node <= N; node++){
        gcount[find(ldr, node)]++;
    }

    for(auto [a, b] : edges){
        ecount[find(ldr, a)]++;
    }

    long long ans = 0;

    for(int node = 1; node <= N; node++){
        long long curr =
            (long long)gcount[node] * (gcount[node] - 1) / 2
            - ecount[node];

        ans += curr;
    }

    cout << ans << endl;
}