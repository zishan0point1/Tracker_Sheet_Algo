#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define int long long
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << nline;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


bool isPos(int mid, int m, int n, vector<int> &v){
    int sum = 0, cnt = 1;

    for(int i = 0; i < n; i++){
        sum += v[i];

        if(sum > mid) cnt++, sum = v[i];
    }

    return (cnt <= m);
}

void solve(){

    int n, m;   cin >> n >> m;

    int sum = 0;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i],  sum += v[i];

    // int l_b = sum / m;
    // debug(l_b)

    int s = *max_element(all(v)), e = sum;
    int ans = 0;
    int mid = s + (e - s) / 2;
    while(s <= e){

        if(isPos(mid, m, n, v)){
            ans = mid;
            e = mid - 1;
        }
        else   s = mid + 1;

        mid = s + (e - s) / 2;
    }
    
    cout << ans << nline;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    fastio();
    int t = 1;   	
    cin >> t;
    int i = 1;
    while(t--){   cout << "Case " << i << ": "; i++;  solve(); }
    return 0;
}