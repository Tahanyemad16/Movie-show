#include"movieData.h"
#include<iostream>
#include <vector>
using namespace std;

movieData::movieData(string title, int year, string genre, string rate,int fav) {
        this->genre = genre;
        this->title = title;
        this->year = year;
        this->rate = rate;
        this->fav = fav;
}
movieData::movieData() {
        genre = "";
        title = "";
        year = 0;
        rate = "";
        fav = 0;
}
movieData::movieData(const movieData& m) {
    this->genre =m.genre;
    this->title = m.title;
    this->year = m.year;
    this->rate = m.rate;
    this->fav = m.fav;
}
movieData& movieData:: operator=(movieData& m) {
    if (this != &m) {
        this->genre = m.genre;
        this->title = m.title;
        this->year = m.year;
        this->rate = m.rate;
        this->fav = m.fav;
    }
    return*this;
}
void movieData::setGenre(string genre) {
    this->genre = genre;
}
void movieData::setTitle(string title) {
    this->title = title;
}
void movieData::setYear(int year) {
    this->year = year;
}
void movieData::setRate(string rate) {
    this->rate = rate;
}
void movieData::setFav(int fav) {
    this->fav = fav;
}
string movieData::getTitle()const {
    return  title;
}
string movieData::getGenre()const {
    return  genre;
}
int movieData::getYear()const {
    return  year;
}
string movieData::getRate()const {
    return rate;
}
int movieData::getFav()const {
    return fav;
}
void movieData::print()const {
    cout << "==> Movie Details <==" << endl;
    cout << "Title : " << title << endl;
    cout << "Year : " << year << endl;
    cout << "Genre : " << genre << endl;
    cout << "Rate : " << rate << endl;
    cout << "Fav :" << fav << endl;
    cout << "___" << endl;
}
movieData::~movieData(){}

