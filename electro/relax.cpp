#include<iostream>
#include<vector>

typedef std::vector<double> data_t;

const double DELTA=0.05;
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
void start_gnuplot(void);

int main(int argc, char **argv){
  //declarar el arreglo 
  //Matrix sixe: Nx,Ny, XMIN, XMAX,YMIN,YMAX

  int Nx=(XMAX-XMIN)/DELTA;
  int Ny=(YMAX-YMIN)/DELTA;

  data_t potential(Nx*Ny);
  
  int NSTEPS= 200;
  
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
    data[ii*ny+jj]=0.;
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
  ii=nx/2;
  for(int jj=ny/3;jj<=2*ny/3;++jj){
    data[ii*ny+jj]=-30.;
  }  

    
}
void evolve(data_t & data,int nx,int ny, int nsteps){
  start_gnuplot();
  for(int istep=0;istep < nsteps;++istep){
    relaxation_step(data,nx,ny);
    print_gnuplot(data,nx,ny);
  }

}
void relaxation_step(data_t & data,int nx,int ny ){
  for(int ii=1;ii<nx-1;++ii){
    for(int jj=1;jj<ny-1;++jj){
      if(ii ==nx/2 && ny/3<=jj && jj <=2*ny/3) continue;
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
void start_gnuplot(void){
  //std::cout<<"set pm3d\n";
  std::cout<<"set isosample 500, 500\n";
  std::cout<<"set contour base\n";
  std::cout<<"set cntrparam level incremental -100, 3, 100\n";

  std::cout<<"set view map\n";
  std::cout<<"unset key\n";
  std::cout<<"unset surface\n";
  std::cout<<"set palette rgbformulae 33,13,10\n";
  std::cout<<"set term gif animate\n";
  std::cout<<"set output 'anim.gif'\n";
}
void print_gnuplot(const data_t & data, int nx,int ny){
  std::cout << "splot '-' w l lt -1 lw 1.5\n ";
  for(int ii=0;ii<nx;++ii){
    double x = XMIN+ ii*DELTA;
    for(int jj=0;jj<ny;++jj){
      double y= YMIN + jj*DELTA;
      std::cout<< x << "  "<< y <<"  "<< data[ii*ny+jj]<<"\n";
    }
    std::cout<<"\n";
  }
  std::cout <<"e\n";
}

