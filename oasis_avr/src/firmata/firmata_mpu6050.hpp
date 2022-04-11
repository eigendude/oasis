/*
 *  Copyright (C) 2021 Garrett Brown
 *  This file is part of OASIS - https://github.com/eigendude/OASIS
 *
 *  SPDX-License-Identifier: Apache-2.0
 *  See DOCS/LICENSING.md for more information.
 */
#pragma once

#include "firmata_subsystem.hpp"

#include <MPU6050.h>

namespace OASIS
{

class FirmataMPU6050 : public FirmataSubsystem
{
private:
  MPU6050_Base m_mpu6050;
};

} // namespace OASIS
