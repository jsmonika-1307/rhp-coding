#include <iostream>
#include<string.h>
using namespace std;
int main()
{
    int maxlen = 0;
    string s1,s2;
    cin>>s1>>s2;
    int dp[100][100] = {0};
    for(int row = 1; row <= s2.length(); row++){
        for(int col = 1; col <= s1.length(); col++){
            if(s1[col - 1] == s2[row - 1]){
                 dp[row][col] = dp[row-1][col-1] + 1;
                 
                 if(dp[row][col] > maxlen)
                    maxlen = dp[row][col];
            }
            else {
                dp[row][col] = 0;
            }
            
        }
    }
    cout<<maxlen;
    return 0;
}
 