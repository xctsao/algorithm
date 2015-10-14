#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>

using namespace std;

int a[100001];
int size;

void shift_down(int pos)
{
	int i = pos;
	int j;
	int tmp = a[pos];

	while (i <= size/2)
	{
		j = i * 2;
		if (j<=size - 1 && a[j]>a[j + 1])
		{
			j++;
		}

		if (tmp > a[j])
		{
			a[i] = a[j];
			i = j;
		}
		else
			break;
	}

	a[i] = tmp;
}

void shift_up(int pos)
{
	int tmp = a[pos];

	while (pos>1 && a[pos/2] > tmp)
	{
		a[pos] = a[pos / 2];
		pos /= 2;
	}

	a[pos] = tmp;
}

void insert(int value)
{
	a[++size] = value;
	shift_up(size);
}

void del()
{
	if (size == 0)
	{
		return;
	}
	//cout << a[1] << endl;
	printf("%d\n", a[1]);

	a[1] = a[size--];

	shift_down(1);
}

int main()
{
	int t, n;

	//cin >> t;
	scanf("%d", &t);
	
	while ( t-- )
	{
		size = 0;
		int n, type, value;

		//cin >> n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			//cin >> type;
			scanf("%d", &type);
			if (type == 1)
			{
				//cin >> value;
				scanf("%d", &value);
				insert(value);
			}
			else
			{
				del();
			}
		}
	}

	return 0;
}
