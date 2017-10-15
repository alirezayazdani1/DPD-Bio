/* ----------------------------------------------------------------------
   LAMMPS - Large-scale Atomic/Molecular Massively Parallel Simulator
   http://lammps.sandia.gov, Sandia National Laboratories
   Steve Plimpton, sjplimp@sandia.gov

   Copyright (2003) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under 
   the GNU General Public License.

   See the README file in the top-level LAMMPS directory.
------------------------------------------------------------------------- */

#ifndef BOND_WLC_POW_ALL_VISC_H
#define BOND_WLC_POW_ALL_VISC_H

#include "stdio.h"
#include "bond.h"

namespace LAMMPS_NS {

class BondWLC_POW_ALL_VISC : public Bond {
 public:
  BondWLC_POW_ALL_VISC(class LAMMPS *);
  ~BondWLC_POW_ALL_VISC();
  void compute(int, int);
  void coeff(int, char **);
  void init_style();
  double equilibrium_distance(int);
  void write_restart(FILE *);
  void read_restart(FILE *);
  double single(int, double, int, int);

 private:
  double *temp, *r0, *mu_targ, *qp;
  double *gamc, *gamt, *sigc, *sigt;
  double wrr[4], delx, dely, delz; 
  class RanMars *random;
  void allocate();
  void generate_wrr();

};

}

#endif
