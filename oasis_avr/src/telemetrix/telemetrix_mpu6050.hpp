/*
 *  Copyright (C) 2022 Garrett Brown
 *  This file is part of OASIS - https://github.com/eigendude/OASIS
 *
 *  SPDX-License-Identifier: Apache-2.0
 *  See DOCS/LICENSING.md for more information.
 */
#pragma once

#include <MPU6050.h>

namespace OASIS
{

class TelemetrixMPU6050
{
private:
  MPU6050_Base m_mpu6050;
};

} // namespace OASIS
