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


bool accept_hoja(){
    ll n,q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    //We will make a prefix sum array
    for(int i=1;i<n;i++)a[i]+=a[i-1];
    //a[j]-a[i-1] will give the sum in the range [j,i]
    for(int i=0;i<q;i++){
        ll l,r;
        cin>>l>>r;
        
        l--;//1 based indexing
        r--;
        if(l==0)cout<<a[r]<<endl;//0-1=-1(invalid index)
        else cout<<a[r]-a[l-1]<<endl;
        
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