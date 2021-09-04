#include <iostream>

int main() {
	// 첫째 줄에 A 와 B 가 주어진다. A 와 B 는 공백 한 칸으로 구분되어 있다.
	int a = 0;
	int b = 0;
	std::cin >> a >> b;
	//std::cout << "a: " << a << ", b: " << b << std::endl;

	if (a > b) {
		std::cout << ">" << std::endl;
	} else if (a < b) {
		std::cout << "<" << std::endl;
	} else {
		std::cout << "==" << std::endl;
	}
	return (0);
}
