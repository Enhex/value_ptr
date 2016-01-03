# value_ptr
Template class that holds a pointer and automatically dereferences it.
Allows writing more clean and elegant code.


####Insall
Include the header "value_ptr.hpp".


#### Example
```c++
#include <iostream>
#include <memory>
#include "value_ptr.hpp"

using namespace std;


int main()
{
	auto x = make_unique<float>(1.23f);
	auto y = make_unique<float>(100.f);


	// Raw pointer requires dereferencing
	cout << "Pointers:" << endl;
	auto px = x.get();
	auto py = y.get();
	cout << px << endl;			// Accessing address
	cout << *px + *py << endl;	// Have to dereference


	// value_ptr doesn't need manual dereferencing
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
```

#####Output:
```
Pointers:
00804BC8
101.23

Value pointers:
1.23
101.23
4.56
7.89
```
