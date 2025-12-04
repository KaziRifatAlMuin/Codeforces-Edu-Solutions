#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

vector <ll> par, mini, maxi, cnt;

ll find(ll a) {
    if(par[a] == a) return a;
    return par[a] = find(par[a]);
}

void merge(ll a, ll b){
    a = find(a);
    b = find(b);
    if(a != b){
        par[b] = a;
        maxi[a] = max(maxi[a], maxi[b]);
        mini[a] = min(mini[a], mini[b]);
        cnt[a] = cnt[a] + cnt[b];
    }
}

void solve(){
    ll n, m;
    cin >> n >> m;
    par.assign(n+2, 0);
    mini.assign(n+2, 2e9);
    maxi.assign(n+2, 0);
    cnt.assign(n+2, 0);
    for(int i = 0; i <= n; i++) par[i] = i, mini[i] = i, maxi[i] = i, cnt[i] = 1;
    while(m--){
        string s;
        ll a, b;
        cin >> s;
        if(s == "union"){
            cin >> a >> b;
            merge(a,b);
        }
        else{
            cin >> a;
            a = find(a);
            cout << mini[a] << " " << maxi[a] << " " << cnt[a] << "\n"; 
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
// https://codeforces.com/edu/course/2/lesson/7/1/practice