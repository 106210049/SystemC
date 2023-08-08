// All systemc modules should include systemc.h header file

#include<systemc.h>
#include <iostream>
using namespace sc_core;
SC_MODULE(calculation) {
    sc_int<5> a ;
    sc_int<5> b ;
    sc_bv<5> positions = "01101";
    sc_bv<6> mask = "100111";
    sc_lv<8> data_drive="zz01XZ1Z";
    sc_logic buf=sc_dt::Log_Z;
    SC_HAS_PROCESS(calculation);
    calculation(sc_module_name name, sc_int<5>, sc_int<5>);
    void sum();
    void multi();
    void subs();
    void AND();
    void range();
    void logic();
};
calculation::calculation(sc_module_name name, sc_int<5> a, sc_int<5>b) : a(a), b(b) {
    SC_METHOD(sum);
    SC_METHOD(multi);
    SC_METHOD(subs);
    SC_METHOD(AND);
    SC_METHOD(range);
    SC_METHOD(logic);
}
void calculation::sum()
{
    std::cout << "a+b= " << a + b << std::endl;
}
void calculation::multi() {
    std::cout << "a*b= " << a * b << std::endl;
}
void calculation::subs() {
    std::cout << "a-b= " << a - b << std::endl;
}

void calculation::AND() {
    sc_bv<5> active = positions & mask;
    std::cout << "active= " << active << std::endl;
}
void calculation::range() {
    positions.range(3, 2) = "00";
    std::cout << "positions.range(3,2)=00 :" <<positions<< std::endl;
}
void calculation::logic() {
    std::cout << "buf= " << calculation::buf << " ; data_drive= " << calculation::data_drive << std::endl;
}
int sc_main(int argc, char* argv[])
{
    sc_int<5> a=2;
    sc_int<5> b=4;
    calculation calculate("cal",a,b);
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
