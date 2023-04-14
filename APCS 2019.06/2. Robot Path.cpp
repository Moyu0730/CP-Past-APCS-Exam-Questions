#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long

const int MAXN = 1e3 + 50;
const int Mod = 1e9 + 7;
auto dir = vector<pair<int, int>> { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

signed main(){
    opt;
    int n, m;
    cin >> n >> m;
    int arr[MAXN][MAXN], s = 1e10, x, y; // Remember to 
    bool visited[MAXN][MAXN] = {false};
    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < m ; j++ ){
            cin >> arr[i][j];
            if( arr[i][j] < s ){
                s = arr[i][j];
                x = j;
                y = i;
            }
        } 
    }
    
    int cmp, a, b, ans = 0;
    bool flag = true;
    pair<int, int> ind;
    while( flag == true ){
        flag = false;
        ans += arr[y][x];
        visited[y][x] = true;
        cmp = 1e10;
        for( int t = 0 ; t < 4 ; t++ ){
            a = y + dir[t].first;
            b = x + dir[t].second;
            if( a < 0 || b < 0 || a == n || b == m ) continue;
            if( visited[a][b] == true ) continue;
            flag = true;
            if( arr[a][b] < cmp ){
                cmp = arr[a][b];
                ind.first = a;
                ind.second = b;
            }
        }
        x = ind.second;
        y = ind.first;
    }
    cout << ans << "\n";
}