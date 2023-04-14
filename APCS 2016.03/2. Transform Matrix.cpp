#include <iostream>
using namespace std;
   
int R, C, M, x;
int a[11][11], b[11][11];
   
void rFlip(){
    for (int i=0; i<R; i++){
        for (int j=0; j<C; j++){
            b[i][j] = a[i][j];
        }
    }
    for (int i=0; i<R; i++){
        for (int j=0; j<C; j++){
            a[i][j] = b[R-1-i][j];
        }
    }
}
   
void rRotate(){
    for (int i=0; i<R; i++){
        for (int j=0; j<C; j++){
            b[i][j] = a[i][j];
        }
    }
    for (int j=C-1; j>=0; j--){
        for (int i=0; i<R; i++){
            a[C-1-j][i] = b[i][j];
        }
    }
    swap(R, C);
}
   
int main() {
    while( cin >> R >> C >> M ){
        for( int i = 0 ; i < R ; i++ ){
            for( int j = 0 ; j < C ; j++ ){
                cin >> a[i][j];
            }
        }
        int op[M];
        for( int i = 0 ; i < M ; i++ ){
            cin >> op[i];
        }
        for( int i = M - 1 ; i >= 0 ; i-- ){
            if ( op[i] == 0 ) rRotate();
            else rFlip();
        }
   
        cout << R << ' ' << C << '\n';
        for( int i = 0 ; i < R ; i++ ){
            for( int j = 0 ; j < C ; j++ ){
                cout << a[i][j];
                if ( j < C-1 ) cout << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}