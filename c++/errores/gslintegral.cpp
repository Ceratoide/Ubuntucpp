#include <iostream>
#include <cmath>
#include <gsl/gsl_integration.h>

double f (double x, void * params) {
  double alpha = *(double *) params;
  double f = std::pow(x,alpha);
  return f;
}

int main (void) {
  gsl_integration_workspace * w  = gsl_integration_workspace_alloc(1000);
  
  double result,error;
  double alpha = 5;

  gsl_function F;
  F.function = &f;
  F.params = &alpha;

  gsl_integration_qags (&F, 0, 10, 0, 1e-7, 1000,
                        w, &result,&error); 

  std::cout<<result<<"\n";

 

  return 0;
}
