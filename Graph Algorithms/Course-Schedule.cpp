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
    int indegree[n + 1] = {0};
    vector<vector<int>> vv(100001);

    forr(i,0,m) {
        cin >> x >> y;
        vv[x].pb(y);
        indegree[y]++;
    }
    
    map<int, set<int>> ind;
    unordered_map<int,int> deg;
    forr(i, 1, n + 1) {
        ind[indegree[i]].insert(i);
        deg[i] = indegree[i];
    }
    
    vector<int> ans;
    while(sz(ans) < n) {
        vector<pair<int, int>> ers, ins;
        if(sz(ind[0]) == 0) break;
        
        for(auto vbn : ind[0]) {
            ans.pb(vbn);
            ers.pb({0, vbn});
            for(int k : vv[vbn]) {
                ers.pb({deg[k], k});
                deg[k]--;
                ins.pb({deg[k], k});
            }
        }
        
        for(auto x : ers){
            ind[x.F].erase(x.S);
        }
        for(auto x : ins){
            ind[x.F].insert(x.S);
        }
    }
    
    if(sz(ans) < n) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    for(auto vbn : ans) {
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