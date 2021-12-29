#include <iostream> 
using namespace std; 

int main() {
    int64_t t;
    cin >> t; 
    while(t--) {
        int64_t n, m, startr, startc, dirtyr, dirtyc; 
        cin >> n >> m >> startr >> startc >> dirtyr >> dirtyc; 

        int mover = 1, movec = 1;
        int64_t time = 0;  
        while (startr != dirtyr && startc != dirtyc) {
            // check if hit wall 
            if (startr + mover == n + 1 || startr + mover == 0) {
                mover = -mover; 
            }
            if (startc + movec == m + 1 || startc + movec == 0) {
                movec = -movec; 
            }
            // move
            time++; 
            startr += mover; 
            startc += movec; 
        }
        cout << time << '\n'; 
    }
}