#include <iostream> 

using namespace std; 

int main() {
    int t; 
    cin >> t; 
    while (t--) {
        unsigned long long a, s; 
        bool failed = false; 
        cin >> a >> s; 
        string b = ""; 
        while (!failed && s > 0) {
            // max of a + b is 18, hence, next digit must be 1 if 2 digits are used. 
            int last_a = a % 10; 
            int last_s = s % 10; 
            int last_b = ((10 + last_s) - last_a) % 10; 

            if (last_b + last_a == (s % 100)) {
                b = to_string(last_b) + b; 
                a /= 10; 
                s /= 100; 
            }
            else if (last_b + last_a == last_s) {
                b = to_string(last_b) + b; 
                a /= 10; 
                s /= 10; 
            }  else {
                failed = true; 
                break; 
            }
        }
        if (a != 0) {
            failed = true; 
        }
        while (b.size() > 1 && b.front() == '0') {
            b = b.substr(1); 
        }

        cout << '\n';
        if (!failed) {
            cout << b <<'\n'; 
        } else {
            cout << -1 << '\n'; 
        }
    }
}