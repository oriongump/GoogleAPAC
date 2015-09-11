#include<bits/stdc++.h>

using namespace std;

#define sd(x) scanf("%d",&x);
#define LL long long
#define LD long double
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define Fill(a, b) memset(a, b, sizeof(a))
#define INF 1000000009

typedef pair<int,int> PII;
typedef vector<int> VI;

#define M 10010
#define N 110

int ar[N],adj[N][N];
pair<PII, int > edges[M];
VI ans;

void solve()
{
    int n,m,a,b,c;
    sd(n);sd(m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            adj[i][j] = INF;
        }
        adj[i][i] = 0;
    }
    for(int i=0;i<m;i++)
    {
        sd(a);sd(b);sd(c);
        adj[a][b] = min(adj[a][b], c);
        adj[b][a] = min(adj[b][a], c);
        edges[i].F.F = a;
        edges[i].F.S = b;
        edges[i].S = c;
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }*/

    ans.clear();
    int flag = 0;
    for(int i=0;i<m;i++)
    {
        flag = 0;
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(adj[j][edges[i].F.F] + adj[edges[i].F.S][k] + edges[i].S == adj[j][k])
                {
                    flag = 1;
                    if(flag==1)break;
                }
            }
            if(flag == 1)break;
        }
        if(flag == 0)
        {
            ans.PB(i);
        }
    }
    for(int i=0;i<ans.size();i++)
    {
        printf("%d\n",ans[i]);
    }
    //cout<<endl;

}

int main()
{
	freopen("in2.txt","r",stdin);
	freopen("out2.txt","w",stdout);
	int t=1;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		printf("Case #%d:\n",i);
		solve();
	}
}

