//                                               -*- C++ -*-
/**
 * @brief Top-level class for all distribution factories
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

#ifndef OPENTURNS_DISTRIBUTIONFACTORY_HXX
#define OPENTURNS_DISTRIBUTIONFACTORY_HXX

#include "DistributionFactoryImplementation.hxx"
#include "DistributionFactoryResult.hxx"
#include "TypedInterfaceObject.hxx"
#include "ResourceMap.hxx"

BEGIN_NAMESPACE_OPENTURNS



/**
 * @class DistributionFactory
 */
class OT_API DistributionFactory
  : public TypedInterfaceObject<DistributionFactoryImplementation>
{
  CLASSNAME;
public:

  typedef Collection<NumericalPoint>                NumericalPointCollection;
  typedef Collection<DistributionFactory>           DistributionFactoryCollection;

  /** Default constructor */
  explicit DistributionFactory(const UnsignedInteger bootstrapSize = ResourceMap::GetAsUnsignedInteger("DistributionFactoryImplementation-DefaultBootstrapSize"));

  /** Parameter constructor */
  DistributionFactory(const DistributionFactoryImplementation & factory);

  /** String converter */
  virtual String __repr__() const;

  /** String converter */
  virtual String __str__(const String & offset = "") const;

  /* Here is the interface that all derived class must implement */

  virtual Distribution build(const NumericalSample & sample) const;
  virtual Distribution build(const NumericalPoint & parameters) const;
  virtual Distribution build() const;

  /** Build the distribution and the parameter distribution */
  virtual DistributionFactoryResult buildEstimator(const NumericalSample & sample) const;

  /** Build the distribution and the parameter distribution in a new parametrization */
  virtual DistributionFactoryResult buildEstimator(const NumericalSample & sample,
                                                   const DistributionParameters & parameters) const;

  /** Accessor to known parameter */
  void setKnownParameter(const NumericalPoint & values, const Indices & positions);
  NumericalPoint getKnownParameterValues() const;
  Indices getKnownParameterIndices() const;

  /** Catalog of factories */
  static DistributionFactoryCollection GetContinuousUniVariateFactories();
  static DistributionFactoryCollection GetContinuousMultiVariateFactories();
  static DistributionFactoryCollection GetDiscreteUniVariateFactories();
  static DistributionFactoryCollection GetDiscreteMultiVariateFactories();
  static DistributionFactoryCollection GetUniVariateFactories();
  static DistributionFactoryCollection GetMultiVariateFactories();

private:

}; /* class DistributionFactory */


END_NAMESPACE_OPENTURNS

#endif /* OPENTURNS_DISTRIBUTIONFACTORY_HXX */
