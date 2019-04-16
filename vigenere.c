/**********************************************************************
 * This program is written to perform a Vigenere cipher using command 
 * line input. To perform the Vigenere ciher, you must enter in the 
 * command line: ./a.out key message E to encrypt or 
 * ./a.out key message D to decrypt.
 *
 * @author Trung-Vuong Pham
 * @version 1.0
 *********************************************************************/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Checks whether a string is valid, and no characters other than letters are contained
bool valid(const char str[]){
  int length = strlen(str);
  for(int i = 0; i < length; i++){
    if(isalpha(str[i])==0){
      return false;
    }
  }
  return true;
}

//Converts all lowercase characters to uppercase
void toUpper(char str[]){
  int length = strlen(str);
  for(int i = 0; i < length; i++){
    if(str[i] > 96){
      str[i] -= 32;
    }
  }
}

//Encrypts the message read in the argument
void encrypt(char msg[], char key[]){
  int length = strlen(msg);
  for(int i = 0; i < length; i++){
    msg[i] -= 'A';
    msg[i] += key[i % strlen(key)] - 'A';
    msg[i] = msg[i] % 26;
    msg[i] += 'A';
  }
}

//Decrypts the message read in the argument
void decrypt(char msg[], char key[]){
  int length = strlen(msg);
  for(int i = 0; i < length; i++){
    msg[i] -= 'A';
    msg[i] += 26 -(key[i % strlen(key)] - 'A');
    msg[i] = msg[i] % 26;
    msg[i] += 'A';
  }
}

//Controls checking of valid, upper case functions and actual vigenere cipher
int cipher(char key[], char msg[], char method[]){
  if(valid(key) && valid(msg)){
    toUpper(key);
    toUpper(msg);
    if(strcmp(method, "E") == 0){
      encrypt(msg, key);
      return 1;
    }
    else if(strcmp(method, "D") == 0){
      decrypt(msg, key);
      return 1;
    }
  }
  strcpy(msg, "Error!");
  return 0;
}

// Main method that runs the Vigenere cipher
int main(int argc, char **argv){
  if(argc == 4){
    cipher(argv[1], argv[2], argv[3]);
    if(strcmp(argv[2],"Error!")!=0){
          printf("%s\n", argv[2]);
          return 0;
    }
  }
  else{
	printf("There are not enough arguments in prompt!");
  }  
   return 0;
}
