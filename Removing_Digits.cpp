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
vector<int> dp(N, inf);
int32_t main()
{
    int n;
    cin >> n;
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i < 10)
        {
            dp[i] = 1;
            continue;
        }
        int x = i;
        while (x > 0)
        {
            int no = x % 10;
            dp[i] = min(dp[i], 1 + dp[i - no]);
            x /= 10;
        }
    }
    cout << dp[n];
}