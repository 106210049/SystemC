// Combined_Events.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//The following forms of wait() are supported.
//1. wait() : wait on events in sensitivity list(SystemC 1.0).
//2. wait(e1) : wait on event e1.
//3. wait(e1 | e2 | e3) : wait on events e1, e2, or e3.
//4. wait(e1 & e2 & e3) : wait on events e1, e2, and e3.
//5. wait(200, SC_NS) : wait for 200 ns.
//6. wait(200, SC_NS, e1) : wait on event e1, timeout after 200 ns.
//7. wait(200, SC_NS, e1 | e2 | e3) : wait on events e1, e2, or e3, timeout after 200 ns.
//8. wait(200, SC_NS, e1 & e2 & e3) : wait on events e1, e2, and e3, timeout after 200 ns.
//9. wait(sc_time(200, SC_NS)) : wait for 200 ns.
//10. wait(sc_time(200, SC_NS), e1) : wait on event e1, timeout after 200 ns.
//11. wait(sc_time(200, SC_NS), e1 | e2 | e3) : wait on events e1, e2, or e3, timeout after 200 ns.
//12. wait(sc_time(200, SC_NS), e1 & e2 & e3) : wait on events e1, e2, and e3, timeout after 200 ns.
//13. wait(200) : wait for 200 clock cycles, SC_CTHREAD only(SystemC 1.0)
//14. wait(0, SC_NS) : wait one delta cycle.
//15. wait(SC_ZERO_TIME) : wait one delta cycle.
//Note :
//	a mixture of "|" operators and "&" operators is not supported in SystemC 2.0

#include<systemc.h>
#include <iostream>
using namespace sc_core;
SC_MODULE(COMBINED) {
	sc_event e1, e2, e3, e4, e5, e6, e7, e8, e9, e10;
	SC_CTOR(COMBINED) {
		SC_THREAD(Trigger);
		SC_THREAD(Catcher_0);
		SC_THREAD(Catcher_1);
		SC_THREAD(Catcher_2and3);
		SC_THREAD(Catcher_4or5);
		SC_THREAD(Catcher_timeout_or_6);
		SC_THREAD(Catcher_timeout_or_7or8);
		SC_THREAD(Catcher_timeout_or_9and10);
	}
	void Trigger(void);
	void Catcher_0(void);
	void Catcher_1(void);
	void Catcher_2and3(void);
	void Catcher_4or5(void);
	void Catcher_timeout_or_6(void);
	void Catcher_timeout_or_7or8(void);
	void Catcher_timeout_or_9and10(void);
};
void COMBINED::Trigger() {
	e1.notify(1, SC_SEC);
	e2.notify(2, SC_SEC);
	e3.notify(3, SC_SEC);
	e4.notify(4, SC_SEC);
	e5.notify(5, SC_SEC);
	e6.notify(6, SC_SEC);
	e7.notify(7, SC_SEC);
	e8.notify(8, SC_SEC);
	e9.notify(9, SC_SEC);
	e10.notify(10, SC_SEC);
}
void COMBINED::Catcher_0() {
	wait(2, SC_SEC);
	std::cout << sc_time_stamp() << ": 2sec timeout" << std::endl;
}
void COMBINED::Catcher_1() {
	wait(e1);
	std::cout << sc_time_stamp() << ": catch e1" << std::endl;
}
void COMBINED::Catcher_2and3() {
	wait(e2 & e3);
	std::cout << sc_time_stamp() << ": catch e2 and e3" << std::endl;
}
void COMBINED::Catcher_4or5() {
	wait(e4 | e5);
	std::cout << sc_time_stamp() << ": catch e4 or e5" << std::endl;
}
void COMBINED::Catcher_timeout_or_6() {
	wait(sc_time(5, SC_SEC), e6);
	std::cout << sc_time_stamp() << ": 5sec timeout or catch e6" << std::endl;
}
void COMBINED::Catcher_timeout_or_7or8() {
	wait(sc_time(20, SC_SEC), e7|e8);
	std::cout << sc_time_stamp() << ": 20sec timeout or catch e7 or e8" << std::endl;
}
void COMBINED::Catcher_timeout_or_9and10() {
	wait(sc_time(20, SC_SEC), e9 & e10);
	std::cout << sc_time_stamp() << ": 20sec timeout or catch (e9 and e10)" << std::endl;
}
int sc_main(int argc, char *argv[])
{
	COMBINED combined("event combined");
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
