// Process_Method.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <systemc.h>
#include <iostream>
using namespace sc_core;
SC_MODULE(PROCESS) {
    SC_CTOR(PROCESS) {
        SC_THREAD(thread);
        SC_METHOD(method);
    }
    void thread();
    void method();
};
void PROCESS::thread() {
    int idx = 0;
    while (true) {
        std::cout << " thread " << idx++ << " @ " << sc_time_stamp() << std::endl;
        wait(1, SC_SEC);
    }
    
}
void PROCESS::method() {
    int idx = 0;
    std::cout << " method " << idx++ << " @ " << sc_time_stamp() << std::endl;
    next_trigger(1, SC_SEC);
}
int sc_main(int argc, char *argv[])
{
    //std::cout << "Hello World!\n";
    PROCESS process("process");
    sc_start(4, SC_SEC);
    return 0;
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
