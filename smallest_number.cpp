
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{   
	int m;
	int n;
	int a;
	int b;
	int i;
	int d;

	cout << "Enter numres amount" << endl;
	cin >> m;

	cout << "enter first namber" << endl;
	cin >> a;

	if (m != 1){
		cout << "enter next number" << endl;
		cin >> b;
		if (b < a )
			n = b;
		else 
			n = a;
		
		if (m <= 2)
	cout << "smallest " << n << endl;	
	
	}
	else 
		cout << "smallest "<< a << endl;
	
	
	if ( m > 2 ){
		for(i = m; i > 2; i--){
			cout << "enter next numer" << endl;
			cin >> d;
			if (d < n )
				n = d;
			else n;
		}

		cout << "smallest " << n <<endl;
	}
	    
	return 0;
}

