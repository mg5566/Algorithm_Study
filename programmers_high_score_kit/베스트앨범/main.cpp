#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
  vector<int> answer;

  // 장르의 총 재생 횟수 저장하기
  // 장르별 음악 재생 횟수 저장하기
  map<string, int> genres_map;
  map<string, map<int, int>> list;
  int size = genres.size();
  for (int i = 0; i < size; ++i) {
    genres_map[genres[i]] += plays[i];
    list[genres[i]][i] = plays[i];
  }
  while (genres_map.size() > 0) {
    // 많이 재새된 장르 찾기
    int max = 0;
    string genres;
    for (map<string, int>::iterator genres_map_it = genres_map.begin(); genres_map_it != genres_map.end(); ++genres_map_it) {
      if (max < genres_map_it->second) {
        max = genres_map_it->second;
        genres = genres_map_it->first;
      }
    }
    // genres 에서 재생회수가 높은 2개 선정하기
    for (int i = 0; i < 2; ++i) {
      int high = 0;
      int idx = -1;
      for (map<int, int>::iterator it = list[genres].begin(); it != list[genres].end(); ++it) {
        if (high < it->second) {
          high = it->second;
          idx = it->first;
        }
      }
      if (idx == -1)
        break;
      answer.push_back(idx);
      list[genres].erase(idx);
    }
    genres_map.erase(genres);
  }
  return answer;
}

int main(void) {
  vector<string> genres = {"classic", "pop", "classic", "classic", "pop"};
  vector<int> plays = {500, 600, 150, 800, 2500};

  vector<int> result = solution(genres, plays);
  int size = result.size();
  for (int i = 0; i < size; ++i)
    cout << "result[" << i << "] : " << result[i] << endl;
  return (0);
}
