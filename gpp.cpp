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
    while(n--){
        string str,tmp;
        cin>>str;
        cin>>tmp;
        vector<string> ggg;
        bool ans=1;
        while(1){
            cin>>tmp;
            if(tmp==";") break;
            if(mp.find(tmp)==mp.end()){
                ans=0;
            }
            ggg.pb(tmp);
        }
        if(mp.find(str)!=mp.end()){
            ans=0;
        }
        if(ans==0){
            gg.pb(vector<int>());
            gg.back().pb(-1);
        }
        else{
            gg.pb(vector<int>());
            gg.back().pb(++tt);
            mp[str]=tt;
            for(int i=0; i<ggg.size(); i++){
                gg.back().pb(mp[ggg[i]]);
            }
        }
    }
    for(int i=0; i<gg.size(); i++){
        vector<int> &a=gg[i];
        int x=a[0];
        if(x==-1){
            cout<<"no\n";
            continue;
        }
        bool ans=1;
        n=a.size();
        vector<int> tmp(101,0);
        for(int j=1; j<n; j++){
            int pr=a[j];
            bb[x][pr]=1;
            for(int k=1; k<=100; k++){
                if(tmp[k] && bb[pr][k]) ans=0;
                else if(tmp[k] || bb[pr][k]) tmp[k]=1;
            }
        }
        if(ans) cout<<"ok\n";
        else{
            cout<<"no\n";
            for(int j=1; j<=100; j++) bb[x][j]=0;
        }
    }
    return 0;
}