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
  int N;
  cin >> N;
  string s;
  int key[9]={0,3,6,9,12,15,19,22,26};
  getline(cin,s);
  rep(i,N){
    cout << "Case #" << i+1 << ": ";
    getline(cin,s);
    // ss sStream(s);
    char c;
    int prev,cur;
    prev=-1;
    //while(sStream>>c){
    rep(ii,s.size()){
      c=s.at(ii);
      //cout<<c;
      if(c==' '){
        cur=0;
        if(cur==prev){
          cout<<" ";
        }
        prev=cur;
        cout<<cur;
      }else{
        int n=(int)(c-'a');
        rep(j,9){
          if(n<key[j]){
            cur=j+1;
            if(cur==prev){
              cout<<" ";
            }
            cout<<cur;
            rep(k,n-key[j-1]){
              cout<<cur;
            }
            prev=cur;
            break;
          }
        }
      }
    }
    cout<<endl;
  }
  return 0;
}