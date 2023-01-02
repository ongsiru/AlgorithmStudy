#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MN = 101;
const int MK = 100101;

int w[MN], cost[MN];
int dp[MK]; //1차원 배열

int main() {
    int N, K;   cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> cost[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = K; j >= 0; j--) { //큰 값부터 작은 값으로 
            if (j >= w[i]) //배낭에 넣을 수 있을 때만
                dp[j] = max(dp[j], dp[j - w[i]] + cost[i]); //더 큰 값으로 갱신
            printf("%d\n", dp[K]);
        }
    }

    cout << dp[K];
}