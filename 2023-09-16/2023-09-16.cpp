//  C++에서 자주 사용되는 알고리즘 함수가 있다.

#include <iostream>

// ①sort
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	return a < b;
}

// ①sort는 첫 번째 인자의 배열 주소부터 두 번째 인자의 배열 주소 까지 비교함수의 반환값에 따라 정렬한다.
	// greater<자료형> : 내림차순 비교함수
int main(void) {
	int a[10] = { 9, 3, 5, 4, 1, 10, 8, 6, 7, 2 };
	sort(a, a + 10, greater<double>());
	for (int i = 0; i < 10; i++) {
		cout << a[i] << ' ';
	}

	cout << endl;

	sort(a, a + 10, compare);
	for (int i = 0; i < 10; i++) {
		cout << a[i] << ' ';
	}

}