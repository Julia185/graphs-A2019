#include "Graph.h"
#include "Vertex.h"
#include "BFS.h"
#include "Floyd_Warshall.h"

#include <vector>
#include <time.h>
#include <cstdlib>
#include <iostream>

#include <string>
#include <sstream>
#include <fstream>
#include <list>

using namespace std;

Graph::Graph(int _nb_vertex)
{
    this->nb_vertex = _nb_vertex;

    for (int i=0;i<nb_vertex; ++i)
    {
        Vertex* v = new Vertex(i, 0, 0);
        ListVertex.push_back(v);
    }
    srand(time(NULL));

    int id=0;
    for (int i=0;i<nb_vertex; ++i)    {
        for (int j=0;j<nb_vertex; ++j)        {
            if (i==j)continue;
            int r=rand()%2;
            if(r==1) /// il existe un lien
            {
                 Edge* e = new Edge(id,1,ListVertex[i],ListVertex[j]);
                 ListEdge.push_back(e);
                ++id;
            }
        }
    }

}

void Graph::genererMatrice(){
    Adj = new int*[nb_vertex];
    for (int i =0;i<nb_vertex;i++){
        Adj[i] = new int[nb_vertex];
        for (int j =0;j<nb_vertex;j++)
            Adj[i][j]=0;
    }
    int n = ListEdge.size();
    for (int k =0; k<n ;k++){
        int c = ListEdge[k]->cost;
        int i = ListEdge[k]->source->id;
        int j = ListEdge[k]->destination->id;
        Adj[i][j]=c;
    }
}

void Graph::genererDistVertex(){
    int k=0;
    for (int i=0;i<nb_vertex;i++){
        ListVertex[i]->distance = new int[nb_vertex];
    }

    Floyd_Warshall(this);
    cout<<" \t";

    for (int i =0;i<nb_vertex;i++)
        cout<<i<<"\t";
    cout<<endl;

    for (int i =0;i<nb_vertex;i++){
        cout<<i<<"\t";
        for (int j =0;j<nb_vertex;j++)
                if(ListVertex[i]->distance[j]==INT_MAX) cout <<"INF\t";
                else cout<<ListVertex[i]->distance[j]<<"\t";
        cout<<endl;
    }
    cout<<endl;
}


Graph::Graph(const Graph& other){
    if (this != &other) {
            this->nb_vertex = other.nb_vertex;
            this->nb_edge = other.nb_edge;

            this->ListVertex = other.ListVertex;
            this->ListEdge = other.ListEdge;

            for (int i =0;i<nb_vertex;i++)
                delete[] Adj[i];
            delete[] Adj;

            genererMatrice();
    }
}


void Graph::afficher(){
    cout << "Matrix of the Graph :" << endl;
    cout<<" \t";
    for (int i =0;i<nb_vertex;i++)
        cout<<i<<"\t";
    cout<<endl;

    for (int i =0;i<nb_vertex;i++){
        cout<<i<<"\t";
        for (int j =0;j<nb_vertex;j++)
            cout<<Adj[i][j]<<"\t";
        cout<<endl;
    }
    cout<<endl;
}

Graph::Graph(){
    /// lecture fichier puis construction graph
    ifstream FICH("file.txt");
    cout << "res de file2graph : " << this->file2graph(FICH) <<endl;

}


Graph::~Graph(){
    ///delete adjency matrix

    for (int i =0;i<nb_vertex;i++)
        delete[] Adj[i];
    delete[] Adj;
}

///REVOIR CES 2 FONCTIONS

vector<Vertex*>& Graph::getVertices() {
    return ListVertex;
}

vector<Edge*>& Graph::getEdges() {
    return ListEdge;
}


/*
///Cr�ation d'une matrice � partir de la liste d'Edges
void Graph::MatrixFromEdges(Graph G) {
    cout << "Creation of the matrix from the edges : " << endl;

    for(int i = 0; i<G.nb_vertex; ++i)
    {
        Vertex* v = new Vertex(i, 0, 0);
        ListVertex.push_back(v);
    }

    Matrix = new int* [G.nb_vertex];

    for(int i = 0; i < nb_vertex(); ++i) {
        Matrix[i] = new int[nb_vertex];
    }

    for(int i = 0; i<nb_edges();i++)
    {
        Matrix[listEdge[i].get_src().iden()-1][listEdge[i].get_dest().iden()-1]=listEdge[i].get_cost();
        //cout<<listEdge[i].get_cost();
    }
}
*/
///Fonction qui trie ordre croissant
void Graph::sortEdge() {
    int length = nb_edge;

    for (int i = 0; i < length-1; ++i) {
        for (int j = 0; j < length-1-i; ++j) {
            if ((ListEdge[j]->cost) > (ListEdge[j+1]->cost)) {
                Edge* p = ListEdge[j+1];
                ListEdge[j+1] = ListEdge[j];
                ListEdge[j] = p;
            }
        }
    }
}


