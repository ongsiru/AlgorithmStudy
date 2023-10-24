#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n = 0, st = 0, ed = 0, temp = 0;
    long long ans = 0;
    cin >> n;
    vector<pair<int, int>> v(n, { 0,0 });

    for (int i = 0; i < n; i++) {
        cin >> st >> ed;
        if (st > ed) {
            st = temp;
            st = ed;
            ed = temp;
        }
        v[i] = { st,ed };
    }
    sort(v.begin(), v.end());
    st = v[0].first, ed = v[0].second;
    for (int i = 1; i < n; i++) {
        if (ed > v[i].first) {
            if (v[i].second > ed) ed = v[i].second;
        }
        else {
            ans += ed - st;
            st = v[i].first, ed = v[i].second;
        }
    }
    ans += ed - st;
    cout << ans << "\n";
    return 0;
}