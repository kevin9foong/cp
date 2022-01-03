#include<iostream> 
using namespace std; 

int main() {
    int t; 
    cin >> t; 
    while (t--) {
        int64_t n; 
        cin >> n; 
        int64_t a[n]; 
        int64_t dp[n]; 
        int64_t count = 0; 
        for (int N = 0; N < n; N++) {
            int64_t temp; 
            cin >> temp; 
            a[N] = temp; 
            
            // solve dp 
            if (N == 0) {
                dp[N] = 1; 
            } else {
                if (a[N] >= a[N - 1]) {
                    dp[N] = dp[N - 1] + 1; 
                } else {
                    dp[N] = 1; 
                }
            }
            count += dp[N]; 
        }
        cout << count << '\n'; 
    }
}