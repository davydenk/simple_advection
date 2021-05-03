#pragma once
#include "mesh.hpp"

/*! The class is used for solving the equation by applying a chosen 
 * descreete scheme to the mesh data. The schemes curently available are:  
 * - first order upwind scheme
 */
template <typename T>
class CSolver{
public:
  
  void FOU(CMesh<T>& m, const T& eq_coeff, const T& time_step, 
           const size_t& Nsteps, const size_t& PrintInterval=0);  
    
};


/*! This function applies the first order upwind scheme to the mesh data. 
   * The basic scheme info can be found in en.wikipedia.org/wiki/Upwind_scheme.
   * Parameters used:
   * - a reference to a mesh variable
   * - advection equation coefficient 
   * - time step
   * - the number of steps
   * - PritInterval for the output, if set to 0, no intermidiate output occurs.
   * Currently, the output is performed in text format, so it is not adviced to print 
   * too many steps. The intermidiate output files are written to the "gif_dir" folder
   * with the names "TIME_STEP.dat".
   * The final output is printed to the "result.txt" file.
   */  
template <typename T>
void CSolver<T>::FOU(CMesh<T>& m, const T& eq_coeff, const T& time_step,
                       const size_t& Nsteps, const size_t& PrintInterval ) {
  T mult_coeff=eq_coeff*time_step/m.step;
  T time{0};
  if(eq_coeff>0){
    for(size_t s=0;s<Nsteps;++s){
      //evolve border with periodic boundary conditions  
      m.new_field[0]=m.field[0]-mult_coeff*(m.field[0]-m.field[m.Ncells-1]);
      for(size_t i=1;i<m.Ncells;++i){ 
        m.new_field[i]=m.field[i]-mult_coeff*(m.field[i]-m.field[i-1]);
      }//for
      time+=time_step;
      m.field.swap(m.new_field);//to avoid copying
      if((PrintInterval!=0)&&(s%PrintInterval==0)){
        std::string name;
        name=std::to_string(s);
        name="./gif_dir/"+name+".dat";
        m.print_txt(name);
      }
    }//for steps  
  }else{
    for(size_t s=0;s<Nsteps;++s){
      for(size_t i=0;i<m.Ncells-1;++i){ 
        m.new_field[i]=m.field[i]-mult_coeff*(m.field[i+1]-m.field[i]);
      }//for
      m.new_field[m.Ncells-1]=m.field[0]-mult_coeff*(m.field[0]-m.field[m.Ncells-2]);
      time+=time_step;
      m.field.swap(m.new_field);
      if((PrintInterval!=0)&&(s%PrintInterval==0)){
        std::string name;
        name=std::to_string(s);
        name="./gif_dir/"+name+".dat";
        m.print_txt(name);
      }
    }//for steps    
  }//if-else; repeated the whole loop to avoid "if" inside
  
  m.print_txt("result.txt");
}
