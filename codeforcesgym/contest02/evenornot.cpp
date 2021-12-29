#include <iostream> 

using namespace std; 

int main() {
    int t; 
    cin >> t;

    while (t--) {
        string equality; 
        cin >> equality; 
        int len = equality.size(); 
        int count = 0; 
        for (int i = 0; i < len; i++) {
            if (equality[i] == 'N') {
                count++; 
            }
        }
        cout << ((count == 1) ? "NO\n" : "YES\n"); 
    }
    return 0; 
}
