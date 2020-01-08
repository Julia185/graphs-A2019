#include "Vertex.h"
#include <iostream>

using namespace std;

Vertex::Vertex(int _id, int _cost, int _nbNeighbor)
{
       this->id = _id;
       this->nbNeighbor = _nbNeighbor;

}
Vertex::~Vertex(){
    delete[] distance;
}

Vertex::getNbNeighbor()const {
    return nbNeighbor;
}

int* Vertex::getVoisin(){
    return this->voisin;
}

void Vertex::Cost(int _id,int dist){
    distance[_id] = dist;
}

