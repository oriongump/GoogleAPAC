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

//#define SMALL
#define LARGE

int main(){
#ifdef SMALL
  freopen("C-small-practice.in","r",stdin);
  freopen("C-small.out","w",stdout);
#endif
#ifdef LARGE
  freopen("C-large-practice.in","r",stdin);
  freopen("C-large.out","w",stdout);
#endif
  int N;
  cin >> N;
  string s;
  getline(cin,s);
  rep(i,N){
    cout << "Case #" << i+1 << ": ";
    getline(cin,s);
    ss sStream(s);
    cout<<endl;
  }
  return 0;
}