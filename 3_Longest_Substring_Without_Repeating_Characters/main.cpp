#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

int lengthOfLongestSubstring(std::string s) {
	std::vector<int> dict(256, -1);
	int max_len = 0;
	int start = -1;

	for (int i = 0; i < (int)s.size(); ++i) {
		if (dict[s[i]] > start)
			start = dict[s[i]];
		dict[s[i]] = i;
		max_len = std::max(max_len, i - start);
	}

	return (max_len);
}

int main(void) {
	std::string a;

	std::cin >> a;

	std::cout << "result : " << lengthOfLongestSubstring(a) << std::endl;


	return (0);
}
