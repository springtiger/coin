/**************************************************************************\
 *
 *  This file is part of the Coin 3D visualization library.
 *  Copyright (C) 1998-2004 by Systems in Motion.  All rights reserved.
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
 *  Systems in Motion, Teknobyen, Abels Gate 5, 7030 Trondheim, NORWAY.
 *  <URL:http://www.sim.no/>.
 *
\**************************************************************************/

#ifndef COIN_SBBASIC_H
#define COIN_SBBASIC_H

/* *********************************************************************** */

#include <Inventor/C/basic.h>

/* *********************************************************************** */
/* Trap people trying to use Inventor headers while compiling C source code.
 * (we get support mail about this from time to time)
 */
#ifndef __cplusplus
#error You are not compiling C++ - maybe your source file is named <file>.c
#endif

/* *********************************************************************** */
/* Include these for Open Inventor compatibility reasons (they are not
 * actually used in Coin.)
 */
#define SoEXTENDER
#define SoINTERNAL

/* *********************************************************************** */

/* Some useful inline template functions:
 *   SbAbs(Val)              - returns absolute value
 *   SbMin(Val1, Val2)       - returns minimum value
 *   SbMax(Val1, Val2)       - returns maximum value
 *   SbClamp(Val, Min, Max)  - returns clamped value
 *   SbSwap(Val1, Val2)      - swaps the two values (no return value)
 *   SbSqr(val)              - returns (val)�
 */

template <class Type>
inline Type SbAbs( Type Val ) {
  return (Val < 0) ? 0 - Val : Val;
}

template <class Type>
inline Type SbMax( const Type A, const Type B ) {
  return (A < B) ? B : A;
}

template <class Type>
inline Type SbMin( const Type A, const Type B ) {
  return (A < B) ? A : B;
}

template <class Type>
inline Type SbClamp( const Type Val, const Type Min, const Type Max ) {
  return (Val < Min) ? Min : (Val > Max) ? Max : Val;
}

template <class Type>
inline void SbSwap( Type & A, Type & B ) {
  Type T; T = A; A = B; B = T;
}

template <class Type>
inline Type SbSqr(const Type val) {
  return val * val;
}

/* *********************************************************************** */

#endif /* !COIN_SBBASIC_H */