#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#define _USE_MATH_DEFINES

const double Q=sqrt(0.5); //GeV
const double alpha = 1.0/137; //constant fine structure
const double hbarc = 1.97327; // 10^(-14)GeV cm
const int N_data = 5;
const double mp = 0.9383; //mass of proton GeV

void calculate_gfactors (double m, double b, std::vector<double>& ffactors);
void print (std::vector<double> gfactors);

int main ()
{
  std::cout.precision(6);
  std::cout.setf(std::ios::scientific);

  //Valores dados por el ajuste
  double m = 0.256633;
  double b = 0.325643;

  std::vector<double>gfactors(2, 0.0); //GM first value and GE second value

  calculate_gfactors (m, b, gfactors);

  print (gfactors);
  
  return 0;
}

void calculate_gfactors (double m, double b, std::vector<double>& gfactors)
{
  double GE = 0.0;
  double GM = 0.0;
  double tau = Q*Q/(4*mp*mp);

  GM = sqrt(m/(2*tau));
  GE = sqrt(b*(1+tau)-tau*GM*GM);

  gfactors[0] = GM;
  gfactors[1] = GE;
}

void print (std::vector<double> gfactors)
{
  std::cout<<"GM factor"<<"\t"<<"GE factor"<<std::endl;
  std::cout<<gfactors[0]<<"\t"<<gfactors[1]<<std::endl;
}
