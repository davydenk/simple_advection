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

