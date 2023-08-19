// MUTEX.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<systemc.h>
#include <iostream>
using namespace sc_core;
void BUS(int who, int thread);
SC_MODULE(MUTEX) {
    sc_mutex m;
    SC_CTOR(MUTEX) {
        SC_THREAD(thread_1);
        SC_THREAD(thread_2);
    }
    void thread_1();
    void thread_2();
};
void MUTEX::thread_1() {
    while (true) {
        //cout << "@" << sc_time_stamp() << " Checking mutex intance 0" << endl;
        if (m.trylock()==-1) {
            m.lock();
            std::cout << sc_time_stamp() << ": thread_1 obtained resource by lock()" << std::endl;
            BUS(1,1);
        }
        else {
            std::cout << sc_time_stamp() << ": thread_1 obtained resource by trylock()" << std::endl;
        }
        wait(1, SC_SEC);
        m.unlock();
        std::cout << sc_time_stamp() << ": unlocked by thread_1" << std::endl;        
        wait(SC_ZERO_TIME);
    }
}
void MUTEX::thread_2() {
    while (true) {
        //cout << "@" << sc_time_stamp() << " Checking mutex intance 1" << endl;
        if (m.trylock() == -1) {
            m.lock();
            std::cout << sc_time_stamp() << ": thread_2 obtained resource by lock()" << std::endl;
            BUS(1,2);
        }
        else {
            std::cout << sc_time_stamp() << ": thread_2 obtained resource by trylock()" << std::endl;
        }
        wait(1, SC_SEC);
        m.unlock();
        std::cout << sc_time_stamp() << ": unlocked by thread_2" << std::endl;
        wait(SC_ZERO_TIME);
    }
}
void BUS(int who, int thread) {
    std::cout<< sc_time_stamp() << " Bus access by instance " << who << " with lock by thread "<< thread << endl;
}
int sc_main(int argc, char *argv[])
{
    MUTEX mutex("mutex");
    sc_start(4, SC_SEC);
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
