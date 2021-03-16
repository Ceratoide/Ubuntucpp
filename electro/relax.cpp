#include<iostream>
#include<vector>

typedef std::vector<double> data_t;

const double DELTA=0.1;
const double XMIN = 0.;
const double XMAX = 1.;
const double YMIN = 0;
const double YMAX = 1.2;

void initial_conditions(data_t & data, int nx, int ny);
void boundary_conditions(data_t & data, int nx, int ny);
void evolve(data_t & data,int nx,int ny, int nsteps);
void relaxation_step(data_t & data,int nx,int ny );
void print_screen(const data_t & data, int nx,int ny);
void print_gnuplot(const data_t & data, int nx,int ny);
int main(int argc, char **argv){
  //declarar el arreglo
 
  
  //Matrix sixe: Nx,Ny, XMIN, XMAX,YMIN,YMAX


  int Nx=(XMAX-XMIN)/DELTA;
  int Ny=(YMAX-YMIN)/DELTA;

  data_t potential(Nx*Ny);
  
  int NSTEPS= 1;
  
  //std::vector<double> -> Nx*Ny
  potential.resize(Nx*Ny);
  //conjunto de b.c
  initial_conditions(potential,Nx,Ny);
  boundary_conditions(potential, Nx, Ny);
  //evolucionar
  evolve(potential,Nx,Ny,NSTEPS);
  //printeeeeeeeeee locooo estoy re locooooooo
  


  return 0;
}
void initial_conditions(data_t & data, int nx, int ny){

  for(int ii=10;ii<nx;++ii){
    for(int jj=10;jj<ny;++jj){
      data[ii*ny+jj]=0;
    }
  }
}
void boundary_conditions(data_t & data, int nx, int ny){
  int ii,jj;
  //firts row
  ii=0;
  for(int jj=0;jj<ny;++jj){
    data[ii*ny+jj]=100.;
  }
  //last row
  ii=nx-1;
  for(int jj=0;jj<ny;++jj){
    data[ii*ny+jj]=0.;
  }
  //firts row
  jj=0;
  for(int ii=1;ii<nx;++ii){
    data[ii*ny+jj]=0.;
  }
  //last row
  jj=ny-1;
  for(int ii=1;ii<nx;++ii){
    data[ii*ny+jj]=0.;
  }

}
void evolve(data_t & data,int nx,int ny, int nsteps){
  for(int istep=0;istep < nsteps;++istep){
    relaxation_step(data,nx,ny);
    print_gnuplot(data,nx,ny);
  }

}
void relaxation_step(data_t & data,int nx,int ny ){
  for(int ii=1;ii<nx-1;++ii){
    for(int jj=1;jj<ny-1;++jj){
      data[ii*ny+jj]=(data[(ii-1)*ny+jj]+data[ii*ny+(jj-1)]+data[(ii+1)*ny+jj]+data[ii*ny+(jj+1)])/4.;
    }
  }

}
void print_screen(const data_t & data, int nx,int ny){
  for(int ii=0;ii<nx;++ii){
    for(int jj=0;jj<ny;++jj){
      std::cout<< data[ii*ny+jj]<<"  ";
    }
    std::cout<<"\n";
  }
  std::cout<<"\n";
 
}
void print_gnuplot(const data_t & data, int nx,int ny){
  for(int ii=0;ii<nx;++ii){
    double x = XMIN+ ii*DELTA;
    for(int jj=0;jj<ny;++jj){
      double y= YMIN + jj*DELTA;
      std::cout<< x << "  "<< y <<"  "<< data[ii*ny+jj]<<"\n";
    }
    std::cout<<"\n";
  }
}
//evolve{
  //for ii < NSTEPS
  //relaxation_step
  //print
//}
