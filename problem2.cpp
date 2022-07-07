/*
2. You are given an array of strings “words”. Return the words if that can be typed using letters of
alphabet on the same row from the keyboard. Assume every character in word and keyboard
are lowercase for now.
e.g. words: ["Alaska", "Dad"," lemon"]
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> same_row_keyboard(vector<string> input) {
	vector<string> keyboardWords{ "qwertyuiop", "asdfghjkl", "zxcvbnm" };
	vector<string> result;
	for (string word : input) {
		set<int> usedRows;
		for (char c : word) {
			for (int i = 0; i < keyboardWords.size(); ++i) {
				if (keyboardWords[i].find(c) != string::npos) {
					usedRows.insert(i);
				}
			}
		}
		if (usedRows.size() == 1)
			result.push_back(word);
	}
	return result;
}

int main()
{
	vector<string> testcase1{ "alaska", "dad", "lemon" };
	vector<string> answer = same_row_keyboard(testcase1);
	for (string word : answer)
		cout << word << endl;
	return 0;
}