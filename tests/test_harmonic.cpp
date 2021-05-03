 
#include <iostream>
#include <cmath>

#include "input_params.hpp"
#include "initial_conditions.hpp"
#include "test_functions.hpp"
#include "mesh.hpp"
#include "solver.hpp"

int main(int argc, char *argv[]){
    std::cout<<"This program is a simple (serial, 1-dimentional) \n" <<
            "simulator of advection  equation using a 1st order upwind scheme."
            <<std::endl;
    if(argc<2){
		std::cout<<"usage: "<<argv[0]<< " PARAM_FILE"<<std::endl;
		exit(1);
	}
    
    std::cout<<"Currently running the single harmonic test"<<std::endl;
    CParams<double> params(argv[1]);
    CMesh<double> data(params.Ncells, params.domain_start,params.domain_end, 
                       cos_function<double>);
    CSolver<double> solve;
    solve.FOU(data,params.eq_coeff, params.time_step, 
              params.Nsteps, params.output_step);
    
    //use the mesh constructor to have the test functions applied
    CMesh<double> test_data(params.Ncells, params.domain_start,params.domain_end, 
                       test_function<double>);
    
    for(size_t i=0;i<params.Ncells;++i){
        if (std::fabs(data.field[i]-test_data.field[i])>1.0e-10){
            std::cerr<<"The harmonic test has failed"<<std::endl;
            exit(1);
        }
    }
    std::cout<<"The harmonic test has passed"<<std::endl;
};
