//                                               -*- C++ -*-
/**
 *  @brief Class for the Nataf transformationEvaluation evaluation for elliptical
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
#ifndef OPENTURNS_INVERSEROSENBLATTEVALUATION_HXX
#define OPENTURNS_INVERSEROSENBLATTEVALUATION_HXX

#include "OTprivate.hxx"
#include "NumericalMathEvaluationImplementation.hxx"
#include "Matrix.hxx"
#include "NumericalPoint.hxx"
#include "Distribution.hxx"
#include "StorageManager.hxx"

BEGIN_NAMESPACE_OPENTURNS

/**
 * @class InverseRosenblattEvaluation
 *
 * This class offers an interface for the Nataf function for elliptical distributions
 */
class OT_API InverseRosenblattEvaluation
  : public NumericalMathEvaluationImplementation
{
  CLASSNAME;
public:


  /** Default constructor */
  InverseRosenblattEvaluation();

  /** Parameter constructor */
  explicit InverseRosenblattEvaluation(const Distribution & distribution);


  /** Virtual constructor */
  virtual InverseRosenblattEvaluation * clone() const;

  /** Evaluation */
  NumericalPoint operator () (const NumericalPoint & inP) const;

  /** Gradient according to the marginal parameters */
  virtual Matrix parameterGradient(const NumericalPoint & inP) const;

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
  Distribution distribution_;

}; /* InverseRosenblattEvaluation */


END_NAMESPACE_OPENTURNS

#endif /* OPENTURNS_INVERSEROSENBLATTEVALUATION_HXX */
