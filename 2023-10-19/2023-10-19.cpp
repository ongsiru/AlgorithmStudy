//본인은 DFS로 풀었지만 다른 분의 풀이가 직관적이어서 가져왔다.

#include <string>
#include <vector>
using namespace std;


int distance(int x, int y, int r, int c) {
    return abs(x - r) + abs(y - c);
}


string solution(int n, int m, int y, int x, int c, int r, int k) {
    string answer = "";
    while (k > 0) {
        --k;
        if (y < n && distance(x, y + 1, r, c) <= k) { answer += "d"; y += 1; }
        else if (x > 1 && distance(x - 1, y, r, c) <= k) { answer += "l"; x -= 1; }
        else if (x < m && distance(x + 1, y, r, c) <= k) { answer += "r"; x += 1; }
        else if (y > 1 && distance(x, y - 1, r, c) <= k) { answer += "u"; y -= 1; }
        else if (k == 0) return "impossible";
    }
    return answer;
}