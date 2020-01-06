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

        //attribute
        Vertex(int,int,int);
        Vertex(){};
        virtual ~Vertex();

        //functions
        int getNbNeighbor()const;
        int* getVoisin();
};

#endif // VERTEX_H

/**contain attributes and functions on the vertices, ...*/
