#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int find(int ldr[], int node){
  if(ldr[node] != node){
    ldr[node] = find(ldr,ldr[node]);
  }
  return ldr[node];
}
void join(int ldr[], int lt, int rt){
  ldr[find(ldr,rt)] = find(ldr,lt);
}
int main(){
  int N,E;
  cin>>N>>E;
  vector<pair<int,pair<int,int>>> edges;
  int ldr[N+1];
  for(int node = 1; node<= N; node++){
    ldr[node] = node;
  }
  while(E--){
    int a,b,cost;
    cin>>a>>b>>cost;
    if(cost <= 0){
      join(ldr,a,b);
    }
    else{
      edges.push_back(make_pair(cost,make_pair(a,b)));
    }
  }
  long long rewards = 0;
  sort(edges.begin(), edges.end());
  for(auto[cost,p] : edges){
    int a = p.first, b = p.second;
    if(find(ldr,a) != find(ldr,b)){
      join(ldr,a,b);
    }
    else{
      rewards += cost;
    }
  }
  cout<<rewards<<endl;
}