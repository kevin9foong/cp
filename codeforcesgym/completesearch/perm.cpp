#include<vector> 
using namespace std; 

int searchPerm(vector<int>& perm, vector<int>& chosen, int n) {
    if (perm.size() == n) { 
        // perm generated 
    } else {
        for (int i = 0; i < n; i++) {
            if (chosen[i]) continue; 
            chosen[i] = true; 
            perm.push_back(i); 
            // search assuming i added at this position 
            searchPerm(perm, chosen, n);

            // else i not added in this position, add another (next) elem at 
            // current position
            chosen[i] = false; 
            perm.pop_back(); 
        }
    }
}

int main() {
    vector<int> perm; 
    int n = 5; 
    // form perm including {0, 1, 2, 3, 4} 
    vector<bool> chosen; 
    for (int i = 0; i < n; i++) {
        chosen[i] = false; 
    }
}