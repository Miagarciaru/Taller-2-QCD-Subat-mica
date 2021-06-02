#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#define _USE_MATH_DEFINES

const double Q=sqrt(0.292); //GeV
const double alpha = 1.0/137; //constant fine structure
const double hbarc = 1.97327; // 10^(-14)GeV cm
const int N_data = 5;
const double mp = 0.9383; //mass of proton GeV

double scattered_electron_energy (double E1, int theta);
double diferential_cross_section_Mott (double E1, double E3, int theta);
void initial_values (std::vector<int>& angles, std::vector<double> & energies1, std::vector<double> & energies3, std::vector<double> & expdifcrosection, std::vector<double> & Mottdifcrosection);
void print (std::vector<int> angles, std::vector<double> energies1, std::vector<double> energies3, std::vector<double> expdifcrosection, std::vector<double> Mottdifcrosection);

int main ()
{
  std::cout.precision(6);
  std::cout.setf(std::ios::scientific);

  std::vector<int>angles(N_data, 0);
  std::vector<double>energies1(N_data, 0.0);
  std::vector<double>energies3(N_data, 0.0);
  std::vector<double>expdifcrosection(N_data, 0.0);
  std::vector<double>Mottdifcrosection(N_data, 0.0);
  
  initial_values (angles, energies1, energies3, expdifcrosection, Mottdifcrosection);

  print (angles, energies1, energies3, expdifcrosection, Mottdifcrosection);

  return 0;
}

double scattered_electron_energy (double E1, int angle)
{
  double energy = 0.0;
  double theta = angle*M_PI/180;

  energy = (E1*mp)/(mp+2*E1*sin(theta/2.0)*sin(theta/2.0));
  
  // energy = (Q*Q)/(4*E1*sin(theta/2.0)*sin(theta/2.0));

  return energy;
}

double diferential_cross_section_Mott (double E1, double E3, int angle)
{
  double Mott = 0.0;
  double theta = angle*M_PI/180;
  
  Mott = ((alpha*alpha)/(4*E1*E1*pow(sin(theta/2.0), 4)))*(E3/E1)*cos(theta/2.0)*cos(theta/2.0);

  //Calculating the Mott differential cross section from natural units to SI:

  Mott = Mott*hbarc*hbarc*pow(10, -28);  //Mott en cm2/steradian
  
  return Mott;
}

void initial_values (std::vector<int>& angles, std::vector<double> & energies1, std::vector<double> & energies3, std::vector<double> & expdifcrosection, std::vector<double> & Mottdifcrosection)
{
  //angles values
  angles[0] = 60;
  angles[1] = 75;
  angles[2] = 90;
  angles[3] = 120;
  angles[4] = 135;

  //energies of incident electron GeV

  energies1[0] = 0.627;
  energies1[1] = 0.527;
  energies1[2] = 0.466;
  energies1[3] = 0.400;
  energies1[4] = 0.380;

  //energies of scattered electron

  energies3[0] = scattered_electron_energy (energies1[0], angles[0]);
  energies3[1] = scattered_electron_energy (energies1[1], angles[1]);
  energies3[2] = scattered_electron_energy (energies1[2], angles[2]);
  energies3[3] = scattered_electron_energy (energies1[3], angles[3]);
  energies3[4] = scattered_electron_energy (energies1[4], angles[4]);

  //experimental differential cross section cm^2/steradian

  expdifcrosection[0] = 5*pow(10, -32);
  expdifcrosection[1] = 3*pow(10, -32);
  expdifcrosection[2] = 2*pow(10, -32);
  expdifcrosection[3] = 1*pow(10, -32);
  expdifcrosection[4] = 9*pow(10, -33);

  //Mott differential cross section

  Mottdifcrosection[0] = diferential_cross_section_Mott (energies1[0], energies3[0], angles[0]);
  Mottdifcrosection[1] = diferential_cross_section_Mott (energies1[1], energies3[1], angles[1]);
  Mottdifcrosection[2] = diferential_cross_section_Mott (energies1[2], energies3[2], angles[2]);
  Mottdifcrosection[3] = diferential_cross_section_Mott (energies1[3], energies3[3], angles[3]);
  Mottdifcrosection[4] = diferential_cross_section_Mott (energies1[4], energies3[4], angles[4]);  
}

void print (std::vector<int> angles, std::vector<double> energies1, std::vector<double> energies3, std::vector<double> expdifcrosection, std::vector<double> Mottdifcrosection)
{
  /*
  for (int ii=0; ii<N_data; ii++)
    {
      std::cout<<angles[ii]<<"\t"<<energies1[ii]<<"\t"<<energies3[ii]<<"\t"<<expdifcrosection[ii]<<"\t"<<Mottdifcrosection[ii]<<std::endl;
    }
  */
  
  for (int jj=0; jj<N_data; jj++)
    {
      std::cout<<pow(tan(angles[jj]*M_PI/360), 2)<<"\t"<<expdifcrosection[jj]/Mottdifcrosection[jj]<<std::endl;
    }
}
