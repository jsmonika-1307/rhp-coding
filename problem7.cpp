#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> arr(200002, 0);

    // Mark ranges using difference array
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;

        arr[l]++;
        arr[r + 1]--;
    }

    // Find how many recipes cover each temperature
    for (int i = 1; i <= 200000; i++) {
        arr[i] += arr[i - 1];
    }

    // Convert to 1 if temperature is acceptable
    for (int i = 1; i <= 200000; i++) {
        arr[i] = (arr[i] >= k);
    }

    // Prefix sum for fast queries
    vector<int> prefix(200001, 0);
    for (int i = 1; i <= 200000; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    // Answer queries
    while (q--) {
        int a, b;
        cin >> a >> b;

        cout << prefix[b] - prefix[a - 1] << "\n";
    }

    return 0;
}
