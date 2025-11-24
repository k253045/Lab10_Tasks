#include <stdio.h>
#include <string.h>

struct Movie {
    char title[50];
    char genre[30];
    char director[50];
    int releaseYear;
    float rating;
};

void addMovie(struct Movie movies[], int *count, int max);
void viewAllMovies(struct Movie movies[], int count);
void searchByGenre(struct Movie movies[], int count);

int main() {
    int maxMovies = 100;
    struct Movie movies[100];
    int count = 0;
    int choice;

    do {
        printf("1. Add New Movie\n");
        printf("2. Search Movies by Genre\n");
        printf("3. Display All Movies\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
        case 1:
            addMovie(movies, &count, maxMovies);
            break;
        case 2:
            searchByGenre(movies, count);
            break;
        case 3:
            viewAllMovies(movies, count);
            break;
        case 4:
            printf("Exiting \n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}

void addMovie(struct Movie movies[], int *count, int max) {
    if (*count >= max) {
        printf("Movie list full\n");
        return;
    }

    struct Movie m;

    printf("Enter movie title: ");
    fgets(m.title, sizeof(m.title), stdin);
    m.title[strcspn(m.title, "\n")] = '\0';

    printf("Enter genre: ");
    fgets(m.genre, sizeof(m.genre), stdin);
    m.genre[strcspn(m.genre, "\n")] = '\0';

    printf("Enter director: ");
    fgets(m.director, sizeof(m.director), stdin);
    m.director[strcspn(m.director, "\n")] = '\0';

    printf("Enter release year: ");
    scanf("%d", &m.releaseYear);

    printf("Enter rating: ");
    scanf("%f", &m.rating);
    getchar();

    movies[*count] = m;
    (*count)++;

    printf("Movie added\n");
}

void searchByGenre(struct Movie movies[], int count) {
    char searchGenre[30];
    int found = 0;

    printf("Enter genre to search: ");
    getchar();
    fgets(searchGenre, sizeof(searchGenre), stdin);
    searchGenre[strcspn(searchGenre, "\n")] = '\0';

    for (int i = 0; i < count; i++) {
        if (strcasecmp(movies[i].genre, searchGenre) == 0) {
            printf("Title: %s\n", movies[i].title);
            printf("Director: %s\n", movies[i].director);
            printf("Year: %d\n", movies[i].releaseYear);
            printf("Rating: %.1f\n", movies[i].rating);
            found = 1;
        }
    }

    if (!found) {
        printf("No movies found\n");
    }
}

void viewAllMovies(struct Movie movies[], int count) {
    if (count == 0) {
        printf("No movies available\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("Title: %s\n", movies[i].title);
        printf("Genre: %s\n", movies[i].genre);
        printf("Director: %s\n", movies[i].director);
        printf("Year: %d\n", movies[i].releaseYear);
        printf("Rating: %.1f\n", movies[i].rating);
    }
}



