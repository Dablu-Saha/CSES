/*
Author : Dablu_saha
I can do it!!!
*/

//Link:https://cses.fi/problemset/task/1648

#ifdef Dablu
#include "pain.h"
#else
#include"bits/stdc++.h"
#endif
using namespace std;
void fastio() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
#define ll long long
#define lld long long double
#define int ll
#define endl "\n"
const ll INF=1e18;
ll mod=1e9+7;
//Segment Tree
int n;
vector<int> tree(1e6);

void build(vector<int> &a,int v,int tl,int tr){
    if(tl==tr)tree[v]=a[tl];
    else{
        int m=(tl+tr)/2;
        build(a,v*2,tl,m);
        build(a,v*2+1,m+1,tr);
        tree[v]=0;
    }

}

//Update
void update(int v,int tl,int tr,int l, int r,int x){
    if(l>r)return ;
    else if(tl==l && tr==r)tree[v]+=x;
    else{
        int m=(tl+tr)/2;
        update(v*2,tl,m,l,min(r,m),x);
        update(v*2+1,m+1,tr,max(l,m+1),r,x);
    }

}

//Query(get)
int get(int v,int tl,int tr,int pos){
    if(tl==tr)return tree[v];
    int m=(tl+tr)/2;
    if(pos<=m)return tree[v]+get(2*v,tl,m,pos);
    else return tree[v]+get(2*v+1,m+1,tr,pos);
}


bool accept_hoja(){
    ll n,q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    build(a,1,0,n-1);
    for(int i=0;i<q;i++){
        ll qt;
        cin>>qt;
        if(qt==1){
            ll a,b,u;
            cin>>a>>b>>u;
            update(1,0,n-1,a-1,b-1,u);
        }
        else{
            ll pos;
            cin>>pos;
            pos--;
            cout<<get(1,0,n-1,pos)<<endl;
        }
    }
    
//////////////////////////////////////
    return 0;
}
 
signed main() {
    fastio();
    int t = 1;
    // cin>>t;cin.ignore();
    for(int case_no=1;case_no<=t;case_no++) {
        //cout<<"Case #"<<case_no<<": ";
        
        bool ans = accept_hoja();
        //(ans) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
    }
}