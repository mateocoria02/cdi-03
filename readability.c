#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 4096



int read_file(char *text, char *filename);

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Uso: ./readability file\n");
        return 1;
    }

    char text[MAX];

    if (read_file(text, argv[1])) {
        printf("Archivo no encontrado\n");
        return 1;
    }

    // TODO

    int i=0;//cuadrantes
    int o=0;//oraciones
    int l2=0;//letras
    int p=0;//palabras

//text =palabras en especifico en el texto  
    while(text[i]){

        if(text[i]=='.'||text[i]=='!'||text[i]=='?'){

            o++;

        }

        if(isalpha(text[i])>=1){

            l2++;

        }

        if(isspace(text[i])>=1){

            p++;

        }

        i++;

    }

    printf("%d", "%d", "%d", o, l2, p);
    
    float L=(l2/p)*100;
    float S=(o/p)*100;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    

    if(index>16){

        printf("Grade +16");

    }
    else if(index<1){

        printf("Before grade 1");

    }
    else{

        printf("%f grado ", index);

    }


    return 0;
}

int read_file(char *text, char *filename) {

    FILE *fp;
    char c;
    char full_name[30];
    
    sprintf(full_name, "texts/%s.txt", filename);
    fp = fopen(full_name, "r");
    
    if (!fp) {
        return 1;
    } 
    while ((c = getc(fp)) != EOF) {
        *text = c;
        text++;
    }
    return 0;
}
