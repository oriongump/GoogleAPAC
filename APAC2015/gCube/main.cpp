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

//#define SAMPLE
//#define SMALL
#define LARGE

int main(){
#ifdef SAMPLE
  freopen("sample.in","r",stdin);
#endif
#ifdef SMALL
  freopen("B-small-attempt1.in","r",stdin);
  freopen("B-small.out","w",stdout);
#endif
#ifdef LARGE
  freopen("B-large.in","r",stdin);
  freopen("B-large.out","w",stdout);
#endif
  int N;
  cin >> N;
  rep(i,N){
    int n,m;
    cin>>n>>m;
    cout << "Case #" << i+1 << ": "<<endl;
    vector<int> a(n);
    rep(j,n)cin>>a[j];
    int L,D;
    rep(j,m){
      int dim;
      cin>>L>>D;
      dim=D-L+1;
      double slength=1;
      rep(k,dim){
        slength*=pow(a[L+k],1.0/dim);
      }
      printf("%0.9lf",slength);
      cout<<endl;
    }
    //cout<<endl;
  }
  return 0;
}