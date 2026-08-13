#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<pair<int,int>> arr(N);
  for(int i = 0; i < N; i++){
    int ht,lt;
    cin>>ht>>lt;
    arr[i] = make_pair(ht,lt);
  }
  sort(arr.begin(), arr.end(), greater<>());
  int prev = 0;
  vector<int> ltarr;
  vector<int> htarr;
  for(auto[ht,lt] : arr){
    if(lt > prev){
      prev = lt;
      ltarr.push_back(lt);
      htarr.push_back(ht);
    }
  }
  int Q;
  cin>>Q;
  while(Q--){
    int qt;
    cin>>qt;
     auto it = upper_bound(ltarr.begin(),ltarr.end(), qt);
     int idx = it - ltarr.begin();
     cout<<htarr[idx]<<endl;
     }
  }