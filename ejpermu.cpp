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
  permutacion.push_back(N);
  int sep=100;
  for(int kk=0;kk<4;++kk){
    for(int ii=0;ii<kk;++ii){
      int parte= permutacion[ii]%sep;
      int numero=permutacion[ii]-parte;
      int valor=0;
      for(int jj=0;jj<girar(parte).size();++jj){
	valor=numero+girar(parte)[jj];
	permutacion.push_back(valor);
      }
      sep*=10;
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
