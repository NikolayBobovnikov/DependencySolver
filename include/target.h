#include <functional>
#include <iostream>
#include <memory>

struct Target {
  Target(size_t _id, std::function<void()> _task) : id(_id), task(_task) {}

  size_t id;
  std::function<void()> task;
};

struct TargetHelpers {
  static std::unique_ptr<Target> Create(size_t id, std::function<void()> task) {
    return std::make_unique<Target>(id, task);
  }

  static std::unique_ptr<Target> CreateTest(size_t id) {
    return std::make_unique<Target>(
        id, [=]() { std::cout << "Building " << id << std::endl; });
  }
};