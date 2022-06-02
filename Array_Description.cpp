/*Author Avneesh Goyal*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>
#define pb push_back
#define endl '\n'
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define all(v) (v).begin(), (v).end()
#define FIO ios_base::sync_with_stdio(0), cin.tie(0)
#define fi first
#define minq priority_queue<int, vector<int>, greater<int>>
#define maxq priority_queue<int>
#define s(v) sort(all(v))
#define revs(v) sort(all(v), greater<int>())
#define se second
const int mod = 1e9 + 7;
// dp[i][x] is the number of valid arrays of size i with last element as x this is the state of a dp
// we have to find dp[n][last]
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<vector<ll>> dp(n + 2, vector<ll>(m + 2, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1)
            {
                if (a[i] == 0 || a[i] == j)
                    dp[i][j] = 1;
                continue;
            }
            if (a[i] == 0 || j == a[i])
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % mod;
            }
        }
    }
    ll sum = 0;
    for (int i = 1; i <= m; i++)
    {
        sum += dp[n][i] % mod;
    }
    cout << sum%mod;
}