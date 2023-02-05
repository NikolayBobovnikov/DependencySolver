#include "builder.h"
#include "target_manager.h"

int
main() {
  TargetManager m;
  auto t = m.CreateTarget(0);
  t->task();
}
