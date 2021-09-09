#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
  int answer = 45;

  // 0 ~ 9 까지 모두 더하면 45 니까
  // numbers 다 더하고 45 빼면 된다.
  return (answer -= accumulate(numbers.begin(), numbers.end(), 0));
}

int main(void) {
  int arr[] = {1, 2, 3, 4, 6, 7, 8, 0};
  vector<int> numbers(arr, arr + 8);

  cout << "result : " << solution(numbers) << endl;
  return (0);
}
