#include<bits/stdc++.h>
using namespace std;

const int M=5;

bool has_use[M];

/*A minimum spanning tree (MST) or minimum weight spanning tree is a subset of the edges of a connected, 
 edge-weighted undirected graph that connects all the vertices together, without any cycles and with the minimum possible total edge weight.*/

int Shortest(int* mst)
{
    int min_index=0;
    int min_val=INT_MAX;
    for(int i=0;i<M;++i)
    {
        if(mst[i]<min_val && !has_use[i])
        {
            min_index=i;min_val=mst[i];
        }
    }
    
    return min_index;
}

void PrintMST(int g[M][M],int* parent)
{
    cout<<"edge:"<<"--"<<"weight:"<<endl;
    int total_weight=0;
    for(int i=1;i<M;++i)
    {
        cout<<parent[i]<<" -- "<<i<<" -- "<<g[i][parent[i]]<<endl;
        total_weight+=g[i][parent[i]];
    }
    
    cout<<"total weight is:"<<total_weight<<endl;
}

void CreateMST(int g[M][M],int start_index)
{
    int mst[M];
    int parent[M];
    
    for(int i=0;i<M;++i)
    {
        mst[i]=INT_MAX;
    }
    
    mst[start_index]=0;       //minimun weight edge in the graph
    parent[start_index]=-1;
    has_use[start_index]=true;
    
    for(int i=0;i<M;++i)
    {
        int u=Shortest(mst);
        
        has_use[u]=true;
        
        for(int v=0;v<M;++v)
        {
            if(!has_use[v] && g[u][v] && g[u][v]<mst[v])
            {
                mst[v]=g[u][v];
                parent[v]=u;
            }
        }
    }
    
    PrintMST(g,parent);
}

int main()
{
    memset(has_use,sizeof(has_use),false);
    
     /* Let us create the following graph
          2    3
      (0)--(1)--(2)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (3)-------(4)
            9          */
   int g[M][M] = {{0, 2, 0, 6, 0},
                  {2, 0, 3, 8, 5},
                  {0, 3, 0, 0, 7},
                  {6, 8, 0, 0, 9},
                  {0, 5, 7, 9, 0},
                 };

    
    CreateMST(g,0);
    
    return 0;
}
