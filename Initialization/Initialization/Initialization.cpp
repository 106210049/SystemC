// Initialization.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<systemc.h>
#include <iostream>
using namespace sc_core;
SC_MODULE(INITIALIZATION) {
        sc_event e;
    SC_CTOR(INITIALIZATION) {
       
            SC_THREAD(trigger);
            SC_THREAD(catcher_1);
            SC_THREAD(catcher_2);
        SC_THREAD(catcher_3);
            sensitive << e;
            dont_initialize();
    }
    void trigger() {
            while (true) {
                    e.notify(1, SC_SEC);
                    wait(2, SC_SEC);
            }
    }
    void catcher_1() {
        while (true) {
            std::cout << sc_time_stamp() << ": catcher_1 triggered" << std::endl;
                wait(e);
        }
    }
    void catcher_2() {
        while (true) {
            std::cout << sc_time_stamp() << ": catcher_2 triggered" << std::endl;
                wait(e);
        }
    }
        void catcher_3() {
        while (true) {
            std::cout << sc_time_stamp() << ": catcher_3 triggered" << std::endl;
                wait(e);
        }
    }
};
int sc_main(int, char* []) {
    INITIALIZATION init("init");
    sc_start(6, SC_SEC);
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
