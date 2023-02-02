#include <exception>
#include <functional>
#include <memory>
#include <set>
#include <vector>

struct Target {
  Target() = delete;
  Target(size_t _id, std::function<void()> _task) : id(_id), task(_task) {}

  size_t id;
  std::function<void()> task;
  std::vector<size_t> depentencies;
};

class TargetManager {
public:
  TargetManager();
  std::unique_ptr<Target> CreateTarget(size_t id, std::function<void()> task);
  std::unique_ptr<Target> CreateTarget(size_t id);

private:
  std::set<size_t> tasks;
};
