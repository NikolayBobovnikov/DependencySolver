#include "buildgraph.h"
#include <cstddef>

class Builder {
public:
  explicit Builder(size_t num_threads);

  void execute(const BuildGraph &build_graph, size_t target_id);
};