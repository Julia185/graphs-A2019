#include"Graph.h"
#include "MinHeap.h"
#include "kruskal.h"
#include "DisjointSet.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int kruskal(Graph* G){

    cout << "Kruskal Algorithm : " << endl;
    cout << "MST :" << endl << "Edge \tWeight" << endl;

    //Initialisation
	int mstWeight = 0;
	vector<Edge*> liste = G->ListEdge;

    liste = sortingCost(G);

    for(unsigned int i = 0; i < liste.size(); ++i){
        Vertex* u = liste[i]->source;
        Vertex* v = liste[i]->destination;

        Vertex* set_u = Find(u);
        Vertex* set_v = Find(v);

        //on vérifie qu'ils n'appartiennent pas au même set
        if (set_u != set_v)
        {
            //on affiche l'edge car il sera dans le MST
            cout << u->id << " - " << v->id << "\t" << liste[i]->cost << endl;

            //on update le résultat
            mstWeight = mstWeight + liste[i]->cost;

            // Merge two sets
            Union(liste[i]);
        }
    }

    for (int i = 0; i < G->nb_vertex; ++i) {
        G->ListVertex[i]->parent = G->ListVertex[i];
    }

    cout << "Le MST a un poids de : " << mstWeight << endl;

    return mstWeight;
}



///Fonction qui trie les edges en fonction de leur coût (du min au plus)
vector<Edge*> sortingCost(Graph* G) {
	//attributs dont on aura besoin
	vector<Edge*> listEdge_sorted;
	unsigned int counter = 0;
	bool test;

	listEdge_sorted.push_back(G->ListEdge[0]);

	for (unsigned int i = 1; i < G->ListEdge.size()/2; ++i) {
            test = true;

            while (test){
                if (counter == listEdge_sorted.size()) {
                    counter = 0;
                    test = false;
                    listEdge_sorted.push_back(G->ListEdge[i]);
                }
                else {
                    if (listEdge_sorted[counter]->cost > G->ListEdge[i]->cost) {
                        listEdge_sorted.insert(listEdge_sorted.begin()+(counter+1), listEdge_sorted[counter]);
                        listEdge_sorted[counter] = G->ListEdge[i];
                        counter = 0;
                        test = false;
                    }
                    else {
                        counter++;
                    }
                }
            }
	}

	/*
	for(unsigned int i =0; i < listEdge_sorted.size(); ++i){
        cout << listEdge_sorted[i]->id << " - cost : " << listEdge_sorted[i]->cost << endl;
	}

	cout << "Nb d'edge trie " << listEdge_sorted.size() << endl;

	*/

	return listEdge_sorted;
}


///Fonction qui fait l'union en fonction du rank
void Union(Edge* e)
{
	Vertex* x = e->source->parent;
	Vertex* y = e->destination->parent;

	x = Find(x);
    y = Find(y);

	// Make tree with smaller height a subtree of the other tree
	if (x->rnk > y->rnk)
		y->parent = x;
	else {
        // If rnk[x] <= rnk[y]
		x->parent = y;
	}
	if (x->rnk == y->rnk)
		++(y->rnk);
}



///Fonction qui cherche le parent du vertex
Vertex* Find(Vertex* _u)
{
	if (_u != _u->parent) {
		_u->parent = Find(_u->parent);
	}

	return _u->parent;
}
