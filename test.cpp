#include <iostream>
#include <unordered_set>
#include <climits>
#include <algorithm>
using namespace std;
int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}

int MinCostUnrecognizedWords(unordered_set<string>& dict, string input, int size)
{
	int dp[size + 1];

	fill_n(dp, size + 1, INT_MAX);

	dp[0] = 0;

	for (int it = 1; it <= size; ++it)
	{
		string left = input.substr(0, it);

		int leftCost = left.size();
		if (dict.find(left) != dict.end())
			leftCost = 0;

		dp[it] = min(dp[it], leftCost);

		for (int j = it + 1; j <= size; ++j)
		{
			string right = input.substr(it, j - it);

			int rightCost = right.size();
			if (dict.find(right) != dict.end())
				rightCost = 0;

			dp[j] = min(dp[j], dp[it] + rightCost);
		}
	}
	return dp[size];
}

int MinCountUnrecognizedWordsRecur(unordered_set<string>& dict, string input, int size)
{
	if (dict.find(input) != dict.end() || size <= 0)
		return 0;

	int minCost = INT_MAX;
	//cout << input << endl;
	for (int it = 1; it <= size; ++it)
	{
		string left = input.substr(0, it);

		string right = input.substr(it, size - it);
		int rightCost = MinCountUnrecognizedWordsRecur(dict, right, size - it);

		if (dict.find(left) != dict.end())
			minCost = min(minCost, rightCost);
		else
			minCost = min(minCost, left.size() + rightCost);


	}

	return minCost;
}

int main() {
	unordered_set<string> dict = {"looked", "just", "like", "her", "brother"};
	string input = "jesslookedjustlikehertimbrother";

	//cout << MinCostUnrecognizedWords(dict, input, input.size()) << endl;
	cout << MinCountUnrecognizedWordsRecur(dict, input, input.size()) << endl;
	return 0;
}
