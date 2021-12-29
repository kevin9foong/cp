#include <iostream> 
#include <cmath> 
using namespace std; 

int main() {
    int t;
    cin >> t; 
    while(t--) {
        int64_t n; 
        cin >> n; 
        // find m * m s.t n + m * m = x * x
        // hence, n = x * x - m * m 
        // hence, n = (x + m) * (x - m)
        // find 2 factors such that the difference 
        // between them is the smallest and divisible by 2.
        // why smallest diff? to minimise 2m so that m * m is smallest. 
        int64_t m = -1; 
        for (int64_t i = sqrt(n); i > 0; i--) {
            // check if divisible 
            if (n % i == 0) {
                // divisible 
                int64_t other = n / i; 
                // if even 
                if ((other - i) > 0 && ((other - i) & 1) == 0) {
                    m = (other - i) /2;
                    m = m * m;  
                    break; 
                } 
            } else {
                // skip 
            }
        }

        cout << m << '\n'; 
    }
}