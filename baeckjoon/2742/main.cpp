#include <iostream>

int main(void) {
	std::ios_base::sync_with_stdio(false);

	int t;

	std::cin >> t;

	for (int i = t; i != 0; --i) {
		std::cout << i << "\n";
	}
	return (0);
}
