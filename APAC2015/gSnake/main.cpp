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

int findNextLoc(int cur,int dir,int speed,int S,int C){
  int loc=cur+speed;
  int row1=cur/C;
  int row2=loc/C;
  switch(dir){
    //r, d, l, u
    case 0:
    {
      if(row1<row2){
        loc-=C;
      }
      return loc;
    }
    case 1:
    {
      if(row2>=S){
        loc%=C;
      }
      return loc;
    }
    case 2:
    {
      if(row2<row1||loc<0){
        loc+=C;
      }
      return loc;
    }
    default:
    {
      if(loc<0){
        loc+=S*C;
      }
      return loc;
    }
  }
}

const int gameTime=1e9;

int main(){
#ifdef SAMPLE
  freopen("sample.in","r",stdin);
  //freopen("sample.out","w",stdout);
#endif
#ifdef SMALL
  freopen("D-small-practice.in","r",stdin);
  freopen("D-small.out","w",stdout);
#endif
#ifdef LARGE
  freopen("D-large-practice.in","r",stdin);
  freopen("D-large.out","w",stdout);
#endif
  int Test;
  cin >> Test;
  vector<PII> actions;
  rep(i,Test){
    actions.clear();
    int S,R,C;
    cin >> S >> R >> C;
    //r, d, l, u
    int pdir[4]={1,C,-1,-C};
    int dir=0;
    vector<int> snake;
    vector<int> food;
    rep(ii,R){
      rep(jj,C){
        int idx=ii*C+jj;
        if(idx%2){
          food.pb(1);
        }else{
          food.pb(0);
        }
      }
    }
    snake.pb(0);
    cout << "Case #" << i+1 << ": ";
    rep(j,S){
      int t;
      char r;
      cin>>t>>r;
      int rot=(r=='R')?0:1;
      actions.pb(PII(t,rot));
    }
    int act=0;
    int ti=0;
    rep(j,gameTime){
      if(act<actions.size()){
        if(j==actions[act].first){       
          if(actions[act].second){
            dir=(dir+3)%4;
          }else{
            dir=(dir+1)%4;
          }
          act++;
        }
      }else{
        break;
      }
      ti++;
      int loc=findNextLoc(snake.back(),dir,pdir[dir],S,C);     
      if(!food[loc]){
        snake.erase(snake.begin());
        std::vector<int>::iterator it;
        // cout<<"Next location: "<<loc<<endl;
        // rep(ii,snake.size()){
        //   cout<<snake[ii]<<" ";
        // }
        // cout<<endl;
        it = find(snake.begin(), snake.end(), loc);
        if (it != snake.end()){
          snake.pb(loc);
          break;
        }
        snake.pb(loc);
      }else{
        snake.pb(loc);
        food[loc]=0;
      }
      //cout<<"Step"<<j+1<<": "<<endl;
      // rep(ii,R){
      //   rep(jj,C){
      //     int idx=ii*C+jj;
      //     if(food[idx]){
      //       cout<<1<<" ";
      //     }else{
      //       std::vector<int>::iterator it;
      //       it = find (snake.begin(), snake.end(), idx);
      //       if(it != snake.end()){
      //         cout<< "* ";
      //       }else{
      //         cout<< 0 << " ";
      //       }
      //     }
      //   }
      //   cout<<endl;
      //}
      //cout<<endl;
    }
    cout << snake.size() << " " << ti << endl;;
  }
  return 0;
}