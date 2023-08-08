// All systemc modules should include systemc.h header file

#include "systemc.h"

SC_MODULE(MODULE_A) {
    MODULE_A(sc_module_name name) {
        std::cout << this->name() << ", no SC_CTOR or SC_HAS_PROCESS" << std::endl;
    }
};

SC_MODULE(MODULE_B) {
private:
    const int i;
    const int j;
public:
    SC_HAS_PROCESS(MODULE_B);
    MODULE_B(sc_module_name, int,int);
    void func_b();
};
MODULE_B::MODULE_B(sc_module_name name, int i,int j) :i(i),j(j){
    SC_METHOD(func_b);
}
void MODULE_B::func_b()
{
    std::cout << this->name() << ", is has proccess constructor and has additional input argument and i= " << i <<" and j= "<<j << std::endl;
}

SC_MODULE(MODULE_C) {
    SC_CTOR(MODULE_C) {
        SC_METHOD(func_c);
    }
    void func_c();
    
};
void MODULE_C::func_c()
{
    std::cout << this->name() << "is sc_ctor constructor"<<std::endl;
}
SC_MODULE(MODULE_D) {
    SC_HAS_PROCESS(MODULE_D);
    MODULE_D(sc_module_name);
    void func_d();
};
MODULE_D::MODULE_D(sc_module_name name) :sc_module(name) {
    SC_METHOD(func_d);
}
void MODULE_D::func_d()
{
std:cout << "Hello" << this->name() << std::endl;
}
int sc_main(int argc, char* argv[])
{
    MODULE_A mod_a("module_a");
    MODULE_B mod_b("module_b",2,3);
    MODULE_C mod_c("module_c");
    MODULE_D mod_d("module_d");
    sc_start();

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
