#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> cnt(3 * n + 1, 0);

        for (int i = 0; i < n; i++) {
            int curr;
            cin >> curr;
            cnt[curr]++;
        }

        int ans = 0;

        for (int val = 1; val <= 2 * n; val++) {
            int curr = val;

            while (cnt[curr] > k) {
                cnt[curr + 1] += cnt[curr] - 1;
                cnt[curr] = 1;
                curr++;
            }

            ans = max(ans, curr - val);
        }

        cout << ans << '\n';
    }

    return 0;
}