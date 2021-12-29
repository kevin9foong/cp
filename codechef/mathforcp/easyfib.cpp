#include <iostream> 
#include <vector> 
#include <cmath> 
using namespace std; 

int64_t log2base(int64_t n) {
    int64_t result = 0; 
    int64_t fact = 1;
    while ((fact << (result + 1)) <= n) {
        result++;  
    }
    return result; 
}
// only works for positive pow. 
int64_t exp(int64_t a, int64_t pow) {
    int64_t res = 1; 
    while (pow > 0) {
        if ((pow & 1) == 1) {
            res = res * a; 
        } 
        pow /= 2; 
        a = a; 
    }
    return res; 
}

int main() {
    int64_t t; 
    cin >> t;  

    // period of fib % 10 is 60. 
    int fib[60]; 
    fib[0] = 0;
    fib[1] = 1; 
    for (int i = 2; i < 60; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % 10; 
    }

    while (t--) {
        int64_t l, position;
        cin >> l; 
        // after each step 1,2,3,4 all 2^0 -> 2, 4 all 2^1 -> 4 all 2^2 
        // hence, find s.t only 1 left is (2^steps)
        position = exp(2, floor(log2base(l))); 
        // since pos is 1-based index.
        cout << fib[(position - 1) % 60] << '\n'; 
    }
}