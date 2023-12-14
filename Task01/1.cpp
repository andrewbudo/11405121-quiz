#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> weights(n);
    int totalWeight = 0;
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
        totalWeight += weights[i];
    }

    int minDifference = totalWeight;
    for (int mask = 0; mask < (1 << n); ++mask) {
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                sum1 += weights[i];
            } else {
                sum2 += weights[i];
            }
        }
        minDifference = min(minDifference, abs(sum1 - sum2));
    }

    cout << minDifference << endl;

    return 0;
}
