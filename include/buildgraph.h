#include <memory>
#include <vector>

/*
Lemma 22.11 on the Book Introduction to Algorithms (Second Edition) states that:
A directed graph G is acyclic if and only if a depth-first search of G yields no
back edges
*/
struct Target;
class TargetManager;

class BuildGraph {
 public:
  explicit BuildGraph(const std::vector<Target>& targets);

  void set_dependency(size_t target_id, size_t dependency_id);

 private:
  std::vector<Target> _targets;
};