#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;

signed main(){
    opt;
    int k; cin >> k;
    string s, ans; cin >> s;

    int count = 1, len = s.size();
    bool last, arr[s.size()];
    vector<int> v;
    for( int i = 0 ; i < len ; i++ ) (int)s[i] < 91 ? arr[i] = 0 : arr[i] = 1;  // 0 for cap, 1 for lower case 
    last = arr[0];
    for( int i = 1 ; i < len ; i++ ){ // B for 0, S for 1
        if( arr[i] != arr[i-1] ){
            if( count >= k ) v.emplace_back(count);
            else v.emplace_back(0);
            count = 0;
        }
        count++;
    }
    if( count >= k ) v.emplace_back(count);
    else v.emplace_back(0);

    for( auto i : v ) cout << i << " ";
    cout << '\n';

    int res = 0, num = 0;
    for( int i = 0 ; i < v.size() ; i++ ){
        if( v[i] == k ){
            if( v[i-1] > k ) num++;
            num++;
        }else{
            if( v[i] > k && v[i-1] == k ) num++;
            res = max( res, num );
            num = 0;
        }
    }
    res = max(res, num);
    cout << res * k << "\n";
}