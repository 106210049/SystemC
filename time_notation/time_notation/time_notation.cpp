// time_notation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<systemc.h>
#include <iostream>
using namespace sc_core;

int sc_main(int argc , char*argv[])
{
    sc_core::sc_report_handler::set_actions("/IEEE_Std_1666/deprecated",sc_core::SC_DO_NOTHING);
    sc_set_time_resolution(1, SC_FS);
    sc_set_default_time_unit(1, SC_SEC);
    std::cout << "1 SEC =     " << sc_time(1, SC_SEC).to_default_time_units() << " SEC" << std::endl;
    std::cout << "1  MS = " << sc_time(1, SC_MS).to_default_time_units() << " SEC" << std::endl;
    std::cout << "1  US = " << sc_time(1, SC_US).to_default_time_units() << " SEC" << std::endl;
    std::cout << "1  NS = " << sc_time(1, SC_NS).to_default_time_units() << " SEC" << std::endl;
    std::cout << "1  PS = " << sc_time(1, SC_PS).to_default_time_units() << " SEC" << std::endl;
    std::cout << "1  FS = " << sc_time(1, SC_FS).to_default_time_units() << " SEC" << std::endl;
        sc_start(1000, SC_SEC);
        double t = sc_time_stamp().to_seconds();
        std::cout << "t= " << t <<" s" << std::endl;
    std::cout << int(t) / 3600 << " hours, " << (int(t) % 3600) / 60 << " minutes, " << (int(t) % 60) << "seconds" << std::endl;
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
