#!/bin/bash
################################################################################
#
#  Copyright (C) 2021 Garrett Brown
#  This file is part of OASIS - https://github.com/eigendude/OASIS
#
#  SPDX-License-Identifier: Apache-2.0
#  See the file LICENSE.txt for more information.
#
################################################################################

# Enable strict mode
set -o errexit
set -o pipefail
set -o nounset

#
# Environment paths and configuration
#

# Get the absolute path to this script
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# Import environment
source "${SCRIPT_DIR}/env_ros2_desktop.sh"

# Import CMake paths
source "${SCRIPT_DIR}/env_cmake.sh"

#
# Build configuration
#

# Default values
MAKE_FLAGS=
COLCON_FLAGS="--merge-install"
CMAKE_PREFIX_PATH=

# macOS flags
if [[ "${OSTYPE}" == "darwin"* ]]; then
  COLCON_FLAGS+=" --packages-skip-by-dep python_qt_binding"
  CMAKE_PREFIX_PATH="$(brew --prefix qt@5)/lib/cmake/Qt5"
fi

# Add ccache support
COLCON_FLAGS+=" --cmake-args -DCMAKE_CXX_COMPILER_LAUNCHER=ccache"

# Uncomment these to force building in serial
#MAKE_FLAGS+=" -j1 -l1"
#COLCON_FLAGS+=" --executor sequential"

#
# Build ROS 2 with colcon
#

echo "Building ROS 2..."

cd "${ROS2_DESKTOP_DIRECTORY}"

PATH="${CMAKE_BIN_DIRECTORY}:${PATH}" \
  MAKE_FLAGS="${MAKE_FLAGS}" \
  CMAKE_PREFIX_PATH="${CMAKE_PREFIX_PATH}" \
  colcon build \
    ${COLCON_FLAGS}
