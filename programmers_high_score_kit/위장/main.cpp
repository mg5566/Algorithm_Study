#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
  int answer = 1;

  // map 을 만들자.
  map<string, int> clothes_map;
  int size = clothes.size();
  for (int i = 0; i < size; ++i) {
    ++clothes_map[clothes[i][1]];
  }
  for (map<string, int>::iterator m_it = clothes_map.begin(); m_it != clothes_map.end(); ++m_it) {
    cout << "clothes_map[" << m_it->first << "]: " << m_it->second << endl;
    answer *= (m_it->second + 1);
  }
  // 갯수를 계산하면 되는데 어찌 계산을 해야하나요?
  // 3개 의 옷 2개의 선글라스가 잇다면 3 * 2 하면 모든 경우의 수를 구할 수 있습니다. 그리고 안 입는 경우도 있기때문에
  // (3 + 1) * (2 + 1) 이렇게 계산을 해야합니다 여기서 하나더 고려할 것은 모두 안입은 경우입니다. 그경우는 1개만 존재하기 때문에 결과값에 -1을 합니다.

  return (answer - 1);
}

int main(void) {
  vector<vector<string> > clothes = {{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}};

  cout << "solution: " << solution(clothes) << endl;
  return (0);
}
