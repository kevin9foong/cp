// square shaped x by x
// want to use all of the cloth
// idea: find gcd 

#include <iostream> 
// forward declaration for compiler 

int euclideanAlgo(int64_t a, int64_t b); 

int main() {
    int t; 
    std::cin >> t; 
    while (t--) {
        int64_t l, b; 
        std::cin >> l >> b;
        
        std::cout << euclideanAlgo(l, b) << '\n'; 
    }
}

int euclideanAlgo(int64_t a, int64_t b) {
    // let a = k * b + r 
    // hence, gcd(a,b) = gcd(b, r) since divisor of a 
    // must divide both b and r with rem = 0 such that a % gcd = 0

    // base case 
    if (a == 0) {
        return b; 
    } else if (b == 0) {
        return a; 
    } else {
        int64_t r = a % b; 
        return euclideanAlgo(b, r); 
    }
} 