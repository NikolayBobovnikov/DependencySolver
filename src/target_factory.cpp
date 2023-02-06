#include "target_factory.h"

#include <exception>
#include <iostream>
#include <string>

Target
TargetFactory::CreateTarget(size_t id, std::function<void()> task) {
  if (_task_ids.count(id) != 0) {
    throw std::invalid_argument(std::string("Target id").append(std::to_string(id)).append("already exists."));
  }

  Target target = Target(id, task);
  _task_ids.insert(id);

  return target;
}

Target
TargetFactory::CreateTarget(size_t id)

{
  return CreateTarget(id, [=]() { std::cout << "Target " << id << std::endl; });
}

std::vector<Target>
TargetFactory::CreateTargets(size_t count) {
  std::vector<Target> result;
  result.reserve(count);
  for (size_t id = 1; id <= count; ++id) {
    result.push_back(CreateTarget(id));
  }
  return result;
}
