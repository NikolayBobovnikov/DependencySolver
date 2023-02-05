#pragma once

#include <functional>
#include <memory>
#include <set>
#include <vector>

struct Target {
  Target(size_t _id, std::function<void()> _task) : id(_id), task(_task) {}

  size_t id;
  std::function<void()> task;
};
