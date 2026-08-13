#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
int main(){
  int L,Q;
  cin>>L>>Q;
  set<int> st;
  st.insert(0);
  st.insert(L);
  while(Q--){
    int qt, x;
    cin>>qt>>x;
    if(qt == 1){
      st.insert(x);
    }
    else{
      auto it = st.lower_bound(x);
      cout<<(*it - *(prev(it)))<<endl;
    }
  }
}