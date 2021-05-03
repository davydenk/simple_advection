#pragma once

#include <iostream>
#include <fstream>
#include <vector>

#include "initial_conditions.hpp"


/*! This class holds both the geometrical data of the mesh 
* and the discrete data on it. It is also responsible for setting the initial
* conditions and printing the data. Currently, the only output implemented
* is a basic .txt format. Thus, it is not advisable to output large amounts of data.
*/
template <typename T>
class CMesh{
public:
  size_t Ncells;
  T step;
  std::vector<T> cells;  
  std::vector<T> field;
  std::vector<T> new_field;
  /*! This constructor takes as a parameter the number 
  * of cells we are going to work with and
  * resizes the vectors used to store the data
  */
  CMesh(size_t N): Ncells(N){
    cells.resize(N);
    field.resize(N);
    new_field.resize(N);
  }
  void init(const T& domain_start, const T& domain_end);
  /*! In case one wants to reuse the mesh variable, this functions makes it
  * possible to reset everything to zero.
  */
  void reset(){
    cells.resize(0);
    field.resize(0);
    new_field.resize(0);
    Ncells=0;
    step=0;
  }
  /*!
  * The function is used to initialize the field variable values with the initial
  * conditions required by means of calling function "f" that can be passed as an argument.
  * For example, if your function is called "my_inital_conditions", you need to invoke this 
  * with set_initial_conditions(my_inital_conditions). Your function should not modify the 
  * field size, but only fill in the values.
  */
  template <typename F>
  void set_initial_conditions(F f){
    f(field);
  };
  void print_txt(std::string file_name);  
    
};

/*!
* This function is responsible prepairing the mesh to work: 
* - initializing the geomentical data based on the physicial dimensions 
* and the number of cells provided in a parameter file.
* - calling the initial conditions set up.
*/
template <typename T>
void CMesh<T>::init(const T& domain_start, const T& domain_end){
    step=(domain_end-domain_start)/Ncells;
    cells[0]=domain_start;
    for(size_t i=1;i<Ncells;++i){
      cells[i]=cells[i-1]+step;
    }
    set_initial_conditions(hat_function<T>);
}

/*! The function prints the field value for each cell into a text file.
* Since the format is .txt, it is not adviced to call 
* it on a large data set nor use it for creating a restart file.
*/
template <typename T>
void CMesh<T>::print_txt(std::string file_name){
  std::ofstream text_file(file_name);
  for(size_t i=0;i<Ncells;++i){
    text_file<<cells[i]<< " " << field[i]<<std::endl;
  }
  text_file.close(); 
}
