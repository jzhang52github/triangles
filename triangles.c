#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
  char input[256];
  int x; 
  int y; 
  int z;
  if (strcmp(argv[0],"user") == 0){
    fgets(input, 255, stdin);
    sscanf(input, "%d %d %d", &x, &y, &z);
    printf("The input values are %d, %d, %d\n", x, y, z);
    printf("RESULT\n");
    if((x+y)>z&&(y+z)>x&&(z+x)>y){
      printf("\tValid\n");
    }
    else{
      printf("\tInvalid\n");
    }
  }
  if (strcmp(argv[0],"horizontal") == 0){
    FILE * input_file = fopen("input","r");
    int counter = 0;
    int total = 0;
    while(fgets(input, 255, input_file)){
      sscanf(input, "%d %d %d", &x, &y, &z);
      if((x+y)>z&&(y+z)>x&&(z+x)>y){
        counter++;
      }
      total++; 
    }
    printf("Out of %d triangles tested, there are %d valid triangles in the set.\n",total,counter);
  }
  else{
    printf("ERROR: Invalid or no arguments. \n");
    printf("DIRECTIONS\n");
    printf("\t./a.out user will read 3 ints from stdin and print either valid or invalid.\n");
    printf("\t./a.out horizontal will treat each line of input as a triangle, and print the total number of valid triangles in the set.\n");
  }
  return 0;
}
