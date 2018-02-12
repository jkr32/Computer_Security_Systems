#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string>



int main(int argc, char** argv) {
    
    /* if (argc!=3) {
     printf("command (for example) : ./enc1 file_to_encrypt key_in_hex\n");
     return 1;
     }*/
    
    argv[1]="/Users/alireza/Downloads/proj3/secret.pdf.enc1";


    
    char* filePDF="/Users/alireza/Downloads/proj3/in.txt";
    int pdf=open(filePDF, O_RDONLY);
    if (pdf<0) {
        printf("cannot open the file %s\n", filePDF);
        return 1;
    }
    
    // open the file to save the encryption

    //find the key


    unsigned long long pdfV;

    char c='0';
    for(int i=0;i<7;i++)
    {
        unsigned long long buf;
        int len=8;
        char tempBuf[8];
        unsigned long long key;
        unsigned long long k;
        
        char* file=argv[1];
        int fdp=open(file, O_RDONLY);
        if (fdp<0) {
            printf("cannot open the file %s\n", file);
            return 1;
        }
        read(fdp, (char*)&buf, 8);
        
        char enc[strlen(file)-4];
        strncpy(enc, file, strlen(file)-6);
        enc[strlen(file)-8]=c++;
        strncpy(enc+strlen(file)-7, ".pdf\0", 5);
        enc[strlen(file)-1]='\0';
        int fdc=open(enc, O_CREAT|O_WRONLY, S_IRUSR|S_IWUSR);
        if (fdc<0) {
            printf("cannot save the decrypted file %s\n", enc);
            return 1;
        }
        
        
        read(pdf, (char*)&pdfV, 8);
        key=buf^pdfV;
        k=key;
        do {
            buf^=k;
            k*=key;
            write(fdc, (char*)&buf, len);
        }while ((len=read(fdp, (char*)&buf, 8))>0);
        close(fdc);
        close(fdp);
    }
    // encryption
    
    
    close(pdf);

    return 0;
}

int mai123n()
{
    /*unsigned long long buf=3759996809423114277;
    unsigned long long encbuf=2745620539022247517;
    unsigned long long inKey=1311768465173141112;
    unsigned long long myKey=1527941247286924920;
    
    unsigned long long result=buf^encbuf;*/
    unsigned long long maxKey=18446744073709551615;
    unsigned long long key=0;
    for(;key<maxKey;key++){
        char str[50];
        sprintf(str, "%llull", key);
        printf("%llu\n",key);
    }
    
    
    return 0;
}

