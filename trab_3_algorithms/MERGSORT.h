#ifndef MERGSORT_H
#define MERGSORT_H

struct Edge
{
  int from;
  int to;
  int weight;
};

void edge_merge_sort(Edge* arr, int l, int r);

#endif
