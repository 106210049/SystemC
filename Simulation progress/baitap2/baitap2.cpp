// baitap2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "systemc.h"
#include<iostream>
using namespace sc_core;
SC_MODULE(PROCESS) {
    sc_clock clk;
    SC_CTOR(PROCESS) :clk("clk,",2, SC_SEC) {
        SC_METHOD(method);
        SC_THREAD(thread);
        SC_CTHREAD(cthread, clk);
    }
    void method();
    void thread();
    void cthread();
};

void PROCESS::method()
{
    std::cout << "method triggered @ " << sc_time_stamp() << std::endl;
    next_trigger(sc_time(2, SC_SEC));
}
void PROCESS::thread()
{
    while (true) {
        std::cout << "thread triggered @ " << sc_time_stamp() << std::endl;
        wait(2, SC_SEC);
    }
}
void PROCESS::cthread() {
    while (true) {
        std::cout << "cthread triggered @ " << sc_time_stamp() << std::endl;
        wait();
    }
}
int sc_main(int argc, char* argv[])
{
    PROCESS process("process");
    std::cout << "execution phase begins @ " << sc_time_stamp() << std::endl;
    sc_start(8, SC_SEC);
    std::cout << "execution phase ends @ " << sc_time_stamp() << std::endl;
    return (0);
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
