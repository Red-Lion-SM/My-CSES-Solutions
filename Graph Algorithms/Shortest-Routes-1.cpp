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

vector<vector<pair<int, int>>> vv(100001);
int dist[100001], x, y, w, n, m;

void djkistra() {
    set<pair<int, int>> st;
    st.insert({0, 1});
    dist[1] = 0;
    while(!st.empty()) {
        int p = (*st.begin()).S;
        st.erase(st.begin());
        for(auto vbn : vv[p]) {
            if(dist[vbn.F] >= vbn.S + dist[p]) {
                st.erase({dist[vbn.F], vbn.F});
                dist[vbn.F] = vbn.S + dist[p];
                st.insert({dist[vbn.F], vbn.F});   
            }
        }
    }
    forr(i,1,n + 1) {
        cout << dist[i] << ' ';
    }
    cout << '\n';
}

void solve() {
    cin >> n >> m;
    forr(i,0,m) {
        cin >> x >> y >> w;
        vv[x].pb({y, w}), vv[y].pb({y, x});
    }
    int inf = 1e15;
    forr(i, 1, n+1) dist[i] = inf;
    djkistra();
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tin = 1; // cin >> tin;
    while (tin--) solve();
    return 0;
}