/*Author Avneesh Goyal*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
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
const int N = 1e6 + 5;
const int inf = INT_MAX;
vector<int> dp(N, -1);
vector<int> coins(105);
int n, x;
int solve(int sum)
{
    if (sum == 0)
        return 0;
    if (dp[sum] != -1)
        return dp[sum];
    int c = inf;
    for (int i = 0; i < n; i++)
    {
        if (coins[i] <= sum)
            c = min(c, 1 + solve(sum - coins[i]));
    }
    return dp[sum]=c;
}
int32_t main()
{
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
        dp[coins[i]] = 1;
    }
    int ans = solve(x);
    if (ans == inf)
        cout << -1;
    else
        cout << ans;
}