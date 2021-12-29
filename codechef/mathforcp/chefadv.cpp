#include <iostream>
using namespace std; 

bool solve(long long diffn, long long diffm,long long x, long long y) {
    if (diffn >= 0 && diffm >= 0 && (diffn % x == 0) && (diffm % y == 0)) {
        return true; 
    } else {
        return false; 
    }
}

int main() {
    int t; 
    cin >> t; 
    while (t--) {
        int n, m, x, y; 
        cin >> n >> m >> x >> y; 
        bool solved = solve(n - 1, m - 1, x, y) || solve(n - 2, m - 2, x, y); 
        // either use the +1 or not 
        cout << (solved ? "Chefirnemo" : "Pofik") << endl;
    }
}