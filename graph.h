#pragma once

#include <cstddef>
#include <iostream>
#include <limits>
#include <vector>

namespace MyGraph {

using Node = std::vector<size_t>;
const size_t INF = std::numeric_limits<size_t>::max();

class Graph {
public:
  Graph(std::istream &in);
  std::vector<size_t> FindAllDistances(size_t v);

private:
  void ReadGraph(std::istream &in);
  std::vector<Node> vertexes_;
};

} // namespace MyGraph
