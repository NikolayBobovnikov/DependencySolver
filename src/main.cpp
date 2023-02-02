#include "builder.h"
#include "target.h"

int main() {
  TargetManager m;
  auto t = m.CreateTarget(0);
  t->task();
}
