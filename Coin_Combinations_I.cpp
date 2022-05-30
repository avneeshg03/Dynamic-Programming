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
int n, x;
const int N = 1e9 + 7;
vector<int> coins(105);
vector<int> dp(1e6 + 5, 0);
int32_t main()
{
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    sort(coins.begin(), coins.begin() + n);
    dp[0] = 1;
    // cout << solve(x);
    for (int sum = 1; sum <= x; sum++)
    {
        for (int i = 0; i < n; i++)
        {
            if (coins[i] <= sum)
                dp[sum] = (dp[sum] + dp[sum - coins[i]]) % N;
            else
            break;
        }
    }
    cout << dp[x];
}