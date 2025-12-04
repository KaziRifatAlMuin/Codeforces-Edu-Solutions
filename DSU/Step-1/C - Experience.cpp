#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

vector <ll> par, sum, diff, sz;

ll find(ll a) {
    ll p = par[a];
    if(par[a] == a) return a;
    par[a] = find(p);    // recursively update parent
    diff[a] += diff[p];  // now diff[p] is the full offset to root
    return par[a];
}

void merge(ll a, ll b){
    ll ra = find(a);
    ll rb = find(b);
    if(ra != rb){
        if(sz[ra] <= sz[rb]){
            par[ra] = rb;
            sz[rb] += sz[ra];
            diff[ra] = sum[ra] - sum[rb];
        }
        else{
            par[rb] = ra;
            sz[ra] += sz[rb];
            diff[rb] = sum[rb] - sum[ra];
        }
    }
}

void solve(){
    ll n, m;
    cin >> n >> m;
    par.assign(n+2, 0);
    sum.assign(n+2, 0);
    diff.assign(n+2, 0);
    sz.assign(n+2, 1);
    for(int i = 0; i <= n; i++) par[i] = i;
    while(m--){
        string s;
        ll x, y, v;
        cin >> s;
        if(s == "join"){
            cin >> x >> y;
            merge(x,y);
        }
        else if(s == "add"){
            cin >> x >> v;
            ll r = find(x);
            sum[r] += v;
        }
        else{
            cin >> x;
            ll r = find(x);
            cout << sum[r] + diff[x] << "\n"; 
        }
    }
}
    
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/C