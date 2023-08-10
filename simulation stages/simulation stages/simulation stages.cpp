// simulation stages.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <systemc.h>
#include <iostream>

SC_MODULE(STAGE) {
	SC_CTOR(STAGE) {
		std::cout<<sc_time_stamp()<< ": Elaboration: constructor" << std::endl;
		SC_THREAD(thread);
	}
	void thread();
	void before_end_of_elaboration();
	void end_of_elaboration();
	void start_of_simulation();
	void end_of_simulation();
	~STAGE() {
		std::cout << sc_time_stamp() << ": Cleanup: desctructor" << std::endl;
	}
};
void STAGE::thread() {
	std::cout << sc_time_stamp() << ": Execution.initialization" << std::endl;
	int i = 0;
	while (true) {
		wait(1, SC_SEC);
		std::cout << sc_time_stamp() << ": Execution.simulation" << std::endl;
		if (++i >= 2) {
			sc_stop();
		}
	}
}
void STAGE::before_end_of_elaboration() {
	std::cout << "before end of elaboration" << std::endl;
}
void STAGE::end_of_elaboration() {
	std::cout << "end of elaboration" << std::endl;
}
void STAGE::start_of_simulation() {
	std::cout << "start of simulation" << std::endl;
}
void STAGE::end_of_simulation() {
	std::cout << "end of simulation" << std::endl;
}
int sc_main(int argc, char*argv[])
{
	STAGE stages("stages");
	sc_start();
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
