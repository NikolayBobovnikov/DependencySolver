#include "builder.h"
#include <iostream>
#include <string>
#include <stack>

Builder::Builder(size_t num_threads) {}

void
Builder::execute(const BuildGraph &build_graph, size_t target_id) const {}

void
Builder::top_sort(const BuildGraph &build_graph, size_t target_id) const {
  // states for DFS
  std::vector<Builder::DFS_States> states(build_graph.size(), DFS_States::not_visited);

  // topological sorting (vector with LIFO semantics)
  std::vector<size_t> top_sorting(build_graph.size(), 0);
  size_t top_sort_index = build_graph.size() - 1;

  _dfs(build_graph, target_id, states, top_sorting, top_sort_index);

  std::cout << "Topological ordering: " << std::endl;
  for (auto target_id : top_sorting) {
    std::cout << std::to_string(target_id) << ", ";
  }
}

void
Builder::_dfs(const BuildGraph &build_graph, size_t target_id, std::vector<DFS_States> &states,
              std::vector<size_t> &top_sort_ordering, size_t &top_sort_index) const {
  if (target_id >= build_graph.size()) {
    throw std::runtime_error("Target id" + std::to_string(target_id) + " does not exist.");
  }

  states[target_id] = DFS_States::visiting;

  for (const auto &child_id : build_graph.get_dependencies(target_id)) {
    if (DFS_States::visiting == states[child_id]) {
      // found cycle
      throw std::runtime_error("Dependency graph should be acyclic.");
    }
    if (DFS_States::not_visited == states[child_id]) {
      _dfs(build_graph, child_id, states, top_sort_ordering, top_sort_index);
    }
  }

  // mark as visited
  states[target_id] = DFS_States::visited;

  // use time of exit for ordering
  top_sort_ordering[top_sort_index] = target_id;
  --top_sort_index;
}