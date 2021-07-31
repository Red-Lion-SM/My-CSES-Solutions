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

const string S = "UDRL";

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int n, m;

bool check(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

pair<int, int> par[1001][1001];
int pre[1001][1001], vis[1001][1001];
int dist[1001][1001], distA[1001][1001];
string a[1001];

void dfs(int i, int j, int pi, int pj) {
    par[i][j] = {pi, pj};
    vis[i][j] = 1;
    if(i == 0 || j == 0 || i == n - 1 || j == m - 1) {
        string ans;
        while(i != -1 && a[i][j] != 'A') {
            ans += S[pre[i][j]];
            int t = i;
            i = par[i][j].F, j = par[t][j].S;
        }
        cout << "YES\n";
        cout << sz(ans) << '\n';
        reverse(all(ans));
        cout << ans << '\n';
        exit(0);
    }
    
    forr(k,0,4) {
        int x = i + dx[k], y = j + dy[k];
        if(check(x, y) && dist[x][y] > distA[x][y] && a[x][y] == '.' && vis[x][y] == 0) {
            pre[x][y] = (k / 2) * 2 + 1 - k % 2;
            dfs(x, y, i, j);
        }
    }
}

void reverse_bfs() {
    
    forr(i,0,n){
        forr(j,0,m){
            dist[i][j] = INT64_MAX;
            distA[i][j] = INT64_MAX;
            vis[i][j] = 0;
        }
    }

    int Ax = -1, Ay = -1;
    
    queue<vector<int>> q;
    forr(i,0,n) {
        forr(j,0,m) {
            if(a[i][j] == 'M')
                q.push({i, j, 0}), dist[i][j] = 0;
            if(a[i][j] == 'A') 
                Ax = i, Ay = j;
        }
    }
    while(!q.empty()) {
        vector<int> p = q.front();
        q.pop();
        forr(k,0,4) {
            int x = p[0] + dx[k], y = p[1] + dy[k];
            if(check(x, y) && dist[x][y] == INT64_MAX && a[x][y] != '#') {
                dist[x][y] = 1 + p[2];
                q.push({x, y, dist[x][y]});
            }
        }
    }

    q.push({Ax, Ay, 0});
    distA[Ax][Ay] = 0;
    while(!q.empty()) {
        vector<int> p = q.front();
        q.pop();
        forr(k,0,4) {
            int x = p[0] + dx[k], y = p[1] + dy[k];
            if(check(x, y) && distA[x][y] == INT64_MAX && a[x][y] == '.') {
                distA[x][y] = 1 + p[2];
                q.push({x, y, distA[x][y]});
            }
        }
    }
    
    dfs(Ax, Ay, -1, -1);
}

void solve() {
    cin >> n >> m;
    forr(i,0,n) cin >> a[i];
    reverse_bfs();
    cout << "NO\n";
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tin = 1; // cin >> tin;
    while (tin--) solve();
    return 0;
}