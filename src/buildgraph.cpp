#include "buildgraph.h"

#include <stdexcept>
#include <string>
#include <format>

BuildGraph::BuildGraph(const std::vector<Target> &targets) : _targets(targets) {
  _dependencies.reserve(targets.size());
}

BuildGraph::BuildGraph(std::vector<Target> &&targets) : _targets(std::move(targets)) {
  _dependencies.reserve(_targets.size());
}

void
BuildGraph::set_dependency(size_t target_id, size_t dependency_id) {
  _validate_target_id(target_id);
  _validate_target_id(dependency_id);

  _dependencies[target_id].push_back(dependency_id);
}

void
BuildGraph::set_dependencies(const std::vector<std::pair<size_t, size_t>>& dependencies) {
  for (const auto& [target, dependency] : dependencies) {
    set_dependency(target, dependency);
  }
}

void
BuildGraph::_validate_target_id(size_t id) const {
  if (id > _targets.size()) {
    throw std::invalid_argument(std::format("Target id {} does not exist.", id));
  }
}
