# 📗AlgorithmStudy

### Index

<details>
  <summary>
    정리노트
  </summary>
  <div>
    2023-01-05  <a href="https://github.com/ongsiru/AlgorithmStudy/blob/master/2023-01-05/2023-01-05.cpp">C++ 자료구조 STL 정리</a> <br>
    2023-09-16  <a href="https://github.com/ongsiru/AlgorithmStudy/blob/master/2023-09-16/2023-09-16.cpp">C++ 알고리즘 STL 정리</a> <br>
    2023-09-27  <a href="https://github.com/ongsiru/AlgorithmStudy/blob/master/2023-09-28/2023-09-28.cpp">C++ 자료구조 그래프 구현</a> <br>
    2023-10-03  <a href="https://github.com/ongsiru/AlgorithmStudy/blob/master/2023-10-03/2023-10-03.cpp">C++ 알고리즘 탐색 구현</a> <br>
  </div>
</details>

<details>
  <summary>
    탐색
  </summary>
  <div>
    2022-12-31 https://www.acmicpc.net/problem/7576 <br>
    2023-01-03 https://www.acmicpc.net/problem/2606 <br>
    2023-01-04 https://www.acmicpc.net/problem/15649 <br>
    2023-01-11 https://www.acmicpc.net/problem/15650 <br>
    2023-01-12 https://www.acmicpc.net/problem/15651 <br>
    2023-01-13 https://www.acmicpc.net/problem/15652 <br>
    2023-01-15 https://www.acmicpc.net/problem/15654 <br>
    2023-01-17 https://www.acmicpc.net/problem/15655 <br>
    2023-01-18 https://www.acmicpc.net/problem/15656 <br>
    2023-01-19 https://www.acmicpc.net/problem/15657 <br>
    2023-01-20 https://www.acmicpc.net/problem/15663 <br>
    2023-01-21 https://www.acmicpc.net/problem/15664 <br>
    2023-01-22 https://www.acmicpc.net/problem/15665 <br>
    2023-01-24 https://www.acmicpc.net/problem/15666 <br>
    2023-01-31 https://www.acmicpc.net/problem/1260 <br>
    2023-11-20 https://github.com/ongsiru/AlgorithmStudy/blob/master/2023-11-20/2023-11-20.cpp <br>
  </div>
</details>

<details>
  <summary>
    그리디
  </summary>
  <div>
    2023-01-06 https://www.acmicpc.net/problem/1800 <br>
    2023-01-07 https://www.acmicpc.net/problem/13458 <br>
    2023-01-08 https://www.acmicpc.net/problem/1461 <br>
    2023-01-09 https://www.acmicpc.net/problem/1464 <br>
    2023-01-26 https://www.acmicpc.net/problem/11047 <br>
    2023-01-27 https://www.acmicpc.net/problem/1931 <br>
    2023-01-29 https://www.acmicpc.net/problem/1541 <br>
    2023-01-30 https://www.acmicpc.net/problem/11399 <br>
  </div>
</details>

<details>
  <summary>
    중복&DP
  </summary>
  <div>
    2022-12-30 https://www.acmicpc.net/problem/12865 <br>
    2023-01-25 https://www.acmicpc.net/problem/1965 <br>
    2023-11-18 https://github.com/ongsiru/AlgorithmStudy/blob/master/2023-11-18/2023-11-18.cpp <br>
  </div>
</details>

# 📘Coding Test Summary

### 1. 탐색

A. DFS와 백트래킹

```cpp

vector<bool> visited(MAX, false);
vector<int> nums;
vector<int> arr;

// 1. 중복순열
// 순열 > 0부터 시작하는데 순서에 따라 다름
void dfs(int cnt)
{
    // 종료조건
    if (cnt == MAX)
    {
        print();
        return;
    }
    // 연산
    // 재귀조건
    // a.중복순열
    for (int i = 0; i < 4; i++)
    {
        arr.push_back(nums[i]);
        dfs(cnt + 1);
        arr.pop_back();
    }
    // b.순열

    for (int i = 0; i < 4; i++)
    {
        if (visited[i]) continue;
        visited[i] = true;
        arr.push_back(nums[i]);
        dfs(cnt + 1);
        visited[i] = false;
        arr.pop_back();
    }
}
// 조합 > start부터 인덱스 시작, 방문했으면 해당
void dfs(int cnt, int start)
{
    // 종료조건
    if (cnt == MAX)
    {
        print();
        return;
    }
    // 연산
    // 재귀조건
    // a.중복조합
    for (int i = start; i < 4; i++)
    {
        arr.push_back(nums[i]);
        dfs(cnt + 1, i);
        arr.pop_back();
    }
    // b.조합
    for (int i = start; i < 4; i++)
    {
        if (visited[i]) continue;
        visited[i] = true;
        dfs(cnt + 1, i);
        visited[i] = false;
    }
}
```
B. BFS 좌표

