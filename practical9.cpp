#include <bits/stdc++.h>
using namespace std;

// Encryption function
string Encryption(int no_rows, int len_key, int len_msg, string msg, int col_val[]) {
    int x = 0;
    char enc_mat[no_rows + 1][len_key]; // Creating the matrix

    for (int i = 0; i < no_rows + 1; i++) {
        for (int j = 0; j < len_key; j++) {
            // Initializes the positions with '_' after the end of the message
            if (x >= len_msg) {
                enc_mat[i][j] = '_';
            } else {
                enc_mat[i][j] = msg[x];
            }
            x++;
        }
    }

    int t = 1;
    string cipher = "";

    // Finding the cipher text according to the value of col_val matrix
    while (t <= len_key) {
        for (int i = 0; i < len_key; i++) {
            int k = col_val[i];
            if (k == t) {
                for (int j = 0; j < no_rows + 1; j++) {
                    cipher += enc_mat[j][i];
                }
                t++;
            }
        }
    }

    return cipher;
}

// Decryption function
string Decryption(int no_rows, int len_key, string cipher, int col_val[]) {
    char dec_mat[no_rows + 1][len_key];
    int x = 0, t = 1;

    // Rearrange the matrix according to the col_val
    while (t <= len_key) {
        for (int i = 0; i < len_key; i++) {
            int k = col_val[i];
            if (k == t) {
                for (int j = 0; j < no_rows + 1; j++) {
                    dec_mat[j][i] = cipher[x];
                    x++;
                }
                t++;
            }
        }
    }

    string message = "";
    for (int i = 0; i < no_rows + 1; i++) {
        for (int j = 0; j < len_key; j++) {
            // Replacing the '_' with space
            if (dec_mat[i][j] == '_') {
                dec_mat[i][j] = ' ';
            }
            message += dec_mat[i][j];
        }
    }

    return message;
}

int main() {
    // Example usage
    int no_rows = 3;
    int len_key = 4;
    string plaintext = "I <3 U SO MUCH";
    int col_val[] = {3, 1, 4, 2}; // Example column order

    string ciphertext = Encryption(no_rows, len_key, plaintext.length(), plaintext, col_val);
    cout << "Ciphertext: " << ciphertext << endl;

    string decrypted_text = Decryption(no_rows, len_key, ciphertext, col_val);
    cout << "Decrypted text: " << decrypted_text << endl;

    return 0;
}
