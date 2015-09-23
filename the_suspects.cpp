#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define N 30000

int p[N] = { -1 };

void make_set(int n)
{
	for (int i = 0; i < n; i++)
	{
		p[i] = i;
	}

	return;
}

int find_parent(int i)
{
	if (p[i] != i)
	{
		p[i] = find_parent(p[i]);
	}

	return p[i];
}

void united(int i, int j)
{
	int pi = find_parent(i);
	int pj = find_parent(j);

	if (pi < pj)
	{
		p[p[j]] = pi;
	}
	if (pi > pj)
	{
		p[p[i]] = p[j];
	}

	return;
}

int main()
{
	int m, n;

	while (true)
	{
		int count = 0;
		cin >> n >> m;
		if (n == 0 && m == 0)
		{
			return 0;
		}

		make_set(n);

		// 	for (int i = 0; i < n; i++)
		// 	{
		// 		cout << p[i] << " ";
		// 	}

		while (m-- > 0)
		{
			int num;
			vector<int> member_list;

			cin >> num;

			for (int i = 0; i < num; i++)
			{
				int member;

				cin >> member;
				member_list.push_back(member);
			}

			sort(member_list.begin(), member_list.end());
			for (int i = 1; i < member_list.size(); i++)
			{
				united(p[member_list[0]], p[member_list[i]]);
			}
		}

		for (int i = 0; i < n; i++)
		{
			p[i] = p[find_parent(i)];
		}

		for (int i = 0; i < n; i++)
		{
			if (p[i] == 0)
			{
				count++;
			}
			//cout << p[i] << " ";
		}
		cout << count << endl;
	}
	return 0;
}
