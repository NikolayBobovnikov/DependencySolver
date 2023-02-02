#include "target.h"
#include <exception>
#include <iostream>

TargetManager::TargetManager(){};

std::unique_ptr<Target>
TargetManager::CreateTarget(size_t id, std::function<void()> task) {
  if (tasks.count(id) != 0) {
    auto what = std::string("Target id").append(std::to_string(id)).append("already exists.");
    throw std::invalid_argument(std::move(what));
  }

  std::unique_ptr<Target> target;
  try {
    target = std::make_unique<Target>(id, task);
    tasks.insert(id);
  } catch (...) {
    throw;
  }

  return target;
}

std::unique_ptr<Target>
TargetManager::CreateTarget(size_t id)

{
  return CreateTarget(id, [=]() { std::cout << "Target " << id << std::endl; });
}