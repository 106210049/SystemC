// event.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<systemc.h>
#include <iostream>

SC_MODULE(events) {
    sc_in<bool> clock;

    sc_event  e1;
    sc_event  e2;

    void do_test1() {
        while (true) {
            // Wait for posedge of clock
            wait();
            cout << "@" << sc_time_stamp() << " Starting test" << endl;
            // Wait for posedge of clock
            wait();
            cout << "@" << sc_time_stamp() << " Triggering e1" << endl;
            // Trigger event e1
            e1.notify(5, SC_NS);
            // Wait for posedge of clock
            wait();
            // Wait for event e2
            wait(e2);
            cout << "@" << sc_time_stamp() << " Got Trigger e2" << endl;
            // Wait for posedge of clock
            wait();
            cout << "@" << sc_time_stamp() << "Terminating Simulation" << endl;
            sc_stop(); // sc_stop triggers end of simulation
        }
    }

    void do_test2() {
        while (true) {
            // Wait for event e2
            wait(e1);
            cout << "@" << sc_time_stamp() << " Got Trigger e1" << endl;
            // Wait for 3 posedge of clock
            wait(5);
            cout << "@" << sc_time_stamp() << " Triggering e2" << endl;
            // Trigger event e2
            e2.notify();
        }
    }

    SC_CTOR(events) {
        SC_CTHREAD(do_test1, clock.pos());
        SC_CTHREAD(do_test2, clock.pos());
    }
};

int sc_main(int argc, char* argv[]) {
    sc_clock clock("my_clock", 1, 0.5);

    events  object("events");
    object.clock(clock);

    sc_start();  // Run the simulation till sc_stop is encountered
    return 0;// Terminate simulation
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
