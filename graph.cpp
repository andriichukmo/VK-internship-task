#include "graph.h"
#include <cassert>
#include <queue>
#include <stdexcept>

namespace MyGraph {

Graph::Graph(std::istream &in) { ReadGraph(in); }

void Graph::ReadGraph(std::istream &in) {
  size_t n;
  in >> n;
  vertexes_.resize(n);
  size_t m;
  in >> m;
  for (size_t i = 0; i < m; ++i) {
    size_t id1, id2;
    in >> id1 >> id2;
    if (id1 >= n || id1 < 0 || id2 >= n || id2 < 0) {
      throw std::invalid_argument("wrong vertex id");
    }
    vertexes_[id1].push_back(id2);
    vertexes_[id2].push_back(id1);
  }
}

std::vector<size_t> Graph::FindAllDistances(size_t v) {
  size_t n = vertexes_.size();
  std::vector<size_t> dist(n, INF);
  dist[v] = 0;
  std::queue<size_t> recently_added;
  recently_added.push(v);

  while (!recently_added.empty()) {
    size_t cur = recently_added.front();
    recently_added.pop();
    for (auto &nxt : vertexes_[cur]) {
      if (dist[nxt] == INF) {
        dist[nxt] = dist[cur] + 1;
        recently_added.push(nxt);
      }
    }
  }

  return dist;
}

} // namespace MyGraph
