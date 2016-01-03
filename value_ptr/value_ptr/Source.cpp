#include <iostream>
#include <memory>
#include "value_ptr.hpp"

using namespace std;


int main()
{
	auto x = make_unique<float>(1.23f);
	auto y = make_unique<float>(100.f);


	// Raw pointer requires dereferencing
	cout << endl << "Pointers:" << endl;
	auto px = x.get();
	auto py = y.get();
	cout << px << endl;			// Accessing address
	cout << *px + *py << endl;	// Have to dereference


	// value_wrapper doesn't need manual dereferencing
	cout << endl << "Value pointers:" << endl;
	value_ptr<float> vx(x.get());
	value_ptr<float> vy(y.get());
	cout << vx << endl;			// Accessing value
	cout << vx + vy << endl;	// No need to manually dereference

	vx = 4.56f;
	cout << *x << endl;

	*x = 7.89f;
	cout << vx << endl;


	// pause
	cin.get();
}