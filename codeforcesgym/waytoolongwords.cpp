#include <iostream>

using namespace std; 

// solve simply with naive iteration 
int main() {
    int numWords; 
    cin >> numWords; 
    string wordArr [numWords]; 
    for (int i = 0; i < numWords; i++) {
        string word; 
        cin >> word; 
        int strlen = word.length();
        if (strlen > 10) { 
            wordArr[i] = word.at(0) + to_string((strlen - 2)) + word.at(strlen - 1); 
        } else {
            wordArr[i] = word; 
        }
    }
    for (int i = 0; i < numWords; i++) {
        cout << wordArr[i] << '\n'; 
    }
}  