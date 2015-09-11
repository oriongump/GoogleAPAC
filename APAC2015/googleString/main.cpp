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

int reverseEngineer(ll idx){
  if(idx==1){
    return 0;
  }else if(idx==2){
    return 0;
  }
  ll n=floor(log2(idx));
  if(idx%(int)pow(2,n)==0){
    return 0;
  }
  n++;
  //cout << "n="<<n;
  idx=pow(2,n)-idx;
  //cout<<" idx="<<idx<<";";
  return !reverseEngineer(idx);
}

int main(){
#ifdef SAMPLE
  freopen("sample.in","r",stdin);
#endif
#ifdef SMALL
  freopen("A-small-attempt1.in","r",stdin);
  freopen("A-small.out","w",stdout);
#endif
#ifdef LARGE
  freopen("A-large.in","r",stdin);
  freopen("A-large.out","w",stdout);
#endif
  int N;
  cin >> N;
  rep(i,N){
    ll idx;
    cin>>idx;
    cout << "Case #" << i+1 << ": ";
    
    cout<<reverseEngineer(idx);
    cout<<endl;
  }
  return 0;
}