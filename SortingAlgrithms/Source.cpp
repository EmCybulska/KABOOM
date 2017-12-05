#include <iostream>

class A {
public:
	A() {
		counter++;
		number = counter;
	}

	int number;
	static int counter;
};

int A::counter = 0;

int main() {

	std::cout << A::counter << std::endl;
	//std::cout << A::counter << std::endl;
	//std::cout << A::counter << std::endl;


	return 0;
}