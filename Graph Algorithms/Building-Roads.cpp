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

void dfs(int z) {
    visited[z]++;
    for(int vbn : vv[z]) {
        if(visited[vbn] == 0)
            dfs(vbn);
    }
}

void solve() {
    int n, m, x, y; cin >> n >> m;
    forr(i,0,m) {
        cin >> x >> y;
        vv[x].pb(y), vv[y].pb(x);
    }
    vector<int>prnts;
    forr(i, 1, n + 1) {
        if(visited[i] == 0) {
            prnts.pb(i);
            dfs(i);
        }
    }
    cout << sz(prnts) - 1 << '\n';
    for(int i = 1; i < sz(prnts); i++) {
        cout << prnts[i] << ' ' << prnts[i - 1] << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tin = 1; // cin >> tin;
    while (tin--) solve();
    return 0;
}