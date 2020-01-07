#ifndef VERTEX_H
#define VERTEX_H


class Vertex
{
    public:
        //members
        int id;
        int visit;
        int cost;
        int nbNeighbor;
        //pointeur qui contient les voisins du vertex
        int* voisin;
        int *distance; // distance[i] will hold the cost of the vertex with all the other vertex

        //attribute
        Vertex(int,int,int);
        Vertex(){};
        virtual ~Vertex();

        //functions
        int getNbNeighbor()const;
        int* getVoisin();
        //Distance mise en place
        void Cost(int _id,int dist);
};

#endif // VERTEX_H

/**contain attributes and functions on the vertices, ...*/
