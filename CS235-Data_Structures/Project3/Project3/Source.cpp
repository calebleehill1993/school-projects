#include <iostream>
using namespace std;
/*

Prompt the user for an integer. Print out the factors of the integer in descending order.

Example:
Input:
25

Output:
25
5
1

*/

int main()
{
	int a = 0;
	int b = 0;
	cin >> a;
	b = a;
	cout << endl;
	for (b; b != 0; b--)
	{
		if ((a % b) == 0)
		{
			cout << b << " x " << a / b << endl;
		}
	}

	cout << endl;

	return main();
}