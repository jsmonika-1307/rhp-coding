#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
int n; cin>>n;
vector<int> a(n);
for(int i = 0; i < n; i++){
	cin>>a[i];
}
sort(a.begin(), a.end());
vector<int> ans;
long long cf = 0ll;
for(int ctr = 1; ctr <= a[n-1]; ctr++){
	auto it = lower_bound(a.begin(),a.end(), ctr);
	int cnt = a.end() - it;
	cf += cnt;
	ans.push_back(cf % 10);
	cf /= 10;
}
while(cf > 0){
	ans.push_back(cf % 10);
	cf /= 10;
}
for(int i = (int)(ans.size()) - 1; i >= 0; i--){
	cout<<ans[i];
}
}