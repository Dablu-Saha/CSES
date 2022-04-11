/*
Author : Dablu_saha
I can do it!!!
*/
Link:https://cses.fi/problemset/task/1669
 
#include"bits/stdc++.h"
using namespace std;
void fastio() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
#define ll long long
#define int ll
#define endl "\n"
 
template<typename T> ostream& operator<<(ostream& out,const vector<T>& v){out<<'[';for(auto i=v.begin();i!=v.end();i++) out<<(i!=v.begin()?",":"")<<(*i);return(out<<']');}
template<typename T> ostream& operator<<(ostream& out,const set<T>& s){out<<'[';for(auto i=s.begin();i!=s.end();i++) out<<(i!=s.begin()?",":"")<<(*i);return(out<<']');}
template<typename T> ostream& operator<<(ostream& out,const unordered_set<T>& s){out<<endl<<'[';for(auto i=s.begin();i!=s.end();i++) out<<(i!=s.begin()?",":"")<<(*i);return(out<<']');}
template<typename T1,typename T2> ostream& operator<<(ostream& out,const pair<T1,T2> &p){return(out<<'('<< p.first<<","<<p.second<<')');}
template<typename T1,typename T2> ostream& operator<<(ostream& out,const map<T1,T2> &m){out<<'{'<<endl;for(auto x:m) out<<"  "<<x.first<<" -> "<<x.second<<endl;return(out<<'}');}
template<typename T1,typename T2> ostream& operator<<(ostream& out,const unordered_map<T1,T2> &m){out<<'{'<<endl;for(auto x:m) out<<"  "<<x.first<<" -> "<<x.second<<endl;return(out<<'}');}
 
vector<int> parent(100001,0);
vector<int> g[100001];
vector<int> visited(100001,0);
ll x=-1,y=-1;
void dfs(int v){
    parent[v]=-1;
    visited[v]=1;
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        ll c=q.front();
        q.pop();
        for(auto z:g[c]){
            if(visited[z] && parent[c]!=z ){
                x=z;
                y=c;
                //cout<<c<<endl;
                return;
            }
            else if(visited[z])continue;
            else{
                visited[z]=1;
                parent[z]=c;
                q.push(z);
            }
        }
 
    }
}
 
 
bool accept_hoja(){
//////////////////////////////////////// 
    ll n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(visited[i]==0)dfs(i);
        if(x!=-1 && y!=-1)break;
    }
    
    if(x==-1){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    //cout<<x<<" "<<y<<endl;
    vector<ll> v1,v2;
    while(x!=-1){
        v1.push_back(x);
        x=parent[x];
    }
    while(y!=-1){
        v2.push_back(y);
        y=parent[y];
    }
    map<int,int> mp;
    for(int i=0;i<v1.size();i++){
        mp[v1[i]]++;
    }
    ll com=-1;
    vector<ll> ans1,ans2;
    for(int i=0;i<v2.size();i++){
        if(mp[v2[i]]==0)ans1.push_back(v2[i]);
        else{
            ans1.push_back(v2[i]);
            com=v2[i];
            break;
        }
    }
    for(int i=0;i<v1.size();i++){
        if(v1[i]!=com)ans2.push_back(v1[i]);
        else break;
 
    }
    reverse(ans2.begin(),ans2.end());
    cout<<ans1.size()+ans2.size()+1<<endl;
    for(auto x:ans1)cout<<x<<" ";
    for(auto x:ans2)cout<<x<<" ";
    cout<<ans1[0];
    cout<<endl;
 
 
    //cout<<v1<<v2<<endl;
    
///////////////////////////////////////
    return 0;
}
 
signed main() {
    fastio();
    int t = 1;
    //cin>>t;cin.ignore();
    for(int case_no=1;case_no<=t;case_no++) {
        //cout<<"Case #"<<case_no<<": ";
        bool ans = accept_hoja();
        //(ans) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
    }
}
