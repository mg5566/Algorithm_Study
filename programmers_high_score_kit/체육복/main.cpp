#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
  // int answer = n - lost.size();
  int answer = 0;
  vector<int> student(n, 1);  // 학생 n 명이 기본적으로 체육복을 소지하고 있다고 가정한다.

  // 체육복이 없는 학생은 -1, 여벌이 있는 학생은 +1
  int size = lost.size();
  for (int i = 0; i < size; ++i)
    --student[lost[i] - 1];
  size = reserve.size();
  for (int i = 0; i < size; ++i)
    ++student[reserve[i] - 1];

  /* 잘 동작하는 것을 확인했습니다.
  // test print
  size = student.size();
  for (int i = 0; i < size; ++i) {
    cout << "student[" << i << "] : " << student[i] << endl;
  }
  */

  // student 를 탐색하면서 체육복이 없는 학생은 체육복을 빌린다.
  for (int i = 0; i < n; ++i) {
    // 체육복이 없으면
    if (student[i] == 0) {
      // 앞사람 찾기
      if (i > 0 && student[i - 1] == 2) {
        --student[i - 1];  // 빌려줘서 -1
        ++student[i];  // 빌려서 +1
        // ++answer;
      } else if (i < n - 1 && student[i + 1] == 2) {
        --student[i + 1];  // 빌려줘서 -1
        ++student[i];  // 빌려서 +1
        // ++answer;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    if (student[i] == 1)
      ++answer;
  }
  return (answer);
}

int main(void) {
  vector<int> lost = {2, 4};
  vector<int> reserve = {1, 3, 5};
  cout << "solution : " << solution(5, lost, reserve) << endl;
  return (0);
}
