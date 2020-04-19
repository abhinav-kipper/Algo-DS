//EXPOGO Solved using dfs as well as bfs partial
#include<iostream>
#include<math.h>
#include<climits>
#include<queue>
#define ll long long
#define limit 10000
using namespace std;
ll mlen=LLONG_MAX;
string fans="IMPOSSIBLE";
ll fx=0, fy=0;
// void rec(ll x,ll y,ll i, string ans,ll len){
   
//     if (x<(-limit) || y<(-limit) || x>limit || y>limit) return;
//     if (x==fx && y==fy){
//       // if (fx==-2 && fy==-3)
//          //cout<<x<<" "<<y<<" "<<ans<<endl;
//         if (mlen>len){
//             fans=ans;
//             mlen=len;
//         }
//         return;
//     }
//     rec(x+pow(2,i-1),y,i+1,ans+'E',len+1);
//     rec(x-pow(2,i-1),y,i+1,ans+'W',len+1);
//     rec(x,y+pow(2,i-1),i+1,ans+'N',len+1);
//     rec(x,y-pow(2,i-1),i+1,ans+'S',len+1);
// }
int main(){
    int t,i=1;
    cin>>t;
    while (i<=t){
       
        cin>>fx>>fy;
        ll len=0;
        //rec(0,0,1,ans,len);
        queue<pair<string,pair<ll,ll>>> q;
        q.push(make_pair("",make_pair(0,0)));
        ll level=0;
        while (!q.empty()){
            level++;
             ll move = pow(2,level-1);
            int size=q.size();
            for (int i=0;i<size;i++){
                 pair<string,pair<ll,ll>> cur=q.front();
                 ll x=cur.second.first,y=cur.second.second;
                 string ans=cur.first;
                 if (x==fx && y==fy){
                     if (mlen>level){
                         mlen=level;
                        fans=ans;
                     }
                 }
                 q.pop();
                if (x+move<limit) q.push(make_pair(ans+"E",make_pair(x+move,y)));
                if (x-move>(-limit)) q.push(make_pair(ans+"W",make_pair(x-move,y)));
                if (y+move<limit) q.push(make_pair(ans+"N",make_pair(x,y+move)));
                if (y-move>(-limit)) q.push(make_pair(ans+"S",make_pair(x,y-move)));
            }
         
        }
        cout<<"Case #"<<i<<": "<<fans<<endl;
        fans="IMPOSSIBLE";
        mlen=LLONG_MAX;
        i++;
    }
}
