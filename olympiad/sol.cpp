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
#define int long long
#define all(x) x.begin(),x.end()

template<typename T>
bool mxx(T &a,T b){if(b>a){a=b;return 1;}return 0;}
template<typename T>
bool mnn(T &a,T b){if(b<a){a=b;return 1;}return 0;}

const int mod=1e9+7;

set<vector<int> > s;

void build(){
    vector<int> tmp;
    tmp.pb(1);tmp.pb(2);tmp.pb(4);tmp.pb(5);
    s.in(tmp);
    tmp.clear();
    tmp.pb(2);tmp.pb(3);tmp.pb(5);tmp.pb(6);
    s.in(tmp);
    tmp.clear();
    tmp.pb(4);tmp.pb(5);tmp.pb(7);tmp.pb(8);
    s.in(tmp);
    tmp.clear();
    tmp.pb(5);tmp.pb(6);tmp.pb(8);tmp.pb(9);
    s.in(tmp);
    tmp.clear();
    tmp.pb(1);tmp.pb(2);
    s.in(tmp);
    tmp.clear();
    tmp.pb(1);tmp.pb(4);
    s.in(tmp);
    tmp.clear();
    tmp.pb(2);tmp.pb(3);
    s.in(tmp);
    tmp.clear();
    tmp.pb(2);tmp.pb(5);
    s.in(tmp);
    tmp.clear();
    tmp.pb(3);tmp.pb(6);
    s.in(tmp);
    tmp.clear();
    tmp.pb(4);tmp.pb(5);
    s.in(tmp);
    tmp.clear();
    tmp.pb(4);tmp.pb(7);
    s.in(tmp);
    tmp.clear();
    tmp.pb(5);tmp.pb(6);
    s.in(tmp);
    tmp.clear();
    tmp.pb(5);tmp.pb(8);
    s.in(tmp);
    tmp.clear();
    tmp.pb(6);tmp.pb(9);
    s.in(tmp);
    tmp.clear();
    tmp.pb(7);tmp.pb(8);
    s.in(tmp);
    tmp.clear();
    tmp.pb(8);tmp.pb(9);
    s.in(tmp);
    tmp.clear();
}

void go(){
    string str;
    cin>>str;
    int n=str.size();
    // cout<<str<<" sheesh\n";
    vector<int> dp(n+10,0),ll(n+10,0);
    dp[0]=1;
    for(int i=1; i<=n; i++){
        dp[i]=dp[i-1];
        vector<int> tmp;
        if(i>1){
            tmp.pb(str[i-1]-'0');
            tmp.pb(str[i-2]-'0');
            if(tmp[0]>tmp[1]) swap(tmp[0],tmp[1]);
            if(s.find(tmp)!=s.end()){
                dp[i]=(dp[i]+dp[i-2])%mod;
                ll[i]=1;
            }
            tmp.clear();
        }
        if(i>3){
            for(int j=i-4; j<i; j++){
                tmp.pb(str[j]-'0');
            }
            sort(all(tmp));
            if(s.find(tmp)!=s.end()){
                // cout<<"hheerre\n";
                int gg=23;
                if(ll[i-2]) gg--;
                if(ll[i-1]) gg--;
                if(ll[i]){
                    if(ll[i-2]) gg-=2;
                    else gg--;
                }
                dp[i]=(dp[i]+dp[i-4]*gg)%mod;
            }
        }
    }
    cout<<dp[n]<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    build();
    while(t--){
        go();
        // cout<<"loool1\n";
    }
    return 0;
}