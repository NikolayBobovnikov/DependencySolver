#pragma once

#include "buildgraph.h"

/*
It is also possible to check whether a given directed graph is a DAG in linear
time, either
 * by attempting to find a topological ordering and then testing for each edge
whether the resulting ordering is valid[18] or alternatively, for some
topological sorting algorithms,
 * by verifying that the algorithm successfully orders all the vertices without
meeting an error condition.[17]

*/

class Builder {
public:
  explicit Builder(size_t num_threads);

  void execute(const BuildGraph &build_graph, size_t target_id) const;

private:
  /// <summary>
  /// Enumeration of the node states during DFS.
  /// </summary>
  enum class DFS_States : uint8_t { not_visited, visiting, visited };

  std::vector<size_t> _top_sort(const BuildGraph &build_graph, size_t target_id) const;

  void _dfs(const BuildGraph &build_graph, size_t target_id, std::vector<DFS_States> &states,
            std::vector<size_t> &top_sort) const;
};