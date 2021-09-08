#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// FIFO 스타일이기 때문에 queue 를 사용합니다.
vector<int> solution(vector<int> progresses, vector<int> speeds) {
  vector<int> answer;

  queue<int> q;

  // queue 초기화
  int size = progresses.size();
  for (int i = 0; i < size; ++i) {
    q.push(progresses[i]);
  }
  // 개발 진행
  while (!q.empty()) {
    size = speeds.size();
    for (int i = 0; i < size; ++i) {
      // queue 는 container adaptor 로써 element access 를 지원하는 interface 가 없습니다.
      // 따라서 front 값을 다른 변수에 저장하여 개발 진행을 한 후 queue 맨 뒤로 보냅니다.
      int n = q.front() + speeds[i];
      q.pop();
      q.push(n);
      // 이 과정이 싫다면 double ended queue 를 이용하여 random element access 기능을 사용할 수 있습니다.
      // dq[i] += speed[i];
    }

    // 앞에서 100퍼인지 체크하기
    int count = 0;
    while (1) {
      if (q.size() > 0 && q.front() >= 100) {
        count++;
        speeds.erase(speeds.begin());
        q.pop();
        continue;
      }
      break;
    }
    if (count > 0)
      answer.push_back(count);
  }
  return answer;
}

int main(void) {
  int progresses_array[] = {93, 30, 55};
  int speeds_array[] = {1, 30, 5};
  vector<int> progresses(progresses_array, progresses_array + sizeof(progresses_array) / sizeof(int));
  vector<int> speeds(speeds_array, speeds_array + sizeof(speeds_array) / sizeof(int));

  vector<int> result = solution(progresses, speeds);

  for (vector<int>::iterator v_it = result.begin(); v_it != result.end(); ++v_it) {
    cout << *v_it << endl;
  }
  return (0);
}
