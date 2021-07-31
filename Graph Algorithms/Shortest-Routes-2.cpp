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
const int mod = 1000000007, inf = 1e15;

int dist[501][501], n, m, q, x, y, w;

void floyd_warshall() {
    forr(k,0,n){
        forr(i,0,n){
            forr(j,0,n){
                if(dist[i][k] < inf && dist[k][j] < inf)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

void solve() {
    cin >> n >> m >> q;
    forr(i,0,n) forr(j,0,n) dist[i][j] = inf;
    forr(i,0,n) dist[i][i] = 0;
    forr(i,0,m) {
        cin >> x >> y >> w;
        dist[x - 1][y - 1] = min(dist[x -1][y - 1], w);
        dist[y - 1][x - 1] = min(dist[y -1][x - 1], w);
    }
    floyd_warshall();
    forr(i,0,q) {
        cin >> x >> y;
        if(dist[x - 1][y - 1] == inf) dist[x - 1][y - 1] = -1;
        cout << dist[x - 1][y - 1] << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tin = 1; // cin >> tin;
    while (tin--) solve();
    return 0;
}