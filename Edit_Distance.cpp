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
const int mod = 1e9 + 7;
/*
Intution:  we have 3 types of operations add,replace,remove.So we can perform any of 3 mentioned ops on current element.
           Also it is a Optimization problem and doesn't seem to be done greedy we use DP then.

State   : dp[i][j] gives total minimum ops needed to match substring (0,i) to substring (0,j)

Answer  : dp[n][m]

Reccurr : dp[i][j]=(remove ith char i.e dp[i-1][j]+1),(replace dp[i-1][j-1]+(s[i]!=l[j])),(insert dp[i][j-1]+1);

BaseCase: to match substr of length 0 to a particular length we need that much length of chars.Similarly to match a substr of particular len to 0 we need to replace them.
*/
int32_t main()
{
    string s, l;
    cin >> s >> l;
    int n = s.size();
    int m = l.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 2 * m));
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (j == 0)
            {
                dp[i][j] = i;
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i - 1][j - 1] + (s[i - 1] != l[j - 1]), dp[i][j - 1] + 1));
            }
        }
    }
    cout << dp[n][m];
}