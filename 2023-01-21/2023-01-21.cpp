#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
#define MAX 9

int n, m;
int arr[MAX];
int vis[MAX];
vector<int> num;

void func(int k, int idx) {
    if (k == m) {
        for (int i = 0; i < k; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    else {
        int prev = 0;
        for (int i = idx; i < n; i++) {
            if (prev != num[i]) {
                arr[k] = num[i];
                prev = num[i];
                func(k + 1, i + 1);
            }

        }
    }
}
int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) { int in; cin >> in; num.push_back(in); }
    sort(num.begin(), num.end());
    func(0, 0);

    return 0;
}