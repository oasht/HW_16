#include "Film.h"

void main()
{
	vector<Film>v_films;
	Film f1("Bridget_Jones", "Beeban_Kidron", "Comedy", 7.5, 35.56);
	Film f2("Blue_jasmine", "Woody_Allen", "Drama", 7.1, 43.20);
	Film f3("Titanik", "James_Cameron", "Historical", 8.5, 78.41);
	Film f4("Pulp_fiction", "Qentin_Tarantino", "Drama", 10.00, 85.77);
	Film f5("Seven", "David_Fincher", "Detective", 9.5, 45.84);
	Film f6("The_Godfather", "Francis_Ford_Coppola", "Thriller", 8.8, 28.98);
	Film f7("The_Irishman", "Martin_Scorsese", "Crime", 6.3, 42.92);
	Film f8("Alien", "Ridley_Scott", "Horror", 5.5, 22.56);
	Film f9("Beetlejuice", "Tim_Burton", "Horror", 4.9, 43.89);
	Film f10("The_Terminal", "Steven_Spielberg", "Romance", 7.9, 65.83);

	v_films.push_back(f1);
	v_films.push_back(f2);
	v_films.push_back(f3);
	v_films.push_back(f4);
	v_films.push_back(f5);
	v_films.push_back(f6);
	v_films.push_back(f7);
	v_films.push_back(f8);
	v_films.push_back(f9);
	v_films.push_back(f10);

	bool key_1;
	do
	{
		system("cls");

		cout << " Choose the action: \n\n1 - Check the list of movies \n2 - Sort movies by name  \n3 - Sort movies by author" <<
			"\n4 - Sort movies by genre \n5 - Add new film \n6 - Delete a film" << endl;
		short key;
		cout << endl;
		cin >> key;
		cout << endl;

		switch (key)
		{
		case 1:
		{system("cls");
		f1.ReadFile();
		for (int i = 0; i < v_films.size(); i++)
		{
			
			//cout << i + 1 << ") ";
			//v_films[i].Print();
			
		}
		}

		break;

		case 2:
		{system("cls");
			f1.Search_name(v_films);
		}


		break;

		case 3:
		{system("cls");
			f1.Search_author(v_films);
		}

		break;

		case 4:
		{system("cls");
			f1.Search_genre(v_films, f1);
		}
		break;
		case 5:
		{system("cls");
			f1.AddFilm(v_films);
			for (int i = 0; i < v_films.size(); i++)
			{
				cout << i + 1 << ") ";
				v_films[i].Print();
			}
		}

		break;

		case 6:
		{system("cls");
		for (int i = 0; i < v_films.size(); i++)
		{
			cout << i + 1 << ") ";
			v_films[i].Print();
		}
			f1.DeleteFilm(v_films);
			system("cls");
			for (int i = 0; i < v_films.size(); i++)
			{
				cout << i + 1 << ") ";
				v_films[i].Print();
			}
		}

		break;
		}

		cout << endl;
		cout << "Continue? 1 - yes, 0 - no" << endl;
		cout << endl;
		cin >> key_1;
	} while (key_1);
	cout << endl;
	cout << "The end" << endl;




}