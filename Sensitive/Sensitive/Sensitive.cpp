// Sensitive.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<systemc.h>
#include <iostream>
using namespace sc_core;
SC_MODULE(SENSITIVE) {
    sc_event e1, e2;
    SC_CTOR(SENSITIVE) {
        SC_THREAD(trigger_1);
        SC_THREAD(trigger_2);
        SC_THREAD(catch_1or2_dyn);
        SC_THREAD(catch_1or2_static);
        sensitive << e1 << e2;
    }
    void trigger_1();
    void trigger_2();
    void catch_1or2_dyn();
    void catch_1or2_static();
    
};
void SENSITIVE::trigger_1() {
    wait(SC_ZERO_TIME);
    while (true) {
        e1.notify();
        wait(2, SC_SEC);
    }
}
void SENSITIVE::trigger_2() {
    wait(SC_ZERO_TIME);
    while (true) {
        e2.notify();
        wait(3, SC_SEC);
    }
}
void SENSITIVE::catch_1or2_dyn() {
    while (true) {
            wait(e1 | e2);
        std::cout << "Dynamic sensitivty: e1 or e2 @ " << sc_time_stamp() << std::endl;
    }
}
void SENSITIVE::catch_1or2_static(void) {
    while (true) {
        wait();
        std::cout << "Static sensitivity: e1 or e2 @ " << sc_time_stamp() << std::endl;
    }
}
int sc_main(int argc, char* argv[])
{
    //std::cout << "Hello World!\n";
    SENSITIVE sensitivity("sensitive");
    sc_start(7,SC_SEC);
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
