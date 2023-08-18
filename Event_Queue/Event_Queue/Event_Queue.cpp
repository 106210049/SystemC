// Event_Queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<systemc.h>
#include <iostream>
using namespace sc_core;
SC_MODULE(QUEUE) {
    sc_event e;
    sc_event_queue eq;
    SC_CTOR(QUEUE) {
        SC_THREAD(trigger);
        SC_THREAD(catch_e);
        sensitive << e;
        dont_initialize();
        SC_THREAD(catch_eq);
        sensitive << eq;
        dont_initialize();
    }
    void trigger();
    void catch_e();
    void catch_eq();
};
void QUEUE::trigger() {
    while (true) {
        e.notify(1, SC_SEC);
        e.notify(2, SC_SEC);
        eq.notify(1, SC_SEC);
        eq.notify(2, SC_SEC);
        wait(10, SC_SEC);
    }
}
void QUEUE::catch_e() {
    while (true) {
        std::cout << sc_time_stamp() << ": catches e" << std::endl;
        wait(e);
    }
}
void QUEUE::catch_eq() {
    while (true) {
        std::cout << sc_time_stamp() << ": catches eq" << std::endl;
        wait();
    }
}
int sc_main(int argc, char *argv[])
{
    QUEUE queue("queue");
    sc_start(20, SC_SEC);
    return 0;
    //std::cout << "Hello World!\n";
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
