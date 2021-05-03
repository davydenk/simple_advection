#pragma once

#include <algorithm> 
#include <iostream>
#include <cmath>
#include <vector>

/*!
 * A simple "hat function" requred in the initial problem set.
 */
template <typename T>
void hat_function(std::vector<T>& data){
  if(data.size()<750){
   std::cerr<<"the function hat_function can only work with meshes longer than 750 cells, but it has been called on the mesh of size " <<data.size()<<". Exiting..."<<std::endl;
  }
  for(size_t i=0;i<250;++i){
    data[i]=0.1; 
  }
  for(size_t i=250;i<=750;++i){
    data[i]=1.0; 
  }
  for(size_t i=751;i<data.size();++i){
    data[i]=0.1; 
  }
}

/*!
 * A constant function used for simple unit test
 */
template <typename T>
void const_function(std::vector<T>& data){
  std::fill(data.begin(),data.end(),0.5);
}

/*!This function is used for testing. Do not modify it without modifying the related result test function.
 * 
 */
template <typename T>
void cos_function(std::vector<T>& data){
  T pi{3.14159265358979323846};
  for(size_t i=0;i<data.size();++i){
    data[i]= std::cos(2*pi*i/data.size());      
  }

}


