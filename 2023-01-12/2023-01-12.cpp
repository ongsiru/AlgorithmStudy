#include <iostream>

using namespace std;
#define MAX 9

int N, M;
int arr[MAX];
bool visited[MAX];

void dfs(int k) {
    if (k == M) { // M까지 들어갔을 시 실행
        for (auto i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
    else { // M까지 안 들어갔을 시
        for (auto i = 1; i <= N; i++) { //1부터!
            arr[k] = i; // 값 저장
            dfs(k + 1); // 더 깊게 내려가자 (M까지)
        }
    }
}

int main() {
    cin >> N >> M;
    dfs(0);
}