#include <iostream> 
using namespace std; 

int64_t gcd(int64_t x, int64_t y) {
    return x == 0 
        ? y
        : y == 0 
            ? x
            : gcd(y, x % y);  

}

int64_t lcm(int64_t x, int64_t y) {
    // lcm * gcd = x * y for 2 natural numbers at least 
    return (x * y) / gcd(x, y); 
}

int main() {
    int64_t t; 
    cin >> t; 
    while (t--) {
        int64_t n, a, b, k; 
        cin >> n >> a >> b >> k; 

        // inclusion exclusion principle 
        cout << ((((n / a) + (n / b) - 2 * (n / lcm(a, b))) >= k) ? "Win" : "Lose") << '\n';   
    }

    return 0; 
}