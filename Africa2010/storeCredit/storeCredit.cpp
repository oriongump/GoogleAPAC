#include <string>
#include <vector>
#include <stdio.h>
#include <cmath>
#include <map>
#include <iostream>

using namespace std;

#define rep(i,m) for(int i=0;i<(int) (m);i++)
#define rep2(i,n,m) for(int i=n;i<(int) (m);i++)
#define pb push_back

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
  freopen("A-small-practice.in","r",stdin);
  freopen("A-small.out","w",stdout);
#endif
#ifdef LARGE
  freopen("A-large-practice.in","r",stdin);
  freopen("A-large.out","w",stdout);
#endif
  int c,N;
  cin >> N;
  rep(i,N){
    int I;
    cin>>c>>I;
    vector<int> L;
    //cout << "Price: " << c << " " << I;
    rep(j,I){
      int price;
      cin>>price;
      L.pb(price);
    }
    //cout << endl << L.size() << endl;
    int a,b;
    a=0;
    b=L.size()-1;
    //quickSort(L,a,b+1);
    // cout<<"Sorted price: ";
    // for(auto e: L){
    //   cout<< " "<< e;
    // }
    // cout<<endl;
    cout << "Case #" << i+1 << ": ";
    // rep(j,L.size()-1){
    //   if(L[b]>c){
    //     b--;
    //   }else{
    //     break;
    //   }
    // }
    // findBags(a,b,c,L);
    bool isFound=false;
    rep(ii,L.size()-1){
      int jj=ii+1;
      for(;jj<L.size();jj++){
        if((L[ii]+L[jj])==c){
          a=ii;
          b=jj;
          isFound=true;
          break;
        }
      }
      if(isFound){
        break;
      }
    }
    cout << a+1 << " "<< b+1 << endl; 
  }
  return 0;
}