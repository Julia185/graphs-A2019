#include "Vertex.h"


Vertex::Vertex(int _id, int _cost, int _nbNeighbor)
{
       this->id = _id;
       this->cost = _cost;
       this->nbNeighbor = _nbNeighbor;

}
Vertex::~Vertex(){}

Vertex::getNbNeighbor()const{return nbNeighbor;}

int* Vertex::getVoisin(){
    return this->voisin;
}

