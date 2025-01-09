#include<iostream>
#include<algorithm>
#include"movieData.h"
#include"movie.h"
#include<conio.h>
using namespace std;

void searchByYear(movie& m) {
    cout << "what's the year you will search about its movies :";
    int y;
    cin >> y;
    cout << endl << "      ok l will display" << endl << endl;
    vector<movieData>searchByYear = m.filterByYear(y);
    for (const auto& moVie : searchByYear)
        moVie.print();
}

void searchByRate(movie& m) {
    cout << "what's the rate you will search about its movies :";
    string y;
    cin >> y;
    cout << endl << "      okay l will display" << endl << endl;
    vector<movieData>searchByRate = m.filterByRate(y);
    for (const auto& moVie : searchByRate)
        moVie.print();
}

void searchByGenre(movie& m) {
    cout << "what's the genre you will search about its movies :";
    string y;
    cin >> y;
    transform(y.begin(), y.end(), y.begin(), ::tolower);
    cout << endl << "       okay l will display " << endl << endl;
    vector<movieData>searchByGenre = m.filterByGenre(y);
    for (const auto& moVie : searchByGenre)
        moVie.print();
}

void searchByTitle(movie& m) {
    cout << "what's the Title you will search about its movies :";
    string y;
    cin >> y;
    transform(y.begin(), y.end(), y.begin(), ::tolower);
    cout << endl << "       okay l will display " << endl << endl;
    movieData* result = m.searchByTitle(y);
    if (result != nullptr)
        result->print();
    else
        cout << "The movie not found" << endl;
}

void search(movie& m) {
    cout << "what you will search by :";
    string var;
    cin >> var;
    if (var == "year") {
        searchByYear(m);
    }
    else if (var == "rate") {
        searchByRate(m);
    }
    else if (var == "genre") {
        searchByGenre(m);
    }
    else if (var == "title") {
        searchByTitle(m);
    }
}
void PrintAllMovies(movie& m)
{
    vector<movieData> result = m.getMovieList();
    for (const auto& mov : result)
    {
        mov.print();
    }
}
void ShowMenu()
{
    cout << "\t\t\t\t\t\t -------------------------------------------------------------\n"
        << "\t\t\t\t\t\t|                      Contacts Book Menu                     |\n"
        << "\t\t\t\t\t\t -------------------------------------------------------------\n"
        << "\t\t\t\t\t\t| 1. Add a new Movie                                          |\n"
        << "\t\t\t\t\t\t| 2. Search by Title                                          |\n"
        << "\t\t\t\t\t\t| 3. Search By Year                                           |\n"
        << "\t\t\t\t\t\t| 4. Search by Rate                                           |\n"
        << "\t\t\t\t\t\t| 5. Search by Genre                                          |\n"
        << "\t\t\t\t\t\t| 6. Print Fav Movies                                         |\n"
        << "\t\t\t\t\t\t| 7. Print all Movies                                         |\n"
        << "\t\t\t\t\t\t| 8. Save To File                                             |\n"
        << "\t\t\t\t\t\t| 9. Load from File                                           |\n"
        << "\t\t\t\t\t\t| 10. Exit                                                    |\n"
        << "\t\t\t\t\t\t -------------------------------------------------------------\n";
}
void addmovie(movie& m)
{
    string title, genre;
    int year, fav;
    string rate;
    cout << "Enter The Title : ";
    cin >> title;
    cout << "Enter The Year : ";
    cin >> year;
    cout << "Enter The Rate : ";
    cin >> rate;
    cout << "Enter The Genre : ";
    cin >> genre;
    cout << "Is it Your Favourite movie Or not : (1 for yes , 0 for not )";
    cin >> fav;
    movieData mov(title, year, genre, rate, fav);
    m.addmovie(mov);
}
int main() {
    movie m;

    int option;
    while (true) {
        ShowMenu();

        cout << "Enter number of option  : ";
        cin>>option;
        system("cls");

        switch (option) {
        case 1:
            addmovie(m);
            break;
        case 2:
            searchByTitle(m);
            break;
        case 3:
            searchByYear(m);
            break;
        case 4:
            searchByRate(m);
            break;
        case 5:
            searchByGenre(m);
            break;
        case 6:
            m.favList();
            break;
        case 7:
            PrintAllMovies(m);
            break;
        case 8:
            m.saveToFile();
            break;
        case 9:
            m.loadFromFile();
            break;
        case 10:
            return 0;
        default:
            cout << "Invalid Option !!!" << endl;
        }
    }

    return 0;
}