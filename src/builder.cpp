#include "builder.h"
#include <iostream>
#include <string>

Builder::Builder(size_t num_threads) {}

void
Builder::execute(const BuildGraph &build_graph, size_t target_id) const {}

void
Builder::run_dfs(const BuildGraph &build_graph, size_t target_id) const {
  // states
  std::vector<Builder::DFS_States> states(build_graph.size(), DFS_States::not_visited);
  _dfs(build_graph, target_id, states);

  for (auto state : states) {
    std::cout << std::to_string((uint8_t) state) << ", ";
  }
}

void
Builder::_dfs(const BuildGraph &build_graph, size_t target_id, std::vector<DFS_States> &states) const {
  if (target_id >= build_graph.size()) {
    throw std::runtime_error("Target id" + std::to_string(target_id) + " does not exist.");
  }

  std::cout << "Visiting " + std::to_string(target_id) << std::endl;
  states[target_id] = DFS_States::visiting;

  for (const auto &child_id : build_graph.get_dependencies(target_id)) {
    if (DFS_States::visiting == states[child_id]) {
      // found cycle
      throw std::runtime_error("Dependency graph should be acyclic.");
    }
    if (DFS_States::not_visited == states[child_id]) {
      _dfs(build_graph, child_id, states);
    }
  }

  std::cout << std::to_string(target_id) << " visited" << std::endl;
  states[target_id] = DFS_States::visited;
}