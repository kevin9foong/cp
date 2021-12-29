#include <iostream> 
#include <vector> 

using namespace std;

int main() {
    long long t; 
    cin >> t; 
    while(t--) {
        long long n, k, x;  
        cin >> n >> k >> x; 
        string bastring; 
        cin >> bastring; 
        vector<int> counter (1, 0); 
        vector<int> multiplier (1, 1); 
        int mult = 1; 
        int starCount = 0; 
        
        for (int i = n - 1; i >= 0; i--) {
            char c = bastring[i]; 
            if (c == 'a' && starCount > 0) {
                mult = max(1, counter.back() * multiplier.back()); 
                multiplier.push_back(mult); 
                counter.push_back(0); 
            } else if (c == '*') {
                starCount++; 
                int prevCount = counter.back(); 
                counter.pop_back(); 
                counter.push_back(prevCount + 1);
            } 
        }
        //compute 
        int mult_len = multiplier.size(); 
        int counter_len = counter.size(); 
        for (int i = mult_len - 1; i >= 0; i--) {

        }
        for (int i = counter_len - 1; i >= 0; i--) {

        }

        
    }
}