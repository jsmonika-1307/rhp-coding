#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
using namespace std;
int main() {
    int R; cin>> R;
    set<int> vis;
    map<int, vector<pair<int,int>>> g;
    while(R--){
        int src, dest, dist; cin>> src >> dest >> dist;
        g[src].push_back(make_pair(dest, dist));
        g[dest].push_back(make_pair(src, dist));
    }
    int st,end; cin>> st >> end;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0, st));
    while(!pq.empty()){
        auto[currdist, city] = pq.top(); pq.pop();
        if(!vis.contains(city)){
            vis.insert(city);
            if(city == end){
                cout<< currdist << endl;
                return 0;
            }
            for(auto [oc, ocd]: g[city]){
                if(!vis.contains(oc)){
                    pq.push(make_pair(currdist + ocd, oc));
                }
            }
        }
    }
    cout << "NO PATH EXISTS FROM " << st << " TO " << end << endl;
    return 0;
}