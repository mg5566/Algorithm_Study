#include <iostream>

int main(void) {
	int n;

	std::cin >> n;

	int sum = 0;
	for (int i = 1; i <= n; ++i)
		sum += i;

	std::cout << sum;
	return (0);
}
