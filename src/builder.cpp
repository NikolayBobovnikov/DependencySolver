#include "builder.h"
#include <iostream>
#include <stack>
#include <string>

Builder::Builder(size_t num_threads) {}

void
Builder::execute(const BuildGraph &build_graph, size_t target_id) const {
  std::stack<size_t> top_sorting = _top_sort(build_graph, target_id);

  std::cout << "Topological ordering: " << std::endl;
  while (!top_sorting.empty()) {
    std::cout << "Target id " + std::to_string(top_sorting.top()) << std::endl;
    top_sorting.pop();
  }
}

std::stack<size_t>
Builder::_top_sort(const BuildGraph &build_graph, size_t target_id) const {
  // states for DFS
  std::vector<Builder::DFS_States> states(build_graph.size(), DFS_States::not_visited);

  // topological sorting
  std::stack<size_t> top_sorting;

  _dfs(build_graph, target_id, states, top_sorting);

  return top_sorting;
}

void
Builder::_dfs(const BuildGraph &build_graph, size_t target_id, std::vector<DFS_States> &states,
              std::stack<size_t> &top_sort_ordering) const {
  if (target_id >= build_graph.size()) {
    throw std::runtime_error("Target id" + std::to_string(target_id) + " does not exist.");
  }

  states[target_id] = DFS_States::visiting;

  for (const auto &child_id : build_graph.get_dependencies(target_id)) {
    // check for cycles
    if (DFS_States::visiting == states[child_id]) {
      // found cycle
      throw std::runtime_error("Dependency graph should be acyclic.");
    }

    if (DFS_States::not_visited == states[child_id]) {
      _dfs(build_graph, child_id, states, top_sort_ordering);
    }
  }

  // mark as visited
  states[target_id] = DFS_States::visited;

  // use time of exit for ordering
  top_sort_ordering.push(target_id);
}