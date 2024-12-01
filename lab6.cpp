#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BOOKS 100
#define MAX_LENGTH 100

typedef struct {
    char* last_name;      
    char* first_name;     
    char* title;          
    char* publisher;      
    int year;             
} book;


void free_book(book* b) {
    if (b->last_name) free(b->last_name);
    if (b->first_name) free(b->first_name);
    if (b->title) free(b->title);
    if (b->publisher) free(b->publisher);
}

book create_book() {
    book new_book = {0}; 
    char buffer[MAX_LENGTH];

    printf("Введите фамилию автора: ");
    fgets(buffer, MAX_LENGTH, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    new_book.last_name = strdup(buffer);

    
    printf("Введите имя автора: ");
    fgets(buffer, MAX_LENGTH, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    new_book.first_name = strdup(buffer);

    
    printf("Введите название книги: ");
    fgets(buffer, MAX_LENGTH, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    new_book.title = strdup(buffer);

    
    printf("Введите издательство: ");
    fgets(buffer, MAX_LENGTH, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    new_book.publisher = strdup(buffer);

    
    printf("Введите год издания: ");
    scanf("%d", &new_book.year);
    getchar(); 

    return new_book;
}


void print_books(book books[], int count) {
    if (count == 0) {
        printf("\nСписок книг пуст.\n");
        return;
    }

    printf("\n%-20s %-20s %-30s %-20s %-5s\n", "Фамилия автора", "Имя автора", "Название книги", "Издательство", "Год");
    printf("-------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-20s %-30s %-20s %-5d\n",
               books[i].last_name, books[i].first_name, books[i].title, books[i].publisher, books[i].year);
    }
}


void find_books_by_author(book books[], int count, char* author) {
    int found = 0;
    printf("\nКниги автора %s:\n", author);
    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].last_name, author) == 0) {
            printf("- %s\n", books[i].title);
            found = 1;
        }
    }
    if (!found) {
        printf("Книги данного автора не найдены.\n");
    }
}

void sort_strings(char* strings[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(strings[i], strings[j]) > 0) {
                char* temp = strings[i];
                strings[i] = strings[j];
                strings[j] = temp;
            }
        }
    }
}


void find_authors_by_publisher(book books[], int count, char* publisher) {
    char* authors[MAX_BOOKS];
    int author_count = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].publisher, publisher) == 0) {
            authors[author_count++] = books[i].last_name;
        }
    }

    if (author_count == 0) {
        printf("\nАвторы издательства %s не найдены.\n", publisher);
        return;
    }

    sort_strings(authors, author_count);

    printf("\nАвторы издательства %s:\n", publisher);
    for (int i = 0; i < author_count; i++) {
        printf("- %s\n", authors[i]);
    }
}

int main() {
    book books[MAX_BOOKS]; 
    int count = 0;         
    int choice;
    
    do {
        printf("1.Добавить новую книгу\n");
        printf("2.Показать все книги\n");
        printf("3.Найти книги автора\n");
        printf("4.Найти авторов издательства\n");
        printf("5.Выход\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1: 
                if (count < MAX_BOOKS) {
                    books[count++] = create_book();
                } else {
                    printf("Массив книг заполнен!\n");
                }
                break;

            case 2: 
                print_books(books, count);
                break;

            case 3: {
                char author[MAX_LENGTH];
                printf("Введите фамилию автора: ");
                fgets(author, MAX_LENGTH, stdin);
                author[strcspn(author, "\n")] = '\0'; 
                find_books_by_author(books, count, author);
                break;
            }

            case 4: { 
                char publisher[MAX_LENGTH];
                printf("Введите название издательства: ");
                fgets(publisher, MAX_LENGTH, stdin);
                publisher[strcspn(publisher, "\n")] = '\0';
                find_authors_by_publisher(books, count, publisher);
                break;
            }

            case 5: 
                printf("Выход из программы.\n");
                for (int i = 0; i < count; i++) {
                    free_book(&books[i]);
                }
                break;

            default:
                printf("Неверный выбор. Попробуйте снова.\n");
        }
    } while (choice != 5);

    return 0;
}
