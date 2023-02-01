#include <functional>

struct Target {
  size_t id;

  std::function<void()> task;
};