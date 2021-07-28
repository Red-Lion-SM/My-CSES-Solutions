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
int backtrack[N][N];
int n, m;

bool check(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m && (a[x][y] == '.' || a[x][y] == 'B') && visited[x][y] == 0);
}

char str(int k) {
    string dirs = "UDLR";
    return dirs[k];
}

void dfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j]++;
    int flag = 0, xb = -1, yb = -1;
    while(sz(q) > 0) {
        pair<int, int> p = q.front();
        q.pop();
        for(int z = 0; z < 4; z++) {
            int x = dx[z] + p.F, y = dy[z] + p.S;
            if(check(x, y)) {
                q.push({x, y});
                backtrack[x][y] = 1 - z % 2 + (z / 2) * 2;
                visited[x][y]++;
                if(a[x][y] == 'B') {
                    xb = x, yb = y; 
                    flag++;
                }
            }
        }
        if(flag) break;
    }
    if(!flag) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        string path;
        while(a[xb][yb] != 'A') {
            path += str(backtrack[xb][yb]);
            int temp = xb;
            xb = xb + dx[backtrack[xb][yb]];
            yb = yb + dy[backtrack[temp][yb]]; 
        }
        reverse(all(path));
        cout << sz(path) << '\n';
        cout << path << '\n';
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
    forr(i,0,n) {
        forr(j,0,m) {
            if(a[i][j] == 'A') {
                dfs(i, j);
                return;
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tin = 1; // cin >> tin;
    while (tin--) solve();
    return 0;
}