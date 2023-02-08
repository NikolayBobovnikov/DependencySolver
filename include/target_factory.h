#pragma once

#include "target.h"

/// @brief Factory for build targets and ID management.
class TargetFactory {
public:
  Target CreateTarget(size_t id, std::function<void()> task);
  Target CreateTarget(size_t id);
  TargetFactory() = default;
  TargetFactory(const TargetFactory &) = delete;

  std::vector<Target> CreateTargets(size_t count = 0);

private:
  std::set<size_t> _task_ids;
};
