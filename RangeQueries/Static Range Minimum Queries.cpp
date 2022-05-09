/*
Author : Dablu_saha
I can do it!!!
*/
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

void build(vector<int> &a,int v,int l,int r){
    if(l==r)tree[v]=a[l];
    else{
        int mid=(l+r)/2;
        build(a,2*v,l,mid);
        build(a,2*v+1,mid+1,r);
        tree[v]=min(tree[v*2],tree[v*2+1]);
    }
}

//For Query
int query(int v,int tl,int tr,int l,int r){
    if(l>r)return 1e18;
    if(tl==l && tr==r)return tree[v];
    int m=(tl+tr)/2;
    return min(query(v*2,tl,m,l,min(r,m)),query(v*2+1,m+1,tr,max(l,m+1),r));
}

bool accept_hoja(){
    ll n,q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    build(a,1,0,n-1);

    for(int i=0;i<q;i++){
        ll x,y;
        cin>>x>>y;
        x--;
        y--;
        cout<<query(1,0,n-1,x,y)<<endl;
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