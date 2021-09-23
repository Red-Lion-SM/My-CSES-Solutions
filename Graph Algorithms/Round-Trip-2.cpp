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
const int mod = 1000000007, N = 100001;

vector<vector<int>> vv(N);
vector<int> visited(N, 0), stk(N, 0), par(N, -1);

void dfs(int z, int p = -1) {
    visited[z]++;
    stk[z]++;
    par[z] = p;
    for(auto vbn : vv[z]) {
        if(visited[vbn] == 0) {
            dfs(vbn, z);
        }
        if(stk[vbn] == 1) {
            int j = z;
            vec_i path = {z};
            while(j != vbn) {
                j = par[j];
                path.pb(j);
            }
            reverse(all(path));
            cout << (int)path.size() + 1 << '\n';
            cout << path.back() << ' ';
            for(auto c : path) {
                cout << c << ' ';
            }
            cout << '\n';
            exit(0);
        }
    }
    stk[z]--;
}

void solve() {
    int n, m, x, y; cin >> n >> m;
    forr(i,0,m) {
        cin >> x >> y;
        vv[x].pb(y);
    }
    forr(i,1,n + 1) {
        if(visited[i] == 0) {
            dfs(i);
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