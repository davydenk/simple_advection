#pragma once
#include "mesh.hpp"

template <typename T>
class CSolver{
public:
  
  void FOU(CMesh<T>& m, const T& eq_coeff, const T& time_step, 
           const size_t& Nsteps, const size_t& PrintInterval=0);  
    
};

template <typename T>
void CSolver<T>::FOU(CMesh<T>& m, const T& eq_coeff, const T& time_step,
                       const size_t& Nsteps, const size_t& PrintInterval ) {
  T mult_coeff=eq_coeff*time_step/m.step;
  T time{0};
  for(size_t s=0;s<Nsteps;++s){
    //evolve border with periodic boundary conditions  
    m.new_field[0]=m.field[0]-mult_coeff*(m.field[0]-m.field[m.Ncells-1]);
    for(size_t i=1;i<m.Ncells;++i){ 
      m.new_field[i]=m.field[i]-mult_coeff*(m.field[i]-m.field[i-1]);
    }//for
    time+=time_step;
    m.field.swap(m.new_field);
    if((PrintInterval!=0)&&(s%PrintInterval==0)){
      std::string name;
      name=std::to_string(s);
      name="./gif_dir/"+name+".dat";
      m.print_txt(name);
    }
    
  }//for steps
    m.print_txt("result.txt");
}
