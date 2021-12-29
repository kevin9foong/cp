#include <iostream> 
#include <string> 
#include <cmath>
using namespace std; 

int main() {
    int t; 
    cin >> t; 
    while (t--) {
        unsigned long long a, s; 
        cin >> a >> s; 
        string sol = ""; 
        bool failed = false; 
        while (!failed && s > 0) {
            // check if can remove 2 last digits 
            int last2digitsOfS = s % 100; 
            int lastDigitOfA = a % 10; 
            int diff = last2digitsOfS - lastDigitOfA; 
            if (last2digitsOfS >= 10 && diff < 10) {
                sol = to_string(diff) + sol;  
                s = floor(s / 100); // remove last 2 digits of s
                a = floor(a / 10);  
            } else {
                // check to remove last digit 
                int lastDigitOfS = s % 10; 
                int diff2 = lastDigitOfS - lastDigitOfA; 
                if (diff2 >= 0 && diff2 < 10) {
                    sol = to_string(diff2) + sol; 
                    s = floor(s / 10); // remove last 1 digit of s 
                    a = floor(a / 10); 
                } else {
                    failed = true; 
                    break; 
                }
            }
        }
        while (sol.size() > 1 && sol.front() == '0') {
            sol = sol.substr(1); 
        }
        if (!failed && !(a > 0)) {
            cout << sol << '\n'; 
        } else {
            cout << -1 << '\n'; 
        }
    }
}