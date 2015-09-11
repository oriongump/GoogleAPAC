#include <string>
#include <vector>
#include <stdio.h>
#include <cmath>
#include <map>
#include <iostream>
#include <sstream>
#include <array>

using namespace std;

#define rep(i,m) for(int i=0;i<(int) (m);i++)
#define rep2(i,n,m) for(int i=n;i<(int) (m);i++)
#define pb push_back

typedef stringstream ss;

#define SMALL
//#define LARGE

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
  std::vector<std::vector <int> > digit={
  {1,1,1,1,0,1,1},
  {1,1,1,1,1,1,1},
  {1,1,1,0,0,0,0},
  {1,0,1,1,1,1,1},
  {1,0,1,1,0,1,1},
  {0,1,1,0,0,1,1},
  {1,1,1,1,0,0,1},
  {1,1,0,1,1,0,1},
  {0,1,1,0,0,0,0},
  {1,1,1,1,1,1,0},
  };
  int N;
  cin >> N;
  string s; 
  getline(cin,s);
  rep(i,N){
    int sum;
    cout << "Case #" << i+1 << ": ";
    getline(cin,s);
    ss sStream(s);
    ss bStream(s);
    int n;
    //char c;
    sStream >> n;
    bStream >> n;
    bool candi[10]={1,1,1,1,1,1,1,1,1,1};
    int work[7]={0};
    int broken[7]={0};
    rep(ii,n){
      string segment;
      bStream >> segment;
      rep(k,7){
        int sig=segment.at(k)-'0';
        if(sig>0){
          work[k]=1;
        }
      }
    }
    rep(ii,n){
      sum=0;
      bool temp[10];
      bool cur[10]={0};
      string segment;
      sStream >> segment;
      //cout<< segment << " ";
      // rep(k,7){
      //   int sig=segment.at(k)-'0';
      //   if(sig>0){
      //     work[k]=1;
      //   }
      // }
      rep(j,10){
        bool isValid=true;
        rep(k,7){
          int sig=segment.at(k)-'0';
          if(((digit[j][k]-sig)<0)||(work[k]*((sig-digit[j][k])<0))){
            cout<<9-j <<" at " << k << " " << (digit[j][k]-sig<0) << " | " << (work[k]*(sig-digit[j][k]<0)) << "! ";
            isValid=false;
            break;
          }
        }
        temp[j]=isValid;
        if(temp[j]&&candi[j]){
          cur[(j+1)%10]=true;
          //cout<<j<<" ";
          sum++;
        }
      }
      //cout<<sum <<"; ";
      if(sum==0){
        cout<<"ERROR!";
        break;
      }else{
        rep(j,10){
          candi[j]=cur[j];
        }
      }   
    }
    
    if(sum==1){
      int idx,pidx;
      rep(j,10){
        if(candi[j]){
          idx=j;
          pidx=(idx+9)%10;
          break;
        }
      }
      rep(ii,N){
        rep(k,7){
          if(digit[pidx][k]&&!work[k]){
            broken[k]=1;
          }
        }
        pidx=(pidx+9)%10;
      }
      rep(jj,7){
        cout<<digit[idx][jj]*!broken[jj];
      }    
    }else if(sum>1){
      cout<<"ERROR!";
    }
    cout<<endl;
  }
  return 0;
}