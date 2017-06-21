#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

void CALCULATE_PI ();
int GET_SEED ();
int GET_NUM_ITERATION ();
bool ISFORMAT (int numEntered, int numNeeded, char lastChar);

double NUM_GENERATOR();
double DISTANCE(double x, double y);
int CALC_POINT_IN_CIRCLE(int seed, int numIteration);


int main() {

   CALCULATE_PI();
   
   return 0 ;
}   


void CALCULATE_PI() {

   int seed, numIteration;
   int numPointPicked;
   
   /*
    * Ask user to input seed and number of iterations
    *
    * Verify the format after every input: 
    *    if the input is not matched with the requirement,
    *    continue ask user to reinput again until it matches
    * 
    * Calculate the value of pi and print the result
    */
   
   seed = GET_SEED();
   numIteration = GET_NUM_ITERATION();
   
   numPointPicked = numIteration;
   
   printf("The value of pi is %0.5lf.\n", 
           (double)(CALC_POINT_IN_CIRCLE(seed,numIteration) 
           / (double)numPointPicked * 4));
       
   return ;
}


int GET_SEED() {

   /*
    * Ask user to input seed number, if its wrong format
    *    continue asking until user inputs correctly
    */
   int numEntered, seed;
   char lastChar;
       
   do {
   
      printf("Enter the seed for the random number generator: ");
      numEntered = scanf(" %d%c",&seed,&lastChar);
      
   } while (!ISFORMAT(numEntered,2,lastChar));
  
  return seed;
  
}


int GET_NUM_ITERATION() {
   
   /*
    * Ask user to input number of interation,
    * if its wrong format, continue asking until user 
    *   inputs correctly
    */ 
    
   int numEntered,numIteration;
   char lastChar;

   do {
   
      printf("Enter the number of iterations to run: ");
      numEntered = scanf(" %d%c",&numIteration,&lastChar);
   
   } while (!(ISFORMAT(numEntered,2,lastChar) && numIteration >0));
 
  return numIteration; 
}


bool ISFORMAT(int numEntered, int numNeeded, char lastChar) { 
   bool value = true;
   /*
    * Verify input format: return true if the number of input user entered
    *   has to match with number needed    
    */
   if ((numEntered == numNeeded) && (lastChar == '\n')) {
   
      return value;
   
   } 
   
   else {
   
   /*
    * Eat up all characters that are not number 
    *    to prepare for another input
    */
      do {
         scanf("%c",&lastChar);
         if (!isspace(lastChar)) {
            value = false;
         }
      } while (lastChar != '\n');
      
   }

   return value;
}

double NUM_GENERATOR(){
   
   /*
    * Generate a random number between -1 and 1
    */
   int LO = -1;
   int HI =  1;
   
   return (LO + ((double)rand())/(((double)RAND_MAX) / (HI - LO)));
   
}


int CALC_POINT_IN_CIRCLE(int seed, int numIteration) {

   /* 
    * Generate N-number of points that equal to number of 
    *    iteration  
    *
    * Calculate distance away from the center of points
    *    were generated using distance formular
    *
    * If distnace <= 1, which indicates the points are inside
    *    the circle
    * 
    * Return number of points that locates inside cicle   
    */
   
   int numPointInCir=0;
   double x,y;
   
   srand(seed); 
   
   for (int i=0; i<numIteration; ++i) {
      
      x = NUM_GENERATOR();
      y = NUM_GENERATOR();
           
      if (DISTANCE(x,y) <= 1) {
         numPointInCir += 1;
      }
   } 
   
   return numPointInCir;
}


double DISTANCE(double x, double y){
   
   /*
    * Distance away from the center (0,0)
    *    sqrt( (x-0)^2 + (y-0)^2) )
    */
    
   return sqrt(x*x + y*y);

}









     



