#include <iostream>

int main(void) {
	// 첫째 줄에 연도가 주어진다. 연도는 1보다 크거나 같고, 4000보다 작거나 같은 자연수이다.
	int year;

	year = 0;
	std::cin >> year;
	if (year < 1 || year > 4000) {
		std::cout << "0";
		return (0);
	}

	// 첫째 줄에 윤년이면 1, 아니면 0을 출력한다.
	// 4의 배수이면서, 100의 배수가 아닐 때 또는 400의 배수일 때
	if ((year % 4) == 0) {
		if (((year % 100) != 0) || ((year % 400) == 0)) {
			std::cout << "1";
			return (0);
		}
	}
	std::cout << "0";
	return (0);
}
