#include"Graph.h"
#include "MinHeap.h"
#include "DisjointSet.h"
#include <iostream>

using namespace std;


int kruskal(Graph& G) {

    cout << "Kruskal Algorithm : " << endl;

	MinHeap MH = MinHeap(G.ListEdge, G.ListEdge.capacity(), G.ListEdge.size());

	//création pointeur
	int* vertexK = new int[G.ListVertex.size()];

	for (int i = 0; i < G.ListVertex.size(); ++i) {
		vertexK[i] = (G.ListVertex[i]->id);
	}


	DisjointSet ds = DisjointSet(G.ListVertex.size());
	unsigned int compteur = 0;

	Edge t;

	while (compteur != G.ListVertex.size()-1) {
		t = MH.TakeMin();

		if (ds.diff(t.destination->id, t.source->id)) {//if in different sets
			cout << "Edge: " << t.id << ",Weight: " << t.cost << ",Connecting vertex " << t.source->id+1 << ",vertex " << t.destination->id+1 << endl;
			ds.Union(t.destination->id, t.source->id);
		}
		else {
			continue;
		}

		MH.deleteMin();
		compteur++;
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

}


    void kruskalMST(int cost[][G.nb_vertex])
{
    int minCost = 0; // Cost of min MST

    // Initialize sets of disjoint sets.
    for (int i = 0; i < G.nb_vertex; i++)
        parent[i] = i;

    // Include minimum weight edges one by one
    int edge_count = 0;

    while (edge_count < G.nb_vertex - 1) {
        int minimum = INT_MAX, a = -1, b = -1;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (Find(i) != Find(j) && cost[i][j] < minimum) {
                    minimum = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        union1(a, b);
        printf("Edge %d:(%d, %d) cost:%d \n",
               edge_count++, a, b, min);
        mincost += min;
    }
    printf("\n Minimum cost= %d \n", mincost);
}












    //On initialise le résultat
    int mstWeight = 0;

    //on trie les edges en fonction du coût
    G.sortEdge();

    //Create disjoint sets
    DisjointSet ds(G.nb_vertex);

    for (int i = G.ListEdge.begin(); i != G.ListEdge.end(); i+=2)
    {
        int u = i;
        int v = i->second.second;

        int set_u = ds.Find(u);
        int set_v = ds.Find(v);

        // Check if the selected edge is creating
        // a cycle or not (Cycle is created if u
        // and v belong to same set)
        if (set_u != set_v)
        {
            // Current edge will be in the MST so print it
            cout << u << " - " << v << endl;

            // Update MST weight
            mstWeight += i->first;

            // Merge two sets
            ds.Union(set_u, set_v);
        }
    }

    return mstWeight;
}

*/
