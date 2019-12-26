#ifndef TOPOLOGICALSORT_H_INCLUDED
#define TOPOLOGICALSORT_H_INCLUDED

#include "Graph.h"
#include <stack>

void TopologicalSortUtil(int, Graph*, std::stack<int>&);

void TopologicalSort(Graph*);

#endif // TOPOLOGICALSORT_H_INCLUDED
