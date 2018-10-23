#ifndef ENERGYPENALTY_H
#define ENERGYPENALTY_H

#include "AuxKernel.h"

// Forward Declarations
class EnergyPenalty;

template <>
InputParameters validParams<EnergyPenalty>();

/**
 * Coupled auxiliary value
 */
class EnergyPenalty : public AuxKernel
{
 public:
  /**
   * Factory constructor, takes parameters so that all derived classes can be built using the same
   * constructor.
   */
  EnergyPenalty(const InputParameters & parameters);

 protected:
  virtual Real computeValue() override;

  const VariableGradient & _grad_nx;
  const VariableGradient & _grad_ny;
  Real _K, _Rmol, _T, _m3permol;
};

#endif // ENERGYPENALTY_H