///Fonction qui v�rifie qu'un vertex est bien dans la liste
int Graph::verifV(int ID, Vertex*& v){
    for(int i=0; i<nb_vertex; ++i) {
        if (ListVertex[i]->id == ID) {
            v = ListVertex[i];
            return 1;
        }
    }
    return 0;
}


/*
///Fonction qui ajoute un Edge dans la liste
void Graph::addEdge(Vertex* src, Vertex* dest, int cost, int id) {
    //cr�ation d'un edge
    Edge* e = new Edge(id, src, dest, cost);
    //ajout dans la liste
    ListEdge.push_back(e);
}



///Fonction qui utilise addEdge
void Graph::addEdgeSD(int src,int dest,int cost, int id){

    ListVertex[src-1].add_nei(dest);

    //cr�ation des deux vertices
    Vertex* v1 = new Vertex(id, cost, );
    Vertex* v2 = new Vertex();

    //on v�rifie qu'ils existent
    verifV(src,v1);
    verifV(dest,v2);

    addEdge(v1, v2, cost, id);
}
*/

///Fonction qui v�rifie que deux vertices sont bien reli�s par un edge
Edge* Graph::verifEdge_o(Vertex* source, Vertex* destination) {
	for(int i=0; i<ListEdge.size(); ++i) {
		if((ListEdge[i]->source == source) && (ListEdge[i]->destination == destination)) {
			return ListEdge[i];
		}
	}
	return NULL;
}

///fonction qui d�tecte la fin d'une ligne dans un fichier
bool endLine (ifstream& fichier){
    char carac;

    fichier.get(carac);

    if ((carac == '\n') || (carac == '\r')) {
        return true;
    }
    else {
        return false;
    }
}

int Graph::file2graph( ifstream& FICH )
{
    ///try fichier

    if(FICH){

        ///first line for nb vertices
            FICH.seekg(0,ios::beg);
            string nb_vertices;
            FICH >> nb_vertices;
                ///conversion string to int and transfert to Graph
                istringstream(nb_vertices) >> nb_vertex;
            ///type of the graph: o for directed graph, n for undirected graph
            FICH.seekg(0,ios::cur);
            string types;
            FICH >> types[0];

            ///type of representation: m adjacency matrix, l adjacency list.
            FICH.seekg(0,ios::cur);
            FICH >> types[1];


        ///gestion exception 3 premi�re lignes
        try {
            if (nb_vertex <0 || (types[0]!='o' && types[0]!='n')  || (types[1]!='m' && types[1]!='l')) throw(-1);
            else throw(1);
        }catch(int nb){

        if (nb!=1) exit (EXIT_FAILURE);  ///si pb dans cr�ation graph on stoppe
        else
            {
                ///lecture fichier avec adjency matrix (directed or undirected) ==>graph_o_matrix
                if ((types[0] =='o' || types[0] =='n' )&& types[1]=='m') {
                    if (graph_o_matrix(FICH)!=1) exit (EXIT_FAILURE);
                    else return (graph_o_matrix(FICH));
                    }
                     else if ((types[0] =='o' || types[0] =='n' )&& types[1]=='l') {
                        if (graph_list(FICH) != 1) exit (EXIT_FAILURE);
                        else return (graph_list(FICH));
                    }
        }
        }
    }
    else{
        return 0;
    }
}

int Graph::graph_o_matrix(ifstream& FICH){
    try { //si marche renvoie 1
    try { //exception par m�moire ou allocation
    int i;
    for(i=0;i<nb_vertex; ++i)
    {
        Vertex* v = new Vertex(i, 0, 0);
        ListVertex.push_back(v);
    }

    int id=0;

    for (int i=0; i<nb_vertex; ++i)    {

        lineX(FICH,i+3); //mis en place au niveau voulu
        int compteur = 0;
        int j = 0;

        string line; //string contenant la ligne de la matrix
        getline(FICH, line);

        int posEspace =0;

        while (j<nb_vertex)
        {

            posEspace = line.find(" ",posEspace+1);
            string VALUE = line.substr(compteur,posEspace-compteur);
            istringstream iss (VALUE);
            int c = stringToInt(VALUE);

            Edge* e = new Edge(id, c, ListVertex[i],ListVertex[j]);
            ListEdge.push_back(e);
            ++id;
            ++j;

            //on se met apr�s l'espace
            compteur = compteur+(posEspace-compteur);
        }
    }
    }catch(exception const& e) {return 0;}
    throw 1;
    }catch(int nb){return nb;}
}

