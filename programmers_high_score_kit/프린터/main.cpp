#include <iostream>
#include <deque>
#include <string>
#include <vector>

using namespace std;

int find_priority_index(vector<int> v, int max) {
  int count = 0;
  int size = v.size();
  for (int i = 0; i < size; ++i) {
    if (max == v[i])
      return (i);
  }
  return (count);
}

int find_max_priority(vector<int> v) {
  int max = 1;  // 1 ~ 9
  int size = v.size();
  for (int i = 0; i < size; ++i) {
    if (max < v[i])
      max = v[i];
  }
  return (max);
}

int solution(vector<int> priorities, int location) {
  int answer = 1;

  // 대기열이 빌때까지 작업을 진행합니다.
  // find max priority
  int max;
  int index;
  while (!priorities.empty()) {
    max = find_max_priority(priorities);
    // find_priority_index() 를 통해서 queue 에서 뺏다가 뒤로 보내는 동작을 생략할 수 있습니다.
    index = find_priority_index(priorities, max);
    if (location == index)
      break;
    location -= (index);
    cout << "location: " << location << endl;
    if (location < 0)
      location += (priorities.size());
    cout << "location: " << location << endl;
    cout << "max value: " << *(priorities.begin() + index) << endl;
    priorities.erase(priorities.begin() + index);
    --location;
    if (location < 0)
      location += (priorities.size());
    ++answer;
  }
  return answer;
}

int main(void) {
  int arr1[] = {2, 1, 3, 2};
  // 2 [1] 3 2
  // [1] 3 2 2
  // 3 2 2 [1]  1
  // 2 2 [1]    2
  // 2 [1]      3
  // [1]        4

  int arr2[] = {1, 1, 9, 1, 1, 1};
  //0  [1] 1 9 1 1 1
  //0  1 9 1 1 1 [1] 1
  //1  9 1 1 1 [1] 1 1
  //2  1 1 1 [1] 1 1
  //3  1 1[1] 1 1
  //4  1 [1] 1 1
  //5  [1] 1 1

  vector<int> priorities1(arr1, arr1 + sizeof(arr1) / sizeof(int));
  vector<int> priorities2(arr2, arr2 + sizeof(arr2) / sizeof(int));
  cout << solution(priorities1, 1) << endl;
  cout << solution(priorities2, 0) << endl;
}
