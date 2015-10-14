#include <iostream>

using namespace std;

int main()
{
	int n, low, high, max = 0;
	int content[10001] = { 0 };

	cin >> n;

	for (int i = 0; i<n; i++) {
		cin >> low >> high;
		if (high > max) {
			max = high;
		}

		for (int j = low; j < high; j++) {
			content[j] = 1;
		}
	}
	content[max] = 1;

	//for (int  i = 1; i < max; i++)
	//{
	//	cout << content[i] << " ";
	//}
	//cout << endl;

	int k = 1;

	while (content[k] == 0) {
		k++;
	}
	low = k;

	while (content[k] == 1) {
		k++;
	}

	if (k < max) {
		cout << "no" << endl;
	}
	else {
		cout << low << " " << max << endl;
	}

	return 0;
}
