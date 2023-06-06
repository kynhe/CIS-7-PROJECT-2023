/* Grace Kim
 * Kathy Nguyen
 * CIS 7 Project
 * June 5, 2023
 */ 
//System Libraries
#include <iostream> // Input Output Library
#include <string>

using namespace std;

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes 
string encrypt(string plain, string key);
string decrypt(string cipher, string key);

//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables
    string plain;
    string key;

    //Initialize Variables
    
    //Map/Process the Inputs -> Outputs
    cout << "Enter the plain text: ";
    getline(cin, plain);

    cout << "Enter the keyword: ";
    getline(cin, key);

    string eText = encrypt(plain, key);
    string dText = decrypt(eText, key);

    //Display Inputs/Outputs
    cout << "Encrypted text: " << eText << endl;
    cout << "Decrypted text: " << dText << endl;
    
    //Clean up memory and files
    
    //Exit the Program
    return 0;
}

// Function to encrypt the plain text using the Vigenere cipher
string encrypt(string plain, string key) {
    string cipher;
    int keyL = key.length();

    for (int i = 0; i < plain.length(); ++i) {
        char pChar = plain[i];
        char kChar = key[i % keyL];
        int pOffset = pChar - 'A';
        int kOffset = kChar - 'A';
        int eOffset = (pOffset + kOffset) % 26;
        char eChar = 'A' + eOffset;

        // Handle lowercase letters
        if (islower(pChar)) {
            eChar = tolower(eChar);
        }
        // Keep non-alphabetic characters unchanged
        else if (!isupper(pChar)) {
            eChar = pChar;
        }

        cipher += eChar;
    }

    return cipher;
}

// Function to decrypt the cipher text using the Vigenere cipher
string decrypt(string cipher, string key) {
    string plain;
    int keyL = key.length();

    for (int i = 0; i < cipher.length(); ++i) {
        char cChar = cipher[i];
        char kChar = key[i % keyL];
        int cOffset = cChar - 'A';
        int kOffset = kChar - 'A';
        int dOffset = (cOffset - kOffset + 26) % 26;
        char dChar = 'A' + dOffset;

        // Handle lowercase letters
        if (islower(cChar)) {
            dChar = tolower(dChar);
        }
        // Keep non-alphabetic characters unchanged
        else if (!isupper(cChar)) {
            dChar = cChar;
        }

        plain += dChar;
    }

    return plain;
}
