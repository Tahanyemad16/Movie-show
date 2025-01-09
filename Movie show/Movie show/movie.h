#pragma once
#include<vector>
#include"movieData.h"
using namespace std;
class movie
{
public:
	movie();
	movie(movie&);
	movie& operator=(movie&);
	~movie();
	void addmovie(const movieData&);
	movieData* searchByTitle(const string&);
	vector<movieData> filterByGenre(const string&)const;
	vector<movieData> filterByYear(const int&)const;
	vector<movieData> filterByRate(const string&)const;
	vector<movieData> &getMovieList();
	void favList();
	void saveToFile();
	void loadFromFile();


private:
	vector<movieData>movielist;

};

