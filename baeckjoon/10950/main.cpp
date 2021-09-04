#include <iostream>
#include <vector>

int main(void) {
	int t;

	std::cin >> t;

	std::vector<int> a;
	std::vector<int> b;
	int temp_a;
	int temp_b;

	for (int i = 0; i < t; ++i) {
		std::cin >> temp_a >> temp_b;
		a.push_back(temp_a);
		b.push_back(temp_b);
	}
	for (int i = 0; i < t; ++i) {
		std::cout << a[i] + b[i] << std::endl;
	}

	return (0);
}
