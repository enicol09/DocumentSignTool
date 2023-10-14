/** @file createKeys.h
 *  @brief This is a header file that helps in the implementation of Hw_2.
 *         You can see all the function implementations in the c file createKeys.c.Overall,
 *         this h file contains the function declarations that they are need in order to create 
 *         the public and private key in 2 functions => a. private.pem b. public.pem
 *         The files with the keys are being used by the main program => docsign.c
 *  You can see below all the function exmplanations.
 *
 *  @author Elia Nicolaou 1012334
 *  @version 1
 *  @bug No know bugs.
 *  @see docsign.c, createKeys.c
 * 
 * For the implementations of the above i used as references the below links : 
 * https://developers.yubico.com/PIV/Guides/Generating_keys_using_OpenSSL.html
 * https://www.dynamsoft.com/codepool/how-to-use-openssl-generate-rsa-keys-cc.html
 * https://www.example-code.com/C/rsa_generateKey.asp
 */

//define the header files.

#ifndef CREATE_KEYS_H
#define CREATE_KEYS_H

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

//=====================DEFINE CONSTANTS =======================//

 #define PRIVATE "private.pem"
 #define PUBLIC "public.pem"
  
  /* This function is being called in order to find whether a file exists or not.
   * @param fname : the filename ( file ) tha is going to be checked.
   * @return true if exists and false if it doesnt */
  bool boolExists(const char *fname);
  /* This function is being called in order to create the public and private key, in 2 files
   * public.pem and private.pem in case they do not exist */
  void createPem();

#endif
