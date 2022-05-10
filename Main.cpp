#include <iostream>

using namespace std;

int main()
{
	cout << "Takeaway game solver!" << endl;
	cout << "N: ";
	int n;
	cin >> n;
	cout << "S count: ";
	int sCount;
	cin >> sCount;

	int* set = new int[sCount];
	char* positions = new char[n + 1];

	for (int i = 0; i < sCount; i++)
	{
		cout << "S" << i << ": ";
		cin >> set[i];
	}

	positions[0] = 'P';
	for (int nIndex = 1; nIndex < n + 1; nIndex++)
	{
		positions[nIndex] = 'P';
		for (int sIndex = 0; sIndex < sCount; sIndex++)
		{
			int possiblePos = nIndex - set[sIndex];
			if (possiblePos < 0)
			{
				continue;
			}
			if (positions[possiblePos] == 'P')
			{
				positions[nIndex] = 'N';
			}
		}
	}

	for (int i = n; i >= 0; i--)
	{
		cout << i << " : " << positions[i] << endl;
	}

	delete[] set;
	delete[] positions;
}