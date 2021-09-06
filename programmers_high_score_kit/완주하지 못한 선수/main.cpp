#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
	map<string, int> m;

	for (vector<string>::iterator c_it = completion.begin(); c_it != completion.end(); ++c_it) {
		m[*c_it] += 1;
	}

	for (vector<string>::iterator p_it = participant.begin(); p_it != participant.end(); ++p_it) {
		m[*p_it] -= 1;
		if (m[*p_it] < 0)
			return (*p_it);
	}

	return (answer);
}

int main(void) {
	vector<string> participant = {"marina", "josipa", "nikola", "vinko", "filipa"};
	vector<string> completion = {"josipa", "filipa", "marina", "nikola"};

	cout << solution(participant, completion) << endl;
	return (0);
}
