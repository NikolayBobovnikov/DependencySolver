#include "builder.h"
#include "buildgraph.h"
#include "target_factory.h"
#include <iostream>
int
main() {
  TargetFactory m;

  // create N build targets
  auto targets = m.CreateTargets(4);
  for (auto t : targets) {
    t.task();
  }

  BuildGraph g = BuildGraph(std::move(targets));

  g.set_dependencies({{1, 2}, {2, 3}, {1, 3}, {2, 0}});

  const size_t threads_number = 1;
  Builder b = Builder(threads_number);

  try {
    b.execute(g, 1);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
