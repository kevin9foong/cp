#include <iostream> 
#include <vector> 

using namespace std; 

void printDistances(int, vector<int>, vector<int>);

int main() { 
    int cases; 
    cin >> cases; 
    while(cases--) {
        int n; 
        cin >> n; 
        vector<int> ancestors(n); 
        for (int i = 0; i < n; i++) {
            int ancestor_input; 
            cin >> ancestor_input; 
            ancestors[i] = ancestor_input; 
        }

        vector<int> perm(n); 
        for (int i = 0; i < n; i++) {
            int perm_input; 
            cin >> perm_input; 
            perm[i] = perm_input; 
        }

        printDistances(n, ancestors, perm); 
    }
}

void printDistances(int n, vector<int> ancestors, vector<int> perm) {
    int dist[n]; 
    // preallocate values to the dist by the position of nodes. 
    for (int i = 0; i < n; i++) {
        dist[perm[i] - 1] = i; 
    }
    int weights[n]; 
    // weight = the distance from the root for each elem. 
    fill_n(weights, n, -1); 
    
    for (int i = 0; i < n; i++) {
        int node = perm[i]; 
        int parent = ancestors[node - 1]; 
        weights[node - 1] = dist[node - 1] - dist[parent - 1]; 
        if (weights[parent - 1] == -1) {
            cout << -1 << '\n'; 
            return; 
        }
    }
    for (int i = 0; i < n; i++) {
        cout << weights[i] << " ";
    }
    cout << '\n'; 
}