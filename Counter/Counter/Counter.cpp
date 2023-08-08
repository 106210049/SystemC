// Counter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <systemc.h>
#include <iostream>

SC_MODULE(Counter) {
	sc_clock clk;
	int dem = 0;
	SC_CTOR(Counter) :clk("clk", 1, SC_SEC) {
		SC_CTHREAD(counter, clk);
	}
	void counter();
};
void Counter::counter()
{
	while (true) {
		dem++;
	std:cout << "dem= " << dem << std::endl;
		wait();
	}
}
int sc_main(int argc, char* argv[])
{
	Counter count("counter");
	std::cout << "execution phase begins @ " << sc_time_stamp() << std::endl;
	sc_start(4, SC_SEC);
	std::cout << "execution phase ends @ " << sc_time_stamp() << std::endl;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
