#include <iostream>

#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
  long long answer = -1;

  // size 를 구해봅시다.
  int size = g.size();
  vector<int> g_count(size);
  vector<int> s_count(size);
  for (int i = 0; i < size; ++i) {
    // 몇번 왕복 할 수 있는지 계산
    // 금 왕복횟수 배열
    // 은 왕복횟수 배열
    int gold = 0;
    int silver = 0;
    while (a < gold)
      gold = w[i] * g_count[i]++;
    while (b < silver)
      silver = w[i] * s_count[i]++;


  }

  // 금 왕복횟수 * 걸리는 시간
  // 은 왕복횟수 * 걸리는 시간

  //

  return answer;
}

int main(void) {
  int a = 10;
  int b = 10;
  /*
  int g_arr[] = {100};
  int s_arr[] = {100};
  int w_arr[] = {7};
  int t_arr[] = {10};
  */

  vector<int> g(1, 100);
  vector<int> s(1, 100);
  vector<int> w(1, 7);
  vector<int> t(1, 10);

  cout << solution(a, b, g, s, w, t) << endl;
  return (0);
}
