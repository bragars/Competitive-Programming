#include <iostream>
#include <cstring>
#include <vector>
#include <set>
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
    if (L[i].weight < R[j].weight)
    { // Changed condition to <
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

vector<Edge> sorted_edges(vector<Edge> connections)
{
  edge_merge_sort(connections.data(), 0, connections.size() - 1);

  return connections;
}

int find_subtree(vector<int> &parent, int i)
{
  if (parent[i - 1] == i)
    return i;

  return find_subtree(parent, parent[i - 1]);
}

void connect_subtrees(vector<int> &parent, vector<int> &subtree_sizes, int x, int y)
{
  int x_root = find_subtree(parent, x);
  int y_root = find_subtree(parent, y);

  if (subtree_sizes[x_root] < subtree_sizes[y_root])
  {
    parent[x_root] = y_root;
  }
  else if (subtree_sizes[x_root] > subtree_sizes[y_root])
  {
    parent[y_root] = x_root;
  }
  else
  {
    parent[y_root] = x_root;
    subtree_sizes[x_root] += 1;
  }
}

class Solution
{
public:
  int total_weight(int nodes, int edges, const vector<Edge> &connections)
  {
    int weight = 0;
    vector<Edge> sorted_connections = sorted_edges(connections);
    // vector<Edge> sorted_connections = connections;
    // sort(sorted_connections.begin(), sorted_connections.end(), compareEdges);
    vector<int> parent(nodes);

    for (int i = 0; i < nodes; i++)
      parent[i] = i + 1;

    vector<int> subtree_sizes(nodes, 0);

    for (const Edge &edge : sorted_connections)
    {
      int x_subtree = find_subtree(parent, edge.from);
      int y_subtree = find_subtree(parent, edge.to);

      if (x_subtree != y_subtree)
      {
        connect_subtrees(parent, subtree_sizes, edge.from, edge.to);
        weight += edge.weight;
      }
    }
    return weight;
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

  vector<Edge> read_edges(int edges, istream &input)
  {
    vector<Edge> connections;

    for (int i = 0; i < edges; i++)
    {
      int from, to, weight;
      input >> from >> to >> weight;
      connections.push_back({from, to, weight});
    }

    return connections;
  }
};

int main(int argc, char **argv)
{
  Solution solution = Solution();

  int n_nodes, n_edges;
  cin >> n_nodes >> n_edges;

  if (!solution.requirements(n_nodes, n_edges))
    return 0;

  vector<Edge> connections = solution.read_edges(n_edges, cin);
  int total_weight = solution.total_weight(n_nodes, n_edges, connections);
  cout << total_weight;

  return 0;
}
