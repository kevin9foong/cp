#include <iostream> 
using namespace std; 

int main() {
    int64_t t; 
    cin >> t; 

    int64_t primeFactors[100001] = {}; 
    bool isComposite[100001] = {}; 
    // compute prime factors using sieve
    // since A, B >= 2 dont need to compute for 0 and 1.
    for (int i = 2; i < 100001; i++) {
        if (!isComposite[i]) { 
            primeFactors[i] = 1; 
            for (int j = 2; (i * j) < 100001; j++) {
                primeFactors[i * j] = primeFactors[i * j] + 1; 
                isComposite[i * j] = true; 
            }
        }
    }

    int64_t kPrimes[6][100001] = {}; 
    // once again, start from 2
    for (int i = 2; i < 100001; i++) {
        if (primeFactors[i] <= 5) {
            kPrimes[primeFactors[i]][i] = 1; 
        }
    }

    cout << kPrimes[1][2] << endl; 
    for (int i = 1; i < 6; i++) {
        for (int j = 2; j < 100001; j++) {
            kPrimes[i][j] = kPrimes[i][j - 1] + kPrimes[i][j]; 
        }
    }

    while (t--) {
        int64_t a, b, k; 
        cin >> a >> b >> k;
        cout << kPrimes[k][b] - kPrimes[k][a - 1] << '\n'; 
    }
}