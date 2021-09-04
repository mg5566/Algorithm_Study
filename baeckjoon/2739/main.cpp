#include <iostream>

void print_gugudan(int n) {
	// 출력형식과 같게 N*1부터 N*9까지 출력한다.
	for (int i = 1; i < 10; ++i) {
		std::cout << n << " * " << i;
		std::cout << " = " << n * i << std::endl;
	}
}

int main(void) {
	// 첫째 줄에 N이 주어진다. N은 1보다 크거나 같고, 9보다 작거나 같다.
	int n;

	std::cin >> n;
	print_gugudan(n);
	return (0);
}
