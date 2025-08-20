#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Edge
{
  int from;
  int to;
  int weight;
};

void merge(Edge* arr, int l, int m, int r)
{
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  Edge* L = new Edge[n1];
  Edge* R = new Edge[n2];

  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2) {
    if (L[i].weight <= R[j].weight) {
      arr[k] = L[i];
      i++;
    }
    else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }

  delete[] L;
  delete[] R;
}

void edge_merge_sort(Edge* arr, int l, int r)
{
  if (l < r) {
    int m = l + (r - l) / 2;

    edge_merge_sort(arr, l, m);
    edge_merge_sort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

struct Node
{
  int vertex;
  int weight;
};

class Graph
{
public:
  int numVertices;
  vector<vector<Node>> adjacencyList;

  Graph(int vertices) : numVertices(vertices)
  {
    adjacencyList.resize(numVertices);
  }

  int find(vector<int> &parent, int vertex)
  {
    if (parent[vertex] == -1)
    {
      return vertex;
    }

    return find(parent, parent[vertex]);
  }

  void addEdge(int source, int destination, int weight)
  {
    Node newNode{destination, weight};
    adjacencyList[source].push_back(newNode);

    // undirected graph
    Node reverseNode{source, weight};
    adjacencyList[destination].push_back(reverseNode);
  }

  void printGraph()
  {
    for (int i = 0; i < numVertices; ++i)
    {
      for (const auto &node : adjacencyList[i])
      {
        printf("(%d, %d) ", node.vertex, node.weight);
      }
      printf("\n");
    }
  }

  vector<int> get_vertexes()
  {
    set<int> uniqueVertexes;

    for (int i = 0; i < numVertices; ++i)
    {
      for (const auto &node : adjacencyList[i])
      {
        if (uniqueVertexes.find(node.vertex) == uniqueVertexes.end())
        {
          uniqueVertexes.insert(node.vertex);
        }
      }
    }

    vector<int> vertexes(uniqueVertexes.begin(), uniqueVertexes.end());
    return vertexes;
  }

  vector<Edge> sorted_edges(vector<Edge> connections)
  {
    edge_merge_sort(connections.data(), 0, connections.size() - 1);
    return connections;
  }

  bool is_acyclic(Edge connection, vector<int>& parent)
  {
    int srcParent = find(parent, connection.from);
    int destParent = find(parent, connection.to);

    if (srcParent == destParent)
    {
      return false;
    }

    parent[srcParent] = destParent;

    return true;
  }

  void edge_union(Edge edge)
  {
    addEdge(edge.from, edge.to, edge.weight);
  }
};

class Solution
{
public:
  int total_weight(int nodes, int edges, Graph graph, vector<Edge> connections)
  {
    int weight = 0;
    vector<Edge> sorted_connections = graph.sorted_edges(connections);
    Graph graph_aux = Graph(edges);
    vector<int> parent(nodes, -1);

    for (const Edge &edge : sorted_connections)
    {
      if (graph_aux.is_acyclic(edge, parent))
      {
        graph_aux.edge_union(edge);
        weight += edge.weight;
      }
    }

    return weight;
  }

  Graph initialize_graph(int nodes, int edges, vector<Edge> connections)
  {
    Graph graph = Graph(edges);
    for (const auto &edge : connections)
    {
      graph.addEdge(edge.from, edge.to, edge.weight);
    }
    // graph.printGraph();

    return graph;
  }

  bool requirements(int nodes, int edges)
  {
    bool first_requirement = nodes >= 1 && nodes <= 10000;
    bool second_requirement = edges >= 1 && edges <= 100000;

    if (first_requirement && second_requirement)
      return true;
    else
      return false;
  }

  vector<Edge> read_edges(int edges)
  {
    vector<Edge> connections;
    string input;

    for (int i = 0; i < edges; i++)
    {
      Edge edge;
      scanf("%d %d %d", &edge.from, &edge.to, &edge.weight);
      connections.push_back(edge);
    }

    return connections;
  }
};

int main(int argc, char **argv)
{
  Solution solution = Solution();

  int n_nodes, n_edges;
  scanf("%d %d", &n_nodes, &n_edges);

  if (!solution.requirements(n_nodes, n_edges))
    exit(0);

  vector<Edge> connections = solution.read_edges(n_edges);
  Graph graph = solution.initialize_graph(n_nodes, n_edges, connections);
  int a = solution.total_weight(n_nodes, n_edges, graph, connections);
  printf("%d\n", a);
  exit(0);
}