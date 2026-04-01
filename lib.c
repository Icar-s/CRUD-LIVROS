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
        scanf("%d", &nBook.id);
    }else{
        printf("The file could not be opened!");
    }

}