```cpp
int r_dir[4] = { -1, 1, 0, 0 };   // 상하 방향
int c_dir[4] = { 0, 0, -1, 1 };   // 좌우 방향
// 자료구조 선언
vector<vector<int>> map(n, vector<int>(m, 0));
vector<vector<bool>> visited(n, vector<int>(m, false));
queue<pair<int, int>> q;
// 하나씩 증가하면 거리, 현재 위치를 반영하면 경로
vector < vector <?>> dist(n, vector <?> (m, ?));

void bfs(int sr, int sc)
{
    // 초기 조건 3개
    q.push(make_pair(sr, sc));
    visited[sr][sc] = true;
    dist[sr][sc] = ?;
    // 큐 반복
    while (!q.empty())
    {
        // 수거
        int rr = q.first();
        int cc = q.second();
        q.pop();
        // 도착이면 종료
        if ({ rr, cc} == dest) break;
        // 4방향
        for (int i = 0; i < 4; i++){
            int nr = rr + r_dir[i];
            int nc = cc + c_dir[i];
            // 경계조건
            if (0 > nr || n <= nr) continue;
            if (0 > nc || m <= nr) continue;
            // 방문조건
            if (!visited[nr][nc] && map[][])
            {
                visited[nr][nc] = true;
                q.push(make_pair(nr, nc));
                //dist[nr][nc] = (거리or경로) ? 현재 + 1 : 현재 경로;
            }
        }
    }
}
```
C. 이분탐색 > 시간복잡도 logN
```cpp
bool binary_search(vector<int> arr, int target)
{
    int len = arr.size();
    int low = 0, high = len - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        // 원하는 값일 때
        if (target == arr[mid]) return true;
        // 원하는 값보다 작을 때
        if (target < arr[mid]) { high = mid - 1; }
        // 원하는 값보다 클 때
        else if (target > arr[mid]) { low = mid + 1; }
    }
    return false; // 못 찾으면 false 반환
}
```
D. 크루스칼과 유니온 파인드
```cpp
// 유니온 파인드
using System.Numerics;

int parent[MAX];
int find(int x)
{
    if (parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}
bool isSameParent(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) return true;
    else return false;
}
void union(int x, int y)
{
    x = find(x);
    y = find(y);
    parent[y] = x;
}
// 크루스칼
int vertex, edge;
int result = 0;
vector<pair<int, pair<int, int>>> graph; // {weight, {vertex, vertex}}
                                         // 정렬
sort(graph.begin(), graph.end()); > 최소

    for (int i = 1; i <= vertex; i++) parent[i] = i;
for (int i = 0; i < graph.size(); i++)
{
    if (!isSameParent(graph[i].second.first, graph[i].second.second))
    {
        union(graph[i].second.first, graph[i].second.second);
        result += v[i].first;
    }
}
cout << result;
```
E. 다익스트라
```cpp
vector<pair<int, int>> nodes[N];
vector<int> dist(N, INF);

void dijkstra(int start)
{
    priority_queue<pair<int, int>> pq;
    pq.push({ 0, start });
dist[start] = 0;

while (!pq.empty())
{
    // 내림차순 정렬의 최소값이 가장 앞에 오도록 하기 위해 음수로 변환
    int weight = -pq.top().first;
    int current = pq.top().second;
    pq.pop();
    // 각 연결된 노드 중 최단 거리 비교
        for (int i = 0; i < nodes[here].size(); i++)
        {
            // 경유해서 가는게 빠르면 dist 갱신 후 push
            int nWeight = weight + nodes[current][i].first;
            int next = nodes[current][i].second
            if (nWeight < dist[next]){
                dist[next] = nWeight;
                pq.push({ -nWeight, next });
            }
        }
    }
}

```
 F. 그리디 > 정렬
```cpp
struct element
{
    int a;
    int b;
    int c;
};
struct compare
{
    bool operator()(element A, element B){
		    if (A.a != B.a) return A.a<B.a;
		    else if (A.b != B.b) return A.b<B.b;
		    else if (A.c != B.c) return A.c<B.c;
	    }
    };
// element 타입, vector 컨테이너
priority_queue<element, vector<element>, compare> pq;
```
### 2. DP
일정한 규칙을 점화식부터 세우기
### 3. 정렬
A. 퀵 정렬 > 시간복잡도 NlogN
### 4. 슬라이딩 윈도우
특정 조건의 구간 구하기
### 5. 에라토스테네스의 체
```cpp
vector<bool> v(num + 1, true);
// 소수 판별
for (int i = 2; i * i <= num; i++)
{
    if (v[i])
    {
        for (int k = i * i; k <= num; k += i)
        {
            v[k] = false;
        }
    }
}
```
### 6. 비트마스킹
```
Left : <<
Right : >>
NOT(각 비트의 0과 1 반전) : ~ 
AND : &
OR : |
XOR : ^
```
