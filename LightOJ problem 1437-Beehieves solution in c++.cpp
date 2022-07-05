#include<bits/stdc++.h>
using namespace std;
#define inf 1000000
int ans;
int colon[505];
vector<int>graph[505];
int bfs(int src)
{
    int parent[505];
    for(int i=0;i<505;i++){colon[i]=INT_MAX;parent[i]=-1;}
   queue<int>q;
   q.push(src);
   colon[src]=0;
   while(!q.empty())
   {
       int from=q.front();
       q.pop();
       for(int i=0;i<graph[from].size();i++)
       {
           int to=graph[from][i];
           if(colon[to]!=INT_MAX)
           {
               if(parent[from]!=to)
               {

                   ans=min(ans,colon[from]+colon[to]+1);
               }

           }
           else
           {
                   colon[to]=colon[from]+1;
                   parent[to]=from;
                   q.push(to);
           }
       }
   }

}
int main()
{
    int t;cin>>t;
    for(int k=1;k<=t;k++)
    {
        int n,m;cin>>n>>m;ans=inf;
        for(int i=0;i<n;i++)graph[i].clear();
    while(m--)
    {
        int a,b;cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=0;i<n;i++)
    {
        bfs(i);
    }
    printf("Case %d: ",k);
    if(ans==inf)
    {
        cout<<"impossible"<<endl;
    }
    else cout<<ans<<endl;
    }

}
