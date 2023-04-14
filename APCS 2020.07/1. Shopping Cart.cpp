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
    int a, b, n, item, ans = 0;
    int arr[5] = {0};
    cin >> a >> b >> n;
    for( int i = 0 ; i < n ; i++ ){
        arr[1] = arr[0] = 0;
        while( cin >> item ){
            if( item == 0 ) break;
            if( item == a ) arr[0]++;
            if( item == b ) arr[1]++;
            if( item == ( a * -1) ) arr[0]--;
            if( item == ( b * -1) ) arr[1]--;
        }
        if( arr[0] > 0 && arr[1] > 0 ) ans++;
    }
    cout << ans << '\n';
}