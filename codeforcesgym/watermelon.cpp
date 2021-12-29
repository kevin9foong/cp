#include <iostream> 

using namespace std; 

int main() {
    int w; 
    cin >> w;
    // check if 0 or odd 
    // by law of addition of odd numbers, odd = even + odd; 
    // hence, cannot split to 2 even 
    if (w == 0 || (w & 1) != 0) { 
        cout << "NO";
    // all even numbers = even + even or odd + odd. 
    // hence, if even - 2 (even) should give even number. Check if result even number is positive (>0) 
    } else { 
        cout << ((((w - 2) > 0) && ((w - 2) & 1) == 0) ? "YES" : "NO"); 
    } 
    return 0; 
}