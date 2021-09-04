#include <iostream>

int main(void) {
	// 첫 줄에는 정수 x가 주어진다. (-1000 <= x <= 1000; x != 0)
	int x;

	std::cin >> x;

	// 다음 줄에는 정수 y가 주어진다. (-1000 <= y <= 1000; y != 0)
	int y;

	std::cin >> y;

	// 점(x, y)의 사분면 번호를 출력한다.
	if (x > 0) {
		if (y > 0)
			std::cout << "1";
		else
			std::cout << "4";
	} else {
		if (y > 0)
			std::cout << "2";
		else
			std::cout << "3";
	}
	return (0);
}
