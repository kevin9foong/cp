#include<iostream> 
using namespace std; 
#define MAX 1000000

int64_t dp[MAX]; 
bool solved[MAX]; 

int64_t solve(int x) {
    if (solved[x]) {
        return dp[x]; 
    } 
    // otherwise solve it 
    int64_t count = 0; 
    if (x - 2 >= 0) {
        count += solve(x - 2);  
    }
    if (x - 3 >= 0) {
        count += solve(x - 3); 
    }
    dp[x] = count % 1000000009; 
    solved[x] = true; 
    return dp[x]; 
}

int main() {
    int64_t t; 
    cin >> t; 
    for (int i = 0; i < MAX; i++) {
        if (i < 4) {
            solved[i] = true; 
        } else { 
            solved[i] = false; 
        }
    }
    dp[0] = 0; 
    dp[1] = 0; 
    dp[2] = 1; 
    dp[3] = 1; 

    while (t--) {
        int64_t n; 
        cin >> n;
        cout << solve(n) << '\n';   
    }
}