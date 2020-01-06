#include"Graph.h"
#include <iostream>

using namespace std;

bool contains(Vertex* vert, Vertex* u, Vertex* v) {
    bool a = find(vert.begin(), vert.end(), u) != vert.end();
    bool b = find(vert.begin(), vert.end(), v) != vert.end();

    return !(a && b);
}

void kruskal(Graph& G) {

    cout << "Kruskal Algorithm : " << endl;

    //on trie par ordre croissant la liste
    G.sortEdge();

    Vertex* setV;
    Edge* setE;

    for(int i = 0; i < G.ListEdge.size(); ++i) {
        Edge*& e = G.ListEdge[i];

        if(containsAtMostOne(setV, e.source, e.destination)) {
            setE.insert(&e);

            if(!contains(setV, e.source)) {
                setV.insert(e.source);
            }

            if(!contains(verticeSet, e.dst)) {
                SetV.insert(e.destination);
            }
        }
    }








    /*

    Graph G2(G1.nb_vertex);
    G1.sortEdge();

    int id;

    for(int i=0, j=0; (i < (G1.nb_vertex)-1) && (j < (G1.nb_edge)) ; j = j+2) {
            //                                              ici rajouter avant ==0
        if((G2.getVertices()[G1.getEdges()[j].getSrc().id-1].nbNeighbor == 0) || (G2.getVertices()[G1.getEdges()[j].destination.(id-1)].nbNeighbor == 0)){
            G2.addEdgeSD(G1.getEdges()[j].getSrc().id, G1.getEdges()[j].getDest()->id, G1.getEdges()[j].cost(), id);
            G2.addEdgeSD(G1.getEdges()[j].getDest().id, G1.getEdges()[j].getSrc().id, G1.getEdges()[j].cost(), id+1);
            ++i;
            id = id+2;
        }
    }

    G2.MatrixFromEdges();
    ///On affiche la matrice obtenue
    G2.afficher();


    */
}