///Cr�e un graph � partir d'une liste d'adjacence
int Graph::graph_list(ifstream& File){

    try{///return 1 if it construct the graph
        for(int i = 0; i < nb_vertex; ++i){
            ///Cr�ation de la liste de vertices
            Vertex* v = new Vertex(i, 0, 0);
            ListVertex.push_back(v);
        }

        ///variables pour la suite
        int compteur = 0, counter = 0;
        int j = 0, c = 0, id = 0;

        for (int i = 0; i < nb_vertex; ++i) {
            ///on se place � la bonne ligne (on commence a 0)
            lineX(File,3+i);

            string line;
            getline(File, line);
            int taille = line.size();
            cout << endl << "taille de la ligne : " << taille << endl << endl;

            ///on se replace au d�but de la ligne
            File.seekg(0,ios::beg);
            lineX(File,3+i);

            do {
                string morceau;
                File >> morceau;
                cout << "morceau : " << morceau << endl;

                int p = morceau.size();

                if(counter%2 == 0) {
                    j = stringToInt(morceau);
                }
                else {
                    c = stringToInt(morceau);
                    ///On cr�e le nouveau edge
                    Edge* e = new Edge(id, c, ListVertex[i],ListVertex[j]);
                    ListEdge.push_back(e);
                }

                compteur = compteur + p + 1;
                cout << "compteur : " << compteur << endl << endl;
                counter++;
                id++;
            }
            while(compteur <= taille);

            compteur = 0;
            cout << "On passe a la ligne suivante!" << endl << endl;
            //cout << "Le vertex a " << (compteur-1)/2 << " voisin(s)" << endl;
        }
        return 1;
    }
    catch(exception const& e) {return 0;}
}

///Fonction qui place le curseur � la ligne x
void Graph::lineX(ifstream& File, int x) {

        ///on remet le curseur au d�but du fichier
        File.seekg(0, ios::beg);

        ///on le d�place au d�but de la ligne x
        for (int i = 0; i < x; ++i) {
            string line;
            getline(File,line);
        }

}

///fonction qui transforme un string en int
int Graph::stringToInt(string ss){
    int value;

    value = atoi(ss.c_str());
    return value;
}


///Fonction qui met tous les vertices � non visit�
void Graph::setAllUnvisited() {
    for (int i = 0; i < nb_vertex; ++i) {
        ListVertex[i]->visit = 0;
    }
}

///Fonction qui indique si le vertex id est visit�
bool Graph::isVisited(int ID) {
    return ListVertex[ID]->visit;
}


///Fonction qui note le vertex id comme visit�
void Graph::visited(int ID) {
    ListVertex[ID]->visit = 1;
}


///Fonction qui traverse le graph et compte le nb de vertices visit�s
int Graph::pathes_prefixe(Graph* G){
    vector<int> v;
    v = BFS(G,0);

    int nbVisited = v.size();
    return nbVisited;
}


///Fonction qui v�rifie la "relatedness" du graph
bool Graph::graph_connexe(Graph* G){
    int value = pathes_prefixe(G);
    if(G->nb_vertex == value) return 1;
    else return 0;
}

/*
///Fonction qui convertit une matrice en liste (graphe o)
void Graph::matrix2list_o(){
    //on cr�e le vector
	vector<Vertex*> vertex;

	for(unsigned int i=0; i < nb_vertex; ++i) {
    Adj->push_back(vertex);

		//build an adjacency list from the adjacency matrix
		for (unsigned int j = 0; j < nb_vertex; ++j) {
			if(Adj[i][j] == 1) {
				Adj[i].push_back(ListVertex[j]);
			}
		}
	}
}


///Fonction qui convertit une matrice en liste (Graphe n)
void Graph::matrix2list_n(){
    //cr�ation du vector
	vector<Vertex*> vertex;

	for(unsigned int i=0; i < nb_vertex; ++i) {
        //on l'ajoute � la liste
		Adj.push_back(vertex);

		for (unsigned int j=0; j < i+1; ++j) {
			if(Adj[i][j] == 1) {
				Adj[i].push_back(ListVertex[j]);
			}
		}

		for (unsigned int j=i; j < nb_vertex; ++j) {
			if((Adj[j][i] == 1) && (i != j)) {
				Adj[i].push_back(ListVertex[j]);
			}
		}
	}
}


///Fonction qui convertit une liste en matrice (Graph o)
void Graph::list2matrix_o() {
	vector<int> vect;

	for (unsigned int i = 0; i < nb_vertex; ++i) {
		Adj.push_back(vect);

		for (unsigned int j = 0; j < nb_vertex; ++j) {
			if(verifEdge_o(ListVertex[i],ListVertex[j]) != NULL) {
				Adj[i].push_back(1);
			}
			else {
                Adj[i].push_back(0);
            }
		}
	}
}


///Fonction qui convertit une liste en matrice (Graph n)
void Graph::list2matrix_n() {
	vector<int> vect;

	for (unsigned int i = 0; i < nb_vertex; ++i) {
		ListVertex.push_back(vect);

		for (unsigned int j = 0; j < i; ++j) {
			if(is_n_edge(ListVertex[i],ListVertex[j]) != NULL) {
                Adj[i].push_back(1);
			}
			else {
                Adj[i].push_back(0);
            }
		}
	}
}
*/
