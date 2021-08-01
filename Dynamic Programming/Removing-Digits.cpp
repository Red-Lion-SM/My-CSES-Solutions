// The ones who fear failure are those who have never tasted it..

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back
#define vec_i vector<int>
#define sz(x) (int)(x.size())
#define all(x) (x).begin(),(x).end()
#define forr(x,a,m) for(int x=a;x<m;x+=1)
const int mod = 1000000007;

int dp[1000001];

int play(int n) {
    if(n == 0) return dp[0] = 0;
    if(dp[n] != 0) return dp[n];
    int x = n;
    int ans = INT_MAX;
    while(x > 0) {
        if(x % 10 != 0) ans = min(ans, 1 + play(n - x % 10));
        x /= 10;
    }
    return dp[n] = ans;
}

void solve() {
    int n; cin >> n;
    memset(dp, 0, sizeof(dp));
    cout << play(n) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tin = 1; // cin >> tin;
    while (tin--) solve();
    return 0;
}