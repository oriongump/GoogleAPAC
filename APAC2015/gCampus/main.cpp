#include <string>
#include <vector>
#include <stdio.h>
#include <cmath>
#include <map>
#include <iostream>
#include <sstream>
#include <queue>
#include <algorithm>
#include <memory>
#include <set>

using namespace std;

#define rep(i,m) for(int i=0;i<(int) (m);i++)
#define rep2(i,n,m) for(int i=n;i<(int) (m);i++)
#define pb push_back

typedef stringstream ss;
typedef long long ll;
typedef pair<long,long> PLL;
typedef pair<int,int> PII;

//#define SAMPLE
#define SMALL
//#define LARGE
struct Edge{
  int start;
  int end;
  int length;
};

int shortMatrix[101][101];
int directRoad[101][101];
int directDis[101][101];
int skipList[10001];
vector<Edge> edge;
int N;
int CMax=10000001;
//int tot;

void findSPath(int start){
  int v,k,min;
  vector<bool> final(N);
  vector<int> dist(N);
  rep(i,N){
    final[i]=false;
    if(i<start){
      dist[i]=directDis[i][start];
    }else if(i>start){
      dist[i]=directDis[start][i];
    }
  }
  final[start]=true;
  // rep(i,N){
  //   cout<<dist[i]<<" ";
  // }
  // cout<<endl;
  k=start;
  rep(i,N-1){
    min=CMax;
    rep(w,N){
      if(!final[w] && dist[w] < min){
        min=dist[w];
        v=w;
      }
    }
    final[v]=true;
    //cout << k <<" "<<v<<endl;
    skipList[directRoad[k][v]-1]=1;
    k=v;
    rep(w,N){
      int cost=(v>w)?directDis[w][v]:directDis[v][w];
      if (!final[w] && dist[v] + cost < dist[w]) {
          dist[w] = dist[v] + cost;
      }
    }
  }
  rep(i,N){
    //cout<<dist[i]<<" ";
    if(start<i){
      shortMatrix[start][i]=dist[i];
    }else if(start>i){
      shortMatrix[i][start]=dist[i];
    }
  }
  //cout<<endl;
}

int main(){
#ifdef SAMPLE
  freopen("sample.in","r",stdin);
#endif
#ifdef SMALL
  freopen("C-small-attempt0.in","r",stdin);
  //freopen("C-small.out","w",stdout);
#endif
#ifdef LARGE
  freopen("C-large.in","r",stdin);
  freopen("C-large.out","w",stdout);
#endif
  int Test;
  cin>>Test;
  rep(i,Test){
    int M;
    edge.clear();
    memset(shortMatrix,0,sizeof(shortMatrix));
    memset(directRoad,0,sizeof(directRoad));
    memset(directDis,127,sizeof(directDis));
    cin >> N >> M;
    //cout << Test << " " << N << " " << M << endl;
    cout << "Case #" << i+1 << ": "<<endl;
    rep(j,M){
      int u,v,c;
      cin>>u>>v>>c;
      if(u>v){
        int temp=u;
        u=v;
        v=temp;
      }
      Edge temp;
      temp.start=u;
      temp.end=v;
      temp.length=c;
      edge.pb(temp);
      if(directRoad[u][v]>0){
        if(directDis[u][v]>c){
          directRoad[u][v]=j+1;
          directRoad[v][u]=j+1;
          directDis[u][v]=c;
          directDis[v][u]=c;
        }
      }else{
        directRoad[u][v]=j+1;
        directRoad[v][u]=j+1;
        directDis[u][v]=c;
        directDis[v][u]=c;
      }
    }
    rep(ii,N-1){
        findSPath(ii);
    }
    // rep(ii,N){
    //   rep(jj,N){
    //     if(directDis[ii][jj]==2139062143){
    //       cout<<0<<" ";
    //     }else{
    //       cout<<directDis[ii][jj]<<" ";
    //     }
    //   }
    // }
    // rep(ii,N){
    //   rep(jj,N){
    //     cout<<shortMatrix[ii][jj]<<" ";
    //   }
    // }
    rep(j,M){
      if(skipList[j])continue;
      if(edge[j].length>shortMatrix[edge[j].start][edge[j].end])cout<<j<<" ";
    }
    cout<<endl;
  }
  return 0;
}