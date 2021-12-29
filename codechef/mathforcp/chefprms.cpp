#include <iostream> 
#include <vector> 
#include <unordered_set> 
using namespace std; 

vector<int64_t> sieve(int64_t n) { 
    bool isPrime[n + 1];
    vector<int64_t> result; 

    if (n < 2) {
        return result; 
    }

    for (int64_t i = 0; i < n + 1; i++) {
        isPrime[i] = true; 
    }
    isPrime[0] = false; 
    isPrime[1] = false; 

    for (int64_t j = 2; j < n + 1; j++) {
        if (isPrime[j] == true) {
            result.push_back(j); 
            for (int64_t k = j; k * j <= n; k++) {
                isPrime[k * j] = false; 
            }
        }
    }
    return result;  
}

int main() {
    int64_t t;
    cin >> t; 
    vector<int64_t> primesToN = sieve(200); 
    while (t--) {
        bool solved = false; 
        int64_t n; 
        cin >> n; 

        unordered_set<int64_t> prods; 
        for (int i = 0; i < primesToN.size() - 1; i++) {
            for (int j = i + 1; (j < primesToN.size()) && ((primesToN[i] * primesToN[j]) > 1) && ((primesToN[i] * primesToN[j]) <= n); j++) { 
                // cout << "prod added: " << primesToN[i] * primesToN[j] << endl; 
                prods.insert(primesToN[i] * primesToN[j]); 
            }
        }

        for (auto i = prods.begin(); i != prods.end(); i++) {
            int other = n - *i; 
            // cout << "prod1: " << *i << endl; 
            // cout << "prod: " << other << endl; 
            if (prods.find(other) != prods.end()) {
                solved = true; 
                break; 
            }
        }

        cout << (solved ? "YES" : "NO") << '\n';  
    } 
}