#include"Graph.h"
#include "MinHeap.h"
#include "kruskal.h"
#include "DisjointSet.h"
#include <iostream>

using namespace std;


int kruskal(Graph* G){

    cout << "Kruskal Algorithm : " << endl;
    cout << "MST :" << endl << "Edge \tWeight" << endl;

    //Initialisation
	int mstWeight = 0;
	vector<Edge*> liste = G->ListEdge;
	liste = sortingCost(liste);


	for(int i = 0; i < liste.size(); ++i){
		Vertex* u = liste[i]->source;
		Vertex* v = liste[i]->destination;

		Vertex* set_u; // = Find(u);
		Vertex* set_v; // = Find(v);

		//on vérifie qu'ils n'appartiennent pas au même set
		if (set_u != set_v)
		{
            //on affiche l'edge car il sera dans le MST
			cout << u->id << " - " << v->id << "\t" << liste[i]->cost << endl;

			//on update le résultat
			mstWeight = mstWeight + liste[i]->cost;

			// Merge two sets
			//Union(liste[i]);
		}
	}

	for (int i = 0; i < G->nb_vertex; ++i) {
		G->ListVertex[i];
		//->setParent(G->ListVertex[i]);
	}
	return mstWeight;
}


///Fonction qui tri les edges en fonction de leur coût (du min au plus)
vector<Edge*> sortingCost(vector<Edge*> _ListEdge) {
	//attribut dont on aura besoin
	vector<Edge*> listEdge_sorted;
	listEdge_sorted.push_back(_ListEdge[0]);
	int counter = 0;
	bool test;


	for (int i = 1; i < _ListEdge.size(); ++i) {
		test = true;

		while (test){
			if (counter == listEdge_sorted.size()) {
				counter = 0;
				test = 0;
				listEdge_sorted.push_back(_ListEdge[i]);
			}
			else {
				if (listEdge_sorted[counter]->cost > _ListEdge[i]->cost) {
					listEdge_sorted.insert(listEdge_sorted.begin() + (counter+1), listEdge_sorted[counter]);
					listEdge_sorted[counter] = _ListEdge[i];
					counter = 0;
					test = 0;
				}
				else {
					counter++;
				}
			}
		}
	}
	return listEdge_sorted;
}

/*
///Fonction qui fait l'union de
void Union(Edge* e)
{

	Vertex* x = e->source()->getParent();
	Vertex* y = e->destination->getParent();

	// Make tree with smaller height a subtree of the other tree
	if (x->getRank() > y->getRank())
		y->getParent()->setParent(x);
	else // If rnk[x] <= rnk[y]
		x->getParent()->setParent(y);

	if (x->getRank() == y->getRank())
		y->setRank(y->getRank() + 1);

}



///Fonction qui cherche un vertex
Vertex* Find(Vertex* _u)
{
	Vertex* u = _u;
	Vertex* res = u->getParent();

    //parent de u pointe vers parent de u
	if (u != u->getParent())
		res->setParent(Find(res->getParent()));
	return res->getParent();
}

*/
