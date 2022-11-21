#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
using namespace std;

#define ff first
#define ss second
#define pb push_back
#define in insert
#define eb emplace_back
// #define int long long
#define all(x) x.begin(),x.end()

template<typename T>
bool mxx(T &a,T b){if(b>a){a=b;return 1;}return 0;}
template<typename T>
bool mnn(T &a,T b){if(b<a){a=b;return 1;}return 0;}

const int mxn=1e4+10;

vector<int> g[mxn],ll[mxn];

int vis[mxn];
int is[mxn];
int kk[mxn];
int sz[mxn];

int tt;

void ddf(int to,int fr){
    vis[to]=1;
    for(int i=0; i<g[to].size(); i++){
        int x=g[to][i];
        if(x==fr) continue;
        if(vis[x]){
            if(kk[to]==0){
                kk[x]=1;
                is[to]=++tt;
                ll[is[to]].pb(to);
            }
        }
        else{
            ddf(x,to);
            if(is[x] && kk[x]==0){
                is[to]=is[x];
                ll[is[to]].pb(to);
            }
        }

    }
}

int dfs(int to,int fr){
    int ret=0;
    if(is[to]==0){
        for(int i=0; i<g[to].size(); i++){
            int x=g[to][i];
            if(x==fr) continue;
            mxx(ret,dfs(x,to)+1);
        }
    }
    else{
        int l=0;
        for(int i=0; i<ll[is[to]].size(); i++){
            int tmp=ll[is[to]][i];
            for(int j=0; j<g[tmp].size(); j++){
                int x=g[tmp][j];
                if(is[x]==is[to]) continue;
                if(x==fr) continue;
                mxx(ret,max(l,sz[is[to]]-l)+dfs(x,tmp));
                l++;
            }
        }
    }
    return ret;
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    ddf(1,0);
    for(int i=1; i<=tt; i++){
        sz[i]=ll[i].size();
        reverse(all(ll[i]));
        // for(int j=0; j<ll[i].size(); j++){
            // cout<<ll[i][j]<<' ';
        // }
        // cout<<'\n';
    }
    // cout<<tt<<'\n';
    cout<<dfs(1,0)<<'\n';
    return 0;
}