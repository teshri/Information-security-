#include <iostream>
using namespace std;
int main() {
int data[7]; // Reduced size to 7 as we only need 4 da0ta bits and 3 parity bits
int dataatrec[7], c1, c2, c3, i;

cout << "Enter 4 bits of data one by one\n";
cin >> data[0];
cin >> data[1];
cin >> data[2];
cin >> data[3]; // Corrected index
// Calculation of even parity
data[4] = data[0] ^ data[2] ^ data[3]; // Corrected index
data[5] = data[0] ^ data[1] ^ data[3]; // Corrected index
data[6] = data[1] ^ data[2] ^ data[3]; // Corrected index
cout << "\nEncoded data is\n";
for (i = 0; i < 7; i++)
cout << data[i];
cout << "\n\nEnter received data bits one by one\n";
for (i = 0; i < 7; i++)
cin >> dataatrec[i];
c1 = dataatrec[3] ^ dataatrec[4] ^ dataatrec[5]; // Corrected indices
c2 = dataatrec[3] ^ dataatrec[4] ^ dataatrec[6]; // Corrected indices
c3 = dataatrec[3] ^ dataatrec[5] ^ dataatrec[6]; // Corrected indices
int c = c3 * 4 + c2 * 2 + c1;
if (c == 0) {
cout << "\nNo error while transmission of data\n";
} else {
cout << "\nError on position " << c;
cout << "\nData sent : ";
for (i = 0; i < 7; i++)
cout << data[i];
cout << "\nData received : ";
for (i = 0; i < 7; i++)
cout << dataatrec[i];
cout << "\nCorrect message is\n";
if (dataatrec[c] == 0)
dataatrec[c] = 1;
else
dataatrec[c] = 0;
for (i = 0; i < 7; i++) {
cout << dataatrec[i];
}
}
return 0;
}