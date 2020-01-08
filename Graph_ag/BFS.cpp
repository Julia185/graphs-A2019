#include "BFS.h"
#include "Graph.h"
#include <iostream>

using namespace std;

//id : vertex de d�part
vector<int>  BFS(Graph* G, int ID) {

                //rendu pour ordre voisin
                vector<int> v;

    cout << "\n\n BFS starts at "<< ID <<endl;
    list<int> q;

    //on note tous les vertex comme non visit�s
    G->setAllUnvisited();

    //on visite le 1er
    G->visited(ID);

        //on l'ajoute � la queue
        q.push_back(ID);

    //on continue de visiter les autres vertices
    while (!q.empty()) {
        ID = q.front();
        cout << " " << ID << " ";
                    //on ins�re le vecteur visite dans la liste
                    v.push_back(ID);

        q.pop_front();

         int currVertex;

        for(int i = 0; i< G->nb_vertex; ++i)
        {   int k =0;

            while(G->Adj[ID][i]!=0&& k<1){
                k++;
                currVertex = i;
                    if (!G->isVisited(currVertex)) {
                        G->visited(currVertex);
                        q.push_back(currVertex);
                    }

            }
        }
    }
        return v;
}
