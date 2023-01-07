#include <iostream>
#include <vector>
#include <queue>
#define MAX 987654321

using namespace std;

int n, p, k;
int answer = MAX;

vector<vector<pair<int, int> > > edges;
int minPassed[1001];

bool dijkstra(int target) {

    for (int i = 1; i <= n; i++) minPassed[i] = MAX;

    priority_queue<pair<int, int> > pq;
    pq.push({ 0, 1 });
    minPassed[1] = 0;

    while (!pq.empty()) {

        int here = pq.top().second;
        int passed = -pq.top().first;
        pq.pop();

        if (minPassed[here] > passed) continue;

        for (int i = 0; i < edges[here].size(); i++) {
            int next = edges[here][i].first;
            int next_passed = passed + (edges[here][i].second > target);

            if (next_passed < minPassed[next]) {
                minPassed[next] = next_passed;
                pq.push({ -next_passed, next });
            }
        }
    }

    return minPassed[n] <= k;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> p >> k;
    edges.resize(n + 1);

    int u, v, c;
    int maxNum = 0;
    for (int i = 0; i < p; i++) {
        cin >> u >> v >> c;
        edges[u].push_back({ v, c });
        edges[v].push_back({ u, c });
        maxNum = max(maxNum, c);
    }


    int left = 0, right = maxNum, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (dijkstra(mid)) {
            right = mid - 1;
            answer = mid;
        }
        else {
            left = mid + 1;
        }
    }

    if (answer == MAX) cout << -1;
    else cout << answer;
}
