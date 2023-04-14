#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int MAXN = 500 + 50;
const int Mod = 1e9 + 7;

signed main(){
    opt;
    int n, m, k, a, b;
    cin >> n >> m >> k;
    bool graph[MAXN][MAXN];
    vector<bool> devil;
    int dev[MAXN][5];
    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < 4 ; j++ ){
            cin >> arr[i][j];
            devil.emplace_back(i);
        }
    }

    while( devil.size() > 0 ){
        for( int i = 0 ; i < devil.size() ; i++ ){
            a = arr[i][0] + arr[i][2];
            b = arr[i][1] + arr[i][3];
            if( a < 0 || b < 0 || a == n || b == m ){
                devil
            }
        }
    }
}