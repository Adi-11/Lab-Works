#include <bits/stdc++.h>
#include <iostream>
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define endl '\n'
#define pb push_back
#define mp make_pair
#define mod 100'000'0007
#define vi vector<int>
#define vl vector<long long>
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

struct segmentTree
{
    ll size;
    vl sums;
    void init(ll n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        sums.assign(2 * size, 0LL);
    }

    void set(ll i, ll v, ll x, ll lx, ll rx)
    {
        if (rx - lx == 1)
        {
            sums[x] = v;
            return;
        }
        ll m = (lx + rx) / 2;
        if (i < m)
        {
            set(i, v, 2 * x + 1, lx, m);
        }
        else
        {
            set(i, v, 2 * x + 2, m, rx);
        }
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }

    void set(ll i, ll v)
    {
        set(i, v, 0, 0, size);
    }

    ll queryResult(ll l, ll r, ll x, ll lx, ll rx)
    {
        if (lx >= r or rx <= l)
            return 0;

        if (l <= lx and rx <= r)
            return sums[x];

        ll m = (lx + rx) / 2;
        ll leftKid = queryResult(l, r, 2 * x + 1, lx, m);
        ll rightKid = queryResult(l, r, 2 * x + 2, m, rx);
        return leftKid + rightKid;
    }
    ll queryResult(ll l, ll r)
    {
        return queryResult(l, r, 0, 0, size);
    }
};

void solve()
{
    ll n, m;
    cin >> n >> m;

    segmentTree st;
    st.init(n);
    for (ll i = 0; i < n; i++)
    {
        ll v;
        cin >> v;
        st.set(i, v);
    }

    while (m--)
    {
        ll query;
        cin >> query;
        if (query == 1)
        {
            ll i, v;
            cin >> i >> v;
            st.set(i, v);
        }
        else
        {
            ll l, r;
            cin >> l >> r;
            ll res = st.queryResult(l, r);
            cout << res << endl;
        }
    }
}
int main()
{
    fastio;
    solve();
    return 0;
}