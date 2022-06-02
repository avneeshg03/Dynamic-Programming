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
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> matrix(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char c;
            cin >> c;
            if (c == '.')
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
        }
    }
    if (matrix[n][n] == 0)
    {
        cout << 0;
        return 0;
    }
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    dp[n][n] = 1;
    for (int i = n; i > 0; i--)
    {
        for (int j = n; j > 0; j--)
        {
            if (i == n && j == n)
                continue;
            if (matrix[i][j])
                dp[i][j] = (dp[i][j + 1] + dp[i + 1][j]) % mod;
        }
    }
    cout << dp[1][1];
}