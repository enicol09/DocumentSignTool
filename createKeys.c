/** @file createKeys.c
 *  @brief This is the c file that helps the implementation of Hw_2.
 *         It contains all the function implementations as they are declared at h file createKeys.h .
 *         Overall, this c file contains the function implementations that they are need in order to create
 *         the keys - in 2 files => public.pem / private.pem
 *
 *  You can see below all the function exmplanations.
 *
 *  @author Elia Nicolaou 1012334
 *  @version 1
 *  @bug No know bugs.
 *  @see docsign.c , createKeys.h\
 * 
 * For the implementations of the above i used as references the below links : 
 * https://developers.yubico.com/PIV/Guides/Generating_keys_using_OpenSSL.html
 * https://www.dynamsoft.com/codepool/how-to-use-openssl-generate-rsa-keys-cc.html
 * https://www.example-code.com/C/rsa_generateKey.asp
 *
 */

#include "createKeys.h"

  
  /* This function is being called in order to find whether a file exists or not.
   * @param fname : the filename ( file ) tha is going to be checked.
   * @return true if exists and false if it doesnt */
bool boolExists(const char *fname) {
   if(!(access( fname, F_OK ) == 0 )) {
      return true; }
    return false;
}
 /* This function is being called in order to create the public and private key, in 2 files
   * public.pem and private.pem in case they do not exist */
void createPem(){

             int ret = 0;
	RSA *r = NULL;
	BIGNUM	*bne = NULL;
	BIO *bp_public = NULL, *bp_private = NULL;

	int bits = 2048;
	unsigned long e = RSA_F4;

	// 1. generate rsa key
	bne = BN_new();
	ret = BN_set_word(bne,e);
	if(ret != 1){
		goto free_all;
	}

	r = RSA_new();
	ret = RSA_generate_key_ex(r, bits, bne, NULL);
	if(ret != 1){
		goto free_all;
	}

	// 2. save public key
        if(boolExists(PUBLIC)){
	bp_public = BIO_new_file("public.pem", "w+");
	ret = PEM_write_bio_RSAPublicKey(bp_public, r);
	if(ret != 1){
		goto free_all;
	}
}
         if(boolExists(PRIVATE)){
	// 3. save private key
	bp_private = BIO_new_file("private.pem", "w+");
	ret = PEM_write_bio_RSAPrivateKey(bp_private, r, NULL, NULL, 0, NULL, NULL);
       }
	// 4. free
        free_all:

	BIO_free_all(bp_public);
	BIO_free_all(bp_private);
	RSA_free(r);
	BN_free(bne);

}
