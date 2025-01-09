#include"movie.h"
#include<algorithm>
#include<fstream>
using namespace std;

movie::movie(){}
movie::movie(movie& m) {
    movielist = m.movielist;
}

movie& movie:: operator=(movie& m) {
    if (&m != this) {
        movielist = m.movielist;
    }
    return *this;
}

void movie::addmovie(const movieData& moVie) {
        movielist.push_back(moVie);
}

movieData* movie::searchByTitle(const string& title) {
        for (auto& moVie : movielist) {
            string t=moVie.getTitle();
            transform(t.begin(), t.end(), t.begin(), ::tolower);
            if (t == title) {
                return &moVie;
            }
        }
        return nullptr;
}

vector<movieData> movie::filterByGenre(const string& genre)const {
        vector<movieData>result;
        for (const auto& moVie : movielist) {
            string t = moVie.getGenre();
            transform(t.begin(), t.end(), t.begin(), ::tolower);
            if (t == genre) {
                result.push_back(moVie);
            }
        }
        return result;
}

vector<movieData> movie::filterByYear(const int& year)const {
        vector<movieData>result;
        for (const auto& moVie : movielist) {
            if (moVie.getYear() == year) {
                result.push_back(moVie);
            }
        }
        return result;
}

vector<movieData> movie::filterByRate(const string& rate)const {
        vector<movieData>result;
        for (const auto& moVie : movielist) {
            if (moVie.getRate() == rate) {
                result.push_back(moVie);
            }
        }
        return result;
}

vector <movieData>& movie::getMovieList() {
        return movielist;
} 

movie::~movie(){}

void movie::favList() {
    for (const auto& moVie : movielist) {
        if (moVie.getFav() == 1) {
            moVie.print();
        }
    }
}

void movie::saveToFile() {
    fstream out;
    out.open("MoVie",ios::out);
    if (out.is_open()) {
        out << movielist.size()<<endl;
        for (const auto& moVie : movielist) {
            out << moVie.getTitle() << endl;
            out << moVie.getRate() << endl;
            out << moVie.getYear() << endl;
            out << moVie.getGenre() << endl;
            out << moVie.getFav() << endl;
            out << "======================================" << endl;
        }
        out.close();
    }
}

void movie::loadFromFile() {
    fstream in;
    in.open("MoVie", ios::in);
    if (in.is_open()) {
        string title, genre, size, year, fav,rate;
        getline(in, size);
        int s = 0;
        for (int i = 0; i < size.size(); i++)
        {
            s = (size[i] - '0') + s * 10;
        }
        for (int i = 0; i < s; i++) {
            getline(in, title);
            getline(in, rate);
            getline(in, year);
            getline(in, genre);
            getline(in, fav);
            int y = 0;
            for (int i = 0; i < year.size(); i++)
            {
                y = (year[i] - '0') + y * 10;
            }

            int f = 0;
            for (int i = 0; i < fav.size(); i++)
            {
                f = (fav[i] - '0') + f * 10;
            }
            movieData MD(title,y,genre,rate,f);
            movielist.push_back(MD);
            string var;
            getline(in, var);
        }
        in.close();
    }

}
 


