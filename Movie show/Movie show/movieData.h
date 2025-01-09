#pragma once
#include<string>
using namespace std;

class movieData {
private:
	int year;
	string rate;
	string title;
	string genre;
	int fav;
public:
	movieData();
	movieData(const movieData&);
	movieData& operator=(movieData&);
	movieData(string, int, string, string,int);
	~movieData();
	void setGenre(string);
	void setTitle(string);
	void setYear(int);
	void setRate(string);
	void setFav(int);
	string getGenre() const;
	string getTitle() const;
	int getYear() const;
	string getRate() const;
	int getFav() const;
	void print() const;

}; 
