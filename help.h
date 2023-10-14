/** @file help.h
 *  @brief This is a header file that helps in the implementation of Hw_2.
 *         You can see all the function implementations in the c file help.c.Overall,
 *         this h file contains the function declarations that they are need in order to create 
 *         some functions that are going to be helpful for the implementation of the program.
 *
 *  @author Elia Nicolaou 1012334
 *  @version 1
 *  @bug No know bugs.
 *  @see docsign.c, createKeys.c , help.c
 * 
 * 
 */

//define the header files.

#ifndef HELP_H
#define HELP_H

//--------------------------------------------------//

//include libraries.

 #include <stdbool.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <openssl/rsa.h>
 #include "openssl/sha.h"
 #include <openssl/pem.h>
 #include <openssl/ssl.h>

//===================== FUNCTIONS =======================//

 /* This function is being called in order to find whether a file exists or not.
   * if the file doesn't  exists then it prints an error message and exists.
   * @param fname : the filename ( file ) tha is going to be checked.
   * */
void exists(const char *fname);

/* This function is being called in order to find how many characters are in a file.
   * @param fname : the filename ( file ) tha is going to be checked for how many characters it has.
   * @return the number of characters.
   * */
int countCharacters(const char *fname);

#endif






