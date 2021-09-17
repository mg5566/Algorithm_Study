#include <iostream>

#include <string>
#include <vector>

using namespace std;

void recursive_network(int pos, vector<vector<int> > computers, vector<bool> &visit, int n) {
  visit[pos] = true;

  for (int i = 0; i < n; ++i) {
    if (visit[i] == false && computers[pos][i])
      recursive_network(i, computers, visit, n);
  }
}

int solution(int n, vector<vector<int> > computers) {
  int answer = 0;

  vector<bool> visit(n, false);

  for (int i = 0; i < n; ++i) {
    if (visit[i] == false) {
      answer++;
      recursive_network(i, computers, visit, n);
    }
  }

  return answer;
}

int main(void) {
  vector<vector<int> > computers = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
  cout << "solution: " << solution(3, computers) << endl;
  return (0);
}
