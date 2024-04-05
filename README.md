# Algorithme-Moore-Dijkstra  
L'algorithme de Moore-Dijkstra est une méthode utilisée pour trouver le chemin le plus court entre un point de départ et tous les autres points dans un graphe.  
  
Implémentation de la méthode Dijkstra. On suppose que les graphes sur lesquels on cherche à calculer les plus courts chemins sont des graphes simples où les longueurs (coûts) des arêtes sont positives. Ils seront représentés par des matrices d'adjacence pondérées.  

La matrice c représentant le graphe ci-dessus est par exemple :  

```cpp
int c[8][8] = {  {0,2,0,6,0,0,0,0},
                        {2,0,2,0,7,0,0,0},
                        {0,2,0,1,0,2,0,0},
                        {6,0,1,0,0,0,4,0},
                        {0,7,0,0,0,3,0,3},
                        {0,0,2,0,3,0,2,0},
                        {0,0,0,4,0,2,0,2},
                        {0,0,0,0,3,0,2,0}};
```

Pour tout couple de sommets i et j, c[i][j] est égal à 0 s'il n'y a pas d'arête (𝑖,𝑗) ou égal à la longueur de l'arête si elle existe.  
  
Vous devez coder un algorithme nommé mooredijkstra(c,d,n,s) déterminant la valeur des plus courts chemins d'un sommet origine s quelconque vers tous les autres.  
  
Ces valeurs seront stockées dans un tableau d argument de la fonction. Pour tout i, d[i] sera la valeur du plus court chemin de s à i. n est le nombre de sommets.  
