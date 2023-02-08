#include "buildgraph.h"

#include <stdexcept>
#include <string>

BuildGraph::BuildGraph(const std::vector<Target> &targets) : _targets(targets), _dependencies(_targets.size()) {}

BuildGraph::BuildGraph(std::vector<Target> &&targets) : _targets(std::move(targets)), _dependencies(_targets.size()) {}

size_t
BuildGraph::size() const {
  return _targets.size();
}

void
BuildGraph::set_dependency(size_t target_id, size_t dependency_id) {
  _validate_target_id(target_id);
  _validate_target_id(dependency_id);

  _dependencies[target_id].push_back(dependency_id);
}

void
BuildGraph::set_dependencies(const std::vector<std::pair<size_t, size_t>> &dependencies) {
  for (const auto &[target, dependency] : dependencies) {
    set_dependency(target, dependency);
  }
}

void
BuildGraph::set_dependencies(const std::vector<std::pair<size_t, std::vector<size_t>>> &dependencies) {
  for (const auto &[target, target_dependencies] : dependencies) {
    for (auto dependency : target_dependencies) {
      set_dependency(target, dependency);
    }
  }
}

const std::vector<size_t> &
BuildGraph::get_dependencies(size_t target_id) const {
  _validate_target_id(target_id);
  return _dependencies[target_id];
}

void
BuildGraph::_validate_target_id(size_t id) const {
  if (id > _targets.size()) {
    throw std::invalid_argument(std::string("Target id").append(std::to_string(id)).append(" does not exist."));
  }
}