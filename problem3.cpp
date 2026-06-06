#include <iostream>
using namespace std;

int main() {
int R, C;
cin >> R >> C;
int arr[100][100];
    long int dp[100][100];

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> arr[i][j];
            if(i == 0)
                dp[i][j] = arr[i][j];
        }
    }

for(int row = 1; row < R; row++) {
  long int firstMax = 0, secondMax = 0;
    for(int col = 0; col < C; col++) {
      if(dp[row-1][col] > firstMax) {
             secondMax = firstMax;
            firstMax = dp[row-1][col];
            }
            else if(dp[row-1][col] > secondMax) {
  secondMax = dp[row-1][col];
    }
     }
for(int col = 0; col < C; col++) {
  if(dp[row-1][col] == firstMax)
    dp[row][col] = arr[row][col] + secondMax;
  else
    dp[row][col] = arr[row][col] + firstMax;
        }
    }
long int ans = dp[R-1][0];

  for(int col = 1; col < C; col++) {
        if(dp[R-1][col] > ans)
            ans = dp[R-1][col];
    }

    cout << ans;
}