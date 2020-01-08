#include <vector>
#include "Edge.h"
#include "Graph.h"

#ifndef KRUSKAL_H_INCLUDED
#define KRUSKAL_H_INCLUDED

int kruskal(Graph*);

std::vector<Edge*> sortingCost(Graph*);

void Union(Edge*);

Vertex* Find(Vertex*);

#endif // KRUSKAL_H_INCLUDED
