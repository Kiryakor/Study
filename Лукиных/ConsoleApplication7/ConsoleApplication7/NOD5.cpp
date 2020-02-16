#include "stdafx.h"
#include "NOD5.h"
#include <iostream>

using namespace std;
void NOD5::NOD()
{
	while (a > 0 && b > 0)
	{
		if (a > b)
			a = a - b;
		else b = b - a;
	}
	
}

void NOD5::VVOD()
{
	cout << "Enter a ";
	cin >> a;
	cout << "Enter b ";
	cin >> b;

}
void NOD5::VIVOD()
{
	cout << "NOD : " << a + b << endl;
}


