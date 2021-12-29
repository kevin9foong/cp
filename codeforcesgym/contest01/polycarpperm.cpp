#include <iostream> 
#include <list> 

using namespace std; 

void form_original(int n, list<int> after) {
    list<int> original;
    
    if (after.front() != n && after.back() != n) {
        cout << -1 << '\n'; 
        return; 
    }

    while (after.size() > 1) {
        int left = after.front(); 
        int right = after.back(); 

        if (left > right) {
            original.push_front(left); 
            after.pop_front(); 
            left = after.front(); 
        } else { 
            original.push_back(right); 
            after.pop_back(); 
            right = after.back(); 
        }
    }
    int lastElem = after.front();
    original.push_back(lastElem); 
    
    for (int i = 0; i < n - 1; i++) {
        cout << original.front() << " ";  
        original.pop_front(); 
    } 
    cout << original.front() << "\n"; 
}

int main() {
    int count; 
    cin >> count; 

    for (int i = 0; i < count; i++) {
        // get the input 
        int n; 
        cin >> n;
        list<int> after;  
        int temp;
        for (int j = 0; j < n; j++) { 
            cin >> temp;
            after.push_back(temp);  
        }
        
        form_original(n, after); 
    }
}