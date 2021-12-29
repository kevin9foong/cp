#include <iostream> 
#include <vector> 

using namespace std; 

// atm bal = 0
// 1 < -1 > -3 ... > 

int main() {
    int cases; 
    cin >> cases; 
    while (cases--) {
        int students, rem; 
        cin >> students >> rem; 
        vector<int> queue (students); // 1 -1 ... 
        // cout << "Students size: " << students << endl; 
        for (int i = 0; i < students; i++) {
            cin >> queue[i]; 
        }
        // int start = -1; is just end - len
        int end;

        int bal = rem; 
        int currLen = 0; 

        // if amount is less than zero, 

        // < 1, 2, 3 > // 3 students 
        for (int i = 0; i < students; i++) {
            int amt = queue[i]; 
            if ((bal >= 0) && (bal + amt >= 0)) { 
                currLen++; 
                bal += amt; 
                end = i; 
            } else {
                // else 
                // 1, 2 < 3, 4, 5, 6 > 
                // never reduce currLen, since we alr found the longest doesnt make sense to reset it.  
                bal -= queue[i - currLen]; 
                bal += queue[i]; 
            }
        }
        // cout << "longest len: " << longestLen << endl; 
        end = end + 1; 
        int start = end + 1 - currLen; 
        if (currLen == 0) { 
            cout << -1 << '\n'; 
        } else {
            cout << start << " " << end << '\n'; 
        }
    }
}