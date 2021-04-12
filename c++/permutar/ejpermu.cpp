#include <iostream>
#include <vector>
#include <cmath>
std::vector <int> girar(int N);
std::vector <int> permutar(int N);
int main(int argn, char* argv[]){
  int N= std::atoi(argv[1]);
  std::vector <int> lista= permutar(N);
  for(int ii=0;ii<lista.size();++ii){
    std::cout<<(ii+1)<<"\t"<<lista[ii]<<"\n";
  }
  return 0;
v}
std::vector <int> permutar(int N){
  std::vector <int> permutacion;
  int P=N;
  int sep=100;
  int parte=P%sep;
  int numero= P-parte;
  int valor=0;
  for(int ii=0;ii<girar(parte).size();++ii){
    valor=numero+girar(parte)[ii];
    permutacion.push_back(valor);
  }
  int fac=1;
  int num=1;
  for(sep=1000;sep<(P*10);sep*=10){
    fac=fac*(num+1);
    num=num+1;
    for(int jj=0;jj<fac;++jj){
      P=permutacion[jj];
      parte=P%sep;
      numero=P-parte;
      for(int ii=0;ii<girar(parte).size()-1;++ii){
	valor=numero+girar(parte)[ii];
	permutacion.push_back(valor);
      }
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
