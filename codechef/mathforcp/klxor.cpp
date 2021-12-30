#include <iostream> 
#include <string>
using namespace std; 

// long t = fs.nextInt();
//         while(t-- >0) {
//             // get input
//             int strlen = fs.nextInt();
//             int sublen = fs.nextInt();
//             char[] bnStr = fs.next().toCharArray();

//             int numOnes = 0;
//             for (int i = 1; i < sublen + 1; i++) {
//                 int currOnes = 0;
//                 // j stores idx to iterate till
//                 for(int j = i - 1; j < strlen - sublen + i; j++) {
//                     if (bnStr[j] == '1') {
//                         currOnes++;
//                     }
//                 }
//                 if ((currOnes & 1) != 0) {
//                     numOnes++;
//                 }
//             }
//             // now i have my stuff to XOR
//             // XOR is associative
//             // x ^ x = 0
//             // x ^ 0 = x

//             System.out.println(numOnes);
//         }
int main() {
    int64_t t; 
    cin >> t; 
    while (t--) {
        int64_t strlen, sublen;
        string s;  
        cin >> strlen >> sublen; 
        cin >> s;  

        int64_t numOnes = 0; 
        int64_t currOnes = 0; 
        for (int64_t i = 0; i < strlen - sublen + 1; i++) {
            if (s[i] == '1') {
                currOnes++; 
            }
        }

        if ((currOnes & 1) != 0) {
                numOnes++;
        }

        for (int64_t i = 1; i < sublen; i++) {
            currOnes -= s[i - 1]; 
            currOnes += s[strlen - sublen + i]; 
            if ((currOnes & 1) != 0) {
                numOnes++;
            }
        }

        cout << numOnes << '\n';
    }
}