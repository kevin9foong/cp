#include <iostream> 

using namespace std; 

int main() {
    int count; 
    cin >> count; 

    for (int i = 0; i < count; i++) {
        int num; 
        cin >> num;
        // even 
        if ((num & 1) == 0) {
            cout << 0 << '\n';
        // odd 
        } else {
            // max 10 iterations
            int digit = num % 10;
            bool hasEvenDigit = (digit & 1) == 0;    
            while (num > 10) {
                num /= 10;
                digit = num % 10;\
                hasEvenDigit = hasEvenDigit || ((digit & 1) == 0); 
            }

            if ((num & 1) == 0) {
                cout << 1 << '\n'; 
            } else if (hasEvenDigit) {
                cout << 2 << '\n'; 
            } else {
                cout << -1 << '\n'; 
            }
        }
    }
}