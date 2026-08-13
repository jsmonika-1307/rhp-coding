#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>>& arr, int row, int col, int m, int n) {
    if (row < 0 || row >= m || col < 0 || col >= n || arr[row][col] == '#') {
        return;
    }
    arr[row][col] = '#';
    dfs(arr, row + 1, col, m, n);
    dfs(arr, row - 1, col, m, n);
    dfs(arr, row, col + 1, m, n);
    dfs(arr, row, col - 1, m, n);
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<char>> arr(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int rooms = 0;
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            if (arr[row][col] == '.') {
                rooms++;
                dfs(arr, row, col, m, n);
            }
        }
    }

    cout << rooms << endl;
    return 0;
}