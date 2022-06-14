#include <iostream>
#include "Adder.h"
#include "Calc.h"

using namespace std;

void Calc::run() {
	int op1, op2;
	cout << "�� �� �Է� >> ";
	cin >> op1 >> op2;

	Adder* adder = new Adder(op1, op2);
	cout << adder->process() << endl;

	delete adder;
}

void calc_main() {
	Calc* c = new Calc();
	c->run();

	delete c;
}