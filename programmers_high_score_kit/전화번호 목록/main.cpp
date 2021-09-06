#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
  bool answer = true;

  sort(phone_book.begin(), phone_book.end());

  for (int i = 0; i < (int)phone_book.size() - 1; ++i) {
    // if (phone_book[i + 1].find(phone_book[i].c_str(), 0, phone_book[i].length()) != string::npos) {
    // if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size())) {
    if (phone_book[i + 1].compare(0, phone_book[i].length(), phone_book[i]) == 0) {
      return false;
    }
  }
  return answer;
}

int main(void) {
  vector<string> phone_book = {"12", "123", "1235", "567", "88"};
  //vector<string> phone_book = {"123","456","789"};

  cout << solution(phone_book) << endl;
  return (0);
}
