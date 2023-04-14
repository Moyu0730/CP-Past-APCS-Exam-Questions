#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int MAXN = 1e4 + 50;
const int Mod = 1e9 + 7;
vector<pair<int, int>> v;
int n;

signed main(){
    opt;
    cin >> n;
    int x, y;
    for( int i = 0 ; i < n ; i++ ){
        cin >> x >> y;
        v.push_back({x, +1});
        v.push_back({y, -1});
    }
    sort(v.begin(), v.end());

    int count = 0, ind = 0, ans = 0;
    for( int i = 0 ; i < 1e7 ; i++ ){
        while( v[ind].first == i ){
            count += v[ind].second;
            ind++;
        }
        if( count != 0 ) ans++;
    }
    cout << ans;
}