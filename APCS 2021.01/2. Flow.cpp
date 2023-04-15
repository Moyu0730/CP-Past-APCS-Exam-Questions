// v1.0 - 5% Solution

#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int MAXN = 1e3 + 50;
// const int Mod = 1e9 + 7;
int n, m, k, res;
int q[MAXN][MAXN], c[MAXN][MAXN];

int unit( int k ){
    int tmp = 0;
    for( int i = 0 ; i < n ; i++ ){
        int sever = c[k][i];

        for( int j = 0 ; j < m ; j++ ){
            int unit = q[i][j];
            if( sever == j ) tmp += unit;
            else tmp += unit * (unit > 1000 ? 2 : 3);
        }
    }

    return tmp;
}

signed main(){
    opt;
    cin >> n >> m >> k;
    // Input Q
    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < m ; j++ ){
            cin >> q[i][j];
        }
    }
    // Input K
    for( int i = 0 ; i < k ; i++ ){
        for( int j = 0 ; j < n ; j++ ){
            cin >> c[i][j];
        }
    }
    // Solve
    res = INT32_MAX;
    for( int i = 0 ; i < k ; i++ ){
        // cout << unit(i) << " | ";
        res = min(unit(i), res);
        // cout << res << '\n';
    }

    cout << res << "\n";
}

// -------------------------------------------------- //

// v2.0 - 100% Answer But Not Really Good

#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int MAXN = 1e3 + 50;
// const int Mod = 1e9 + 7;
int n, m, k, res, tmp;
vector<vector<int>> combine, q, c;
vector<int> def;

signed main(){
    // opt;
    cin >> n >> m >> k;
    // Input Q
    q.resize(n);
    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < m ; j++ ){
            cin >> tmp;
            q[i].emplace_back(tmp);
        }
    }

    // Input K
    c.resize(k);
    for( int i = 0 ; i < k ; i++ ){
        for( int j = 0 ; j < n ; j++ ){
            cin >> tmp;
            c[i].emplace_back(tmp);
        }
    }

    // Add
    for( int i = 0 ; i < m ; i++ ) def.emplace_back(-1);
    for( int i = 0 ; i < 55 ; i++ ) combine.emplace_back(def);

    res = INT32_MAX;
    for( int st = 0 ; st < k ; st++ ){
        for( int i = 0 ; i < 55 ; i++ ){
            for( int j = 0 ; j < m ; j++ ){
                combine[i][j] = -1;
            }
        }

        for( int j = 0 ; j < n ; j++ ){
            int server = c[st][j];
            if( combine[server][0] != -1 ){
                for( int ind = 0 ; ind < combine[server].size() ; ind++ ) combine[server][ind] += q[j][ind];
            }else{
                for( int ind = 0 ; ind < combine[server].size() ; ind++ ) combine[server][ind] = q[j][ind];
            }
        }

        tmp = 0;
        for( int i = 0 ; i < combine.size() ; i++ ){
            if( combine[i][0] != -1 ){
                for( int j = 0 ; j < combine[i].size() ; j++ ){
                    if( i == j ) tmp += combine[i][j];
                    else{
                        if( combine[i][j] < 1000 ) tmp += combine[i][j] * 3;
                        else{
                            int diff = combine[i][j] - 1000;
                            tmp += ( 3000 + diff * 2 );
                        }
                    }
                }
            }
        }

        res = min(res, tmp);
    }

    cout << res << "\n";
}

// -------------------------------------------------- //

// v3.0 Better and Easier Answer

#include<bits/stdc++.h>
using namespace std;

int n, m, k, q[50+10][50+10], server[50+10], city[50+10][50+10];

int calc(){
    for( int i = 0 ; i < 55 ; i++ )
        for( int j = 0 ; j < m ; j++ )
            city[i][j] = 0;
    
    for( int i = 0 ; i < n ; i++ )
        for( int j = 0 ; j < m ; j++ )
            city[server[i]][j] += q[i][j];
    
    int ans = 0;
    for( int i = 0 ; i < 55 ; i++ )
        for( int j = 0 ; j < m ; j++ ){
            if( i == j ) ans += city[i][j];
            else{
                if( city[i][j] <= 1000 ) ans += city[i][j] * 3;
                else ans += 3000 + (city[i][j] - 1000) * 2;
            }
        }

    return ans;
}

int main(){
    cin >> n >> m >> k;
    for( int i = 0 ; i < n ; i++ )
        for( int j = 0 ; j < m ; j++ )
            cin >> q[i][j];
    
    int ans = INT_MAX;
    while( k-- ){
        for( int i = 0 ; i < n ; i++ ) cin >> server[i];
        ans = min( ans, calc() );
    }
    cout << ans;
}