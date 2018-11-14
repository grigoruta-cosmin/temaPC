#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int nr_legitimatie;
    char nume[30];
}student;

void print_encrypt(int ids[100], int id_counter){
    FILE *fisier;
    fisier = fopen("encrypt.txt", "w+");
    for(int i = 0 ; i < id_counter ; i++){
        fprintf(fisier, "%d \n", transf_binar(ids[i]));
    }
    fclose(fisier);
}

int transf_binar(int number){
    int nr_2 = 0, p = 1, c;
    while(number != 0){
        c = number % 2;
        number /= 2;
        nr_2 = nr_2 + c*p;
        p *= 10;
    }
    return nr_2;
}

int *crypt_id(student list[100], int list_count){
    static int ids[100];
    for(int i = 0 ; i < list_count ; i++){
        list[i].nr_legitimatie = list[i].nr_legitimatie ^ 7;
        ids[i] = list[i].nr_legitimatie;
    }
    return ids;
}

int main()
{
    student students[200];
    int numar_studenti;
    printf("Numarul studentilor =");
    scanf("%d", &numar_studenti);
    for(int i = 0 ; i < numar_studenti ; i++){
        printf("Numar Legitimatie =");
        scanf("%d", &students[i].nr_legitimatie);
        getchar();
        printf("\nNume Student=");
        fgets(students[i].nume, 30, stdin);
        students[i].nume[strlen(students[i].nume) - 1] = '\0';
    }

    for(int i = 0 ; i < numar_studenti ; i++){
        printf("Numarul Legimitatie: %d Nume: %s \n", students[i].nr_legitimatie, students[i].nume);
    }

    printf("***CRIPTAT***");

    int *legitimatii = crypt_id(students, numar_studenti);
    print_encrypt(legitimatii, numar_studenti);

    return 0;
}
