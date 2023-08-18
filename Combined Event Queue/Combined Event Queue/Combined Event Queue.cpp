// Combined Event Queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<systemc.h>
#include <iostream>
using namespace sc_core;
SC_MODULE(QUEUE_COMBINED) {
    sc_event_queue e1, e2;
    SC_CTOR(QUEUE_COMBINED) {
        SC_THREAD(trigger);
        SC_THREAD(catcher);
        sensitive << e1 << e2;
        dont_initialize();
    }
    void trigger();
    void catcher();
};
void QUEUE_COMBINED::trigger() {
        e1.notify(1, SC_SEC);
        e1.notify(2, SC_SEC);
        e2.notify(2, SC_SEC); // eq1 and eq2
        e2.notify(3, SC_SEC); // eq2
}
void QUEUE_COMBINED::catcher() {
    while (true) {
        std::cout << sc_time_stamp() << ": catches trigger" << std::endl;
        wait();
    }
}
int sc_main(int argc, char *argv[])
{
    QUEUE_COMBINED queue_combined("queue_combined");
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
