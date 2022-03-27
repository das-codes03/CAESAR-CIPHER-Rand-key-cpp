/*
 *  AUTHOR: ARGHADEEP DAS 
 *  c++
 *  Improved CAESAR CIPHER WITH RANDOMLY GENERATED KEY
 *  
*/

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

void Encrypt_msg(string originalMsg)
{
    string alphabet {};

    for(int i { 32 }; i < 127; ++i) {
        alphabet.push_back(i);
    }

    string key = alphabet;
    srand((time(0)));
    random_shuffle(key.begin(), key.end());

    string encrypted_msg;
    for(auto c : originalMsg) {
        char k { key.at(alphabet.find(c)) };
        encrypted_msg.push_back(k);
    }

    cout << "\nThe encrypted msg is:\n\n" << encrypted_msg << endl;
    cout << "\nCopy the key including the '|'s: \n\n\t|" << key << "|\n"<<endl;
}

void Decrypt_msg(string secretMsg, string key)
{

    string alphabet {};

    for(int i { 32 }; i < 127; ++i) {
        alphabet.push_back(i);
    }

    string decrypted_msg;
    for(auto c : secretMsg) {
        char k { alphabet.at(key.find(c,1)-1) };
        decrypted_msg.push_back(k);
    }

    cout << "\nThe original msg is:\n\n" << decrypted_msg << endl;
}

int main()
{

    do {
        cout << "Select an operation:\n"
                "(E) Encrypt a message - generates a encrypted message and a key\n"
                "(D) Decrypt a secret message using key\n";

        char op {};

        cin >> op;
        op = tolower(op);
        string org_msg, en_msg, k;

        switch(op) {
        case 'e':
            cout << "\nEnter your messege: ";
            getline(cin >> ws, org_msg);
            Encrypt_msg(org_msg);
            break;

        case 'd':
            cout << "\nEnter encrypted messege: ";
            getline(cin >> ws, en_msg);
            cout << "\nEnter key: ";
            getline(cin >> ws, k);
            Decrypt_msg(en_msg, k);
            break;
        }
    } while(true);
}
