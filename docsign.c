/** @file docsing.c
 *   @brief This is the main function of the implementation of HW2 in C programming language.
 * The program uses OpenSSL for cryptographically signing any file of your
 * system. The tool should be able to run in two modes: (a) signing mode, and (b) validation mode.
 * In mode (a), the tool should open a document, compute the digital signature of the document
 * and produce a new document that concatenates the original document with the produced digital
 * signature. In mode (b), the tool should load a signed document from the disk and check if the
 * attached signature is correct.
 *
 *  @author Elia Nicolaou 1012334
 *  @version 1
 *  @bug No know bugs.
 *
 */

// Define Libraries
#include "cryptoOperations.h"

// the main function
int main(int argc, char const *argv[])
{

  // always checked if the public/private.pem files exists.
  createPem();
  int size = argc - 1;
  // char fname[strlen(argv[1])];

  if (DEBUG)
  {
    printf("size is %i ", size);
    printf("%s", argv[1]);
  }

  if (size == 0)
  {
    printf(" \n Usage: docsign -sv \n -s sign document \n -v validate signature");
  }
  else if (size == 2)
  {
    char fname[strlen(argv[1])];
    if (!strcmp(argv[1], "-s"))
    {
      strcpy(fname, argv[2]);
      // always checked the file exists.
      exists(fname);
      // calling function for signing.
      doSignOperation(fname);
    }
    else if (!strcmp(argv[1], "-v"))
    {
      strcpy(fname, argv[2]);
      // always checked if the file exists.
      c
          // calling function for validation
          doValidate(fname);
    }
    else
    {
      printf("ERROR -1: Wrong Command Line format -> Usage : docign -sv \n");
      exit(1);
    }
  }
  else
  {
    printf(" ERROR -2: Wrong Command Line format -> Usage : docign -sv \n");
    exit(1);
  }
}
