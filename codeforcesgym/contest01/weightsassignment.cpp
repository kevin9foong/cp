#include <iostream> 
#include <vector> 

using namespace std; 

void assignWeight(int, vector<int>, vector<int>); 

int main() {
    int count; 
    cin >> count; 
    while (count--) {
        int n; 
        cin >> n; 
        int b = n; 
        vector<int> ancestor; 
        while (b--) { 
            int ancestorInput; 
            cin >> ancestorInput; 
            ancestor.push_back(ancestorInput); 
        }
        b = n; 
        vector<int> perm; 
        while (b--) {
            int permInput;
            cin >> permInput; 
            perm.push_back(permInput); 
        }

        assignWeight(n, ancestor, perm); 
    }
}

void assignWeight(int n, vector<int> ancestors, vector<int> perm) {
    // trees have unique path to root for each node. 
    // if hops to the root, visit unvisited node, then impossible. 
    // else just assign least on top of prev max.
    vector<bool> visited(n, false); 
    vector<int> weight(n, 0); 
    int prevMax = 0; 
    // i is the order 
    for (int i = 0; i < n; i++) {
        int vertex = perm[i]; 
        int hop = vertex; 
        visited[hop - 1] = true; 
        int parent = ancestors[vertex - 1]; 
        int cost = prevMax; 
        while (hop != parent) {
            if (!visited[hop - 1]) {
                cout << -1 << '\n'; 
                return; 
            }
            weight[hop - 1] = prevMax + 1; 
            cost += weight[hop - 1];  
            hop = ancestors[hop - 1]; 
            parent = ancestors[hop - 1];
        }
        weight[parent - 1] = 0;
        prevMax = cost;  
    }

    for (int i = 0; i < n - 1; i++) {
        cout << weight[i] << " "; 
    }
    cout << weight[n - 1] << '\n'; 
}