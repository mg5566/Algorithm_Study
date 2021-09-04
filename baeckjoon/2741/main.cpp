#include <iostream>

int main(void) {
	std::ios_base::sync_with_stdio(false);

	int n;

	std::cin >> n;

	for (int i = 1; i <= n; ++i) {
		std::cout << i << "\n";
	}
	return (0);
}
