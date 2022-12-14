#include "Film.h"


string Film::Get_name()
{
	return name;
}

string Film::Get_author()
{
	return author;
}

string Film::Get_genre()
{
	return genre;
}

double Film::Get_rating()
{
	return rating;
}

double Film::Get_price()
{
	return price;
}


void Film::Print()
{
	cout << name << " by " << author << " (" << genre << ", " << rating << " stars for " << price << " $$)" << endl << endl;
}


void Film::Search_name(vector<Film>& mas)
{
	string _name;
	int n = 0;
	cout << "Enter the name of the film you would like to find" << endl;
	cin >> _name;
	cout << endl;
	for (int i = 0; i < mas.size(); i++)
	{
		if (mas[i].Get_name() == _name)
		{
			cout << "Such a movie(s) exists: " << endl << endl;
			mas[i].Print();
		}
		else
			n++;
	}
	if (n == mas.size())
		cout << "No film like this exists in stock" << endl;

}

void Film::Search_author(vector<Film>& mas)
{
	string _author;
	int n = 0;
	cout << "Enter the author of the film you would like to find" << endl;
	cin >> _author;
	cout << endl;
	cout << "                         Result(s) of your search:" << endl << endl;
	for (int i = 0; i < mas.size(); i++)
	{
		if (mas[i].Get_author() == _author)
		{
			mas[i].Print();
		}
		else
			n++;
	}

	if (n == mas.size())
		cout << "No film like this exists in stock" << endl;
}

void Film::AddFilm(vector<Film> & mas)
{
	Film f;
	cout << "Enter name of the movie" << endl;
	cin >> f.name;
	cout << "Enter author of the movie" << endl;
	cin >> f.author;
	cout << "Enter genre of the movie" << endl;
	cin >> f.genre;
	cout << "Enter rating of the movie" << endl;
	cin >> f.rating;
	cout << "Enter price of the rent" << endl;
	cin >> f.price;
	mas.push_back(f);
}

void Film::Search_genre(vector<Film> & mas, Film f)
{
	vector<Film> GenreVector;
	string _genre;
	int n = 0;
	cout << "Enter the genre of the film you would like to find" << endl;
	cin >> _genre;
	cout << endl;
	cout << "                         Result(s) of your search:" << endl << endl;
	for (int i = 0; i < mas.size(); i++)
	{
		if (mas[i].Get_genre() == _genre)
		{
			mas[i].Print();
			GenreVector.push_back(mas[i]);
		}
		else
			n++;
	}
	Sleep(4000);

	for (int i = 0; i < GenreVector.size(); i++)
		for (int j = i + 1; j < GenreVector.size(); j++)
			if (GenreVector[j].Get_rating() > GenreVector[i].Get_rating())
				swap(GenreVector[j], GenreVector[i]);
	system("cls");
	cout << "The most popular movie of this genre is " << GenreVector[0].Get_name() << endl;
	Sleep(4000);
	if (n == mas.size())
		cout << "No film like this exists in stock" << endl;
	system("cls");
	
		f.WriteFile_new(GenreVector);
	
}

void Film::DeleteFilm(vector<Film> & mas)
{
	int n;
	vector<Film>::iterator it = mas.begin();
	cout << "Choose the number of movie you want to delete" << endl;
	cin >> n;
	advance(it, n - 1);
	mas.erase(it);
	system("cls");
}

void Film::WriteFile(vector<Film> & mas)
{
	fstream fs;
		fs.open("films_all.txt", ios::in);
		if (!fs.fail())
		{
			cout << "Error" << endl;
		}

		ofstream fz;
		fz.open("films_all.txt");
		for (auto it = mas.begin(); it != mas.end(); it++)
		{
			fz << *it;
		}
		fz.close();
}
ostream& operator<<(ostream & os, Film & f)
{
	os << f.name << " by " << f.author << " (" << f.genre << ", " << f.rating << " stars for " << f.price << " $$)" << endl << endl;
	return os;
}

void Film::ReadFile(vector<Film>& mas)
{

	ifstream fw;
	fw.open("films_all.txt");
	if (!fw.is_open())
	{
		cout << "Error" << endl;
	}
	else
	{
		Film tmp;
		while (fw >> tmp.name >> tmp.author >> tmp.genre>>tmp.rating>>tmp.price)
		{
			mas.push_back(tmp);
		}
		fw.close();
		for (int i = 0; i < mas.size(); i++)
		{
			cout << mas[i] << endl;
		}
	}


}

void Film::WriteFile_new(vector<Film>& mas)
{


	fstream fs;
	fs.open("films_sorted.txt", ios::in);
	if (!fs.fail())
	{
		cout << "Error" << endl;
	}

	ofstream fz;
	fz.open("films_sorted.txt");
	for (auto it = mas.begin(); it != mas.end(); it++)
	{
		fz << *it;
	}
	fz.close();
}


