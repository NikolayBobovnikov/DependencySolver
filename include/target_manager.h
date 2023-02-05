#include "target.h"

class TargetManager {
 public:
  TargetManager();
  std::unique_ptr<Target> CreateTarget(size_t id, std::function<void()> task);
  std::unique_ptr<Target> CreateTarget(size_t id);

 private:
  std::set<size_t> tasks;
};
