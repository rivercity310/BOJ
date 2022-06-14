#include "Adder.h"

Adder::Adder(int op1, int op2) {
	this->op1 = op1;
	this->op2 = op2;
}

int Adder::process() {
	return op1 + op2;
}