#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
	int instruments;
	cin >> instruments;

	vector<int>weights(instruments);

	for (int i = 0; i < instruments; i++){
		cin >> weights[i];
	}

	int  summWeights = 0;

	for (int i = 0; i < instruments; i++){
		summWeights += weights[i];
	}

	int minimaldiff = summWeights;

	for (int i = 0; i < pow(2, instruments); i++){
		int subsetsumm = 0;
		for (int a = 0; a < instruments; a++){
			if (i & (1<<a)){
				subsetsumm +=weights[a];
			}
		}
	int diff = abs(summWeights - 2 * subsetsumm);
	minimaldiff = min(minimaldiff, diff);
	}
	
	cout << minimaldiff << endl; 
}
