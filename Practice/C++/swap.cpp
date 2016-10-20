
//2‚Â‚Ì’l‚ğŒğŠ·

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
