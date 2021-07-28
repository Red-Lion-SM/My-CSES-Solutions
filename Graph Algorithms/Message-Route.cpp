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

int parent[100001];
vector<vector<int>> vv(100001);
vector<int> visited(100001, 0);

void bfs(int z) {
    queue<int> q;
    q.push(z);
    visited[z]++;
    while(sz(q) > 0) {
        int p = q.front();
        q.pop();
        for(int vbn : vv[p]) {
            if(visited[vbn] == 0) {
                visited[vbn]++;
                parent[vbn] = p;
                q.push(vbn);
            }
        }
    }
}

void solve() {
    int n, m, x, y; cin >> n >> m;
    forr(i,0,m) {
        cin >> x >> y;
        vv[x].pb(y), vv[y].pb(x);
    }
    bfs(1);
    if(visited[n] == 0) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    vector<int> ans;
    int z = n;
    while(z != 1) {
        ans.pb(z);
        z = parent[z];
    }
    ans.pb(1);
    reverse(all(ans));
    cout << sz(ans) << '\n';
    for(int vbn : ans) {
        cout << vbn << ' ';
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tin = 1; // cin >> tin;
    while (tin--) solve();
    return 0;
}