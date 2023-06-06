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
    getline(cin, plain); // Read the plain text from the user

    cout << "Enter the keyword: ";
    getline(cin, key); // Read the keyword from the user

    string eText = encrypt(plain, key); // Encrypt the plain text
    string dText = decrypt(eText, key); // Decrypt the cipher text

    //Display Inputs/Outputs
    cout << "Encrypted text: " << eText << endl; // Print the encrypted text
    cout << "Decrypted text: " << dText << endl; // Print the decrypted text
    
    //Clean up memory and files
    
    //Exit the Program
    return 0;
}

// Function to encrypt the plain text 
string encrypt(string plain, string key) {
    string cipher;
    int keyL = key.length();

    for (int i = 0; i < plain.length(); ++i) {
        char pChar = plain[i]; // Get the current character from the plain text
        char kChar = key[i % keyL]; // Get the current character from the key
        int pOffset = pChar - 'A'; // Calculate the offset of the plain character
        int kOffset = kChar - 'A'; // Calculate the offset of the key character
        int eOffset = (pOffset + kOffset) % 26; // Calculate the offset of the encrypted character
        char eChar = 'A' + eOffset; // Convert the offset back to the encrypted character

        // Handle lowercase letters
        if (islower(pChar)) {
            eChar = tolower(eChar); // Convert the encrypted character to lowercase
        }
        // Keep non-alphabetic characters unchanged
        else if (!isupper(pChar)) {
            eChar = pChar; // Keep non-alphabetic characters unchanged
        }

        cipher += eChar; // Append the encrypted character to the cipher text
    }

    return cipher; // Return the encrypted text
}

// Function to decrypt the cipher text 
string decrypt(string cipher, string key) {
    string plain;
    int keyL = key.length();

    for (int i = 0; i < cipher.length(); ++i) {
        char cChar = cipher[i]; // Get the current character from the cipher text
        char kChar = key[i % keyL]; // Get the current character from the key
        int cOffset = cChar - 'A'; // Calculate the offset of the cipher character
        int kOffset = kChar - 'A'; // Calculate the offset of the key character
        int dOffset = (cOffset - kOffset + 26) % 26; // Calculate the offset of the decrypted character
        char dChar = 'A' + dOffset; // Convert the offset back to the decrypted character

        // Handle lowercase letters
        if (islower(cChar)) {
            dChar = tolower(dChar); // Convert the decrypted character to lowercase
        }
        // Keep non-alphabetic characters unchanged
        else if (!isupper(cChar)) {
            dChar = cChar; // Keep non-alphabetic characters unchanged
        }

        plain += dChar; // Append the decrypted character to the plain text
    }

    return plain; // Return the decrypted text
}
