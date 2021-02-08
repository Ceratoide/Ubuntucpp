#include <iostream>
#include <vector>
#include <cmath>
std::vector <int> girar(int N);
std::vector <int> permutar(int N);
int main(int argn, char* argv[]){
  int N= std::atoi(argv[1]);
  std::vector <int> lista= permutar(N);
  for(int ii=0;ii<lista.size();++ii){
    std::cout<<lista[ii]<<"\n";
  }
  return 0;
}
std::vector <int> permutar(int N){
  std::vector <int> permutacion;
  for(int sep=10;sep<=(N);sep*=10){
    int parte= N%(sep*10);
    int numero=N-parte;
    int valor=0;
    for(int ii=0;ii<girar(parte).size();++ii){
      valor=numero+girar(parte)[ii];
      permutacion.push_back(valor);
    }
  }
  return permutacion;

}



std::vector <int> girar(int N){
  std::vector <int> girador;
  std::vector <int> digitos;
  int num=1;
  for(int sep=1;sep<=(N);sep*=10){
      num=((N)%(10*sep))/sep;
      digitos.push_back(num);
    }
  int valor=0;
  for(int kk=0;kk<digitos.size();++kk){
    
    int ward = digitos[0];
    for(int jj=0;jj<digitos.size()-1;++jj){
      digitos[jj]=digitos[jj+1];
    }
    digitos[digitos.size()-1]=ward;

    for(int ii=0; ii<digitos.size();++ii){
      valor+=digitos[ii]*std::pow(10,ii);
    }
    girador.push_back(valor);
    valor=0;
  }
  return girador;
}
