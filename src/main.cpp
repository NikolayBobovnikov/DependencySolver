#include "builder.h"
#include "buildgraph.h"
#include "target_factory.h"

int
main() {
  TargetFactory m;

  // create N build targets
  auto targets = m.CreateTargets(10);
  for (auto t : targets) {
    t.task();
  }

  BuildGraph g = BuildGraph(std::move(targets));

  g.set_dependencies({{1, 2}, {2, 3}});
}
