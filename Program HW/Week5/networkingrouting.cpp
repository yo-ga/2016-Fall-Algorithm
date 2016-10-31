#include <iostream>
#include <stdio.h>
#include <limits.h>
#define ARR_MAX 20
using namespace std;
int getMinIndex(int dist[ARR_MAX], bool sptSet[ARR_MAX],int V)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] < min)
            min = dist[v], min_index = v;
    return min_index;
}
void dijkstra(int graph[ARR_MAX][ARR_MAX], int source, int det,int V)
{
    int dist[ARR_MAX];
    bool sptSet[ARR_MAX];
    for (int i = 0; i < V; i++)
    {
        dist[i] = (graph[source][i] == 0 ? INT_MAX:graph[source][i]);
        sptSet[i] = false;
    }
    dist[source] = 0;
    sptSet[source] = true;
    for (int count = 0; count < V - 1; count++)
    {
        int u = getMinIndex(dist, sptSet,V);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] + graph[u][u] < dist[v])
                dist[v] = dist[u] + graph[u][v] + graph[u][u];
    }
    printf("%d\n", dist[det]+graph[source][source]+graph[det][det]);
}
int main()
{
    int graph[ARR_MAX][ARR_MAX],n,e,q;
    for(int i=0;i<ARR_MAX;i++){
        for(int j=0;j<ARR_MAX;j++){
            graph[i][j]=0;
        }
    }
    scanf("%d",&n);
    scanf("%d",&e);
    scanf("%d",&q);
    for(int i=0;i<n;i++){
        scanf("%d",&graph[i][i]);
    }
    int fr,to,valu;
    for(int i=0;i<e;i++){
        scanf("%d %d %d",&fr,&to,&valu);
        graph[fr-1][to-1]=valu;
        graph[to-1][fr-1]=valu;
    }
    for(int i=0;i<q;i++){
        scanf("%d %d",&fr,&to);
        dijkstra(graph,fr-1,to-1,n);
    }
    return 0;
}
