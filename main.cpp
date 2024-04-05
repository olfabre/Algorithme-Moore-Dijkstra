#include <iostream>
#include "utilities.h"

using namespace std;

int main() {
    cout << "Mes propres tests: Olivier Fabre" << endl;
    // Nombre de sommets
    int n = 10;

    // On crée un tableau de type integer de taille 8 par defaut la valeur 0
    int d[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // Matrice d'adjacence pondérées
    // Pour tout couple de sommets i et j, c[i][j] est égal à 0 s'il n'y a pas d'arête (𝑖,𝑗)
    // ou égal à la longueur de l'arête si elle existe
    int c[10][10] = { {0,6,18,6,1,12,5,3,10,14},
                      {6,0,12,3,16,6,5,15,13,11},
                      {18,12,0,17,1,7,6,5,8,18},
                      {6,3,17,0,0,19,12,17,18,2},
                      {1,16,1,0,0,7,16,1,14,18},
                      {12,6,7,19,7,0,5,11,13,7},
                      {5,5,6,12,16,5,0,5,6,3},
                      {3,15,5,17,1,11,5,0,14,4},
                      {10,13,8,18,14,13,6,14,0,0},
                      {14,11,18,2,18,7,3,4,0,0}};

    // On crée un pointeur de type integer sur la position du premier indice d'un tableau integer
    int* distance[10] = { c[0], c[1], c[2], c[3], c[4], c[5] , c[6] , c[7], c[8], c[9] };

    // Affectation du sommet origine d'où les plus courts chemins sont calculés
    int s = 0;

    // Affichage de la matrice
    //affichage(distance, n);
    //cout << "---" << endl;

    /* Objectif : Algorithme de calcul des plus courts dans un graphe dont les arcs ont des longueurs positives.
        - c : matrice de longueur de chaque arc
        - d : tableau des plus courts chemins
        - pere : tableau donnant pour chaque sommet i son prédecesseur pred[i] dans le plus court chemin.
        - n : nombre de sommets du graphe
        - s : sommet origine d'où les plus courts chemins sont calculés
    */
    mooredijkstra(distance, d, n, s);

    // Affichage du tableau des plus courts chemins
    //cout << "Le plus court chemin" << endl;
    affichage(d, n);


/*
 La valeur du plus court chemin de 9 à :
-> 0 est égale à 6
-> 1 est égale à 5
-> 2 est égale à 6
-> 3 est égale à 2
-> 4 est égale à 5
-> 5 est égale à 7
-> 6 est égale à 3
-> 7 est égale à 4
-> 8 est égale à 9
-> 9 est égale à 0


 0	6	18	6	1	12	5	3	10	14
6	0	12	3	16	6	5	15	13	11
18	12	0	17	1	7	6	5	8	18
6	3	17	0	0	19	12	17	18	2
1	16	1	0	0	7	16	1	14	18
12	6	7	19	7	0	5	11	13	7
5	5	6	12	16	5	0	5	6	3
3	15	5	17	1	11	5	0	14	4
10	13	8	18	14	13	6	14	0	0
14	11	18	2	18	7	3	4	0	0

 */

    return(0);
}



