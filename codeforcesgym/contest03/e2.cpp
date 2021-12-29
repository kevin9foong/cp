#include <iostream> 
#include <vector> 
#include <cmath>
using namespace std; 

int main() {
    int t; 
    cin >> t; 
    while(t--) {
        int c; 
        cin >> c; 
        int n = c; 
        vector<int> elems (n + 1); 
        while (c--) {
            int temp; 
            cin >> temp; 
            // store number of each elem only up to n 
            if (temp <= n) { 
                elems[temp] = elems[temp] + 1; 
                // cout << "At elem " << temp << ": " << elems[temp] << endl; 
            }
        }
        // store the occurrences up to i. 
        for (int i = 1; i <= n; i++) {
            elems[i] = elems[i - 1] + elems[i]; 
            // cout << "At elem " << i << ": " << elems[i] << endl; 
        }
        // compute results 
        bool failed = false;
        int count = elems[0]; 
        cout << count;  
        for (int i = 1; i <= n; i++) { 
            count -= elems[i - 1]; 
            // for 1 mex
            int needed = 0; 
            for (int j = i - 1; j >= i; j--) {
                // check 0 if have 1
                if (failed) {
                    count = -1; 
                    break; 
                }
                if (j == 0) {
                    if (elems[j] < 1) {
                        count = -1; 
                    } 
                    failed = true; 
                    break;
                } 
                if (elems[j] < j + 1) {
                    count = -1; 
                    failed = true; 
                    // cout << "break\n";
                    break; 
                // if not enough to bring up
                } else if ((elems[j] - elems[j - 1]) < (1 + needed)) {
                    int insufficient_amt = (1 + needed) - (elems[j] - elems[j - 1]); 
                    count += insufficient_amt; 
                    needed = insufficient_amt;
                } else if (j - 1 == 0) {
                    
                } else {
                    needed = 0; 
                }
            }
            cout << count;
            if (i == n) {
                cout << '\n'; 
            } 
        }
    }
}