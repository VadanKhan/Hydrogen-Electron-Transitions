/*
________________TITLE________________
PHYS30762 - Assignment 1 - Hydrogen Transitions
-------------------------------------
This script performs calculates the energy of emitted photons, if a hydrogen
atom decays from a certain principal quantum number (nj) to a lower one (ni).
This base theory is available:
Phillips, A. C. (2013). Introduction to Quantum Mechanics. John Wiley & Sons

The energy level of the hydrogen-like atom is given by the formula:
  E_n = -13.6 * Z^2 / n^2 eV
where:
- E_n is the energy of the level,
- n is the principal quantum number (positive integer starting from 1),
- Z is the atomic number of the atom.
The energy difference Delta E between two levels n_j and n_i (where n_j > n_i) is
given by:
Delta E = E_ni - E_nf = 13.6 * Z^2 * (1/nj^2 - 1/ni^2) eV

This energy difference corresponds to the energy of the photon emitted or absorbed
during the transition between these two levels.

The General Schematic is as follows:

1) Input your Z, nj, ni and units (e or J) in that order.
2) The calculated value will be outputted (or you will be prompted to repeat if
the input is invalid.)
3) User will be asked if a new calculation is required.

Last Updated: 08/02/2024
@author: UID: 10823198

*/

#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>

// Constants
const double E_r{13.605693122994}; // Rydberg constant for hydrogen in eV.s
const double e{1.602176634e-19};   // Elementary Charge in C.s
const int PRECISION{6};            // Set precision of output

double energy(int& Z, int& nj, int& ni) {
  // Calculate the energy of the transition
  double E = Z * Z * E_r * (1.0 / (nj * nj) - 1.0 / (ni * ni));
  return E;
}

double energyLevel(int& Z, int& n) {
  // Calculate the energy of a specific level
  double E = -Z * Z * E_r / (n * n);
  return E;
}

int main() {
  char repeat = 'y';
  while (repeat == 'y' || repeat == 'Y') {
    int Z, ni, nj;
    char unit;

    // Get inputs from the user
    do {
      std::cout << "Enter the atomic number (Z), initial quantum number (nj), final quantum number"
                   " (ni), and the unit of energy (J for Joules, e for electron Volts) in one line "
                   "(using spaces): ";
      std::cin >> Z >> nj >> ni >> unit;
      if (std::cin.fail()) {
        std::cin.clear(); // clear the error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                        '\n'); // remove the invalid input
        std::cout << "Invalid input. Please enter integers for the atomic number and quantum "
                     "numbers, and a character for the unit.\n";
      } else if (Z <= 0) {
        std::cout << "Invalid input. The atomic number must be a positive integer.\n";
      } else if (ni <= 0) {
        std::cout << "Invalid input. The quantum number must be a positive integer.\n";
      } else if (nj <= 0 || nj <= ni) {
        std::cout << "Invalid input. The initial quantum number must be a positive integer greater "
                     "than the initial quantum number.\n";
      } else if (unit != 'j' && unit != 'J' && unit != 'e' && unit != 'E') {
        std::cout << "Invalid unit. Please enter 'J' for Joules or 'e' for electron Volts.\n";
      }
    } while (std::cin.fail() || Z <= 0 || ni <= 0 || nj <= 0 || nj <= ni ||
             (unit != 'j' && unit != 'J' && unit != 'e' && unit != 'E'));

    // Calculate the energy
    double E = -energy(Z, nj, ni); // Flip the sign for photon energy
    double E_initial = energyLevel(Z, nj);
    double E_final = energyLevel(Z, ni);

    // Output the energy
    std::cout << std::setprecision(PRECISION); // Set output to 5 sig figs.
    if (unit == 'j' || unit == 'J') {
      E *= e;
      E_initial *= e;
      E_final *= e;
      std::cout << "The initial energy was " << E_initial << " J.\n";
      std::cout << "The final energy was " << E_final << " J.\n";
      std::cout << "The energy of the transition is " << E << " J.\n";
    } else if (unit == 'e' || unit == 'E') {
      std::cout << "The initial energy was " << E_initial << " eV.\n";
      std::cout << "The final energy was " << E_final << " eV.\n";
      std::cout << "The energy of the transition is " << E << " eV.\n";
    }

    // Ask the user if they want to repeat
    std::cout << "Do you want to calculate another transition? (y/n): ";
    std::cin >> repeat;
  }

  return 0;
}
