/*
Nama : Mochammad Ghifari Eka Narayana
NPM  : 140810190021
Kelas A
Program Shift Cipher
*/

#include<iostream>
#include<string.h>
using namespace std;

string encrypt(string plainText, int key){
  string cipherText = "";
  for (int i = 0; i < plainText.size(); i++){
    if (isupper(plainText[i])){
      cipherText += char(int(plainText[i] + key - 65) % 26 + 65);
    }
    if (islower(plainText[i])){
      cipherText += char(int(plainText[i] + key - 97) % 26 + 97);
    }
    else{
      cipherText += char(int(plainText[i]));
    }
  }
  return cipherText;
}


string decrypt(string cipherText, int key){
  string plainText = "";
  for (int i = 0; i < cipherText.size(); i++){
    if (isupper(cipherText[i])){
      plainText += char((int(cipherText[i] - key - 65) % 26 + 26) % 26 + 65);
    }
    if (islower(cipherText[i])){
      plainText += char((int(cipherText[i] - key - 97) % 26 + 26) % 26 + 97);
    }
    else{
      plainText += char(int(cipherText[i]));
    }
  }
  return plainText;
}

int main(){
  bool isLoop = true;
  char opt;

  while (isLoop == true){
    string plainText;
    cout << "Masukan Text: ";

    getline(cin, plainText);
    int key;
    cout << "Masukan Kunci: ";
    cin >> key;

    string cipherText = encrypt(plainText, key);
    cout << "\nHasil Enkripsi: " << cipherText;
    cout << "\nHasil Dekripsi: " << decrypt(cipherText, key);
    char repeat;
    cout << "\nRepeat? (Y/N) "; cin >> repeat;
    if(repeat == 'y' || repeat == 'Y'){
      cin.ignore();
      true;
    }
    else
      break;
  }
}