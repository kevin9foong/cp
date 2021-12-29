#include <iostream> 

using namespace std; 

int main() {
    long long t; 
    cin >> t; 
    while (t--) {
        long long w, h; 
        cin >> w >> h;
        long long lines = 2; 
        long long maxVert = 0, maxHorizontal = 0; 
        while (lines--) {
            long long k; 
            cin >> k; 
            long long horizontalMin = __LONG_LONG_MAX__; 
            long long horizontalMax = 0; 
            while (k--) {
                long long val;
                cin >> val; 
                horizontalMin = min(horizontalMin, val); 
                horizontalMax = max(horizontalMax, val); 
                maxHorizontal = max(maxHorizontal, horizontalMax - horizontalMin); 
            }
        }
        long linesVert = 2; 
        while (linesVert--) {
            long long k; 
            cin >> k; 
            long long vertMin = __LONG_LONG_MAX__; 
            long long vertMax = 0; 
            while (k--) {
                long long val;
                cin >> val; 
                vertMin = min(vertMin, val); 
                vertMax = max(vertMax, val); 
                maxVert = max(maxVert, vertMax - vertMin); 
            }
        }
        cout << (max(maxHorizontal * h, maxVert * w)) << endl; 
    }
}