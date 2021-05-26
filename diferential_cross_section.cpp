#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#define _USE_MATH_DEFINES

const double Q=0.292; //GeV2
const double alpha = 1.0/137;
const double hbarc = 1.97327; // 10^(-14)GeV cm
const int N_data = 5;

double scattered_electron_energy (double E1, int theta);
double diferential_cross_section_Mott (double E1, double E3, int theta);
void initial_values (std::vector<int>& angles, std::vector<double> & energies1, std::vector<double> & energies3, std::vector<double> & expdifcrosection);
void print (std::vector<int> angles, std::vector<double> energies1, std::vector<double> energies3, std::vector<double> expdifcrosection);

int main ()
{
  std::cout.precision(6);
  std::cout.setf(std::ios::scientific);

  std::vector<int>angles(N_data, 0);
  std::vector<double>energies1(N_data, 0.0);
  std::vector<double>energies3(N_data, 0.0);
  std::vector<double>expdifcrosection(N_data, 0.0);
  
  initial_values (angles, energies1, energies3, expdifcrosection);

  print (angles, energies1, energies3, expdifcrosection);
  
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

  Mott = (Mott/4*M_PI)*hbarc*hbarc*pow(10, -28)/10;  //Mott en cm2/steradian with correction of the pow function on 10
  
  return Mott;
}

void initial_values (std::vector<int>& angles, std::vector<double> & energies1, std::vector<double> & energies3, std::vector<double> & expdifcrosection)
{
  //angles values
  angles[0] = 60;
  angles[1] = 75;
  angles[2] = 90;
  angles[3] = 120;
  angles[4] = 135;

  //energies of incident electron

  energies1[0] = 0.1;
  energies1[1] = 0.2;
  energies1[2] = 0.3;
  energies1[3] = 0.4;
  energies1[4] = 0.5;

  //energies of scattered electron

  energies3[0] = scattered_electron_energy (energies1[0], angles[0]);
  energies3[1] = scattered_electron_energy (energies1[1], angles[1]);
  energies3[2] = scattered_electron_energy (energies1[2], angles[2]);
  energies3[3] = scattered_electron_energy (energies1[3], angles[3]);
  energies3[4] = scattered_electron_energy (energies1[4], angles[4]);

  //experimental differential cross section

  expdifcrosection[0] = 0.5;
  expdifcrosection[1] = 1.0;
  expdifcrosection[2] = 1.5;
  expdifcrosection[3] = 2.0;
  expdifcrosection[4] = 2.5;
}

void print (std::vector<int> angles, std::vector<double> energies1, std::vector<double> energies3, std::vector<double> expdifcrosection)
{
  for (int ii=0; ii<N_data; ii++)
    {
      std::cout<<angles[ii]<<"\t"<<energies1[ii]<<"\t"<<energies3[ii]<<"\t"<<expdifcrosection[ii]<<std::endl;
    }
}
