#include <iostream>
#include <iomanip>
#include <string.h>
#include<Windows.h>
#include <fstream>
#include <vector>

using namespace std;

class Film
{
	string name;
	string author;
	string genre;
	double rating;
	double price;

public:
	Film()
	{
		name = " ";
		author = " ";
		genre = " ";
		rating = 0;
		price = 0;
	}
	Film(string n, string a, string g, double r, double p)
	{
		name = n;
		author = a;
		genre = g;
		rating = r;
		price = p;
	}
	string Get_name();

	string Get_author();

	string Get_genre();
	double Get_rating();
	double Get_price();
	void Print();
	void Search_name(vector<Film>& mas);
	void Search_author(vector<Film>& mas );
	void AddFilm(vector<Film>& mas);
	void Search_genre(vector<Film>& mas, Film f);
	void DeleteFilm(vector<Film>& mas);
	void WriteFile(vector<Film>& mas);
	void ReadFile();
	friend ostream& operator<<(ostream& os, Film& f);
	void WriteFile_new(vector<Film>& mas);
};


