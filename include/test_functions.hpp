#pragma once

#include <vector>
#include <cmath>

/*!This is the discrete solution of the initial condition test_function
 * u_k=cos(2*pi*k/N). Do not modify without modifying the cos_function!
 */
template <typename T>
void test_function(std::vector<T>& data){
  T a{0.1};
  T rho;
  T pi{3.14159265358979323846};
  size_t N=data.size();
  T temp=1-a+a*cos(2*pi/N);
  T temp2=a*sin(2*pi/N);
  rho=std::sqrt(temp*temp+temp2*temp2);
  T pow_rho;
  pow_rho=std::pow(rho,100000);
  T psi=100000*std::asin(a*std::sin(2*pi/N)/rho);
  for(size_t i=0;i<data.size();++i){
    data[i]= pow_rho*std::cos(2*pi*i/N - psi);      
  }
}

