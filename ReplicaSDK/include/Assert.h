// Copyright (c) Facebook, Inc. and its affiliates. All Rights Reserved
#pragma once

#include <iostream>

#ifndef WIN32
#define ASSERT(x, ...)                                                                       \
  do {                                                                                       \
    if (!(x)) {                                                                              \
      std::cout << "Assert failed: " #x << ", " << __FILE__ << ":" << __LINE__ << std::endl; \
      std::cout << #__VA_ARGS__ << std::endl;                                                \
      exit(-1);                                                                              \
    }                                                                                        \
  } while (false)
#else
#define ASSERT(x, ...)                                                                       \
  do {                                                                                       \
    if (!(x)) {                                                                              \
      std::cout << "Assert failed: " #x << ", " << __FILE__ << ":" << __LINE__ << std::endl; \
      std::cout << " " #__VA_ARGS__ << std::endl;                                            \
      exit(-1);                                                                              \
    }                                                                                        \
  } while (false)
#endif
