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
int n, m, k, r, c, s, t, ctn, res;
bool graph[MAXN][MAXN];
vector< pair<int, int> > rem;
int devil[MAXN][5+5];

signed main(){
    opt;
    cin >> n >> m >> k;
    ctn = k;

    for( int i = 0 ; i < k ; i++ ){
        for( int j = 0 ; j < 5 ; j++ ){
            if( j == 4 ){
                devil[i][j] = 1;
                break;
            }
            cin >> devil[i][j];
        }
    }

    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < m ; j++ ){
            graph[i][j] = false;
        }
    }

    /*
     *  0 -> r, 
     *  1 -> c, 
     *  2 -> s, 
     *  3 -> t, 
     *  4 -> exist
     */
    while( ctn > 0 ){

        for( int i = 0 ; i < k ; i++ ){
            if( devil[i][4] == -1 ) continue;

            // Put Bomb
            graph[devil[i][0]][devil[i][1]] = true;
        }

        for( int i = 0 ; i < k ; i++ ){
            if( devil[i][4] == -1 ) continue;

            // Walk
            devil[i][0] += devil[i][2];
            devil[i][1] += devil[i][3];
            
            // Check Whether Ctn Pos Has Bomb
            if( graph[devil[i][0]][devil[i][1]] == true ){
                devil[i][4] = -1;
                ctn--;
                rem.push_back(make_pair(devil[i][0], devil[i][1]));
                continue;
            }

            // Check Whether Out of Edge
            if( devil[i][0] < 0 || devil[i][1] < 0 || devil[i][0] >= n || devil[i][1] >= m ){
                devil[i][4] = -1;
                ctn--;
            }
        }

        for( auto i : rem ){
            graph[i.first][i.second] = false;
        }

        rem.clear();
    }

    res = 0;
    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < m ; j++ ){
            if( graph[i][j] == true) res++;
        }
    }

    cout << res;
}