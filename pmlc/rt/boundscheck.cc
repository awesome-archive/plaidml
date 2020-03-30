// Copyright 2020 Intel Corporation

#include <stdint.h>

#include <stdexcept>

// This function is called from the BoundsCheckPass.
// index - ndex for a dimension that is accessed by load/store operation
// range - upper bound of the range for this dimension (it is always 0 -
// range)
extern "C" void plaidml_rt_bounds_check(intptr_t index, unsigned range) {
  int64_t accessIndex = (int64_t)index;
  int64_t upperRange = (int64_t)range;
  if (accessIndex < 0 || accessIndex >= upperRange)
    std::runtime_error("Out of bounds index for mlir::LoadOp or mlir::StoreOp");
}
