
#include <iostream>

using std :: cout;
using std :: cin;
using std :: endl;

int main()
{
	int n;

	cout << "Enter n" << endl;
	cin >> n;
	for ( int a = 0; a <= n; a++)
	{
		for (int b = 0; b <= n; b++)
		{
			for (int c = 0; c <= n; c++)
			{
				if ( a * a + b * b == c * c)
					cout << a * a << " + " << b * b << " = " << c * c << endl;
			}
		}
	}

	return 0;
}

