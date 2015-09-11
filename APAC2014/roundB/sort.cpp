#include <string>
#include <vector>
#include <stdio.h>
#include <cmath>
#include <map>
#include <iostream>
#include <sstream>

using namespace std;

#define rep(i,m) for(int i=0;i<(int) (m);i++)
#define rep2(i,n,m) for(int i=n;i<(int) (m);i++)
#define pb push_back

typedef stringstream ss;

//#define SMALL
#define LARGE

void findBags(int &a, int &b, int c, vector<int> &L){
  if(L[a]+L[b]>c){
    b--;
    findBags(a,b,c,L);
  }else if(L[a]+L[b]<c){
    a++;
    findBags(a,b,c,L);
  }
}

int partition(vector<int>& A, int p, int q){
  int x=A[p];
  int i=p;
  rep2(j,p+1,q){
    if(A[j]<x){
      i++;
      swap(A[i],A[j]);
    }
  }
  swap(A[i],A[p]);
  return i;
}

void quickSort(vector<int>& A, int p, int q){
  int r;
  if(p<q){
    r=partition(A,p,q);
    quickSort(A,p,r);
    quickSort(A,r+1,q);
  }
}

int main(){
#ifdef SMALL
  freopen("C-small-practice.in","r",stdin);
  freopen("C-small.out","w",stdout);
#endif
#ifdef LARGE
  freopen("C-large-practice.in","r",stdin);
  freopen("C-large.out","w",stdout);
#endif
  vector<string> s={"abc","def","acd","dfe"};
  vector<int> key={0,3,6,9,12,15,19,22,26};
  vector<pair<int,int> > test={pair<int,int>(2,1),pair<int,int>(5,2),pair<int,int>(1,3),pair<int,int>(1,1)};
  sort(key.begin(),key.end(),greater<int>());
  sort(s.begin(),s.end(),less<string>());
  sort(test.begin(),test.end(),less<pair<int,int> >());
  for(auto e:s){
    cout<<e<<endl;
  }
  cout<<endl;
  for(auto i:key){
    cout<<i<<endl;
  }
  for(auto i:test){
    cout<<i.first<<" "<<i.second<<endl;
  }
  return 0;
}