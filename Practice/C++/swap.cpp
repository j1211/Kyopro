/*2�̒l������*/

#include <iostream>
using namespace std;

int main() {
	int a, b;
	int t;

	cin >> a >> b;
	
	t = a;	//t <- old_a
	a = b;	//a <- old_b
	b = t;	//b <- old_a

	cout << a << " " << b << endl;
	return 0;
}


//����� (���͂��u5 3�v�̂Ƃ��j
//10�s�ڏI���Fa == 5, b == 3, t == ?
//12�s�ڏI���Fa == 5, b == 3, t == 5
//13�s�ڏI���Fa == 3, b == 3, t == 5
//14�s�ڏI���Fa == 3, b == 5, t == 5
