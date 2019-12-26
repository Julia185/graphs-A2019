#ifndef EDGE_H
#define EDGE_H

#include "Vertex.h"

class Edge
{

    public:
        //members
        int id;
        int cost;
        Vertex* source;
        Vertex* destination;

        //constructor
        Edge(int, int, Vertex*, Vertex*);
        ~Edge();
};

#endif // EDGE_H

/**contain the attributes and functions on the edges, ...*/
