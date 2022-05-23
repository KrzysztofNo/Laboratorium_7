#include <stdio.h>
#define INFINITY 9999
#define MAX 10

void Dijkstra(int Graf[MAX][MAX], int n, int start) {
  int cost[MAX][MAX], distance[MAX], pred[MAX];//deklaracja zmiennych
  int visited[MAX], count, mindistance, nextnode, i, j;//deklaracja zmiennych

  for (i = 0; i < n; i++)//tworzenie macierzy wag
    for (j = 0; j < n; j++)
      if (Graf[i][j] == 0)//jeśli wartość danej komórki macierzy=0, to ustawiamy jej wagę na nieskonczoność
        cost[i][j] = INFINITY;
      else//jeśli nie,ustawiamy wage zgodnie z podaną na krawędzi
        cost[i][j] = Graf[i][j];
  for (i = 0; i < n; i++) {//przechodzimy kolejny raz przez wierzchołki i ustawiamy wagę od początkowego wierzchołka jako distance
    distance[i] = cost[start][i];
    pred[i] = start;
    visited[i] = 0;
  }

  distance[start] = 0;
  visited[start] = 1;
  count = 1;
  while (count < n - 1) {//do momentu az mamy do sprawdzenia jeszcze jakies wierzchołki, to minimalny distance ustawiamy jako nieskonczoność
    mindistance = INFINITY;

    for (i = 0; i < n; i++)//przechodzimy po wszystkich wierzcholkach. Natomiast w momencie, gdy distance jest mniejszy od poprzedniego oraz wierzchołek nie został jeszcze sprawdzony to zastępujemy wartość nową-mniejszą
      if (distance[i] < mindistance && !visited[i]) {
        mindistance = distance[i];
        nextnode = i;
      }
    
    visited[nextnode] = 1;
    for (i = 0; i < n; i++)//przechodzimy po "węzłach", których wierzchołki nie były sprawdzone oraz jeśli aktualny najmniejszy distance jest wiekszy od minimalnego distance i wagi jednocześnie kolejnego "węzła", wtedy jest zmiana wartości na mniejszą
      if (!visited[i])
        if (mindistance + cost[nextnode][i] < distance[i]) {
          distance[i] = mindistance + cost[nextnode][i];//zmiana wartości na mniejszą
          pred[i] = nextnode;
        }
    count++;
  }

  for (i = 0; i < n; i++)//wyswietlamy distance
  if (i != start) {
      printf("\nDistance from source to %d: %d", i, distance[i]);
    }

}
int main() {
  int Graf[MAX][MAX], i, j, n, u;
  n = 5;

  Graf[0][0] = 0;//teraz wczytujemy macierze "sąsiedztwa"
  Graf[0][1] = 3;
  Graf[0][2] = 7;
  Graf[0][3] = 1;
  Graf[0][4] = 2;

  Graf[1][0] = 3;
  Graf[1][1] = 0;
  Graf[1][2] = 5;
  Graf[1][3] = 2;
  Graf[1][4] = 2;

  Graf[2][0] = 7;
  Graf[2][1] = 5;
  Graf[2][2] = 0;
  Graf[2][3] = 6;
  Graf[2][4] = 5;

  Graf[3][0] = 1;
  Graf[3][1] = 2;
  Graf[3][2] = 6;
  Graf[3][3] = 0;
  Graf[3][4] = 1;

  Graf[4][0] = 2;
  Graf[4][1] = 2;
  Graf[4][2] = 5;
  Graf[4][3] = 1;
  Graf[4][4] = 2;

  u = 0;//następnie ustawiamy źródło jako wierzchołek o numerze rownym 0
  Dijkstra(Graf, n, u);

  return 0;
}