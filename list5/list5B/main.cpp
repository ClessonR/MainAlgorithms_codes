#include <iostream>
#include <cstdio>
#include <queue>
#include <map>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;


//! Global Variables

string s[105][4],name="Ahmad"; //? Making my life easier
map<string,int>m;
set<string>ans[150],pos;
int t,n;


void check(int x,int y,int z)
{
    if(ans[x].count(s[y][z]))
    {
        for(int i=1;i<=2;i++)
        {if(m[s[y][(z+i)%3]]==0)
            {
                ans[x+1].insert(s[y][(z+i)%3]);
                m[s[y][(z+i)%3]]=1;
            }
        }
    }
}


void check_undefined(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(m[s[i][j]]==0) pos.insert(s[i][j]),m[s[i][j]]=1;
        }
    }
}


int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<3;j++)
            {
                cin>>s[i][j];
            }
        }

        m[name]=1;
        ans[0].insert(name);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<3;k++)
                {
                    check(i,j,k);
                }
            }
        }
        check_undefined(n);
        printf("%d\n",m.size());

        for(int i=0;i<=n;i++)
        {
            if(ans[i].size()==0) break;
            for(set<string>::iterator it=ans[i].begin();it!=ans[i].end();it++)
                cout<<*it<<' '<<i<<endl;
        }


        for(set<string>::iterator it=pos.begin();it!=pos.end();it++)
            cout<<*it<<" undefined"<<endl;

        for(int i=0;i<150;i++)
            ans[i].clear();

        pos.clear();
        m.clear();
    }
    return 0;
}