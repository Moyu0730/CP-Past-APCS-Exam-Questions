#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;

signed main(){
    opt;
    int a[4], b[4], n, ans;
    for( int i = 0 ; i < 3 ; i++ ) cin >> a[i];
    for( int i = 0 ; i < 3 ; i++ ) cin >> b[i];
    cin >> n;

    ans = -1e10;
    for( int i = 0 ; i <= n ; i++ ){
        a[3] = a[0] * i * i + a[1] * i + a[2];
        b[3] = b[0] * (n-i) * (n-i) + b[1] * (n-i) + b[2];
        ans = max( ans, a[3] + b[3] );
    }
    cout << ans << '\n';
}