#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    int totalWeight = 0;
    for (int i = 0; i < n; i++) {
        totalWeight += weights[i];
    }

    int minDiff = totalWeight;
    for (int i = 0; i < pow(2, n); i++) {
        int subsetSum = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                subsetSum += weights[j];
            }
        }
        int diff = abs(totalWeight - 2 * subsetSum);
        minDiff = min(minDiff, diff);
    }

    cout << minDiff << endl;

	return 0;
}
