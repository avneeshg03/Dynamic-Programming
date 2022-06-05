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

int main()
{
    int n;
    cin >> n;
    int max_sum = n * 1000;
    vector<int> x(n);
    for (int &v : x)
        cin >> v;
    vector<vector<bool>> dp(n + 1, vector<bool>(max_sum + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= max_sum; j++)
        {
            dp[i][j] = dp[i - 1][j];
            int left = j - x[i - 1];
            if (left >= 0 && dp[i - 1][left])
            {
                dp[i][j] = true;
            }
        }
    }

    vector<int> possible;
    for (int j = 1; j <= max_sum; j++)
    {
        if (dp[n][j])
        {
            possible.push_back(j);
        }
    }
    cout << possible.size() << endl;
    for (int v : possible)
    {
        cout << v << ' ';
    }
    cout << endl;
}