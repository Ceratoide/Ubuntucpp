#include <iostream>

void print_array(const double data[], const int & size);

int main()
{
  const int NX = 2, NY = 3, NZ = 4;  //los arreglos no se están inicializando, se inicializa x en nullptr y z y y en 0
  double *x=nullptr, y[NY]={0.}, z[NZ]={0.};
  x = new double [NX] {0.};//x tiene valores basura, se soluciona poniendo todos valores 0
  int ii=0, jj=0, kk=0; //las constantes no estan inicializadas, las inicializo en 0
  print_array(x, NX); 
  print_array(y, NY); 
  print_array(z, NZ);
  std::cout << std::endl;

  for (ii = 0; ii < NX; ++ii) {
    x[jj] = ii; //solo incializamos x[0] en x[0]= NX-1
  }
  if (NZ<=NX){ //la intencion del que escribio el codigo tal vez era que se pintara la lista x hasta el tamaño de Z, siempre y cuando se cumpla la condición, el arreglo no se sale de la memoria
    print_array(x, NZ);
  }
  else{print_array(x,NX);}//el else hace que si NZ>NX se printe todo x, es decir, ha llegado al rango máximo que puede representar el arreglo
  print_array(y, NY);
  
  double zy[NZ+NY]={0.};//declaramos un arreglo que será z concatenado con y
  for(int ii=0; ii<NZ+NY;++ii){
    if(ii<NZ){
      zy[ii]=z[ii];
    }
    else {
      zy[ii]=y[ii];
    }
  }
  
  print_array(zy, NZ + NY); //interpreté este error como que la persona queria pintar una concatenacion de los arreglos z y y, el arreglo zy es esto)
  std::cout << std::endl;

  for (jj = 0; jj < NY; ++jj) {
    if(jj<NX){ //el if hace que si el jj en algun momento se sale del arreglo, esa parte de la memoria no se toque
      x[jj] = ii;
    } 
    y[jj] = jj; 
  }
  //estas representaciones siempre estan fuera del arreglo
  //lo que el programador estrella queria era representar los ultimos NY datos del arreglo x, siempre que NX>NY
  if(NX>NY){
    print_array(x+NX-NY, NY);}
  else{
    print_array(x,NX);//En el caso en el que esto no ocurra, simplemente se arroja el valor de x, es decir que ya no hay mas datos representables 
  }
  //lo mismo aplica para este caso pero con el arreglo y los NZ ultimos datos de este
  if(NY>NZ){
    print_array(y+NY-NZ, NZ);}
  else{
    print_array(y,NY);
  }
  //en este codigo en particular esos efectos no se ven y simplemente se obtienen los arreglos x y y
  
  //siguiendo la misma logica que antes lo que el programador queria era los ultimos NX datos del arreglo concatenado de z y y
  if(NZ+NY>NX){
    print_array(zy + NZ + NY-NX, NX);}
  else{print_array(zy,NZ+NY);}
  std::cout << std::endl;

  
 
  for (kk = 0; jj < NZ; ++kk) { //el for nunca está acabando si jj <NZ
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
  
  //al final no estamos devolviendo la memoria!!! entonces la liberamos
  delete [] x;
  return EXIT_SUCCESS;
}

void print_array(const double data[], const int & size)
{
  std::cout << std::endl;
  for (int ii = 0; ii < size; ++ii) {
    std::cout << data[ii] << "  " ;
  }
}


 
