/** @file help.c
 *  @brief This is the c file that helps the implementation of Hw_2.
 *         It contains all the function implementations as they are declared at h file help.h .
 *         Overall, this c file contains the function implementations that they are need for the implementation
 *         of the homework.
 *  You can see below all the function exmplanations.
 *
 *  @author Elia Nicolaou 1012334
 *  @version 1
 *  @bug No know bugs.
 *  @see docsign.c , createKeys.h , createKeys.c, help.h
 * 
 *
 */

//include libraries.
#include "help.h"

 /* This function is being called in order to find whether a file exists or not.
   * if the file doesn't  exists then it prints an error message and exists.
   * @param fname : the filename ( file ) tha is going to be checked.
   * */
void exists(const char *fname) {
   if(!(access( fname, F_OK ) == 0 )) {
    printf(" \n The given file doesnt exists");
    exit(1);
  }
}

/* This function is being called in order to find how many characters are in a file.
   * @param fname : the filename ( file ) tha is going to be checked for how many characters it has.
   * @return the number of characters.
   * */
int countCharacters(const char *fname) {

    FILE *filePointer;
    int c = 0;
    char ch;

    filePointer = fopen(fname, "r");

   if (filePointer == NULL)
    {
        printf("File is not available \n");
    }
    else
    {
        while ((ch = fgetc(filePointer)) != EOF)
        {
            c++;
        }
    }

    fclose(filePointer);
    return c;
}
