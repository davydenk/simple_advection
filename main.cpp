#include <iostream>

#include "input_params.hpp"
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
    
    std::cout<<"meow:"<<argv[1]<<std::endl;
    CParams<double> params(argv[1]);
    CMesh<double> data(params.Ncells, params.domain_start,params.domain_end, 
                       hat_function<double>);
    data.print_txt("out.txt");
    system("mkdir -p gif_dir");
    CSolver<double> solve;
    solve.FOU(data,params.eq_coeff, params.time_step, 
              params.Nsteps, params.output_step);
};
