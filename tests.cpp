#include "tests.h"
#include "graph.h"
#include <cassert>
#include <fstream>
#include <stdexcept>

namespace Tests {

using namespace MyGraph;

void run_all_tests() {
  std::ifstream fin("graph.txt");
  std::ofstream fout("answer.txt");
  Graph g(fin);
  std::vector<size_t> result = g.FindAllDistances(fin);
  for (auto &dist : result) {
    if (dist == INF) {
      throw std::invalid_argument("Graph is not connected.");
    }
    fout << dist << std::endl;
  }
  fin.close();
  fout.close();
}

} // namespace Tests
