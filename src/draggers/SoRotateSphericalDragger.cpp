/**************************************************************************\
 *
 *  Copyright (C) 1998-1999 by Systems in Motion.  All rights reserved.
 *
 *  This file is part of the Coin library.
 *
 *  This file may be distributed under the terms of the Q Public License
 *  as defined by Troll Tech AS of Norway and appearing in the file
 *  LICENSE.QPL included in the packaging of this file.
 *
 *  If you want to use Coin in applications not covered by licenses
 *  compatible with the QPL, you can contact SIM to aquire a
 *  Professional Edition license for Coin.
 *
 *  Systems in Motion AS, Prof. Brochs gate 6, N-7030 Trondheim, NORWAY
 *  http://www.sim.no/ sales@sim.no Voice: +47 22114160 Fax: +47 67172912
 *
\**************************************************************************/

#include <Inventor/draggers/SoRotateSphericalDragger.h>


SO_KIT_SOURCE(SoRotateSphericalDragger);


void
SoRotateSphericalDragger::initClass(void)
{
  SO_KIT_INTERNAL_INIT_CLASS(SoRotateSphericalDragger);
}

SoRotateSphericalDragger::SoRotateSphericalDragger(void)
{
  SO_KIT_INTERNAL_CONSTRUCTOR(SoRotateSphericalDragger);

  // FIXME: SO_KIT_ADD_CATALOG_ENTRY for all entries in this dragger's
  // catalog. 20000107 mortene.
  // feedback
  // feedbackActive
  // feedbackSwitch
  // rotator
  // rotatorActive
  // rotatorSwitch

  // FIXME: should the fields of this class be added to the field list
  // with SO_NODE_ADD_FIELD()? 20000107 mortene.

  SO_KIT_INIT_INSTANCE();
}


SoRotateSphericalDragger::~SoRotateSphericalDragger()
{
  COIN_STUB();
}

SbBool
SoRotateSphericalDragger::setUpConnections(SbBool onoff, SbBool doitalways)
{
  COIN_STUB();
  return FALSE;
}

void
SoRotateSphericalDragger::fieldSensorCB(void * f, SoSensor * s)
{
  COIN_STUB();
}

void
SoRotateSphericalDragger::valueChangedCB(void * f, SoDragger * d)
{
  COIN_STUB();
}

void
SoRotateSphericalDragger::setProjector(SbSphereProjector * p)
{
  COIN_STUB();
}

const SbSphereProjector *
SoRotateSphericalDragger::getProjector(void) const
{
  COIN_STUB();
  return NULL;
}

void
SoRotateSphericalDragger::copyContents(const SoFieldContainer * fromfc, SbBool copyconnections)
{
  COIN_STUB();
}

void
SoRotateSphericalDragger::startCB(void * f, SoDragger * d)
{
  COIN_STUB();
}

void
SoRotateSphericalDragger::motionCB(void * f, SoDragger * d)
{
  COIN_STUB();
}

void
SoRotateSphericalDragger::doneCB(void * f, SoDragger * d)
{
  COIN_STUB();
}

void
SoRotateSphericalDragger::dragStart(void)
{
  COIN_STUB();
}

void
SoRotateSphericalDragger::drag(void)
{
  COIN_STUB();
}

void
SoRotateSphericalDragger::dragFinish(void)
{
  COIN_STUB();
}
