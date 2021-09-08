#include <iostream>

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    // greater, less 등
    // https://www.cplusplus.com/reference/functional/
    priority_queue <int, vector<int>, greater<int> > pq(scoville.begin(), scoville.end());
    int first;
    int second;

    while (pq.size() > 1 && pq.top() < K) {  // scoville 이 2개 이상이면서, 작은 값이 K 이상일때,
      first = pq.top();
      pq.pop();
      second = pq.top();
      pq.pop();
      pq.push(first + (second * 2));
      ++answer;
    }
    // 조합이 없는 경우
    if (pq.top() < K)
      return (-1);
    return answer;
}
int main(void) {
  int arr[] = {1, 2, 3, 9, 10, 12};
  vector<int> scoville(arr, arr + sizeof(arr) / sizeof(int));

  cout << "{1, 2, 3, 9, 10, 12}, 7 : " << solution(scoville, 7) << endl;
  return (0);
}
