#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct Edge
{
  int from;
  int to;
  int weight;
};

void merge(Edge *arr, int l, int m, int r)
{
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  Edge *L = new Edge[n1];
  Edge *R = new Edge[n2];

  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2)
  {
    if (L[i].weight <= R[j].weight)
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }

  delete[] L;
  delete[] R;
}

void edge_merge_sort(Edge *arr, int l, int r)
{
  if (l < r)
  {
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

  void updateAdjacencyList(const vector<Edge> &sortedEdges)
  {
    adjacencyList.clear();
    adjacencyList.resize(numVertices);

    for (const auto &edge : sortedEdges)
    {
      addEdge(edge.from, edge.to, edge.weight);
    }
  }

  void addEdge(int source, int destination, int weight)
  {
    if (source >= numVertices || destination >= numVertices)
    {
      int newSize = max(source, destination) + 1;
      adjacencyList.resize(newSize);
      numVertices = newSize;
    }

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
      cout << "Vertex " << i << " --> ";
      for (const auto &node : adjacencyList[i])
      {
        cout << "(" << node.vertex << ", " << node.weight << ") ";
      }
      cout << endl;
    }
  }

  vector<Edge> sorted_edges(vector<Edge> connections)
  {
    edge_merge_sort(connections.data(), 0, connections.size() - 1);
    return connections;
  }

  bool is_acyclic(Edge connection, vector<int> &parent, vector<int> &rank)
  {
    int srcParent = find(parent, connection.from);
    int destParent = find(parent, connection.to);

    if (srcParent == destParent)
      return false;

    if (rank[srcParent] < rank[destParent])
      parent[srcParent] = destParent;

    else if (rank[srcParent] > rank[destParent])
      parent[destParent] = srcParent;

    else
    {
      parent[destParent] = srcParent;
      rank[srcParent]++;
    }

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
    vector<int> rank(nodes, 0);

    graph.updateAdjacencyList(sorted_connections);

    for (const Edge &edge : sorted_connections)
    {
      if (graph.is_acyclic(edge, parent, rank))
      {
        graph.edge_union(edge);
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

  bool requirements(long int nodes, long int edges)
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
      int from, to, weight;
      cin >> from >> to >> weight;
      connections.push_back({from, to, weight});
    }

    return connections;
  }
};

int main(int argc, char **argv)
{
  Solution solution = Solution();

  long int n_nodes, n_edges;
  cin >> n_nodes >> n_edges;

  if (!solution.requirements(n_nodes, n_edges))
    return 0;

  vector<Edge> connections = solution.read_edges(n_edges);
  Graph graph = solution.initialize_graph(n_nodes, n_edges, connections);
  cout << solution.total_weight(n_nodes, n_edges, graph, connections) << endl;

  return 0;
}
