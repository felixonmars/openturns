//                                               -*- C++ -*-
/**
 *  @brief Class for the Nataf transformation evaluation for independent
 *
 *  Copyright 2005-2015 Airbus-EDF-IMACS-Phimeca
 *
 *  This library is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  along with this library.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef OPENTURNS_NATAFINDEPENDENTCOPULAHESSIAN_HXX
#define OPENTURNS_NATAFINDEPENDENTCOPULAHESSIAN_HXX

#include "NumericalMathHessianImplementation.hxx"
#include "SymmetricTensor.hxx"
#include "NumericalPoint.hxx"
#include "StorageManager.hxx"

BEGIN_NAMESPACE_OPENTURNS

/**
 * @class NatafIndependentCopulaHessian
 *
 * This class offers an interface for the Nataf function for independent distributions
 */
class OT_API NatafIndependentCopulaHessian
  : public NumericalMathHessianImplementation
{
  CLASSNAME;
public:


  /** Default constructor */
  NatafIndependentCopulaHessian();

  /** Parameter constructor */
  explicit NatafIndependentCopulaHessian(const UnsignedInteger dimension);


  /** Virtual constructor */
  virtual NatafIndependentCopulaHessian * clone() const;

  /** Hessian */
  SymmetricTensor hessian(const NumericalPoint & inP) const;

  /** Accessor for input point dimension */
  virtual UnsignedInteger getInputDimension() const;

  /** Accessor for output point dimension */
  virtual UnsignedInteger getOutputDimension() const;

  /** String converter */
  virtual String __repr__() const;

  /** Method save() stores the object through the StorageManager */
  void save(Advocate & adv) const;

  /** Method load() reloads the object from the StorageManager */
  void load(Advocate & adv);

protected:


private:
  UnsignedInteger dimension_;

}; /* NatafIndependentCopulaHessian */


END_NAMESPACE_OPENTURNS

#endif /* OPENTURNS_NATAFINDEPENDENTCOPULAHESSIAN_HXX */
