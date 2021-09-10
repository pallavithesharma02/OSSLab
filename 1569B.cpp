#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n, i, j; string s; cin >> n >> s; char ans[n][n]; memset(ans, '0', sizeof(ans)); bool x=0;
    for(i=0; i<n; i++) ans[i][i]='X';
    for(i=0; i<n; i++){
        if(s[i]=='1'){
            for(j=0; j<n; j++){
                if(i==j) continue;
                if((ans[i][j]=='0'&&ans[j][i]=='0')||(ans[i][j]=='='&&ans[j][i]=='='))
                    ans[i][j]=ans[j][i]='=';
                else{cout << "NO\n"; return;}
            }
        }
        else{
            x=0;
            for(j=0; j<n; j++){
                if(i==j) continue;
                if(ans[i][j]=='0'&&ans[j][i]=='0'&&s[j]=='2'&&!x) ans[i][j]='+', ans[j][i]='-', x=1;
            }
            if(!x){cout << "NO\n"; return;}
        }
    }
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if(ans[i][j]=='0') ans[i][j]='=';
    cout << "YES\n";
    for(i=0; i<n; i++){
        for(j=0; j<n; j++)
            cout << ans[i][j]; cout << '\n';
    }
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}
