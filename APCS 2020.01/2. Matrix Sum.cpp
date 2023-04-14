#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int MAXN = 1e3 + 50;
const int Mod = 1e9 + 7;

int s, t, n, m, r;
int a[MAXN][MAXN];
int b[MAXN][MAXN];

int sol( int x, int y ){
    int count = 0, dif = 0;
    bool flag = true;

    for( int i = 0 ; i < s ; i++ ){
        for( int j = 0 ; j < t ; j++ ){
            if( a[i][j] != b[x+i][y+j] ){
                dif++;
                count += a[i][j] -  b[x+i][y+j];
            }
            if( dif > r ){
                flag = false;
                break;
            }
        }
    }

    // cout << count << '\n';
    if( flag == false ) return -1;
    else return abs(count);
}

signed main(){
    opt;
    cin >> s >> t >> n >> m >> r;

    for( int i = 0 ; i < s ; i++ )
        for( int j = 0 ; j < t ; j++ )
            cin >> a[i][j];

    // for( int i = 0 ; i < s ; i++ )
    //     for( int j = 0 ; j < t ; j++ )
    //         cout <<  a[i][j] << " ";
    // cout << '\n';

    for( int i = 0 ; i < n ; i++ )
        for( int j = 0 ; j < m ; j++ )
            cin >> b[i][j];

    // for( int i = 0 ; i < n ; i++ )
    //     for( int j = 0 ; j < m ; j++ )
    //         cout << b[i][j] << " ";
    // cout << '\n';

    int ans = MAXN, num = 0, tmp;
    for( int i = 0 ; i < n-s+1 ; i++ ){
        for( int j = 0 ; j < m-t+1 ; j++ ){
            tmp = sol(i, j);
            // cout << tmp << '\n';
            if( tmp != -1 ){
                num++;
                ans = min(ans, tmp);
            }
        }
    }

    if( num == 0 ) cout << num << '\n' << -1;
    else cout << num << '\n' << ans;
}