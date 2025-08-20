#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
  int from;
  int to;
  int weight;
};

bool compareEdges(const Edge &e1, const Edge &e2)
{
  return e1.weight < e2.weight;
}

struct DSU
{
  vector<int> parent;
  vector<int> rank;

  DSU(int n)
  {
    parent.resize(n);
    rank.resize(n, 0);
    for (int i = 0; i < n; i++)
    {
      parent[i] = i;
    }
  }

  int find(int x)
  {
    if (parent[x] != x)
    {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  void unite(int x, int y)
  {
    int rootX = find(x);
    int rootY = find(y);
    if (rank[rootX] < rank[rootY])
    {
      parent[rootX] = rootY;
    }
    else if (rank[rootX] > rank[rootY])
    {
      parent[rootY] = rootX;
    }
    else
    {
      parent[rootX] = rootY;
      rank[rootY]++;
    }
  }
};

int minimumSpanningTree(int nodes, int edges, const vector<Edge> &graph)
{
  DSU dsu(nodes);
  int totalWeight = 0;
  vector<Edge> sortedEdges = graph;
  sort(sortedEdges.begin(), sortedEdges.end(), compareEdges);

  for (const Edge &edge : sortedEdges)
  {
    if (dsu.find(edge.from) != dsu.find(edge.to))
    {
      dsu.unite(edge.from, edge.to);
      totalWeight += edge.weight;
    }
  }

  return totalWeight;
}

int main()
{
  int nodes, edges;
  cin >> nodes >> edges;

  vector<Edge> graph(edges);
  for (int i = 0; i < edges; i++)
  {
    cin >> graph[i].from >> graph[i].to >> graph[i].weight;
  }

  int minSpanningTreeWeight = minimumSpanningTree(nodes, edges, graph);
  cout << minSpanningTreeWeight << endl;

  return 0;
}
