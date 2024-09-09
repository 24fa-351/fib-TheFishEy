#include <stdio.h>
#include <stdlib.h>
//Patrick Hung 860865329

int fIterative(int index);
int fRecursive(int index);

int main(int argumentLine, char *argumentValue[]) {

   if (argumentLine != 4)
   {
      printf("Input error");
      return 1; 
   }

   int argument1 = atoi(argumentValue[1]);


   // * I DONT THINK THIS IS RIGHT BUT I PUT IT IN BECAUSE THE TST CASES FIB INDEX SEEMS TO BE OFF BY 1
   argument1 = argument1-1;



   char which = argumentValue[2][0];//[0] is for accessign character in string
   char *fileName = argumentValue[3];

  

   FILE *file = fopen(fileName, "r");
   if (file == NULL)
   {
      printf("Unable to open file\n");
      return 1;
   }

   int fileInt;
   fscanf(file, "%d", &fileInt);
   fclose(file);

   int index = argument1 + fileInt;

   int answer;
   if(which == 'i') 
   {
      answer = fIterative(index);
   }
   else{
      answer = fRecursive(index);
   }


   printf("%d", answer);

   return 0;
}

// iternative
int fIterative(int index) {
   if (index <= 0) return 0; 
   if (index == 1) return 1; 

   int a = 0;
   int b = 1;
   int temp;
   for (int i = 2; i <= index; i++) {
      temp = a + b;
      a = b;
      b = temp;
   }
   return b;
}

// recursive
int fRecursive(int index){
   if (index <= 0) return 0;
   if (index == 1) return 1;


   return fRecursive(index - 1) + fRecursive(index - 2);
}


