Link:https://cses.fi/problemset/task/1668

#include"bits/stdc++.h"
#include <numeric>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
using namespace __gnu_pbds;
void fastio() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
 
const int mod = 1000000007;
const double PI = 3.141592653589793238;
const long long int INF=1e18;
const int MX = 1e6 + 1;
#define int long long
#define ll int
#define lld double
#define cint(n) ll n;cin>>n;cin.ignore();
#define ailoop(a,n) for(int i=0;i<n;i++) {cint(x);a.pb(x);}
#define loop(i,a,b) for(int i=a;i<b;i++)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define vi vector<ll>
#define vs vector<string>
#define vpi vector<pair<ll,ll>>
#define pii pair<int,int>
#define vvi vector<vi>
#define ff first
#define ss second
#define pb push_back
#define ppb pop_back
#define sum(a,s) loop(i,0,a.size()){s+=a[i];}
// #define endl "\n"
#define str string
#define input(s) str s;cin>>s;
#define mop(a, op, b) ((a%mod op b%mod) + mod)%mod
//#define ceil(a,b) (a/b+!!(a%b))
 
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pmset;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pset;
#define fbo find_by_order //returns an iterator to the element at the given position Syntax:   *(s.fbo(<index>))
#define ook order_of_key //returns the positons the element equalto or just greater than the given element Syntax: s.ook(<element>)
 
 
 
 
template<typename T> using indexed_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>; // find_by_order, order_of_key
template<typename T1, typename T2> using indexed_map = tree<T1,T2,less<T1>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T> ostream& operator<<(ostream& out,const vector<T>& v){out<<'[';for(auto i=v.begin();i!=v.end();i++) out<<(i!=v.begin()?",":"")<<(*i);return(out<<']');}
template<typename T> ostream& operator<<(ostream& out,const set<T>& s){out<<'[';for(auto i=s.begin();i!=s.end();i++) out<<(i!=s.begin()?",":"")<<(*i);return(out<<']');}
template<typename T> ostream& operator<<(ostream& out,const unordered_set<T>& s){out<<endl<<'[';for(auto i=s.begin();i!=s.end();i++) out<<(i!=s.begin()?",":"")<<(*i);return(out<<']');}
template<typename T1,typename T2> ostream& operator<<(ostream& out,const pair<T1,T2> &p){return(out<<'('<< p.ff<<","<<p.ss<<')');}
template<typename T1,typename T2> ostream& operator<<(ostream& out,const map<T1,T2> &m){out<<'{'<<endl;for(auto x:m) out<<"  "<<x.ff<<" -> "<<x.ss<<endl;return(out<<'}');}
template<typename T1,typename T2> ostream& operator<<(ostream& out,const unordered_map<T1,T2> &m){out<<'{'<<endl;for(auto x:m) out<<"  "<<x.ff<<" -> "<<x.ss<<endl;return(out<<'}');}
 
 
 
int mpow(int a,int b) {int ans=1;while(b){if(b&1) ans=(ans*a)%mod;a=(a*a)%mod;b>>=1;}return ans;}
vi sieve(int n=MX){vi P;vector<bool> N(n,1);P.pb(2);for(int i=4;i<n;i+=2) N[i]=0;for(int i=3;i<n;i+=2){if(N[i]){P.pb(i);for(int j=i*i;j<n;j+=i) N[j]=0;}}return P;}vi primes;
int power(int a,int b) {int ans=1;while(b){if(b&1) ans*=a;a=(a*a);b>>=1;}return ans;}
//<--------------------MY FUNCTIONS------------------->
 
string d2b(int n){
    int binaryNum[64];
    str s="";
    bool start=0;
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--){
        if(start) s+=(to_string(binaryNum[j]));
        else if(binaryNum[j]==1){
           s+=(to_string(binaryNum[j]));
            start=1;
        }
    }
    return s;
}
bool ifpow2(int x)
{
  return x && (!(x&(x-1)));
}
bool isprime(int n){
    if (n <= 1)
        return false;
    for (int i = 2; i*i <=(n); i++)
        if (n % i == 0)
            return false;
    return true;
}
int binsearch(vi &arr, int l, int r, int x){
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
unsigned nearest_pow2(unsigned x){
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return x ^ (x >> 1);
}
unsigned int onescomplement(unsigned int n){   int number_of_bits = floor(log2(n))+1;
   return ((1 << number_of_bits) - 1) ^ n;
}
 
//<--------------------ENDS HERE----------------------->
 
 
//<--------------------SEGMENT TREE----------------------->
int segtree[4*6+1];
 
pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first) 
        return a;
    if (b.first > a.first)
        return b;
    return make_pair(a.first, a.second + b.second);
}
 
void segbuild(int a[], int v, int tl, int tr) {//a is the given array,v=1,tl=0,tr=a.size()-1
    if (tl == tr) {
        segtree[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        segbuild(a, v*2, tl, tm);
        segbuild(a, v*2+1, tm+1, tr);
        segtree[v] = __gcd(segtree[v*2],segtree[v*2+1]);
    }
}
 
 
int seggcd(int v, int tl, int tr, int l, int r) {//v=1,tl=0,tr=n-1,l=l,r=r
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return segtree[v];
    }
    int tm = (tl + tr) / 2;
    return __gcd(seggcd(v*2, tl, tm, l, min(r, tm)),seggcd(v*2+1, tm+1, tr, max(l, tm+1), r));
}
 
void segupdate(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        segtree[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            segupdate(v*2, tl, tm, pos, new_val);
        else
            segupdate(v*2+1, tm+1, tr, pos, new_val);
        segtree[v] = __gcd(segtree[v*2] , segtree[v*2+1]);
    }
}
 
//<--------------------SEGMENT TREE ENDS----------------------->
//<--------------------DFS----------------------->
vi g[600001];
vi visited(600001,-1);
void dfs(int v,int val){
    if(visited[v]!=-1)return;
    visited[v]=val;
    for(auto next:g[v]){
        dfs(next,val^1);
    }
 
}
//<--------------------DFS ENDS----------------------->
bool comp(const pair<char,vi> &a,const pair<char,vi> &b)
{  return (a.ss.size()>b.ss.size());
}
bool comp1(const vi &a,const vi &b)
{    return a[1]>b[1];
}
 
/* Author: Peaky_fookin_bLInder*/
//<----------check some extra test cases----------->
 
int get(ll c){
    //if(l==r)return 0;
    cout<<"+ "<<c<<endl;
    cint(x)
    return x;
}
 
bool accept_hoja(){
//////////////////////////////////////// 
    ll n,m;
    cin>>n>>m;
    vpi temp;
    loop(i,0,m){
        ll x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
        temp.pb({x,y});
    }
    loop(i,1,n+1){
        if(visited[i]==-1)dfs(i,1);
    }
    bool y=1;
    loop(i,0,m){
        if(visited[temp[i].ss]==visited[temp[i].ff]){
            y=0;
            break;
        }
 
    }
    if(y==0){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    loop(i,1,n+1){
        if(visited[i]==1)cout<<1<<" ";
        else cout<<2<<" ";
 
    }
    cout<<endl;
 
 
 
 
 
 
///////////////////////////////////////
    return 0;
}
 
 
signed main() {
    fastio();
    int t = 1;
    
    //cin>>t;cin.ignore();
    //primes = sieve();
    for(int caseno=1;caseno<=t;caseno++) {
        //cout<<"Case #"<<caseno<<": ";
        bool ans = accept_hoja();
        //(ans) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
    }
}
