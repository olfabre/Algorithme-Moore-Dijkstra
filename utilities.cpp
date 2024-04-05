#include <iostream>
#include <fstream>
#include "utilities.h"
#include "limits.h"
#include <vector>
#include <algorithm>

using namespace std;



/****************************************/
// Objectif : Affichage de la matrice d'adjacence
/* ***************************************/
void affichage(int *c[], int n)
{
	cout << "c = " << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < (n-1); j++)
			cout << c[i][j] << "\t";
		cout << c[i][n-1] << endl;
	}

	cout << endl;
}


/****************************************/
// Objectif : Affichage du tableau des plus courts chemins
/****************************************/
void affichage(int d[], int n)
{
	cout << "d = " << endl;
	for(int i = 0; i < n-1; i++)
		cout << d[i] << "\t";

	cout << d[n-1] << endl << endl;
}




/* Objectif : Algorithme de calcul des plus courts
dans un graphe dont les arcs ont des longueurs positives.
- c : matrice de longueur de chaque arc
- d : tableau des plus courts chemins
- pere : tableau donnant pour chaque sommet i son prédecesseur
pred[i] dans le plus court chemin.
- n : nombre de sommets du graphe
- s : sommet origine d'où les plus courts chemins sont calculés
*/
void mooredijkstra(int *c[], int d[], int n, int s) {
    // Initialisation de NC = Liste des sommets de G pour lesquels le plus court chemin n’est pas connu
    vector<int> NC(n);
    for (int k = 0; k < n; k++) {
        NC[k] = k;
    }

    // Initialisation de d, tableau des plus courts chemins
    for (int k = 0; k < n; k++) {
        d[k] = INT_MAX;
    }
    d[s] = 0; // Distance au sommet source est 0

    // Initialisation du tableau père
    int pere[n];
    for (int k = 0; k < n; k++) {
        pere[k] = -1;
    }

    int j = s; // Le premier pivot est le sommet source

    // Début du traitement de l'algorithme Dijkstra
    for (int l = 0; l < n - 1; l++) {
        for (int i = 0; i < n; i++) {
            if (find(NC.begin(), NC.end(), i) != NC.end() && c[j][i] > 0) {
                if (d[j] + c[j][i] < d[i]) {
                    d[i] = d[j] + c[j][i];
                    pere[i] = j;
                }
            }
        }

        NC.erase(remove(NC.begin(), NC.end(), j), NC.end());

        int minDistance = INT_MAX;
        int prochainJ = -1;
        for (int i = 0; i < n; i++) {
            if (find(NC.begin(), NC.end(), i) != NC.end() && d[i] < minDistance) {
                minDistance = d[i];
                prochainJ = i;
            }
        }

        if (prochainJ == -1) break;
        j = prochainJ;
    }


}

