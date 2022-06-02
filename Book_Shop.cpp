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
// state of the dp is dp[i][x] which says the max pages that can be buyed using first i books and cost of x
// we have to find dp[n][x].
int main()
{
    ll n, x;
    cin >> n >> x;
    vector<int> h(n + 1), p(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int c = 0; c <= x; c++)
        {

            ll res1 = (i == 1) ? 0 : dp[i - 1][c];
            ll res2 = (c < h[i]) ? 0 : p[i] + dp[i - 1][c - h[i]];
            dp[i][c] = max(res1, res2);
        }
    }
    cout << dp[n][x];
}