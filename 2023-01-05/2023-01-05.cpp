// C++에는 알고리즘 문제를 해결하는데 필요한 pair, vector, queue, stack, set, map, priority queue 등의 자료구조를 구현해놓은 STL이 있다.

// 기본적으로 아래의 헤더 파일과 입출력 클래스 개별화를 선언해준다.
#include <iostream>
#include <algorithm>
#include<string>

using namespace std;

// ②vector는 따로 헤더를 선언해준다.
#include <vector>

// ③④queue와 dequeue는 따로 헤더를 선언해준다.
#include <queue>

// ⑤stack은 따로 헤더를 선언해준다.
#include <stack>

// ⑦set은 따로 헤더를 선언해준다.
#include <set>

// ⑧set은 따로 헤더를 선언해준다.
#include <map>

int main() {

	// ①pair : 변수 쌍을 이루는 구조체를 선언해줄 수 있으며 first, second 멤버변수로 구성되어 있다.
		//make_pair() : 변수에 한번에 대입

	pair<int, string> p = make_pair(1, "pair");
	cout << p.first << ". ";
	cout << p.second << endl;


	// ②vector : 메모리의 크기가 동적으로 할당되는 가변적인 배열이다. 
		//front() : 첫 번째 원소
		//back() : 마지막 원소
		//begin() : 첫번째 위치
		//end() : 마지막의 다음 위치
		//push_back() : 마지막에 데이터 추가
		//pop_back() : 마지막에서 데이터 뽑기
		//size() : 원소의 개수
		//clear() : 비우기

	vector<pair<int, string>> v;
	v.push_back(make_pair(2, ". vector"));
	cout << v.front().first << v.back().second << endl; // 벡터의 원소는 하나밖에 없으므로 front = back이다.


	// ③queue : FIFO 자료구조이며 DFS 및 BFS에서 사용된다.
		//push() : back에 데이터 추가
		//pop() : front에서 데이터 뽑기 (주의, 자료형이 void)
		//front() : 첫 번째 원소
		//back() : 마지막 원소
		//size() : queue의 크기
		//empty() : queue가 비어있는지 확인

	queue<pair<int, string>> q;
	q.push(make_pair(3, ". queue"));
	cout << q.front().first << q.back().second << endl;
	q.pop();


	// ④dequeue : 양쪽으로 삽입과 삭제가 가능한 queue 자료구조이다.
		//push_front() : front에 데이터 추가
		//push_back() : back에 데이터 추가
		//pop_front() : front에서 데이터 뽑기 (주의, 자료형이 void)
		//pop_back() : back에서 데이터 뽑기 (주의, 자료형이 void)
		//front() : 첫 번째 원소
		//back() : 마지막 원소
		//begin() : 첫 번째 원소 iterator
		//end() : 마지막 원소의 다음 iterator
		//erase(iterator) : 해당 iterator의 원소를 삭제하고 원소의 개수가 적은 쪽을 당겨서 채우는 멤버함수
		//clear() : deque을 초기화

	deque<pair<int, string>> d;
	d.push_front(make_pair(4, ". dequeue"));
	cout << d.front().first << d.back().second << endl;
	d.pop_back();


	// ⑤priority_queue : 우선순위를 비교함수를 통해 부여한 큐이다. default는 내림차순이고 아래의 예시처럼 구조체를 사용하여 커스텀할 수 있다.
		// greater<자료형> : 오름차순 비교함수
	struct cmp {
		bool operator()(pair<int, string> p1, pair<int, string> p2) {
			if (abs(p1.first) > abs(p2.first)) return true;
			else if (abs(p1.first) == abs(p2.first))
				if (p1.first > p2.first) return true;
				else return false;
			return false;
		}
	};

	priority_queue<pair<int, string>,vector<pair<int, string>>, cmp> pq;
	pq.push(make_pair(5, ". priority_queue"));
	cout << pq.top().first << pq.top().second << endl;


	// ⑥stack : LIFO 자료구조이며 DFS에서 사용된다.
		//push() : top에 데이터 추가
		//pop() : top에서 데이터 뽑기 (주의, 자료형이 void)
		//top() : top에 있는 원소
		//size() : stack의 크기
		//empty() : stack이 비어있는지 확인

	stack<pair<int, string>> st; 
	st.push(make_pair(6, ". stack"));
	cout << st.top().first << st.top().second << endl;
	st.pop();


	// ⑦set : key(원소)들의 집합으로 이루어진 associative 컨테이너
		//insert(k) : 원소 k 삽입
		//begin() : 맨 첫번째 원소를 가리키는 iterator를 반환
		//end() : 맨 마지막 원소를 가리키는 iterator를 반환
		//find(k) : 원소 k를 가리키는 iterator를 반환
		//size() : set의 원소 수
		//empty() : 비어있는지 확인
		//(*iter) : set의 참조 객체

	set<pair<int, string>> s1;
	s1.insert(make_pair(7, ". set"));
	for (auto iter = s1.begin(); iter != s1.end(); ++iter)
		cout << (*iter).first << (*iter).second << endl;


	// ⑧map : pair(원소)들의 집합으로 이루어진 associative 컨테이너
		//insert(make_pair(k, v)) : 원소를 key와 value의 pair로 삽입
		//erase(k) : key값 k를 갖는 원소를 삭제
		//begin() : 맨 첫번째 원소를 가리키는 iterator를 반환
		//end() : 맨 마지막 원소를 가리키는 iterator를 반환
		//find(k) : key값 k에 해당하는 iterator를 반환
		//size() : map의 원소 수
		//empty() : 비어있는지 확인

	map<int, string> m;
	m.insert(make_pair(8, ". map"));
	for (auto iter = m.begin(); iter != m.end(); ++iter)
		cout << (*iter).first << (*iter).second << endl;

}