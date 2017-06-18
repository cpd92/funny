#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int NUM=9;
const int INF=INT_MAX;
bool spt[NUM];
int distination[NUM];

int FindMin(int dis[])    // can improve by priority queue
{
    int min=INF;
    int min_index=0;
    for(int i=0;i<NUM;++i)
    {
        if(spt[i]==false && dis[i]<min)
        {
            min=dis[i];min_index=i;
        }
    }

    return min_index;
}

void PrintShorestPathTree(int dis[])
{
    printf("The SPT is:\n");
    for(int i=0;i<NUM;++i)
    {
        printf("Node %d: Length:%d \n",i,dis[i]);
    }
}

void dijkstra(int graph[NUM][NUM],int begin)
{
    distination[begin]=0;

    for(int j=0;j<NUM-1;j++)
    {
        int u=FindMin(distination);

        spt[u]=true;

        for(int i=0;i<NUM;++i)
        {
            if(spt[i]==false && graph[u][i] && distination[u]!=INF && distination[u]+graph[u][i]<distination[i])
            {
                distination[i]=distination[u]+graph[u][i];
            }
        }
    }

    PrintShorestPathTree(distination);
}

int main()
{
    memset(spt,false,sizeof(spt));

    for(int i=0;i<NUM;++i)        // WRONG:memset(distination,INF,sizeof(distination));
    {
        distination[i]=INF;
    }

    int graph[NUM][NUM] =
                      {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                      };
    dijkstra(graph,0);
    return 0;
}
