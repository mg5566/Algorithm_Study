#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > triangle) {
    int answer = 0;

    int size = triangle.size();
    for (int i = 1; i < size; ++i) {  // 0번 인덱스는 찾을 필요없어요 무조건 1개만 있고 그 상위에 값이 존재하지 않기때문에
      // for 문 안에서 1번더 for문을 반복하면서 2차원 배열 요소를 탐색합니다.
      int inner_size = triangle[i].size();
      for (int k = 0; k < inner_size; ++k) {
        // 0번 인덱스 일때랑 inner_size - 1 번 인덱스 일때만(처음과 끝) 이때만 잘하면 됩니다.
        if (k == 0) {
          triangle[i][k] += triangle[i - 1][k];
        } else if (k == inner_size - 1) {
          triangle[i][k] += triangle[i - 1][k - 1];
        } else {
          triangle[i][k] += max(triangle[i - 1][k], triangle[i - 1][k -1]);
        }
      }
    }
    answer = *max_element(triangle[size - 1].begin(), triangle[size - 1].end());
    return answer;
}

int main(void) {
  vector<vector<int> > triangle = { {7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5} };

  cout << solution(triangle) << endl;
  return (0);
}
