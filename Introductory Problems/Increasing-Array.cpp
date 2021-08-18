/*
           ║ ║
     ╔╗ ╦╗ ║╔╝ ╦╔╦╗   ╔╗ ╦═╦═╗
     ╔╣ ║║ ╠╩╗ ║ ║    ╚╗ ║ ║ ║
     ╚╩ ╝╚ ╝ ╚ ╩ ╩ ══ ╚╝ ╝ ╝ ╝ ✌
 
          fall 7, stand 8...
*/
 
#include<bits/stdc++.h>
using namespace std;
 
#define F first
#define S second
#define elif else if
#define pb push_back
#define mp make_pair
#define int long long
#define ldd long double
#define vec_i vector<int>
#define pair_i pair<int,int>
#define sz(x) (int)(x.size())
#define vec_p vector<pair<int,int>>
#define vec_vec vector<vector<int>>
#define all(x) (x).begin(),(x).end()
 
#define forr(x,a,m) for(int x=a;x<m;x+=1)
#define debug(x) cout<<"~~"<<#x<<" => "<<x<<endl;
 
bool rev(int x, int y) {return x > y;}
void input_arr(int a[], int n) {forr(i, 0, n) cin>>a[i];}
void print_vec(vec_i &v) {for(auto i:v) cout<<i<<" "; cout<<endl;}
void print_arr(int a[],int n){forr(i,0,n)cout<<a[i]<<" ";cout<<endl;}
bool sortbysec(const pair_i &a,const pair_i &b) {return a.S < b.S;}
bool sortinrev(const pair_i &a,const pair_i &b){return(a.F>b.F);}
bool sortinrevbysec(const pair_i &a,const pair_i &b){return(a.S>b.S);}
 
template<typename...T>void input(T &...args) {((cin >> args), ...);}
template<typename...T>void print(T &&...args) {((cout << args << endl),...);}
template<typename...T>void deb(T &&...args) {cout<<"~~ ";((cout<<args<<" "),...);cout<<endl;}
 
// Playing Zone... ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
 
void stand8th(){
    int n; input(n);
    int a[n]; input_arr(a,n);
    int ans=0;
    forr(i,1,n){
        if(a[i]<a[i-1]){
            ans+=a[i-1]-a[i];
            a[i]=a[i-1];
        }
    }
    print(ans);
}
 
//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
 
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int tin = 1; //input(tin);
    while(tin--){
        stand8th();
    }
    return 0;
}