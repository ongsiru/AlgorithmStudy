// C++로 그래프 자료구조를 구현한 것을 정리했다.

#include <iostream>
#include <vector>

#include <cstdlib>
#include <ctime>

using namespace std;

// ①Graph : 정점이 n개, 간선이 m개인 그래프는 아래의 방법으로 구현할 수 있다.

int AdjacencyMatrix[5][6]; // 인접 행렬
/* 변수를 통해서 배열을 동적으로 생성할 때
   1차원 -> int *Matrix1= new int[n];
   2차원 -> int **Matrix2 = new int *[n]; for (int i = 0; i <= n; ++i) Matrix2[i] = new int[m];
   해제  -> delete 포인터/포인터변수;
*/
vector<int> AdjacencyList[5]; // 인접 리스트

vector<pair<int, int>> Edge[5]; // 간선 리스트 or 가중치 인접 리스트
// 가중치 + 간선 그래프의 경우에 구조체를 만들어야 한다. 주로 다익스트라 알고리즘에서 사용된다. 

// ②Tree : 트리는 인접 리스트로 또는 Class로 구현할 수 있다.

int main()
{
    // Vertex가 5개인 랜덤 간선, 가중치 그래프를 구현해보자. 간선이 없는 경우는 0이다.
    srand((unsigned int)time(NULL)); //현재시간을 Seed값으로 부여하여 무작위 난수를 출력한다.

    // AdjacencyMatrix
    cout << "1. 인접 행렬" << endl;
    for (int i = 0; i < 5; i++) {
        printf_s("[%c] ", i + 65);

        for (int j = 0; j < 5; j++) {
            if (i == j) AdjacencyMatrix[i][j] = 0;
            else
                AdjacencyMatrix[i][j] = rand() % 6;
            cout << AdjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // AdjacencyList
    cout << "2. 인접 리스트" << endl;
    for (int i = 0; i < 5; i++) {
        printf_s("[%c] ", i + 65);
        // push_back은 포인터 사용없이 Linked List를 생성한다.
        for (int j = 0; j < 5; j++) {
            // 가중치가 있는 경우에 간선이 존재한다.
            if (AdjacencyMatrix[i][j] > 0) AdjacencyList[i].push_back(j);
        }

        for (int v : AdjacencyList[i]) {
            printf_s("%c ", v + 65);
        }
        cout << endl;
    }
    cout << endl;

    // EdgeList
    cout << "3. 가중치 인접 리스트" << endl;
    for (int i = 0; i < 5; i++) {
        printf_s("[%c] ", i + 65);

        for (int j = 0; j < 5; j++) {
            Edge[i].push_back(make_pair(j, AdjacencyMatrix[i][j]));
        }

        for (int j = 0; j < Edge[i].size(); j++) {
            if (Edge[i][j].second > 0) printf_s("%c(%d) ", Edge[i][j].first + 65, Edge[i][j].second);
        }
        cout << endl;
    }
}