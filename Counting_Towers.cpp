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
/*dp[i] as the number of ways to fill from ith pos to pos n
linked is tile at ith pos linked or not?
final ans would be dp[1][0]+dp[1][1]
recurrence for dp[i][0]
1. extend both dp[i+1][0] (not linked at i+1 so dp[i+1][0])
2. extend either 2*dp[i+1][0](again not linked at i+1 pos).
3. extend none(may be linked at i+1 or not linked at i+1) dp[i+1][0]+dp[i+1][1].
Recurrence for dp[i][1]
1. extend it (linked at i+1)dp[i][1]=dp[i+1][1].
2.not extend it (may be linked may be not at i+1) dp[i+1][0]+dp[i+1][1].
BASE CASE dp[n][0]=1,dp[n][1]=1;
*/
int n = 1000000;
ll dp[1000001][2];
int main()
{
    FIO;
    int t = 1; // cin >> t;
    while (t--)
    {
        dp[n + 1][0] = dp[n + 1][1] = 1;

        for (int i = n; i >= 2; i--)
        {
            ll op1 = (dp[i + 1][1] + dp[i + 1][0]) % mod;
            ll op2 = dp[i + 1][0];
            ll op3 = (2 * dp[i + 1][0]) % mod;
            ll op4 = dp[i + 1][1];

            dp[i][0] = (op1 + op2 + op3) % mod;
            dp[i][1] = (op1 + op4) % mod;
        }

        int q;
        cin >> q;
        while (q--)
        {
            int query;
            cin >> query;
            cout << (dp[1000000 - query + 2][1] + dp[1000000 - query + 2][0]) % mod << '\n';
        }
    }
    return 0;
}