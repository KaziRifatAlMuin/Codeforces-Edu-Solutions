#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

vector <ll> par;

ll find(ll a) {
    if(par[a] == a) return a;
    return par[a] = find(par[a]);
}

void merge(ll a, ll b){
    a = find(a);
    b = find(b);
    if(a != b){
        par[a] = b;
    }
}

void solve(){
    ll n, m;
    cin >> n >> m;
    par.resize(n+2);
    for(int i = 0; i <= n; i++) par[i] = i;
    while(m--){
        string s;
        ll a, b;
        cin >> s >> a >> b;
        if(s == "union") merge(a,b);
        else{
            if(find(a) == find(b)) cout << "YES\n";
            else cout << "NO\n";
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