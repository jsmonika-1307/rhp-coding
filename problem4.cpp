import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
  Scanner sc = new Scanner(System.in);

  int R = sc.nextInt();
 int C = sc.nextInt();

int[][] arr = new int[100][100];
long[][] dp = new long[100][100];

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                arr[i][j] = sc.nextInt();
                if (i == 0) {
                    dp[i][j] = arr[i][j];
                }
            }
        }

        for (int row = 1; row < R; row++) {
            long firstMax = 0;
            long secondMax = 0;

            for (int col = 0; col < C; col++) {
                if (dp[row - 1][col] > firstMax) {
                    secondMax = firstMax;
                    firstMax = dp[row - 1][col];
                } else if (dp[row - 1][col] > secondMax) {
                    secondMax = dp[row - 1][col];
                }
            }

            for (int col = 0; col < C; col++) {
                if (dp[row - 1][col] == firstMax) {
                    dp[row][col] = arr[row][col] + secondMax;
                } else {
                    dp[row][col] = arr[row][col] + firstMax;
                }
            }
        }

        long ans = dp[R - 1][0];

        for (int col = 1; col < C; col++) {
            if (dp[R - 1][col] > ans) {
                ans = dp[R - 1][col];
            }
        }

        System.out.println(ans);
        sc.close();
    }
}