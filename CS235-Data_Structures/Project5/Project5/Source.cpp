#include <iostream>

using namespace std;

double stuff(double a)
{
	a = a + 1;
	return a;
}

int main()
{
	double stuff1, stuff2, stuff3;
	cin >> stuff1 >> stuff2 >> stuff3;
	cout << stuff(stuff1) << stuff(stuff2) << stuff(stuff3);


	system("pause");

	return 0;
}