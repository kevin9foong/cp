#include <iostream> 
#include <vector> 
#include <unordered_map> 

using namespace std; 

int main() {
    int t; 
    cin >> t; 
    while (t--) {
        int elems;
        vector<long long> arr;
        unordered_map<long long, long long> occ;  
        cin >> elems; 
        int n = elems; 
        while (elems--) {
            long long temp; 
            cin >> temp; 
            arr.push_back(temp); 
            if (occ.find(temp) == occ.end()) {
                occ[temp] = 1; 
            } else {
                occ[temp] = 1 + occ[temp]; 
            }
        }
        bool found = false; 
        int i = 0; 
        while (!found) {
            if (occ[i] == 0) {
                found = true; 
                break;
            }
            i++; 
        }
        // i is MEX
        bool first = true; 
        for (int j = 0; j <= n; j++) {
            // cout << i;
            if (!first) {
                cout << " ";
            }
            if (j > i) {
                cout << "-1"; 
            } else {
                long long count = 0;
                count += occ[j]; 
                cout << count; 
            }
            first = false; 
        }
        cout << '\n';
    }
}