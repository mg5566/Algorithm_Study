#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool cmp(const string &a, const string &b) {
  return ((a + b) > (b + a));
}

string solution(vector<int> numbers) {
  string answer = "";

  vector<string> str_numbers;
  int size = numbers.size();
  for (int i = 0; i < size; ++i)
    str_numbers.push_back(to_string(numbers[i]));
  sort(str_numbers.begin(), str_numbers.end(), cmp);
  for (int i = 0; i < size; ++i)
    answer += str_numbers[i];
  if (answer[0] == '0')
    return ("0");
  return answer;
}

int main(void) {
  int arr1[] = {6, 10, 2};
  int arr2[] = {3, 30, 34, 5, 9};

  vector<int> numbers1(arr1, arr1 + 3);
  vector<int> numbers2(arr2, arr2 + 5);
  cout << solution(numbers1) << endl;
  cout << solution(numbers2) << endl;
  return (0);
}
