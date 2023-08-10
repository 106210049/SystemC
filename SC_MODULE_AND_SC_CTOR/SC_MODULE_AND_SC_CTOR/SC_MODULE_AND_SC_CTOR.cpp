// All systemc modules should include systemc.h header file
//

#include<systemc.h>
#include <iostream>

SC_MODULE(MODULE_A) {
    SC_CTOR(MODULE_A) {
        SC_METHOD(func_a);
    }
    void func_a();
};
void MODULE_A::func_a()
{
    std::cout <<name() << "Hello world" << std::endl;
}

SC_MODULE(MODULE_B) {
    const int i;
    const int j;
    SC_CTOR(MODULE_B);
    MODULE_B(sc_module_name name, int i,int j) : sc_module(name), i(i),j(j) {
        SC_METHOD(func_b);
    }
    void func_b();
};
void MODULE_B::func_b()
{
    std::cout << this->name() << "Hello world" <<" i= "<<i<< "j= "<<j << std::endl;
}
int sc_main(int argc, char* argv[])
{
    MODULE_A module_a("module_a");
    MODULE_B module_b("module_b",1,2);
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
