// Counter_to_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<systemc.h>
#include <iostream>
using namespace sc_core;
SC_MODULE(CLOCK) {
    sc_out<bool> clock;
    SC_CTOR(CLOCK) {
        SC_THREAD(clock_generate);
    }
    void clock_generate();
};
void CLOCK::clock_generate() {
    while (true) {
        clock = 1;
        wait(1, SC_NS);
        clock = 0;
        wait(1, SC_NS);
    }
}
SC_MODULE(COUNTER) {
    sc_in<bool>clock;
    sc_in<bool>reset;
    sc_in<uint8_t> starter_value;
    sc_in<uint8_t>end_value;
    sc_uint<8> count;
    sc_event interrupt;

    SC_CTOR(COUNTER) {
        SC_METHOD(counter);
        sensitive << clock;
        dont_initialize();
        SC_METHOD(interrupt_event);
        sensitive << interrupt;
        dont_initialize();
    }
    void counter();
    void interrupt_event();
};
void COUNTER::counter() {
    if (reset.read()==1) {
        count = starter_value.read();
        std::cout << "RESET At time: " << sc_time_stamp() << " count= " << count << std::endl;
    }
    else {
        if (count == end_value) {
            interrupt.notify();
            count = 0;
        }
        else {
            interrupt.cancel();
            count++;
            std::cout << "At time: " << sc_time_stamp() << " count= " << count << std::endl;
        }
        
    }
}
void COUNTER::interrupt_event() {
    std::cout << "Interrupt event. FINISH COUNT TO 9 AND START AGAIN" << endl;
    std::cout << "At time: " << sc_time_stamp() << " count= " << count << std::endl;
}
int sc_main(int argc, char *argv[])
{
    COUNTER counter("counter");
    CLOCK CycleClock("clk");
    sc_signal<bool> clock;
    sc_signal<bool> reset;
    sc_signal<uint8_t> starter_value;
    sc_signal<uint8_t> end_value;
    sc_signal<bool> interrupt;

    CycleClock.clock(clock);
    counter.end_value(end_value);
    counter.starter_value(starter_value);
    counter.reset(reset);
    counter.clock(clock);

    end_value = 9;
    starter_value = 0;
    clock = 0;
    reset = 1;
    sc_start(1, SC_NS);
    reset = 0;
    sc_start(17, SC_NS);
    reset = 1;
    std::cout << "Reset" << std::endl;
    sc_start(1, SC_NS);
    reset = 0;
    sc_start(20, SC_NS);
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
