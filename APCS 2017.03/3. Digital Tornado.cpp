#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int Mod = 1e9 + 7;
int side, dir;
int arr[50][50];
int ans[3000];
auto direction = vector<pair<int, int>> ({{0, -1}, {-1, 0}, {0, 1}, {1, 0}});

signed main(){
    opt;
    cin >> side >> dir;

    // Input
    for( int i = 0 ; i < side ; i++ )
        for( int j = 0 ; j < side ; j++ )
            cin >> arr[i][j];

    
    int ind = 0, up, down, left, right;
    int x = side/2, y = side/2, mid = side/2;
    ans[ind] = arr[side/2][side/2];
    ind++;
    
    up = down = left = right = mid;
    if( dir == 1 ) up--;
    else if( dir == 2 ) right++;
    else if( dir == 3 ) down++;
    else left--;

    x += direction[dir].first;
    y += direction[dir].second;
    if( dir == 1 ) dir = 2;
    else if( dir == 2 ) dir = 3;
    else if( dir == 3 ) dir = 0;
    else dir = 1;
    ans[ind] = arr[x][y];
    ind++;

    // cout << up << " " << down << " " << left << " " << right << "\n";
    while( x >= 0 && x < side && y >= 0 && y < side ){
        x += direction[dir].first;
        y += direction[dir].second;
        // cout << x << " " << y << '\n';

        if( dir == 1 ){
            if( x == up-1 ){
                up--;
                dir = 2;
            }
        }else if( dir == 2 ){
            if( y == right+1 ){
                right++;
                dir = 3;
            }
        }else if( dir == 3 ){
            if( x == down+1 ){
                down++;
                dir = 0;
            }
        }else{
            if( y == left-1 ){
                left--;
                dir = 1;
            }
        }

        ans[ind] = arr[x][y];
        ind++;
    }

    for( int i = 0 ; i < side * side ; i++ ) cout << ans[i];
    cout << '\n';
}