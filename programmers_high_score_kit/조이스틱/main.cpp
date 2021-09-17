#include <iostream>
#include <string>
#include <vector>

using namespace std;

int calc_move(string name) {
  // sliding window 를 사용하여 가장 길게나오는 "AxxxA"를 찾습니다.
  // "AxxA" two pointer를 이용하여 answer 를 만들기위해서 >, < 방향으로 몇번 움직이는지 계산을 합니다.
  int front_index = 0;  // sliding window 이 끝나고 해당 pointer 를 저장할 때 사용되는 index
  int last_index = 0;
  int start_index;  // sliding window 에서 움직일때 쓰이는 index
  int end_index;
  int max_len = 0;  // last_index - front_index
  int current_index = 0;
  int size = name.size();

  // sliding window
  while (current_index < size) {
    if (name[current_index] == 'A') {
      start_index = current_index;
      end_index = current_index;
      // A가 끝날때까지 last_index 를 증가합니다.
      int cnt = 0;
      while (name[end_index] == 'A') {
        cout << "name[" << end_index << "] : " << name[end_index] << ", cnt : " << cnt << endl;
        ++cnt;
        ++end_index;
      }
      cout << "end_index : " << end_index <<endl;
      if (max_len < end_index - start_index) {
        max_len = end_index - start_index;
        front_index = start_index;
        last_index = (end_index - 1);
        cout << "max_len : " << max_len << endl;
      }
      current_index = (end_index - 1);
    }
    ++current_index;
  }

  // 이동에 대해서 계산해야합니다.
  cout << "front_index : " << front_index << ", last_index : " << last_index << endl;
  int prefix_len = (size - 1) - last_index;  // "BCDFASDASD" "AxxA" ["DSFASD"] 의 길이
  int postfix_len = front_index;             // ["BCDFASDASD"] 의 길이 "AxxA" "DSFASD"

  cout << "calc_move(name): " << (postfix_len + (prefix_len * 2))<< endl;
  return (postfix_len + (prefix_len * 2));
}

int solution(string name) {
  int answer = 0;
  // string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  // cout << "alphabet size : " << alphabet.size() << endl;  // 26

  int size = name.size();
  // cout << size << endl;
  for (int i = 0; i < size; ++i) {
    // name[i] 를 alphabet의 몇번 index 인지 찾아야합니다.
    // 이렇게 하면 너무 오래걸린다. 이렇게 말고, ascii 값 비교로 진행합시다.
    // cout << "name[i] - 'A' : " << name[i] - 'A' << endl;
    // index 가 13보다 크면 <A 이동, 13보다 작으면 A> 이동
    // 이동 횟수 answer 에 반영
    int cnt = name[i] - 'A';
    if (cnt < 14)
    {

      answer += cnt;
    cout << "움직임값 : " << cnt << endl;
    }
    else
    {

      answer += 26 - cnt;
    cout << "반대임값 : " << 26 - cnt << endl;
    }
    // 다음 글자로 이동 for 문 안에서 하고 있습니다.
    // 마지막에는 이동하면 안됩니다.
  }
  // 이동에 대한 최소값을 찾아보세요
  calc_move(name);
  // answer += calc_move(name);
  return answer;
}

int main(void) {
  cout << "solution 0 : " << solution("Z") << endl;
  // cout << "solution 1 : " << solution("JEROEN") << endl;
  cout << "solution 2 : " << solution("JAN") << endl;
  cout << "solution 3 : " << solution("AAAA") << endl;
  return (0);
}
