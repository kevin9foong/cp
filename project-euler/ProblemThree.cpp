#include <iostream> 

using namespace std;

bool isPrime(int); 

int main() {
    long num; 
    cin >> num; 
    if (num < 2) {
        cout << "No prime divisor found." << '\n';
        return 0; 
    }
    long largestPrimeDivisor {2}; 
    long i = 2; 
    // Idea: fundamental law of arithmetic 
    // 100 / 2 = 50 / 2 = 25 / 5 = 5 / 5 = 1 
    // hence, 100 = 2^2 * 5^2 unique prime factorization 
    // after 100 / 2^2  = 25, no longer divisble by multiples of 
    // prime factor 2... generalize this to other prime factors. 
    while (num != 1) {
        while (num % i == 0) {
            largestPrimeDivisor = i;  
            num /= i; 
        }
        i++; 
    }
    cout << largestPrimeDivisor; 
}