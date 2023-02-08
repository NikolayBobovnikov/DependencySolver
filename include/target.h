#pragma once

#include <functional>
#include <memory>
#include <set>
#include <vector>

struct Target {
  size_t id;
  std::function<void()> task;
};
