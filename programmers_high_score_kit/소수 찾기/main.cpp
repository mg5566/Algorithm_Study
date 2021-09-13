#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

bool is_prime(int numbers) {
  if (numbers < 2)
    return (false);
  int root = sqrt(numbers);
  for (int i = 2; i <= root; ++i) {
    if (numbers % i == 0)
      return (false);
  }
  return (true);
}

int solution(string numbers) {
  int answer = 0;

  vector<int> nums;

  sort(numbers.begin(), numbers.end());

  int size = numbers.size();
  do {
    string temp = "";
    for (int i = 0; i < size; ++i) {
      temp.push_back(numbers[i]);
      nums.push_back(stoi(temp));
    }
  } while (next_permutation(numbers.begin(), numbers.end()));

  // 모든 경우 수를 담은 vector 를 완전탐색하면서 prime 인지 판단한다.
  sort(nums.begin(), nums.end());
  nums.erase(unique(nums.begin(), nums.end()), nums.end());
  size = nums.size();
  for (int i = 0; i < size; ++i) {
    if (is_prime(nums[i]))
      ++answer;
  }
  return answer;
}

int main(void) {
  string numbers1 = "17";
  string numbers2 = "011";

  cout << solution(numbers1) << endl;
  cout << solution(numbers2) << endl;
  return (0);
}
