// Semaphore.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<systemc.h>
#include <iostream>
using namespace sc_core;
SC_MODULE(SEMAPHORE) {
    sc_semaphore se;
    SC_CTOR(SEMAPHORE): se(2) {
        SC_THREAD(thread_1);
        SC_THREAD(thread_2);
        SC_THREAD(thread_3);
    }
    void thread_1();
    void thread_2();
    void thread_3();
};
void SEMAPHORE::thread_1() {
    while (true) {
        std::cout <<"Thread 1: " << se.get_value() << std::endl;
        if (se.trywait()==-1) {
            std::cout<<sc_time_stamp() << " semaphore wait function is called at thread 1: " << se.get_value() << std::endl;
            se.wait();
            std::cout << "Thread 1 after wait() is: " << se.get_value() << std::endl;
        }
        std::cout << sc_time_stamp() << ": locked by thread_1, value is " << se.get_value() << std::endl;
        wait(1, SC_SEC);
        se.post(); // release resource
        std::cout << sc_time_stamp() << ": unlocked by thread_1, value is " << se.get_value() << std::endl;
        wait(SC_ZERO_TIME);
    }
}
void SEMAPHORE::thread_2() {
    while (true) {
        std::cout <<"Thread 2: " << se.get_value() << std::endl;
        if (se.trywait()==-1) {
            std::cout << sc_time_stamp() << " semaphore wait function is called at thread 2: " << se.get_value() << std::endl;
            se.wait();
            std::cout << "Thread 2 after wait() is: " << se.get_value() << std::endl;
        }
        std::cout << sc_time_stamp() << ": locked by thread_2, value is " << se.get_value() << std::endl;
        wait(1, SC_SEC);
        se.post(); // release resource
        std::cout << sc_time_stamp() << ": unlocked by thread_2, value is " << se.get_value() << std::endl;
        wait(SC_ZERO_TIME);
    }
}
void SEMAPHORE::thread_3() {
    while (true) {
        std::cout << "Thread 3: " << se.get_value() << std::endl;
        if (se.trywait()==-1) {
            std::cout << sc_time_stamp() << " semaphore wait function is called at thread 3: " <<se.get_value()<< std::endl;
            se.wait();
            std::cout << "Thread 3 after wait() is: " << se.get_value() << std::endl;
        }
        std::cout << sc_time_stamp() << ": locked by thread_3, value is " << se.get_value() << std::endl;
        wait(1, SC_SEC);
        se.post(); // release resource
        std::cout << sc_time_stamp() << ": unlocked by thread_3, value is " << se.get_value() << std::endl;
        wait(SC_ZERO_TIME);
    }
}
int sc_main(int argc, char *argv[])
{
    //std::cout << "Hello World!\n";
    SEMAPHORE semaphore("semaphore");
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
