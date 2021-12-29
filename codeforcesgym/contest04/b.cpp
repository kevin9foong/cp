#include <iostream> 
#include <vector> 
#include <tuple> 
using namespace std; 

vector<tuple<int64_t, int64_t, int64_t>> ans; 
vector<tuple<int64_t, int64_t>> ranges; 

int main() {
    int t; 
    cin >> t; 
    while (t--) {
        ans.clear(); 
        ranges.clear(); 
        int64_t n; 
        cin >> n; 

        for (int i = 0; i<n; i++) {
            int64_t l, r; 
            cin >> l >> r; 
            ranges.push_back(make_tuple(l, r)); 
        }

        // since every elem must be chosen exactly once
        // for each range, find when the min will be called for the range
    }
}

void solve_for(int64_t l, int64_t r) {
    for (auto r : ranges) { 
        // check if current range has been split in the middle
        // for that, there must be one range with right range < r
        if (get<0> r == l && get<1> < r) {
            int64_t new_range = 
        }
    }
}