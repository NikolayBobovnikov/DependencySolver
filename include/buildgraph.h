#pragma once

#include <memory>
#include <stack>
#include <vector>

#include "target.h"
/*
Lemma 22.11 on the Book Introduction to Algorithms (Second Edition) states that:
A directed graph G is acyclic if and only if a depth-first search of G yields no
back edges
*/

class TargetFactory;

/// @brief Class representing build graph.
/// Vertexes are build targets, and edges are directed to the target's dependencies.
class BuildGraph {
public:
  /// @brief Construct a new Build Graph containing specified targets.
  /// @param targets Collection of targets.
  explicit BuildGraph(const std::vector<Target> &targets);

  /// @brief Construct a new Build Graph containing specified targets.
  /// @param targets Collection of targets.
  explicit BuildGraph(std::vector<Target> &&targets);

  /// @brief Default constructor for BuildGraph is not available.
  /// @note Pre-constructed collection of targets is required for construction of the BuildGraph object.
  BuildGraph() = delete;

  /// @brief Get number of targets in the graph.
  /// @return Number of targets in the graph.
  size_t size() const;

  /// @brief Set single dependency for single specified target.
  /// @param target_id
  /// @param dependency_id
  /// @throw std::invalid_argument if specified target/dependency id does not correspond to existing target.
  void set_dependency(size_t target_id, size_t dependency_id);

  /// @brief Sets single dependency for multiple specified targets.
  /// @param list of target-dependency pairs
  void set_dependencies(const std::vector<std::pair<size_t, size_t>> &dependencies);

  /// @brief Set multiple dependencies for multiple specified targets
  /// @param dependencies
  void set_dependencies(const std::vector<std::pair<size_t, std::vector<size_t>>> &dependencies);

  const std::vector<size_t> &get_dependencies(size_t target_id) const;

private:
  void _validate_target_id(size_t id) const;
  std::vector<Target> _targets;
  std::vector<std::vector<size_t>> _dependencies;
};