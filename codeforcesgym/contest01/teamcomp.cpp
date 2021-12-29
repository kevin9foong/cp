#include <iostream> 

using namespace std; 

int maxTeams(int, int); 

int main() {
    int cases; 
    cin >> cases; 

    for (int i = 0; i < cases; i++) {
        int prog, math; 
        cin >> prog >> math; 
        cout << maxTeams(prog, math) << '\n'; 
    }
}

int maxTeams(int prog, int math) {
    int total = prog + math; 
    if (total < 4) {
        return 0; 
    } 
    int teams = total / 4; 
    int bottleneck = min(prog, math); 
    return min(teams, bottleneck); 
}