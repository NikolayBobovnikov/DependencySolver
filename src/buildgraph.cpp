#include "buildgraph.h"

#include <stdexcept>
#include <string>

BuildGraph::BuildGraph(const std::vector<Target> &targets) : _targets(targets) {
  _dependencies.reserve(targets.size());
}

BuildGraph::BuildGraph(std::vector<Target> &&targets) : _targets(std::move(targets)) {
  _dependencies.reserve(targets.size());
}

void
BuildGraph::set_dependency(size_t target_id, size_t dependency_id) {
  _validate_target_id(target_id);
  _validate_target_id(dependency_id);

  _dependencies[target_id].push_back(dependency_id);
}

void
BuildGraph::set_dependencies(std::vector<std::pair<size_t, size_t>> dependencies) {
  for (const auto &dep : dependencies) {
    set_dependency(dep.first, dep.second);
  }
}

void
BuildGraph::_validate_target_id(size_t id) const {
  if (id < 0) {
    throw std::invalid_argument("Target id cannot be negative");
  }

  if (id > _dependencies.size()) {
    throw std::invalid_argument("Target id " + std::to_string(id) + " not found.");
  }
}
