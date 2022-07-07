/*
1. A person has 3000 bananas and a camel. The person wants to transport the
maximum number of bananas to a destination which is 1000 KMs away, using
only the camel as a mode of transportation. The camel cannot carry more than
1000 bananas at a time and eats a banana every km it travels.
What is the maximum number of bananas that can be transferred to the
destination using only camel? (no other mode of transportation is allowed).
*/

#include <bits/stdc++.h>

using namespace std;

//If we travel the whole distance at once, then it won’t be possible to transfer bananas.

//So we need to break down the overall journey into intermediate points.

//Here dynamic programming is used

int max_possible_transfer(int initialBanana, int distance, vector<vector<int>>& dp) {
	if (distance <= 0)
		return initialBanana;
	if (initialBanana <= 0)
		return 0;
	if (dp[initialBanana][distance] != -1)
		return dp[initialBanana][distance];
	int current = 0, requiredLoops;
	//Number of updowns required to transfer initialBanana
	if (initialBanana % 1000)
		requiredLoops = 2 * initialBanana / 1000 + 1;
	else
		requiredLoops = 2 * initialBanana / 1000 - 1;
	// trying all intermediate points
	for (int i = 1; i <= distance; ++i) {
		current = max(current, max_possible_transfer(initialBanana - requiredLoops * i, distance - i, dp));
	}
	//saving the value
	dp[initialBanana][distance] = current;
	return current;
}

int main()
{
	vector<vector<int>> dp(4000, vector<int>(2000, -1));
	int answer = max_possible_transfer(3000, 1000, dp);
	cout << answer << endl;
	return 0;
}