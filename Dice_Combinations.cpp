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
const int M = 1e9 + 7;
int dp[N];
int solve(int n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return dp[n] = 1;
    if (dp[n] != 0)
        return dp[n] % M;
    return dp[n] = (solve(n - 1) + solve(n - 2) + solve(n - 3) + solve(n - 4) + solve(n - 5) + solve(n - 6)) % M;
}
int32_t main()
{
    int n;
    cin >> n;
    // dp[i]=number of ways to get sum i by throwing a dice!!
    cout << solve(n);
}