#include <iostream>
#include <vector>
#include "MERGSORT.h"

using namespace std;

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
