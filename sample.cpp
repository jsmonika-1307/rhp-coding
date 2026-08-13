#include<set>
#include<iostream>
using namespace std;
int main(){
  int n;
  cin>>n;
  set<int> s;
  while(n--){
      int curr; cin>>curr;
      s.insert(curr);
  }
  cout<<s.size()<<endl;
  for(int i : s){
      cout<<i<<" ";
  }
}