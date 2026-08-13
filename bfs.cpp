#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int dr[4] = {-1, 1, 0, 0};
const int dc[4] = {0, 0, -1, 1};

string getPath(int R, int C, vector<string>& g, int brow, int bcol);

int main() {
    int R, C;
    cin >> R >> C;

    string dir = "UDLR";
    vector<string> g(R);

    for (int r = 0; r < R; r++) {
        cin >> g[r];
    }

    queue<pair<int, int>> q;

    // Find A
    for (int row = 0; row < R; row++) {
        for (int col = 0; col < C; col++) {
            if (g[row][col] == 'A') {
                q.push({row, col});
                row = R;   // break outer loop
                break;
            }
        }
    }

    int hops = -1;
    int brow = -1;
    int bcol = -1;
    bool found = false;

    while (!q.empty()) {
        int qsize = q.size();
        hops++;

        while (qsize--) {
            auto [row, col] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int ar = row + dr[i];
                int ac = col + dc[i];

                if (ar >= 0 && ar < R && ac >= 0 && ac < C) {

                    // We can visit this cell
                    if (g[ar][ac] == '.') {
                        g[ar][ac] = dir[i];
                        q.push({ar, ac});
                    }

                    // We found B
                    else if (g[ar][ac] == 'B') {
                        g[ar][ac] = dir[i];
                        brow = ar;
                        bcol = ac;
                        found = true;
                    }
                }
            }
        }

        // B was found after processing this BFS level
        if (found) {
            cout << "YES\n";
            cout << hops + 1 << "\n";
            cout << getPath(R, C, g, brow, bcol) << "\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}

string getPath(int R, int C, vector<string>& g, int brow, int bcol) {
    string path = "";

    while (g[brow][bcol] != 'A') {

        char dir = g[brow][bcol];

        if (dir == 'U') {
            path += 'U';
            brow++;
        }
        else if (dir == 'D') {
            path += 'D';
            brow--;
        }
        else if (dir == 'L') {
            path += 'L';
            bcol++;
        }
        else if (dir == 'R') {
            path += 'R';
            bcol--;
        }
    }
    reverse(path.begin(), path.end());
    return path;
    
}