/*
 *  Copyright (C) 2022 Garrett Brown
 *  This file is part of OASIS - https://github.com/eigendude/OASIS
 *
 *  This file is derived from Telemetrix4Arduino under the AGPL 3.0 License
 *  Copyright (c) 2020-2021 Alan Yorinks
 *
 *  SPDX-License-Identifier: Apache-2.0 AND AGPL-3.0
 *  See DOCS/LICENSING.md for more information.
 */

#pragma once

#include <stdint.h>

namespace OASIS
{
class TelemetrixSPI
{
public:
  void init_spi(uint8_t pinCount, const uint8_t* pins);
  void write_blocking_spi(uint8_t byteCount, const uint8_t* data);
  void read_blocking_spi(uint8_t byteCount, uint8_t readRegister);
  void set_format_spi(uint32_t clock, uint8_t bitOrder, uint8_t dataMode);
  void spi_cs_control(uint8_t csPin, uint8_t csState);

private:
  // A buffer to hold spi report data
  uint8_t spi_report_message[64];
};
} // namespace OASIS
