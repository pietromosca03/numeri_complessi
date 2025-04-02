#include <iostream>
#include "complessi.hpp"


int main(void) {
    using cmp = complessi<double>;

    cmp c1(0,3);
    cmp c2(2,-5);


    cmp c3 = c1+c2; 
    std::cout << c1 << " + " << c2 << " = " << c1+c2 << std::endl;
    std::cout << c1 << " x " << c2 << " = " << c1*c2 << std::endl;

    double h1 = c1.coniugato();
    cmp hh1(c1.parte_reale(),h1);
    std::cout << hh1 << std::endl;
    double p2 = c2.partereale();
    std::cout <<"la parte reale del numero è "<< p2 << std::endl;
    double p3 = c2.parteimmaginaria();
    std::cout <<"la parte immaginaria del numero è "<< p3 << std::endl;
    return 0;

}
