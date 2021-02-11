#include <iostream>
#include <cmath>
typedef float REAL;

REAL sumup(int Nmax); 
REAL sumdown(int Nmax);
int main(int argn,char* argv[]){
  for(int nmax=1;nmax<=100;++nmax){
    std::cout<< nmax <<"\t"
	     << std::fabs(1-sumdown(nmax)/sumup(nmax))
	     << "\n";
  }
  return 0;
}
REAL sumup(int Nmax){
  REAL suma=0.;
  for(int ii=1;ii<= Nmax;++ii){
    suma+=1./ii;
  }
  return suma;
}
REAL sumdown(int Nmax){
  REAL suma=0;
  for(int ii=Nmax;ii>=1;--ii){
    suma+=1./ii;
  }
  return suma;
}
