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
const int N = 1001;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

char a[N][N];
int visited[N][N];
int n, m, ans;

bool check(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == '.' && visited[x][y] == 0);
}

void dfs(int i, int j) {
    visited[i][j]++;
    for(int z = 0; z < 4; z++) {
        int x = i + dx[z], y = j + dy[z];
        if(check(x, y)) {
            dfs(x, y);
        }
    }
}

void solve() {
    cin >> n >> m;
    forr(i,0,n) {
        forr(j,0,m) {
            visited[i][j] = 0;
            cin >> a[i][j];
        }
    }
    ans = 0;
    forr(i,0,n) {
        forr(j,0,m) {
            if(a[i][j] == '.' && visited[i][j] == 0) {
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tin = 1; // cin >> tin;
    while (tin--) solve();
    return 0;
}
