#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h> 
#include <fstream> 

int main(int argc, char* argv[]){
    
    FILE *fp_1 = fopen(argv[1], "rb");
    FILE *fp_2 = fopen(argv[2], "rb");
    uint32_t file1, file2;

    if(argc != 3){
        fputs("Usage: program <file1.bin> <file2.bin>\n", stderr);
        exit(1);
    }

    if(fp_1 == NULL || fp_2 == NULL){
        printf("File open Error");
        exit(1);
    }

    fread(&file1, sizeof(uint32_t), 1, fp_1);
    fread(&file2, sizeof(uint32_t), 1, fp_2);
    
    file1 = ntohl(file1);
    file2 = ntohl(file2);
    
    printf("%d\n",file1+file2);

    fclose(fp_1);
    fclose(fp_2);
}

