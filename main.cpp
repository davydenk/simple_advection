#include <iostream>

#include "mesh.hpp"
#include "solver.hpp"

int main(int argc, char *argv[]){
    std::cout<<"This program is a simple (serial, 1-dimentional) \n" <<
            "simulator of advection  equation using a 1st order upwind scheme."
            <<std::endl;
    
            
    double domain_start{0.0};
    double domain_end{1000.0};
    double eq_coeff{1.0};
    double time_step{0.1};
    size_t Nsteps{100000};
    CMesh<double> data(1000);
    data.init(domain_start,domain_end);
    data.print_txt("out.txt");
    CSolver<double> solve;
    solve.FOU(data,eq_coeff,time_step,Nsteps,0); 

};
