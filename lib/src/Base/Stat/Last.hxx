//                                               -*- C++ -*-
/**
 *  @brief This class is a top-level class for the history mechanism of
 *  simulation algorithms. It delegates to its children the effective
 *  history strategy.
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
#ifndef OPENTURNS_LAST_HXX
#define OPENTURNS_LAST_HXX

#include "HistoryStrategyImplementation.hxx"
#include "NumericalSample.hxx"

BEGIN_NAMESPACE_OPENTURNS



/**
 * @class Last
 */

class OT_API Last
  : public HistoryStrategyImplementation
{

  CLASSNAME;

public:

  /** Constructor with parameters */
  Last();

  /** Constructor with parameters */
  explicit Last(const UnsignedInteger maximumSize);

  /** Virtual constructor */
  virtual Last * clone() const;

  /** Store the point according to the strategy */
  using HistoryStrategyImplementation::store;
  void store(const NumericalPoint & point);

  /** Sample accessor */
  NumericalSample getSample() const;

  /** MaximumSize accessor */
  UnsignedInteger getMaximumSize() const;

  /** Index accessor */
  UnsignedInteger getIndex() const;

  /** Wrapped flag accessor */
  Bool getHasWrapped() const;

  /** String converter */
  String __repr__() const;

  /** Method save() stores the object through the StorageManager */
  void save(Advocate & adv) const;

  /** Method load() reloads the object from the StorageManager */
  void load(Advocate & adv);

protected:

private:
  // Maximum number of points to be hitorized
  UnsignedInteger maximumSize_;

  // Index where the next point will be stored
  UnsignedInteger index_;

  // Flag that tells if the storage has already exceeded maximumSize_
  Bool hasWrapped_;

} ; /* class Last */

END_NAMESPACE_OPENTURNS

#endif /* OPENTURNS_LAST_HXX */
