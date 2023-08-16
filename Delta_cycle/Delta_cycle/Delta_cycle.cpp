// Delta_cycle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<systemc.h>
#include <iostream>
using namespace sc_core;

SC_MODULE(DELTA_CYCLE) {
    int x = 2;
    int y = 1;
    SC_CTOR(DELTA_CYCLE) {
        SC_THREAD(add_x);
        SC_THREAD(add_y);
        SC_THREAD(multiply_x);
        SC_THREAD(multiply_y);
    }
    void add_x();
    void add_y();
    void multiply_x();
    void multiply_y();
};
void DELTA_CYCLE::add_x() {
    std::cout << "add_x: " << x << " + 2" << " = ";
    x += 2;
    std::cout << x << std::endl;
}
void DELTA_CYCLE::add_y() {
    wait(SC_ZERO_TIME); // run after delta cycle
    std::cout << "add_y: " << y << " + 2" << " = ";
    y += 2;
    std::cout << y << std::endl;
}
void DELTA_CYCLE::multiply_x() {
    wait(SC_ZERO_TIME); // run after delta cycle
    std::cout << "multiply_x: " << x << " * 3" << " = ";
    x *= 3;
    std::cout << x << std::endl;
}
void DELTA_CYCLE::multiply_y() {
    std::cout << "multiply_y: " << y << " * 3" << " = ";
    y *= 3;
    std::cout << y << std::endl;
}
int sc_main(int argc, char *argv[])
{
    DELTA_CYCLE delta_cycle("delta_cycle");
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
