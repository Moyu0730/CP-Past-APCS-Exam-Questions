#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int MAXN = 100;
const int Mod = 1e9 + 7;
int arr[MAXN][MAXN];

int r, c, k, m;
auto dir = vector<pair<int, int>> { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

void Mig(){ // Be Careful to calculate the population after operation ! 
    int a, b, count;
    int dif[MAXN][MAXN] = {0};
    for( int i = 0 ; i < r ; i++ ){
        for( int j = 0 ; j < c ; j++ ){
            if( arr[i][j] == -1 ) continue;
            count = 0;
            for( int t = 0 ; t < 4 ; t++ ){
                a = i + dir[t].first;
                b = j + dir[t].second;
                
                if( a < 0 || b < 0 || a == r || b == c ) continue;
                if( arr[a][b] == -1 ) continue;
                
                count++;
                dif[a][b] += arr[i][j] / k;
            }
            dif[i][j] -= count * ( arr[i][j] / k );
        }
    }
    for( int i = 0 ; i < r ; i++ ){
        for( int j = 0 ; j < c ; j++ ){
            arr[i][j] += dif[i][j];
        }
    }
}

signed main(){
    opt;
    cin >> r >> c >> k >> m;
    for( int i = 0 ; i < r ; i++ ){
        for( int j = 0 ; j < c ; j++ ){
            cin >> arr[i][j];
        }
    }

    while(m--) Mig();

    int h = 0, l = 1e9;
    for( int i = 0 ; i < r ; i++ ){
        for( int j = 0 ; j < c ; j++ ){
            if( arr[i][j] == -1 ) continue;
            h = max( h, arr[i][j] );
            l = min( l, arr[i][j] );
            // cout << arr[i][j] << " ";
        }
        // cout << '\n';
    }
    cout << l << '\n' << h << '\n';
}