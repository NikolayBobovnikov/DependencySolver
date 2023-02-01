#include "builder.h"
#include "target.h"

int main() {
    auto t = TargetHelpers::CreateTest(0);
    t->task();
    
}
