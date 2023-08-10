// event2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<systemc.h>
#include <iostream>
using namespace sc_core;
SC_MODULE(EVENT) {
	sc_event e;
	SC_CTOR(EVENT) {
		SC_THREAD(trigger);
		SC_THREAD(catcher);
	}
	void trigger();
	void catcher();
};
void EVENT::trigger()
{
	while (true) {
		std::cout << sc_time_stamp() << std::endl;
		e.notify(1,SC_SEC);
		if (sc_time_stamp() == sc_time(4, SC_SEC))
		{
			e.cancel();
		}
		wait(2, SC_SEC);
		//std::cout << sc_time_stamp() << std::endl;
	}
}
void EVENT::catcher() {
	while (true) {
		wait(e);
		std::cout << "Event cateched at " << sc_time_stamp() << std::endl;
	}
}
int sc_main(int, char* []) {
	EVENT event("event");
	sc_start(8, SC_SEC);
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
