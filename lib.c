#include <stdio.h>

struct book{
        int id;
        char name[50];
        char genre[50];
    };

int main(){
   

    int choose;

    do{
        printf("---MENU---\n");
        printf("Choose the option:\n");
        printf("1- Add Book\n");
        printf("2- Read Lib\n");
        printf("3- Exclude\n");
        printf("4- Quit\n");
        scanf("%d", &choose);

        switch (choose){
            case 1:
                FILE *db = fopen("db.txt", "a");  // Pointer
                if (db != NULL){     //checks if the database exists
                    struct book nBook;
                    printf("Please provide the ID of the book to be added: ");
                    scanf(" %d", &nBook.id);                
                    printf("Please provide the NAME of the book to be added: ");
                    scanf(" %[^\n]s", nBook.name);
                    printf("Please provide the GENRE of the book to be added: ");
                    scanf(" %[^\n]s", nBook.genre);                
                    fprintf(db, "%d|%s|%s\n", nBook.id, nBook.name, nBook.genre);
                    fflush(db);
                    fclose(db);
                    printf("File SAVED!");
                }else{
                    printf("The file could not be opened!");
                }break;
            case 2:
                FILE *dbRead = fopen("db.txt", "r"); // OPEN archive to Read
                if (dbRead == NULL){printf("Error: DataBase is empty!\n");} // Return error
                else{
                    struct book b; // Temp variable
                    printf("-----LIBRARY-----\n");

                    while(fscanf(dbRead, "%d|%[^|]|%[^\n]\n", b.id, b.name, b.genre) == 3){
                        printf("ID: %d | NAME: %s | GENRE: %s\n", b.id, b.name, b.genre);
                    }
                    fclose(dbRead);
                }break;
            
        }
    }while(choose != 4);
}