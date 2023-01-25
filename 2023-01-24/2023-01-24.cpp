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
    if (k == m)
    {
        for (int i = 0; i < k; i++)cout << arr[i] << " ";
        cout << "\n";
    }
    else {
        int prev = 0;
        for (int i = idx; i < num.size(); i++) {
            if (prev != num[i]) {
                arr[k] = num[i];
                prev = num[i];
                func(k + 1, i);
            }
        }
    }
}


int main() {
    cin >> n >> m;
    while (n--) {
        int in; cin >> in;
        num.push_back(in);
    }
    sort(num.begin(), num.end());
    func(0, 0);
    return 0;
}