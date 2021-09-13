#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_prime(string numbers) {
  int num = atoi(numbers.c_str());
  // cout << "atoi : " << num << endl;
  int root = sqrt(num);
  int i = 2;
  while (i <= root) {
    if (num % i == 0)
      return (false);
    ++i;
  }
  return (true);
}

int solution(string numbers) {
  int answer = 0;

  sort(numbers.begin(), numbers.end());
  // cout << numbers << endl;

  do {
    // cout << "permutation : " << numbers << endl;
    if (is_prime(numbers))
      ++answer;
  } while (next_permutation(numbers.begin(), numbers.end()));

  return answer;
}

int main(void) {
  string numbers1 = "17";
  string numbers2 = "011";

  cout << solution(numbers1) << endl;
  cout << solution(numbers2) << endl;
  return (0);
}
