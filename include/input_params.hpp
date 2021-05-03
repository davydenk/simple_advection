#pragma once

#include <iostream>
#include <fstream>
#include <string>

/*! This class is used to handle the initial input parametres obtained from 
 *  a parameter file (possibly provided as an argument to the executable).
 * The names of the class members are self-explanatory.
 */
template <typename T>
class CParams{
public:    
  T domain_start;
  T domain_end;
  T eq_coeff;
  T time_step;
  size_t Nsteps;
  size_t Ncells;
  size_t output_step;
    
  /*! Constructor that takes the parameter file name to read.
   * The parametres are then printed to the standart output.
   */
  CParams(const std::string file_name){
    read(file_name);
    print();
  };
  
  void read(const std::string& file_name);  
  void print();  
};


/*! This function reads the text parameter files. 
 * The file format supported is strictly the following:
 * 1. the variables in the file must be in order:
 *      - domain_start 
 *      - domain_end 
 *      - equation coefficient 
 *      - desired time_step 
 *      - desired intermidiate output interval (0 for no intermidiate output)
 * 2. each variable must follow the ":" symbol.\n
 * The space before the ":" is best used for the variable name (and possible comments about it).\n
 * .
 * The example of a valid parameter file is:\n
 *      domain start coordinate: 0.0\n
 *      domain end coordinate: 1000.0\n
 *      equation coefficient: 1.0\n
 *      time step: 0.1\n
 *      number of time steps: 100000\n
 *      number of cells: 1000\n
 *      intermidiate output step: 0\n
 */
template<typename T> 
void CParams<T>::read(const std::string& file_name ) {
  std::ifstream file_var(file_name);
  if (!file_var){
    std::cerr<<"Failed to open file "<<file_name<<std::endl; 
    exit(1);
  }  
  file_var.ignore(1000, ':');   
  file_var >> domain_start;
  file_var.ignore(1000, ':');   
  file_var >> domain_end;
  file_var.ignore(1000, ':');   
  file_var >> eq_coeff;
  file_var.ignore(1000, ':');   
  file_var >> time_step;
  file_var.ignore(1000, ':');   
  file_var >> Nsteps;
  file_var.ignore(1000, ':');
  file_var >> Ncells;
  file_var.ignore(1000, ':');
  file_var >> output_step;
  file_var.close();
}

/*! This function prints the values from the parameter file to the standart output.
 * The function is not an echo of the parameter file.
 */
template<typename T> 
void CParams<T>::print(){
  std::cout<<"The parameter file has been read successfully. The parameters are:\n"
           <<" domain start coordinate: "<<domain_start
           <<"\n domain end coordinate: "<<domain_end
           <<"\n equation coefficient:  "<<eq_coeff
           <<"\n time step: "<<time_step
           <<"\n number of time steps: "<<Nsteps
           <<"\n number of cells: "<<Ncells
           <<"\n intermidiate output step: "<<output_step;
  if (output_step==0){
    std::cout<<"(no intermidiate output)"<<std::endl;    
  }else{
    std::cout<<std::endl;    
  }//if-else           
}
