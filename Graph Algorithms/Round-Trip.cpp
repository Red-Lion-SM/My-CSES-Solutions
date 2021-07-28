// The ones who fear failure are those who have never tasted it..

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back
#define int long long
#define vec_i vector<int>
#define sz(x) (int)(x.size())
#define all(x) (x).begin(),(x).end()
#define forr(x,a,m) for(int x=a;x<m;x+=1)
const int mod = 1000000007;

vector<vector<int>> vv(100001);
vector<int> visited(100001, 0);
int par[100001];

void dfs(int z, int p) {
    visited[z]++;
    par[z] = p;
    for(auto vbn : vv[z]) {
        if(visited[vbn] == 0) {
            dfs(vbn, z);
        }
        else if(vbn != p){
            vector<int> path1, path2;
            unordered_map<int, int> mpp;
            int x = vbn, j = 0;
            while(x != -1) {
                mpp[x] = j++;
                path1.pb(x);
                x = par[x];
            }
            x = z;
            int fl = 0, ind = -1;
            while(x != -1) {
                if(mpp.count(x)) {ind = mpp[x]; fl++; break;}
                path2.pb(x);
                x = par[x];
            }
            for(int i = ind; i >= 0; i--) {
                path2.pb(path1[i]);
            }
            path2.pb(path2[0]);
            cout << sz(path2) << '\n';
            for(int vbn : path2) {
                cout << vbn << ' ';
            }
            cout << '\n';
            exit(0);
        }
    }
}

void solve() {
    int n, m, x, y; cin >> n >> m;
    forr(i,0,m) {
        cin >> x >> y;
        vv[x].pb(y), vv[y].pb(x);
    }
    for(int i = 1; i <= n; i++) {
        if(visited[i] == 0) {
            dfs(i, -1);
        }
    }
    cout << "IMPOSSIBLE\n";
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tin = 1; // cin >> tin;
    while (tin--) solve();
    return 0;
}