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
//#define SAMPLE

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
#ifdef SAMPLE
  freopen("sample.in","r",stdin);
  freopen("sample.out","w",stdout);
#endif
#ifdef SMALL
  freopen("B-small-practice.in","r",stdin);
  freopen("B-small.out","w",stdout);
#endif
#ifdef LARGE
  freopen("B-large-practice.in","r",stdin);
  freopen("B-large.out","w",stdout);
#endif
  int N;
  cin >> N;
  rep(i,N){
    int edge,elem;
    string direct;
    cin>>edge;
    cin>>direct;
    cout << "Case #" << i+1 << ": "<<endl;
    vector<vector<int> > rawBoard,queBoard,midBoard;
    rep(ii,edge){
      vector<int> lineElem;
      rep(jj,edge){
        cin>>elem;
        lineElem.pb(elem);
      }
      rawBoard.pb(lineElem);
    }
    //create row queue to merge
    switch(direct.at(0)){
      case 'l':
      {
        rep(ii,edge){
          queBoard.pb(rawBoard[ii]);
        }
      }
      break;
      case 'r':
      {
        rep(ii,edge){
          vector<int> temp;
          rep(jj,edge){
            temp.pb(rawBoard[ii][edge-jj-1]);
          }
          queBoard.pb(temp);
        }
      }
      break;
      case 'u':
      {
        rep(ii,edge){
          vector<int> temp;
          rep(jj,edge){
            temp.pb(rawBoard[jj][ii]);
          }
          queBoard.pb(temp);
        }
      }
      break;
      case 'd':
      {
        rep(ii,edge){
          vector<int> temp;
          rep(jj,edge){
            temp.pb(rawBoard[edge-jj-1][ii]);
          }
          queBoard.pb(temp);
        }
      }
      break;
    }
    //merge
    rep(ii,edge){
      vector<int> queRow(edge,0);
      int base=queBoard[ii][0];
      int idx=0;
      rep2(jj,1,edge){
        if(queBoard[ii][jj]==0){
        }else if(base==0){
          base=queBoard[ii][jj];
        }else if(base!=queBoard[ii][jj]){
          queRow[idx]=base;
          idx++;
          base=queBoard[ii][jj];
        }else{
          queRow[idx]=base*2;
          idx++;
          base=0;
        }
        if(jj==edge-1){
          queRow[idx]=base;
        }
      }
      midBoard.pb(queRow);
    }
    switch(direct.at(0)){
      case 'l':
      {
        rep(ii,edge){
          cout<<midBoard[ii][0];
          rep2(jj,1,edge){
            cout<<" "<<midBoard[ii][jj];
          }
          cout<<endl;
        }
      }
      break;
      case 'r':
      {
        rep(ii,edge){
          cout<<midBoard[ii][edge-1];
          rep2(jj,1,edge){
            cout<<" "<<midBoard[ii][edge-jj-1];
          }
          cout<<endl;
        }
      }
      break;
      case 'u':
      {
        rep(ii,edge){
          cout<<midBoard[0][ii];
          rep2(jj,1,edge){
            cout<<" "<<midBoard[jj][ii];
          }
          cout<<endl;
        }
      }
      break;
      case 'd':
      {
        rep(ii,edge){
          cout<<midBoard[0][edge-ii-1];
          rep2(jj,1,edge){
            cout<<" "<<midBoard[jj][edge-ii-1];
          }
          cout<<endl;
        }
      }
      break;
    }
  }
  return 0;
}