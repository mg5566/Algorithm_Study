#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
  vector<int> answer;

  vector<int> student1 = {1, 2, 3, 4, 5};
  vector<int> student2 = {2, 1, 2, 3, 2, 4, 2, 5};
  vector<int> student3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
  /*
  int student1[] = {1, 2, 3, 4, 5};
  int student2[] = {2, 1, 2, 3, 2, 4, 2, 5};
  int student3[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
  */
  /*
  vector<int> student1_vector(student1, student1 + 5);
  vector<int> student2_vector(student2, student2 + 8);
  vector<int> student3_vector(student3, student3 + 10);
  vector<vector<int> > solution_vector;
  solution_vector.push_back(student1_vector);
  solution_vector.push_back(student2_vector);
  solution_vector.push_back(student3_vector);
  */
  vector<int> score(3);

  // answers 를 반복하면서 1번 수포자부터 3번수포자까지 정답을 비교한다.
  // int student;
  int size = answers.size();
  for (int i = 0; i < size; ++i) {
    /*
    student = 0;
    while (student < 3) {
    */
    /*
        cout << "size    : " << solution_vector[student].size() << endl;
        cout << "solve   : " << solution_vector[student][i % solution_vector[student].size()] << endl;
        cout << "answers : " << answers[i] << endl;
      */
    /*
      if (answers[i] == solution_vector[student][i % solution_vector[student].size()])
        ++score[student];
      */
    if (answers[i] == student1[i % student1.size()])
      ++score[0];
    if (answers[i] == student2[i % student2.size()])
      ++score[1];
    if (answers[i] == student3[i % student3.size()])
      ++score[2];
    /*
      ++student;
    }
    */
  }
  // score 를 이용해서 answer 를 만들면 끝.
  int max = *max_element(score.begin(), score.end());
  size = score.size();
  for (int i = 0; i < size; ++i) {
    if (score[i] == max)
      answer.push_back(i + 1);
  }
  return answer;
}

int main(void) {
  int answer_arr1[] = {1, 2, 3, 4, 5};
  int answer_arr2[] = {1, 3, 2, 4, 2};

  vector<int> answers1(answer_arr1, answer_arr1 + 5);
  vector<int> answers2(answer_arr2, answer_arr2 + 5);

  vector<int> result1 = solution(answers1);
  vector<int> result2 = solution(answers2);

  int size = result1.size();
  cout << "result1:";
  for (int i = 0; i < size; ++i) {
    cout << " " << result1[i];
  }
  cout << endl;

  size = result2.size();
  cout << "result2:";
  for (int i = 0; i < size; ++i) {
    cout << " " << result2[i];
  }
  cout << endl;
  return (0);
}
