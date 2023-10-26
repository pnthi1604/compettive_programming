#include <bits/stdc++.h>
#define int long long
#define ll long long

using namespace std;

const ll mod = 1e9+7;
void solve(){
    ll n;
    cin>>n;
    vector<ll>a(n,0),f(n,0),l(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    map<ll,ll>mp;
 	cerr << "check array a\n";
 	for(int i = 0; i < n; i++) {
 		cerr << "a[" << i << "] = " << a[i] << endl;
 	}
 	cerr << "\nend check array a\n";
    for(int i=0;i<n;i++){
        if(!mp[a[i]]){
            
            f[i]=1;
        }
        mp[a[i]]=1;
    }
    cerr << "check array f\n";
    for(int i = 0; i < n; i++) {
    	cerr << "f[" << i << "] = " << f[i] << '\n';
    }
    cerr << "\nend check array f\n";
    cerr << "check array mp\n";
    for(int i = 0; i < n; i++) {
    	cerr << "mp[" << a[i] << "] = " << mp[a[i]] << endl;
    }
    cerr << "\nend check array mp\n";
    mp.clear();
    for(int i=n-1;i>=0;i--){
        if(!mp[a[i]]){
            
            l[i]=1;
        }
        mp[a[i]]=1;
        cerr << "\ndebug\n";
        cerr << "i = " << i << endl;
        cerr << "a[" << i << "] = " << a[i] << endl;
        cerr << "mp[" << a[i] << "] = " << mp[a[i]] << endl;
        cerr << "l[" << i << "] = " << l[i] << endl;
    }
    ll cnt=0,ans=0;             
    for(int i=0;i<n;i++){
        cnt+=f[i];
        ans += l[i]*1ll*cnt;
        cerr << "l[" << i << "] = " << l[i] << endl;
        cerr << "cnt = " << cnt << endl;
        cerr << "ket qua i = " << i << ": " << l[i] * cnt << '\n';
    }
    cout<<ans<<endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}