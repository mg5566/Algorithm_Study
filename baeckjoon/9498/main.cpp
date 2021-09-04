#include <iostream>

int main() {
	// 첫째 줄에 시험 점수가 주어진다. 시험 점수는 0보다 크거나 같고, 100보다 작거나 같은 정수이다.
	int grade = 0;

	std::cin >> grade;
	// exception 은 안하도록하겠습니다.
	if (grade >= 90 && grade <= 100)
		std::cout << "A";
	else if (grade >= 80)
		std::cout << "B";
	else if (grade >= 70)
		std::cout << "C";
	else if (grade >= 60)
		std::cout << "D";
	else
		std::cout << "F";
	return (0);
}
