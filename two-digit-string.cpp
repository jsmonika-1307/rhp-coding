#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
int main(){
    string a,b;
    cin>>a>>b;
    int r = a.length();
    int c = b.length();
    vector<int> pa(r+1,0),pb(c+1,0);
    for(int i = 1; i < r; i++){
         pa[i] = pa[i-1] + (a[i]-'0');
    }
    for(int i = 1; i < c; i++){
         pb[i] = pb[i-1] + (b[i]-'0');
    }
    if(pa[r-1] != pb[c-1]){
        cout<<"-1";
        return 0;
    }
    vector<vector<int>> ans;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(pa[i] == pb[j]){
                ans[i][j] = 1 + ans[i-1][j-1];
            }
            else{
                ans[i][j] = max(ans[i-1][j],ans[i][j-1]);
            }
        }
    }
    cout<<ans[r-1][c-1];

}