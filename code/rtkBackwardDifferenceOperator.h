/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#ifndef __rtkBackwardDifferenceOperator_h
#define __rtkBackwardDifferenceOperator_h

#include "itkNeighborhoodOperator.h"
#include "itkDerivativeOperator.h"

namespace rtk
{
/**
 * \class BackwardDifferenceOperator
 * \brief A NeighborhoodOperator for taking the first order Backward difference
 * at a pixel
 *
 * BackwardDifferenceOperator's coefficients are a convolution
 * kernel for calculating the first order directional Backward difference at a pixel.
 * BackwardDifferenceOperator is a directional NeighborhoodOperator that should be
 * applied to a Neighborhood or NeighborhoodPointer using the inner product
 * method.
 *
 * An example operator to compute the Backward differences of a 2D image can be
 * created with:
 * \code
 *       typedef itk::BackwardDifferenceOperator<float, 2> BackwardDifferenceOperatorType;
 *       BackwardDifferenceOperatorType BackwardDifferenceOperator;
 *       BackwardDifferenceOperator.SetDirection(0); // X dimension
 *       itk::Size<2> radius;
 *       radius.Fill(1); // A radius of 1 in both dimensions is a 3x3 operator
 *       BackwardDifferenceOperator.CreateToRadius(radius);
 * \endcode
 * and creates a kernel that looks like:
 * \code
 *       0   0   0
 *       -1  1   0
 *       0   0   0
 * \endcode
 *
 * \sa NeighborhoodOperator
 * \sa Neighborhood
 * \sa BackwardDifferenceOperator
 * \sa BackwardDifferenceOperator
 *
 * \ingroup Operators
 * \ingroup ITKCommon
 *
 * \wiki
 * \wikiexample{Operators/BackwardDifferenceOperator,Create a Backward difference kernel}
 * \endwiki
 */
using namespace itk;

template< typename TPixel, unsigned int VDimension = 2,
          typename TAllocator = NeighborhoodAllocator< TPixel > >
class BackwardDifferenceOperator:
  public DerivativeOperator< TPixel, VDimension, TAllocator >
{
public:
  /** Standard class typedefs. */
  typedef BackwardDifferenceOperator Self;
  typedef BackwardDifferenceOperator<
    TPixel, VDimension, TAllocator >           Superclass;

  typedef typename Superclass::PixelType     PixelType;
  typedef typename Superclass::PixelRealType PixelRealType;

protected:
  /** Typedef support for coefficient vector type.  Necessary to
   * work around compiler bug on VC++. */
  typedef typename Superclass::CoefficientVector CoefficientVector;

  /** Calculates operator coefficients. */
  CoefficientVector GenerateCoefficients();

};
} // end of namespace rtk and itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "rtkBackwardDifferenceOperator.txx"
#endif

#endif
