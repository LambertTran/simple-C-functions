#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


char *GET_INPUT (char prompt[]);
void PLURAL_FORM(char word[]);
bool isSXZ (char letter);
bool isVOWEL(char letter); 
void ADD_ES(char word[]);
void ADD_S(char word[]);
void ADD_IES(char word []); 
void ADD_VES(char word[]);
void REPLACE_LETTER(char word[],char letReplace[]);
void ADD_LET2STR(char word[],char letter[]);


int main() {

   // prepare space for word with 21 letters max
   char *word= malloc(21);  
   
   word = GET_INPUT("Please enter a word: ");
   
   PLURAL_FORM(word);
   
   free(word);
   
   return 0;
}


char *GET_INPUT (char prompt[]) {
   
   /*
    * Ask user to input  a string with a prompt
    * Return inputted string to main script 
    */
       
   char *str = malloc(21);
   
   printf("%s",prompt);
   scanf("%20s",str);
   
   return str;
}   


bool isSXZ (char letter) {
   // check if last letter is s, x, or z
   
   return letter =='s' || letter =='x' || letter =='z' ;
}

bool isVOWEL(char letter) {
   // check if last letter is vowel
   
   return letter == 'a' || letter == 'e' || letter == 'i' 
          || letter == 'o' || letter == 'u';
}


void ADD_ES(char word[]) {
   // Add 'es' to the inputted word 
   
   ADD_LET2STR(word,"es");
   exit(0);           
}


void ADD_S(char word[]) {
   // Add 's' too the inputted word

   ADD_LET2STR(word,"s");
   exit(0);   
}

void ADD_IES(char word []) {
   // Replace last letter with 'ies' 

   REPLACE_LETTER(word,"ies");
   exit(0);
}

void ADD_VES(char word[]) {
   // Replace last letter with 'ves' 

   REPLACE_LETTER(word,"ves");
   exit(0);
}

void REPLACE_LETTER(char word[],char letReplace[]) {

   /*
    * Replace last letter with indicated letters
    */
   
   char *plural = malloc(strlen(word) + strlen(letReplace)-1); 
   
   int len=strlen(word);
   int i;
   
   /*
    * if the last letter is 'i', then replace 'i' 
    *    with indicated letters
    *
    * if the last letter is 'f', then replace 'f'
    *    with indicated letters 
    */
   
   if (letReplace[0] == 'i') {
      
      for ( i=0; i< len-1; ++i){
         plural[i]=word[i];
      }   
      
      strcat(plural,letReplace);
   }
   else if (word[len-1] == 'e') {
         
         for (i=0; i<len-2; ++i){
         
            plural[i] =word[i];
         }
         strcat(plural,letReplace);
      }
   else if (word[len-1] == 'f') {
         
         for (i=0; i<len-1; ++i){
         
            plural[i] =word[i];
         }
         
         strcat(plural,letReplace);
         }
     
   printf("The plural form of %s is %s.\n",word,plural);
   
   return ;
}


void ADD_LET2STR(char word[],char letter[]) {

   /*
    * Add indicated letters to the end of string  
    */

   char *plural = malloc(strlen(word) + strlen(letter));
      
   strcpy(plural,word);
   
   strcat(plural,letter);     
    
   printf("The plural form of %s is %s.\n",word,plural); 
}


void PLURAL_FORM(char word[]) {

   int i= strlen(word);
   
   if (isSXZ(word[i-1])) {
      
      ADD_ES(word);
   }
   
   else if (word[i-1] == 'h') {
   
      if (word[i-2] =='c' || word[i-2] =='s') {
      
         ADD_ES(word);
      }      
   }
   
   else if (word[i-1] =='y') {
      
      if (isVOWEL(word[i-2])){
         ADD_S(word);
      }
      else {
         ADD_IES(word);
      }   
   }
   
   else if (word[i-1] == 'e') { 
      if (word[i-2] =='f')  {
         ADD_VES(word);
      }
      else {
         ADD_S(word);
      }            
   }
   
   else if (word[i-1] =='f') {
      ADD_VES(word);
   }
   
   else {
      ADD_S(word);
   }    
            
   return;
   
}












