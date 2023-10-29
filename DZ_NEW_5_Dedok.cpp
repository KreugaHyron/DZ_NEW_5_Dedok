#include <iostream>
using namespace std;
const int MAX_MOVIES = 100;

struct NetflixMovie {
    char title[100];
    char director[100];
    char genre[50];
    float popularityRating;
    float price;
};

NetflixMovie movies[MAX_MOVIES];
int numMovies = 0;

void addMovie(const char* title, const char* director, const char* genre, float popularityRating, float price) {
    if (numMovies < MAX_MOVIES) {
        strcpy_s(movies[numMovies].title, title);
        strcpy_s(movies[numMovies].director, director);
        strcpy_s(movies[numMovies].genre, genre);
        movies[numMovies].popularityRating = popularityRating;
        movies[numMovies].price = price;
        numMovies++;
    }
    else {
        cout << "Максимальное количество фильмов достигнуто." << "\n";
    }
}
void searchByTitle(const char* title) {
    for (int i = 0; i < numMovies; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            cout << "Название: " << movies[i].title << ", Режиссёр: " << movies[i].director
                << ", Жанр: " << movies[i].genre << ", Рейтинг: " << movies[i].popularityRating
                << ", Цена: " << movies[i].price << "\n";
            return;
        }
    }
    cout << "Фильм с названием '" << title << "' не найден." << "\n";
}
void searchByGenre(const char* genre) {
    for (int i = 0; i < numMovies; i++) {
        if (strcmp(movies[i].genre, genre) == 0) {
            cout << "Название: " << movies[i].title << ", Режиссёр: " << movies[i].director
                << ", Жанр: " << movies[i].genre << ", Рейтинг: " << movies[i].popularityRating
                << ", Цена: " << movies[i].price << "\n";
        }
    }
}
void searchByDirector(const char* director) {
    for (int i = 0; i < numMovies; i++) {
        if (strcmp(movies[i].director, director) == 0) {
            cout << "Название: " << movies[i].title << ", Режиссёр: " << movies[i].director
                << ", Жанр: " << movies[i].genre << ", Рейтинг: " << movies[i].popularityRating
                << ", Цена: " << movies[i].price << "\n";
        }
    }
}
void mostPopularInGenre(const char* genre) {
    float maxRating = -1;
    int index = -1;

    for (int i = 0; i < numMovies; i++) {
        if (strcmp(movies[i].genre, genre) == 0) {
            if (movies[i].popularityRating > maxRating) {
                maxRating = movies[i].popularityRating;
                index = i;
            }
        }
    }

    if (index != -1) {
        cout << "Самый популярный фильм в жанре '" << genre << "': " << "\n";
        cout << "Название: " << movies[index].title << ", Режиссёр: " << movies[index].director
            << ", Жанр: " << movies[index].genre << ", Рейтинг: " << movies[index].popularityRating
            << ", Цена: " << movies[index].price << "\n";
    }
    else {
        cout << "Фильмы в жанре '" << genre << "' не найдены." << "\n";
    }
}

void displayAllMovies() {
    for (int i = 0; i < numMovies; i++) {
        cout << "Название: " << movies[i].title << ", Режиссёр: " << movies[i].director
            << ", Жанр: " << movies[i].genre << ", Рейтинг: " << movies[i].popularityRating
            << ", Цена: " << movies[i].price << "\n";
    }
}
int main()
{
    setlocale(LC_ALL, "RUS");
    addMovie("Фильм 1", "Режиссер 1", "Жанр 1", 4.5, 9.99);
    addMovie("Фильм 2", "Режиссер 2", "Жанр 2", 3.8, 7.99);
    addMovie("Фильм 3", "Режиссер 3", "Жанр 4", 4.2, 8.99);
    addMovie("Фильм 4", "Режиссер 4", "Жанр 3", 4.9, 10.56);
    searchByTitle("Фильм 1");
    searchByGenre("Жанр 2");
    searchByDirector("Режиссер 4");
    mostPopularInGenre("Жанр 4");
    cout << "Все записи: " << "\n";
    displayAllMovies();
}

