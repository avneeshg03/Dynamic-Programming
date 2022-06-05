/*------ Author - Avneesh Goyal ------*/
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
vector<vector<int>> dp(505, vector<int>(505, INT_MAX));
int solve(int a, int b)
{

    if (a == b)
        return 0;
    if (a <= 0 || b <= 0)
        return INT_MAX;
    if (dp[a][b] != INT_MAX)
        return dp[a][b];
    int res1 = INT_MAX;
    int res2 = INT_MAX;
    for (int i = 1; i < a; i++)
    {
        res1 = min(res1, 1 + solve(a - i, b) + solve(i, b));
    }
    for (int i = 1; i < b; i++)
    {
        res2 = min(res2, 1 + solve(a, b - i) + solve(a, i));
    }
    dp[a][b] = min(res1, res2);
    return dp[b][a] = dp[a][b];
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << solve(a, b);
}