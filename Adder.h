#ifndef ADDER_H
#define ADDER_H

class Adder {
private:
	int op1;
	int op2;
	
public:
	Adder(int op1, int op2);
	int process();
};

#endif
