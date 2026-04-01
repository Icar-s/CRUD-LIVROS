#include <stdio.h>

struct book{
        int id;
        char name[50];
        char gender[50];
    };

int main(){
   
    FILE *db = fopen("db.txt", "a");  // Pointer

    if (db != NULL){     //checks if the database exists
        struct book nBook;
        printf("Please provide the ID of the book to be added: ");
        scanf(" %d", &nBook.id);
        printf("Please provide the NAME of the book to be added: ");
        scanf(" %[^\n]s", nBook.name);
        printf("Please provide the GENDER of the book to be added: ");
        scanf(" %[^\n]s", nBook.gender);

        fprintf(db, "%d|%s|%s\n", nBook.id, nBook.name, nBook.gender);
        fflush(db);
        fclose(db);
        printf("File SAVED!");

    }else{
        printf("The file could not be opened!");
    }

}