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

Last Updated: 01/02/2024
@author: Vadan Khan
