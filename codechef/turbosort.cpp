#include <iostream> 
#include <vector> 
#include <cmath> 

int main() {
    const int_fast64_t max = std::pow(10, 6); 
    std::int32_t t; 
    std::cin >> t; 

    // counting sort problem to solve in O(n + k)
    std::vector<int_fast64_t> arr (max, 0);    
    while (t--) {
        // store the count of each num 
        int_fast64_t temp; 
        std::cin >> temp; 
        // increment count by 1
        arr[temp]++; 
    }
    for (int i = 0; i < max; i++) {
        int times = arr[i]; 
        while (times--) {
            std::cout << i << '\n'; 
        }
    }

    return 0; 
}