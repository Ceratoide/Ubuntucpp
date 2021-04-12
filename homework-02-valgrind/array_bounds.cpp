#include <iostream>

void print_array(const double data[], const int & size);
double* concatenar( const double data1[],const double data2[], const int size1,const int  size2);//funcion auxiliar usada para concatenar arreglos


int main()
{
  const int NX = 2, NY = 3, NZ = 4;  
  double *x=nullptr, y[NY]={0.}, z[NZ]={0.};
  x = new double [NX] {0.};
  int ii=0, jj=0, kk=0; //se inicializan variables, punteros y arreglo en valores nulos.
  print_array(x, NX); 
  print_array(y, NY); 
  print_array(z, NZ);
  std::cout << std::endl;
  
  x[jj]=NX-1;
  ii=NX;

  //pinta las primeras NZ componentes de x
  if (NZ<=NX){
    print_array(x, NZ);
  }
  else{print_array(x,NX);}
  print_array(y, NY);
  
  double *zy; //decalramos el puntero concatenacion de z y y
  zy=concatenar(z,y,NZ,NY);
  
  print_array(zy, NZ + NY); //interpreté este error como que la persona queria pintar una concatenacion de los arreglos z y y
  std::cout << std::endl;

  for (jj = 0; jj < NY; ++jj) {
    if(jj<NX){ //para no salir de los dominios de x
      x[jj] = ii;
    } 
    y[jj] = jj; 
  }
  
  //pinta los últimos NY datos del arreglo x
  if(NX>NY){
    print_array(x+NX-NY, NY);}
  else{
    print_array(x,NX);
  }
  if(NY>NZ){
    print_array(y+NY-NZ, NZ);}
  else{
    print_array(y,NY);
  }
  //en este codigo en particular esos efectos no se ven y simplemente se obtienen los arreglos x y y
  
  delete [] zy;//liberamos la memoria de zy para actualizarla y no tener fugas
  
  zy=concatenar(z,y,NZ,NY);//se vuelve a ejecutar la concatenacion
  if(NZ+NY>NX){
    print_array(zy+NZ+NY-NX, NX);}
  else{print_array(zy,NZ+NY);}
  std::cout << std::endl;
 
  for (kk = 0; jj < NZ; ++kk) { //una vez todos se llenan el for se muere
    if (kk<NX||kk<NY||kk<NZ){
      if (kk<NX){x[kk]=ii;}
      if (kk<NY){y[kk]=jj;}
      if (kk<NZ){z[kk]=ii;}
    }
    else{
      break;
    }
  }
  print_array(x, NX);
  print_array(y, NY); 
  print_array(z, NZ);
  std::cout << std::endl;
  
  //devolvemos la memoria pedida para evitar leaks
  delete [] x;
  delete [] zy;
  return EXIT_SUCCESS;
}

void print_array(const double data[], const int & size)
{
  std::cout << std::endl;
  for (int ii = 0; ii < size; ++ii) {
    std::cout << data[ii] << "  " ;
  }
}
double* concatenar(const double data1[],const double data2[], const int size1,const int  size2){
  int numero=size1+size2;
  double* conc=nullptr;
  conc = new double [numero] {0.};
  for(int ii=0; ii<size1+size2;++ii){
    if(ii<size1){
      conc[ii]=data1[ii];
    }
    else {
      conc[ii]=data2[ii-size1];
    }
  }
  return conc;
}

 
