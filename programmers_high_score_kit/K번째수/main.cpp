#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int> > commands) {
  vector<int> answer;

  vector<int> temp;
  /*
  // commands 순차 적용
  for (vector<vector<int> >::iterator vv_it = commands.begin(); vv_it != commands.end(); ++vv_it) {
    temp.assign(array.begin() + (*vv_it)[0] - 1, array.begin() + (*vv_it)[1]);
    // *vv_it 는 vector<int> command; 라고 생각해라
    // 정렬
    // sort(temp.begin() + (*vv_it)[0] - 1, temp.begin() + (*vv_it)[1] - 1);
    sort(temp.begin(), temp.end());

    // test print
    int size = temp.size();
    for (int i = 0; i < size; ++i) {
      cout << temp[i] << " ";
    }
    cout << endl;

    // 해당 위치 값 찾기
    cout << "answer: " << temp[(*vv_it)[2] - 1] << endl;
    answer.push_back(temp[(*vv_it)[2] - 1]);
  }
  */
  // 더 깔끔한 방법
  int size = commands.size();
  for (int i = 0; i < size; ++i) {
    temp = array;
    sort(temp.begin() + commands[i][0] - 1, temp.begin() + commands[i][1]);
    answer.push_back(temp[commands[i][0] + commands[i][2] - 2]);
  }

  return answer;
}

int main(void) {
  int arr[] = {1, 5, 2, 6, 3, 7, 4};
  int cmd1[] = {2, 5, 3};
  int cmd2[] = {4, 4, 1};
  int cmd3[] = {1, 7, 3};

  vector<int> array(arr, arr + 7);
  vector<int> temp1(cmd1, cmd1 + 3);
  vector<int> temp2(cmd2, cmd2 + 3);
  vector<int> temp3(cmd3, cmd3 + 3);
  vector<vector<int> > commands;
  commands.push_back(temp1);
  commands.push_back(temp2);
  commands.push_back(temp3);
  vector<int> result = solution(array, commands);

  for (vector<int>::iterator it = result.begin(); it != result.end(); ++it) {
    cout << *it << " ";
  }
  cout << endl;
  return (0);
}
