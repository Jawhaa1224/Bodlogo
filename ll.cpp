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

int bb[101][101];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    map<string,int> mp;
    int n; cin>>n;
    int tt=0;
    vector<vector<int> > gg;
    vector<string> ggg;
    while(n--){
        string str,tmp;
        cin>>str;
        cin>>tmp;
        gg.pb(vector<int>());
        if(mp.find(str)!=mp.end()){
            gg.back().pb(-1);
        }
        else gg.back().pb(++tt),mp[str]=tt;
        while(1){
            cin>>tmp;
            if(tmp==";") break;
            if(gg.back()[0]==-1) continue;
            if(mp.find(tmp)==mp.end()){
                gg.back()[0]=-1;
                mp.erase(str);
                continue;
            }
            gg.back().pb(mp[tmp]);
        }
    }
    n=gg.size();
    for(int i=0; i<n; i++){
        if(gg[i][0]==-1){
            cout<<"no\n";
            continue;
        }
        int x=gg[i][0];
        vector<int> tmp(101,0);
        bool ans=1;
        for(int j=1; j<gg[i].size(); j++){
            int pr=gg[i][j];
            bb[x][pr]=1;
            for(int k=1; k<=100; k++){
                if(tmp[k] && bb[pr][k]) ans=0;
                tmp[k]=max(tmp[k],bb[pr][k]);
                bb[x][k]=max(bb[x][k],bb[pr][k]);
            }
        }
        if(ans) cout<<"ok\n";
        else{
            for(int k=1; k<=100; k++) bb[x][k]=0;
            cout<<"no\n";
        }
    }
    return 0;
}