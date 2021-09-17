#include <iostream>
#include <string>
#include <vector>

using namespace std;

void calc_num(vector<int> numbers, int target, int current_num, int index, int *answer) {
  if ((size_t)index == numbers.size()) {
    if (current_num == target)
      ++(*answer);
    return;
  }
  // cout << "current_num : " << current_num;
  // cout << ", index : " << index << ", answer : " << *answer << endl;
  calc_num(numbers, target, current_num + numbers[index], index + 1, answer);
  calc_num(numbers, target, current_num - numbers[index], index + 1, answer);
}

int solution(vector<int> numbers, int target) {
  int answer = 0;
  // recurtion 을 사용한다. BFS 로 풀어보겠습니다.
  calc_num(numbers, target, 0, 0, &answer);
  return answer;
}

int main(void) {
  vector<int> numbers = {1, 1, 1, 1, 1};
  cout << "solution: " << solution(numbers, 3) << endl;
  return (0);
}
