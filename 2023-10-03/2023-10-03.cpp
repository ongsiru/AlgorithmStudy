#include <iostream>
#include <queue>
#include <vector>

#include <cstdlib>

using namespace std;

// 인접리스트 -> vector 2차 배열
vector<int> graph[5];
bool visited[5];

// DFS : 재귀호출과 Stack을 이용한 두 가지 구현 방법이 있다. 
// 코드 흐름을 만들기 위해서는 Stack으로 저장하는 등 복잡한 절차를 거쳐야 하지만, 재귀로 구현하면 복잡한 절차를 운영체제가 알아서 해주기 때문에 간편하다.
void dfs(int x) {
    visited[x] = true;
    printf_s("%c ", x + 65);

    for (int i = 0; i < graph[x].size(); i++) {
        int y = graph[x][i];
        if (!visited[y]) // 백트래킹
            dfs(y);// 방문하지 않았으면 dfs 실행
    }
}

// BFS : 재귀호출과 Stack을 이용한 두 가지 구현 방법이 있다. 
void bfs(int start) {
    queue<int> q;
    q.push(start); // 첫 노드를 queue에 삽입
    visited[start] = true; // 첫 노드를 방문 처리

    // 큐가 빌 때까지 반복
    while (!q.empty()) {
        // 큐에서 하나의 원소를 뽑아 출력
        int x = q.front();
        q.pop();
        printf_s("%c ", x + 65);

        // 해당 원소와 연결된, 아직 방문하지 않은 원소들을 큐에 삽입
        for (int i = 0; i < graph[x].size(); i++) {
            int y = graph[x][i];
            if (!visited[y]) {
                q.push(y);
                visited[y] = true;
            }
        }
    }
}

int main()
{
    /* 그래프 예시

    A ㅡ C ㅡ B
     ＼  |  / |
        E ㅡ D

    */

    graph[0].push_back(2);
    graph[0].push_back(4);
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(4);
    graph[2].push_back(0);
    graph[2].push_back(1);
    graph[2].push_back(4);
    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[4].push_back(0);
    graph[4].push_back(1);
    graph[4].push_back(2);
    graph[4].push_back(3);

    for (int i = 0; i < 5; i++) {
        printf_s("[%c] ", i + 65);
        for (int j = 0; j < graph[i].size(); j++) {
            // cout << graph[i][j] << " ";
            printf_s("%c ", graph[i][j] + 65);
        }
        cout << endl;
    }

    // DFS
    cout << endl << "1.DFS : ";
    dfs(0); // 노드 A부터 탐색 시작

    // 방문 초기화
    for (int i = 0; i < 5; i++) visited[i] = false;

    // BFS
    cout << endl << "2.BFS : ";
    bfs(0);// 노드 A부터 탐색 시작

    cout << endl;
}