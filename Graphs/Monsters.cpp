/*
Author : Dablu_saha
I can do it!!!
*/
Link:https://cses.fi/problemset/task/1194
 
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
 
vector<vector<pair<ll,ll>>> parent;
 
ll n,m;
bool isvalid(ll x,ll y){
    return x>=0 && y>=0 && x<n && y<m;
}
vector<vector<ll>> grid,grid_m,lvl_p,lvl_m;
vector<pair<ll,ll>> sources;
void fill(){
    for(int i=0;i<=1000;i++){
        vector<pair<ll,ll>> temp;
        vector<ll> temp1;
        for(int j=0;j<=1000;j++){
            temp.push_back({-1,-1});
            temp1.push_back(-1);
        }
        parent.push_back(temp);
        lvl_p.push_back(temp1);
        lvl_m.push_back(temp1);
    }
}
 
 
void bfs1(int x, int y){
    queue<pair<ll,ll>> q;
    grid[x][y]=1;
    q.push({x,y});
    parent[x][y]={-2,-2};
    lvl_p[x][y]=0;
    while(!q.empty()){
        pair<ll,ll> temp=q.front();
        q.pop();
        ll xx=temp.first,yy=temp.second;
        if(isvalid(xx-1,yy) && grid[xx-1][yy]==0){
            parent[xx-1][yy]={xx,yy};
            lvl_p[xx-1][yy]=lvl_p[xx][yy]+1;
            grid[xx-1][yy]=1;
            q.push({xx-1,yy});
        }
        if(isvalid(xx+1,yy) && grid[xx+1][yy]==0){
            parent[xx+1][yy]={xx,yy};
            lvl_p[xx+1][yy]=lvl_p[xx][yy]+1;
            grid[xx+1][yy]=1;
            q.push({xx+1,yy});
        }
        if(isvalid(xx,yy-1) && grid[xx][yy-1]==0){
            parent[xx][yy-1]={xx,yy};
            lvl_p[xx][yy-1]=lvl_p[xx][yy]+1;
            grid[xx][yy-1]=1;
            q.push({xx,yy-1});
        }
        if(isvalid(xx,yy+1) && grid[xx][yy+1]==0){
            parent[xx][yy+1]={xx,yy};
            lvl_p[xx][yy+1]=lvl_p[xx][yy]+1;
            grid[xx][yy+1]=1;
            q.push({xx,yy+1});
        }
 
    }
 
 
}
void bfs2(){
    queue<pair<ll,ll>> q;
    for(auto source:sources){
        grid_m[source.first][source.second]=1;
        lvl_m[source.first][source.second]=0;
        q.push(source);
    }
    while(!q.empty()){
        pair<ll,ll> temp=q.front();
        q.pop();
        ll xx=temp.first,yy=temp.second;
        if(isvalid(xx-1,yy) && grid_m[xx-1][yy]==0){
            lvl_m[xx-1][yy]=lvl_m[xx][yy]+1;
            grid_m[xx-1][yy]=1;
            q.push({xx-1,yy});
        }
        if(isvalid(xx+1,yy) && grid_m[xx+1][yy]==0){
            lvl_m[xx+1][yy]=lvl_m[xx][yy]+1;
            grid_m[xx+1][yy]=1;
            q.push({xx+1,yy});
        }
        if(isvalid(xx,yy-1) && grid_m[xx][yy-1]==0){
            lvl_m[xx][yy-1]=lvl_m[xx][yy]+1;
            grid_m[xx][yy-1]=1;
            q.push({xx,yy-1});
        }
        if(isvalid(xx,yy+1) && grid_m[xx][yy+1]==0){
            lvl_m[xx][yy+1]=lvl_m[xx][yy]+1;
            grid_m[xx][yy+1]=1;
            q.push({xx,yy+1});
        }
 
    }
}
 
 
bool accept_hoja(){
//////////////////////////////////////// 
    
    cin>>n>>m;
    fill();
    
    ll xs,ys,xe,ye;
    for(int i=0;i<n;i++){
        vector<ll> temp;
        for(int j=0;j<m;j++){
            char c;
            cin>>c;
            if(c=='#')temp.push_back(1);
            else temp.push_back(0);
            if(c=='A'){
                xs=i;
                ys=j;
                //sources.push_back({i,j});
            }
            if(c=='M'){
                sources.push_back({i,j});
            }
        }
        grid.push_back(temp);
    }
    grid_m=grid;
    
    bfs1(xs,ys);
    bfs2();
    // cout<<endl;
    // for(int i=0;i<4;i++){
    //     for(int j=0;j<4;j++){
    //         cout<<lvl_p[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    //  for(int i=0;i<4;i++){
    //     for(int j=0;j<4;j++){
    //         cout<<lvl_m[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    ll x=-1,y=-1;
    
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=m;j++){
            if(i==0 || j==0 || i==n-1 || j==m-1){
                if((lvl_p[i][j]<lvl_m[i][j] && lvl_p[i][j]!=-1)||(lvl_p[i][j]!=-1 && lvl_m[i][j]==-1)){
                    x=i;
                    y=j;
                    break;
                }
            }
        }
        if(x!=-1 && y!=-1)break;
    }
    if(x==-1 && y==-1){
        cout<<"NO"<<endl;
        return 0;
    }
   // cout<<x<<" "<<y<<endl;
    xe=x;
    ye=y;
    string ans="";
    ll cx=xe,cy=ye,px=parent[xe][ye].first,py=parent[xe][ye].second;
    //cout<<px<<" "<<py<<endl;
    while(px!=-2 && py!=-2){
        if(px<cx)ans+='D';
        else if(px>cx)ans+='U';
        else if(py>cy)ans+='L';
        else if(py<cy)ans+='R';
        cx=px;
        cy=py;
        px=parent[cx][cy].first;
        py=parent[cx][cy].second;
 
    }
    reverse(ans.begin(),ans.end());
    cout<<"YES"<<endl;
    cout<<ans.size()<<endl;
    cout<<ans<<endl;
    
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
