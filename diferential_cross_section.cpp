#include <iostream>
#include <cmath>
#include <iomanip>
#define _USE_MATH_DEFINES

const double Q=0.292; //GeV2
const double alpha = 1.0/137;
const double hbarc = 1.97327; // 10^(-14)GeV cm

double scattered_electron_energy (double E1, int theta);
double diferential_cross_section_Mott (double E1, double E3, int theta);

int main ()
{
  std::cout.precision(6);
  std::cout.setf(std::ios::scientific);
  
  double E1 = 0.5; //GeV
  double E3 = 0.0; //GeV

  int theta = 90;
  E3 = scattered_electron_energy (E1, theta);
    
  std::cout<<E3<<"\t"<<diferential_cross_section_Mott(E1, E3, theta)<<std::endl;
  
  return 0;
}

double scattered_electron_energy (double E1, int angle)
{
  double energy = 0.0;
  double theta = angle*M_PI/180;

  energy = (Q*Q)/(4*E1*sin(theta/2.0)*sin(theta/2.0));

  return energy;
}

double diferential_cross_section_Mott (double E1, double E3, int angle)
{
  double Mott = 0.0;
  double theta = angle*M_PI/180;
  
  Mott = ((alpha*alpha)/(4*E1*E1*pow(sin(theta/2.0), 4)))*(E3/E1)*cos(theta/2.0)*cos(theta/2.0);

  //Calculating the Mott differential cross section from natural units to SI:

  Mott = (Mott/4*M_PI)*hbarc*hbarc*pow(10, -28);  //Mott en cm2/steradian
  
  return Mott;
}
