#include <iostream> 
#include <vector>

using namespace std; 

int main() {
    int cases; 
    cin >> cases; 

    while (cases--) {
        int num_rooms, num_friends; 
        cin >> num_rooms >> num_friends; 

        vector<int> vlad (1, 1); 
        vector<int> friends (num_friends); 
        for (int i = 0; i < num_friends; i++) {
            cin >> friends[i]; 
        }

        vector<int> rooms [num_rooms]; 
        int c = num_rooms - 1; 
        while (c--) {
            int idx, neighbour; 
            cin >> idx >> neighbour;
            rooms[idx - 1].push_back(neighbour);  
            rooms[neighbour - 1].push_back(idx); 
        }

        // 0 unvisited, 1 is by vlad, -1 is by friend
        vector<int> visitedBy (num_rooms, 0); 
        // room 1 is visited
        visitedBy[1 - 1] = 1; 
        for (int i = 0; i < num_friends; i++) {
            visitedBy[friends[i] - 1] = -1; 
        }

        // cout << "BEGIN" << endl; 
        // terminating condition? 
        bool solved = false; 
        while (!solved) {
            vector<int> newFriends; 
            while (friends.size() > 0) {
                int f = friends.back(); 
                friends.pop_back(); 
                for (int i = 0; i < rooms[f - 1].size(); i++) {
                    int newf = rooms[f - 1].at(i); 
                    if (visitedBy[newf - 1] == 0) {
                        newFriends.push_back(newf); 
                        visitedBy[newf - 1] = -1; 
                    }
                }
            }
            friends = newFriends; 
            
            // cout << "vlad size: " << vlad.size() << endl; 
            vector<int> newVlads; 
            while (vlad.size() > 0) {
                int v = vlad.back(); 
                vlad.pop_back(); 
                for (int i = 0; i < rooms[v - 1].size(); i++) {
                    int newv = rooms[v - 1].at(i); 
                    // cout << "next node: " << newv << " is visited: " << visitedBy[newv - 1] << endl; 
                    if (visitedBy[newv - 1] == 0) {
                        // cout << "node check: " << newv << endl; 
                        newVlads.push_back(newv); 
                        visitedBy[newv - 1] = 1; 
                        // cout << "Rooms by node: " << newv << " size: " << rooms[newv - 1].size() << endl; 
                        if (!solved && rooms[newv - 1].size() == 1) {
                            cout << "YES" << '\n'; 
                            solved = true; 
                        }
                    }
                }
            } 
            vlad = newVlads; 
            if (!solved && vlad.size() == 0) {
                cout << "NO" << '\n'; 
                solved = true; 
            }
        }
    }
}