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
        Edge();
        Edge(int, int, Vertex*, Vertex*);
        ~Edge();
        Edge& operator=(const Edge&);

        //functions
        Vertex& getSrc(){return *source;}
        Vertex& getDest(){return *destination;}
};

#endif // EDGE_H

/**contain the attributes and functions on the edges, ...*/
