/** @file cryptoOperations.c
 *  @brief This is the c file that helps the implementation of Hw_2.
 *         It contains all the function implementations as they are declared at h file cryptoOperations.h.
 *         Overall, this c file contains the function implementations that they are need in order to create
 *         the signature and verify the signature.
 *
 *  You can see below all the function exmplanations.
 *
 *  @author Elia Nicolaou 1012334
 *  @version 1
 *  @bug No know bugs.
 *  @see docsign.c , createKeys.h, help.h , cryptoOperations.h
 * 
 * 
 *
 */

 #include "cryptoOperations.h"
/*-------------------------------------------------*/

 /* This function is being called when we are using the first option that means that we want to sign 
   * a given file. If the file is signed properly it prints verification message, else it prints nothing.
   * @param fname : the given file that is going to be signed.
   * */
void doSignOperation(const char *fname) {
    
    int chars = countCharacters(fname); //first we called to find how many characters are in the file.
    
    if(DEBUG)
    printf("\n chars %d:" , chars);
    
    //use the above in order to get the plaintext.
    unsigned char datamu[chars];
    
    FILE *filePointer;
    char ch;
    int i = 0;

     filePointer = fopen(fname, "r");
     while ((ch = fgetc(filePointer)) != EOF)
        {
          datamu[i] = ch;
           i++;
        } 
     fclose(filePointer);

     //we use this two function below given in the OpenSSL in order to create the digest of the given plaintext.
     unsigned char buf[SHA256_DIGEST_LENGTH];
     unsigned char *digest= SHA256(datamu, strlen((const char *)datamu),
               buf);

     //we have done the digest operation so now we are going to signed the document.
     FILE *fp;

     fp = fopen(PRIVATE,"r"); // we open the private.pem file in order  to get the private key.
     RSA *rsa = NULL;
     rsa = RSA_new();
    
     //we read the private key. 
     PEM_read_RSAPrivateKey(fp,&rsa,NULL,NULL);
       
     if (rsa == NULL) { 
     printf("ERROR with reading the private key \n");
     exit(1); }
   
     unsigned char *sigret = malloc((RSA_size(rsa)));
     unsigned int sign = 0; 

     if(RSA_sign(NID_sha256,digest,SHA256_DIGEST_LENGTH,sigret,&sign,rsa) != 1){
        printf("ERROR with signing the document");
        exit(1); }
       
        //producing the filename
        int c1 = strlen(fname);
        int c2 = strlen(".signed");
        char *file = malloc((c1+c2) * sizeof(char));
        for( i=0; i<c1;i++){
        if(fname[i]=='.' || (fname[i]=='/' && i==0))
        break;
        file[i] = fname[i]; }
        file[i]='\0'; 
        strcat(file,".signed");
        file[i+c2]='\0';

        //opening the new file that we are going to save the sign.
        FILE * fPtr;
        fPtr = fopen(file, "w");
    
        if(fPtr == NULL)
       {
        printf(" ERROR : Unable to create the .signed file.\n");
        exit(1);
      } 
     
        fprintf(fPtr,"%s",(datamu)); //first we print the plaintext
        int n;
        for (n = 0; n < sign; n++) 
        fputc(sigret[n],fPtr);
        
       fclose(fPtr);
       
       //everything went well, so print verification message.
       printf("\nDocument %s was just signed. Signed document: %s.\n",fname,file);

}


  /* This function is being called when we are using the second option that means that we want to validate
   * a given file. If the file is correct properly it prints verification message, else it prints nothing.
   * @param fname : the given file that is going to be verified.
   * */
void doValidate(const char* fname){
 
    unsigned char *data;
    int ch;
    int chars = 0;
    int  i=0;

    FILE *filePointer = fopen(fname , "r");
    if (filePointer == NULL)
    {
        printf("ERROR with opening the file");
        return;
    }

    while ((ch = fgetc(filePointer)) != EOF){
        chars++;
    }

    fclose(filePointer);

    if(chars<256){
    printf("ERROR with the file \n");
    } 

    filePointer = fopen(fname, "r");
    data = malloc(sizeof(unsigned char)*(chars-256));
    for(i=0;i<chars-256;i++)
        data[i] = fgetc(filePointer);

   //getting the sign
    unsigned char *sign = malloc(256 * sizeof(char));
    i = 0;
    while ((ch = fgetc(filePointer)) != EOF)
        {
          sign[i] = ch;
          i++;
        }  
   //close the file
   fclose(filePointer);

   //creating the digest of the file
   unsigned char buf[SHA256_DIGEST_LENGTH];
   unsigned char *dig = SHA256(data, strlen((const char *)data),buf);
     
    FILE *fp;
   //opening the public.pem file.
   fp = fopen(PUBLIC,"rt");
   RSA *rsa = NULL;
   rsa = RSA_new();

   //read the public key
   if(PEM_read_RSAPublicKey(fp,&rsa,NULL,NULL)==NULL){
    printf("ERROR with reading the public key \n");
    exit(1); }
   
    fclose(fp);
    
   //verification
   if(RSA_verify(NID_sha256,dig,SHA256_DIGEST_LENGTH,sign,256, rsa) == 1){
        printf("\n Digital signature is valid. \n"); }
    else{
        printf("\n Digital signature is not valid. \n"); }
}
