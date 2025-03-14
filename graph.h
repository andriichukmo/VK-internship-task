#pragma once

#include <cstddef>
#include <iostream>
#include <limits>
#include <vector>

namespace MyGraph {

const size_t INF = std::numeric_limits<size_t>::max();

struct Node {
  std::vector<int> to;
};

class Graph {
public:
  Graph(std::istream &in);
  std::vector<size_t> FindAllDistances(std::istream &in);

private:
  void ReadGraph(std::istream &in);
  std::vector<Node> vertexes_;
};

} // namespace MyGraph
