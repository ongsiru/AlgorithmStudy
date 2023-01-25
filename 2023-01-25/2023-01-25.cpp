#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int n;
	int box[1001];
	int dp[1001];
	cin >> n;
	int ans = 1;

	for (int i = 0; i < n; i++) {
		cin >> box[i];
		dp[i] = 1;
	}


	for (int i = 1; i < n; i++) {
		int maxi = 0;
		for (int j = 0; j < i; j++) {
			if (box[j] < box[i]) {
				if (dp[j] > maxi) {
					maxi = dp[j];
				}
			}
		}
		dp[i] += maxi;
		ans = max(dp[i], ans);
	}

	cout << ans;


	return 0;
}