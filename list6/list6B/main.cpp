#include <bits/stdc++.h>
using namespace std;


//? Global Variables
const int MAXN=1e3+100;
int n,m;

struct Edge{
    int m,u,v,cost;
    bool operator <(const Edge& a)const{
        return cost<a.cost;
    }
};


vector<Edge> edges;
int F[MAXN];

int find(int x)
{
    return x==F[x]?x:F[x]=find(F[x]);
}

void kruskal()
{
    for(int i=0;i<n;i++)F[i]=i;
    sort(edges.begin(),edges.end());
    vector<int> ans;
    for(int i=0;i<m;i++)
    {
        Edge e=edges[i];
        int u=e.u;
        int v=e.v;
        int fu=find(u);
        int fv=find(v);
        if(fu!=fv)
        {
            F[fu]=fv;
        }
        else{
            ans.push_back(e.cost);
        }
    }
    if(ans.size()==0)printf("forest\n");
    else{
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++)
            if(i==0)
                printf("%d",ans[i]);
            else printf(" %d",ans[i]);
        printf("\n");
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0)break;
        edges.clear();
        for(int i=0;i<=m-1;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            edges.push_back((Edge){i,a,b,c});
        }
        kruskal();
    }
    return 0;
}