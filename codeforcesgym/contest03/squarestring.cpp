#include <iostream>
using namespace std;  

int main() {
    int t; 
    cin >> t; 
    while (t--) {
        string check; 
        cin >> check; 
        int len = check.size(); 
        if ((len & 1) != 0) {
            cout << "NO\n"; 
        } else {
            // len is even 
            // maybe yes
            int halfLen = (len / 2) - 1; // last index of first part 
            int last = len - 1; 
            bool failed = false; 
            while (halfLen >= 0 && !failed) {
                if (check[last] != check[halfLen]) {
                    cout << "NO\n"; 
                    failed = true; 
                    break; 
                }
                halfLen--; 
                last--; 
            }
            if (!failed) {
                cout << "YES\n"; 
            } 
        }
    }
}