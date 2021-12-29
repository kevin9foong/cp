#include <iostream> 
#include <string>
#include <unordered_set>

using namespace std; 

int main() {
    int t; 
    cin >> t;
    while (t--) {
        unsigned long long max; 
        cin >> max; 
        unordered_set<string> powSet;
        unsigned long long count = 1; // account for 1 
        unsigned long long pow2 = 2; 
        unsigned long long pow3 = 2; 
        while (pow2 * pow2 <= max) {
            // cout << pow2 * pow2 << '\n'; 
            if (powSet.find(to_string(pow2 * pow2)) == powSet.end()) {
                powSet.insert(to_string(pow2 * pow2)); 
                count++; 
            }
            pow2++; 
        }
        while (pow3 * pow3 * pow3 <= max) {
            // cout << pow3 * pow3 * pow3 << '\n'; 
            if (powSet.find(to_string(pow3 * pow3 * pow3)) == powSet.end()) {
                powSet.insert(to_string(pow3 * pow3 * pow3)); 
                count++; 
            }
            pow3++;  
        }
        cout << count << '\n'; 
    }
}