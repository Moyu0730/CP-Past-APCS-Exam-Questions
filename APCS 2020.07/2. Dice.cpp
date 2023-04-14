#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include <cstring>
using namespace std;
#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int MAXN = 25;
const int Mod = 1e9 + 7;

signed main(){
    opt;
    int n, m, a, b;
    int dice[MAXN][MAXN]; // Top(0), Right(1), Bottom(2), Left(3), Front(4), Back(5)
    int arr[6];
    cin >> n >> m;
    for( int i = 0 ; i < n ; i++ ){
        dice[i][0] = 1; dice[i][1] = 2;
        dice[i][2] = 6; dice[i][3] = 5;
        dice[i][4] = 4; dice[i][5] = 3;
    }

    while( m-- ){
        cin >> a >> b;
        if( b > 0 ){
            swap(arr[a], arr[b]);
        }else{
            if( b == -2 ){
                arr[0] = dice[a][3]; // Left -> Top
                arr[2] = dice[a][1]; // Right -> Bottom
                arr[3] = dice[a][2]; // Bottom -> Left
                arr[1] = dice[a][0]; // Top -> Right

                dice[a][0] = arr[0];
                dice[a][1] = arr[1];
                dice[a][2] = arr[2];
                dice[a][3] = arr[3];
            }
            else{
                arr[0] = dice[a][4]; // Front -> Top
                arr[4] = dice[a][2]; // Bottom -> Front
                arr[2] = dice[a][5]; // Back -> Bottom
                arr[5] = dice[a][0]; // Top -> Back

                dice[a][0] = arr[0];
                dice[a][2] = arr[2];
                dice[a][4] = arr[4];
                dice[a][5] = arr[5];
            }
        }
    }

    for( int i = 0 ; i < n ; i++ ) cout << dice[i][0] << " ";
    cout << '\n';
}