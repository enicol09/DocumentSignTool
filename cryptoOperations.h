/** @file cryptoOperations.h
 *  @brief This is a header file that helps in the implementation of Hw_2 and especially the most important file.
 *         You can see all the function implementations in the c file cryptoOperations.c. Overall,
 *         this h file contains the function declarations that they are need in order to implement the sign
 *         operation and the verify operation.
 *
 *  You can see below all the function exmplanations.
 *
 *  @author Elia Nicolaou 1012334
 *  @version 1
 *  @bug No know bugs.
 *  @see docsign.c, createKeys.c , help.c
 * 
 */

//define the header files.

#ifndef CRYPTO_OPERATIONS_H
#define CRYPTO_OPERATIONS_H

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
 
 //include my_libraries
 #include "createKeys.h"
 #include "help.h"

//=====================DEFINE CONSTANTS =======================//
#define DEBUG false

  /* This function is being called when we are using the first option that means that we want to sign 
   * a given file. If the file is signed properly it prints verification message, else it prints nothing.
   * @param fname : the given file that is going to be signed.
   * */
void doSignOperation(const char *fname) ;

  /* This function is being called when we are using the second option that means that we want to validate
   * a given file. If the file is correct properly it prints verification message, else it prints nothing.
   * @param fname : the given file that is going to be verified.
   * */
void doValidate(const char* fname);


#endif
