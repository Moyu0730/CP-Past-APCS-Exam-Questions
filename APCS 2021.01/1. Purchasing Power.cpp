#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int MAXN = 105;
const int Mod = 1e9 + 7;
int arr[MAXN][5];

signed main(){
    opt;
    int n, d;
    cin >> n >> d;
    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ;  j < 3 ; j++ ){
            cin >> arr[i][j];
        }
    }

    int high, low, cost = 0, mix, num = 0;
    for( int i = 0 ; i < n ; i++ ){
        high = -1; low = 1e9; mix = 0;
        for( int j = 0 ; j < 3 ; j++ ){
            mix += arr[i][j];
            low = min( low, arr[i][j] );
            high = max( high, arr[i][j] );
        }
        if( abs( high - low ) >= d ){
            cost += mix / 3;
            num++;
        }
    }
    cout << num << " " << cost << '\n';
}