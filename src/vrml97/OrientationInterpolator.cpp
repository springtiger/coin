/**************************************************************************\
 *
 *  This file is part of the Coin 3D visualization library.
 *  Copyright (C) 1998-2005 by Systems in Motion.  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  ("GPL") version 2 as published by the Free Software Foundation.
 *  See the file LICENSE.GPL at the root directory of this source
 *  distribution for additional information about the GNU GPL.
 *
 *  For using Coin with software that can not be combined with the GNU
 *  GPL, and for taking advantage of the additional benefits of our
 *  support services, please contact Systems in Motion about acquiring
 *  a Coin Professional Edition License.
 *
 *  See <URL:http://www.coin3d.org/> for more information.
 *
 *  Systems in Motion, Postboks 1283, Pirsenteret, 7462 Trondheim, NORWAY.
 *  <URL:http://www.sim.no/>.
 *
\**************************************************************************/

/*!
  \class SoVRMLOrientationInterpolator SoVRMLOrientationInterpolator.h Inventor/VRMLnodes/SoVRMLOrientationInterpolator.h
  \brief The SoVRMLOrientationInterpolator class is used to interpolate orientations.
  \ingroup VRMLnodes
  
  \WEB3DCOPYRIGHT

  \verbatim
  OrientationInterpolator {
    eventIn      SFFloat    set_fraction      # (-,)
    exposedField MFFloat    key           []  # (-,)
    exposedField MFRotation keyValue      []  # [-1,1],(-,)
    eventOut     SFRotation value_changed
  }
  \endverbatim
  
  The OrientationInterpolator node interpolates among a list of
  rotation values specified in the keyValue field. These rotations are
  absolute in object space and therefore are not cumulative. The
  keyValue field shall contain exactly as many rotations as there are
  keyframes in the key field.  An orientation represents the final
  position of an object after a rotation has been applied. An
  OrientationInterpolator interpolates between two orientations by
  computing the shortest path on the unit sphere between the two
  orientations.  The interpolation is linear in arc length along this
  path. The results are undefined if the two orientations are
  diagonally opposite.  If two consecutive keyValue values exist such
  that the arc length between them is greater than , the interpolation
  will take place on the arc complement. For example, the
  interpolation between the orientations (0, 1, 0, 0) and (0, 1, 0,
  5.0) is equivalent to the rotation between the orientations (0, 1,
  0, 2) and (0, 1, 0, 5.0).  A more detailed discussion of
  interpolators is contained in 4.6.8, Interpolator nodes
  (<http://www.web3d.org/x3d/specifications/vrml/ISO_IEC_14772-All/part1/concepts.html#4.6.8>).

*/

/*!
  \var SoMFRotation SoVRMLOrientationInterpolator::keyValue
  The keyValue vector.
*/

/*!
  \var SoEngineOutput SoVRMLOrientationInterpolator::value_changed
  The eventOut which is sent every time the interpolator has calculated a new value.
*/

#include <Inventor/VRMLnodes/SoVRMLOrientationInterpolator.h>
#include <Inventor/VRMLnodes/SoVRMLMacros.h>
#include <Inventor/engines/SoSubNodeEngineP.h>

SO_NODEENGINE_SOURCE(SoVRMLOrientationInterpolator);

// Doc in parent
void
SoVRMLOrientationInterpolator::initClass(void)
{
  SO_NODEENGINE_INTERNAL_INIT_CLASS(SoVRMLOrientationInterpolator);
}

/*!
  Constructor.
*/
SoVRMLOrientationInterpolator::SoVRMLOrientationInterpolator(void)
{
  SO_NODEENGINE_INTERNAL_CONSTRUCTOR(SoVRMLOrientationInterpolator);

  SO_VRMLNODE_ADD_EMPTY_EXPOSED_MFIELD(keyValue);
  SO_NODEENGINE_ADD_OUTPUT(value_changed, SoSFRotation);
}

/*!
  Destructor.
*/
SoVRMLOrientationInterpolator::~SoVRMLOrientationInterpolator(void)
{
}

// Doc in parent
void
SoVRMLOrientationInterpolator::evaluate(void)
{
  float interp;
  int idx = this->getKeyValueIndex(interp);
  if (idx < 0) return;

  const SbRotation * v = this->keyValue.getValues(0);

  SbRotation v0 = v[idx];
  if (interp > 0.0f) {
    SbRotation v1 = v[idx+1];
    v0 = SbRotation::slerp(v0, v1, interp);
  }
  SO_ENGINE_OUTPUT(value_changed, SoSFRotation, setValue(v0));

}
