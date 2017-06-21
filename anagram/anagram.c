/*
 * Check if string user entered is anagram
 * Ex: abba is anagram
 */



#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


char *GET_INPUT (char prompt[]);

int VALUE_STRING(char str[]);

void PRINT_RESULT(char str1[],char str2[]);




int main () {
   
   /*
    * Ask user to input 2 strings
    * Print the result 
    */  
   
   
   // prepare spaces for 21 letters
   
   char *firstWord  = malloc(21);
   char *secondWord = malloc(21);
   
   firstWord = GET_INPUT("Please enter the first word: ");
   secondWord = GET_INPUT("Please enter the second word: ");
  
   PRINT_RESULT(firstWord,secondWord);
   
   //release the spaces
   free(firstWord);
   free(secondWord);
   
   return 0;
}

char *GET_INPUT (char prompt[]) {
   
   /*
    * Ask user to input a string/word with a prompt 
    * return the string to main function  
    */
   
   char *str = malloc(21);
   
   printf("%s",prompt);
   scanf("%20s",str);
   
   return str;
   
}   
   

int VALUE_STRING(char str[]) {

   /*
    * Convert all characters of the input string to upper case
    * Add all characters together
    */
   
   int sum = 0;
   
   for (int i=0; i< strlen(str); ++i) {
      
      sum = sum + toupper(str[i]);
   }
   
   return sum;
}   
   
   
void PRINT_RESULT(char str1[], char str2[]) {

   /*
    * If the values of all characters in 2 string equal to each other
    *    print Yes 
    * else 
    *    print No 
    */      

   if (VALUE_STRING(str1) == VALUE_STRING(str2)) {
      
      printf("%s is an anagram of %s\n",str1,str2);
   }   
   else {
      
      printf("%s is NOT an anagram of %s\n",str1,str2);
   }
   return;
}   
   
 
   
   
   
   
   
