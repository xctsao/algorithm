#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> result;

vector<string> permute(string s, int i)
{
	if (i >= s.size())
	{
		result.push_back(s);
		//cout << s << endl;
		return result;
	}

	for (int j = i; j < s.size(); j++)
	{
		swap(s[i], s[j]);
		permute(s, i + 1);
		swap(s[j], s[i]);
	}

	return result;
}

int main()
{
	vector<string> result;
	string s;
	cin >> s;
	result = permute(s, 0);
	sort(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}

	return 0;
}
