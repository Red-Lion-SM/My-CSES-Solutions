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

void solve() {
    int n, m, x, y; cin >> n >> m;
    vector<vector<int>> vv(n + 1);
    vector<int> visited(n + 1, 0); 
    vector<pair<int, int>> conn;
    forr(i,0,m) {
        cin >> x >> y;
        conn.pb({x, y});
        vv[x].pb(y), vv[y].pb(x);
    }
    int type[n + 1];
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(visited[i] == 0) {
            q.push(i);
            visited[i]++;
            type[i] = 1;
            while(!q.empty()) {
                int p = q.front();
                q.pop();
                for(int x : vv[p]) {
                    if(visited[x] == 0) {
                        visited[x]++;
                        type[x] = type[p] == 1 ? 2 : 1;
                        q.push(x);
                    }
                }
            }
        }
    }
    for(auto vbn : conn) {
        if(type[vbn.F] == type[vbn.S]) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << type[i] << ' ';
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tin = 1; // cin >> tin;
    while (tin--) solve();
    return 0;
}