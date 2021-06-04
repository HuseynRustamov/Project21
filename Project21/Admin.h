#pragma once
#include<iostream>
#include"Client.h"
#include"Notification.h"
#include"Exception.h"
#include"NotfStock.h"
#include <synchapi.h>
using namespace std;


enum StockControl
{
	DeleteIngredients = 1, ShowAllIngredient, ShowIngedientById, Increase, Decrease,
	UpdateIngredient, Back
};

enum MealControl
{
	DeleteMeal = 1, DeleteAllMeal, UpdateMeal, ShowMealById, ShowAllMeals,
	FindMealById, BackMeal
};



class Admin
{

	Stock s;
	Kitchen k;
	const string sys_username = "admin";
	const string sys_password = "admin";
	vector<NotfIngredient> notf_ingredients;
public:
	Admin(Stock s, Kitchen k)
	{
		this->s = s;
		this->k = k;
	}


	void deleteNotfIngredient()
	{
		notf_ingredients.push_back(NotfIngredient("Terkib hissesi silindi"));
	}

	void increaseNotf()
	{
		notf_ingredients.push_back(NotfIngredient("Daxili artim"));
	}

	void decreaseNotf()
	{
		notf_ingredients.push_back(NotfIngredient("Terkib hissesi azalma:"));
	}

	void updateIngNotf()
	{
		notf_ingredients.push_back(NotfIngredient("Terkib hissesi yenilendi:"));
	}


	void deletenotNotfIngredient()
	{
		notf_ingredients.push_back(NotfIngredient("Terkib hissesi siline bilmez:"));
	}

	void increasenotNotf()
	{
		notf_ingredients.push_back(NotfIngredient("Terkib hissesi artirila bilmez:"));
	}

	void decreasenotNotf()
	{
		notf_ingredients.push_back(NotfIngredient("Terkib hissesi azaldila bilmez:"));
	}

	void updateIngnotNotf()
	{
		notf_ingredients.push_back(NotfIngredient("Terkib hissesi yenilene bilmez:"));
	}

	void deleteMealNotf()
	{
		notf_ingredients.push_back(NotfIngredient("Yemek silindi"));
	}

	void deleteNotMealNotf()
	{
		notf_ingredients.push_back(NotfIngredient("Yemek siline bilmez"));
	}

	void updateMealNotf()
	{
		notf_ingredients.push_back(NotfIngredient("Yenilenen yemek"));
	}

	void updateNotMealNotf()
	{
		notf_ingredients.push_back(NotfIngredient("Yemek yenilene bilmez"));
	}

	void showNotfIngredient()
	{
		for (auto i = notf_ingredients.begin();
			i != notf_ingredients.end(); i++)
		{
			i->printMessage();
		}
	}

	bool login(string username, string password)
	{
		/*const string sys_username = "admin";
		const string sys_password = "admin";*/

		if (username == sys_username && password == sys_password)
		{
			


			cout << "\t\t\t\t\t" << char(218); for (int i = 0; i < 25; i++)cout << char(196); cout << char(191) << endl;
			cout << "\t\t\t\t\t" << char(179) << "     Daxil ol            " << char(179) << endl;
			cout << "\t\t\t\t\t" << char(192); for (int i = 0; i < 25; i++)cout << char(196); cout << char(217) << endl;
			
			Sleep(1000);
			return true;
		}
		else if (username != sys_username && password != sys_password)
		{
			cout << "++Hesabınızı tapın və daxil olun++" << endl;
			return false;
		}
	}

	void signin()
	{
		while (1)
		{
			system("cls");
			string username, password;

			cout << "\t" << char(218); for (int i = 0; i < 25; i++)cout << char(196); cout << char(191) << endl;
			cout << "\t" << char(179) << "++++++++daxil et+++++++++" << char(179) << endl;
			cout << "\t" << char(192); for (int i = 0; i < 25; i++)cout << char(196); cout << char(217) << endl;
			//cout << "Istifadeci adi daxil et ";

			
			cin >> username;
			cout << "\t" << char(218); for (int i = 0; i < 25; i++)cout << char(196); cout << char(191) << endl;
			cout << "\t" << char(179) <<  "++++++++sifre++++++++++++" << char(179) << endl;
			cout << "\t" << char(192); for (int i = 0; i < 25; i++)cout << char(196); cout << char(217) << endl;
			//cout << "Sifre--> ";
			cin >> password;

			if (login(username, password))
				break;
			else
			{
				cout << "++Yeniden daxil et++" << endl;
			}
			cin.ignore();
			cin.get();

		}
	}

	void stockControl()
	{
		//showNotfIngredient();
		while (1)
		{
			system("cls");
			cout << "[1]Terkib hissesini sil" << endl << endl;
			cout << "[2]Butun terkib hisseleri " << endl << endl;
			cout << "[3]Terkib hisseleri--id " << endl << endl;
			cout << "[4]Terkibin artirilmasi" << endl << endl;
			cout << "[5]Terkib hisselerinin azaldilmasi" << endl << endl;
			cout << "[6]Terkib hisselerini yenilenmesi " << endl << endl;
			cout << "[7]--GERI-- " << endl;

			int choice;
			cout << endl;
			cout << "Secim-->";
			cin >> choice;

			switch (choice)
			{
			case DeleteIngredients:
			{
				try
				{
					int id_delete;
					cout << "ID Daxil et--> ";
					cin >> id_delete;
					s.deleteIngredientById(id_delete);
					deleteMealNotf();
				}
				catch (Exception ex)
				{
					deletenotNotfIngredient();
					ex.print();
				}
				//s.deleteNotfIngredient();
				//s.showNotfIngredient();
				cin.ignore();
				cin.get();
				break;
			}
			case ShowAllIngredient:
				try
				{
					s.showAllIngredients();
				}
				catch (Exception ex)
				{
					ex.print();
				}
				cin.ignore();
				cin.get();
				break;
			case ShowIngedientById:
			{
				try
				{
					int id_s_m;
					cout << "ID Daxil et--> ";
					cin >> id_s_m;
					s.showIngredientById(id_s_m);
				}
				catch (Exception ex)
				{
					ex.print();
				}
				cin.ignore();
				cin.get();
				break;
			}
			case Increase:
				try
				{

					int id_increase, amount_increase;
					cout << "ID Daxil et--> " ;
					cin >> id_increase;
					cout << "Mebleg--> ";
					cin >> amount_increase;
					s.increment(id_increase, amount_increase);
					increaseNotf();
				}
				catch (Exception ex)
				{
					increasenotNotf();
					ex.print();
				}
				cin.ignore();
				cin.get();
				break;
			case Decrease:
				try
				{
					int id_decrease, amount_decrease;
					cout << "ID Daxil et--> ";
					cin >> id_decrease;
					cout << "Mebleg--> ";
					cin >> amount_decrease;
					s.decrement(id_decrease, amount_decrease);
					decreaseNotf();
				}
				catch (Exception ex)
				{
					decreasenotNotf();
					ex.print();
				}
				cin.ignore();
				cin.get();
				break;
			case UpdateIngredient:
			{
				try
				{
					int id_update;
					cout << "ID Daxil et--> ";
					cin >> id_update;
					s.updateIngredientById(id_update);
					updateIngNotf();
				}
				catch (Exception ex)
				{
					updateIngnotNotf();
					ex.print();
				}
				cin.ignore();
				cin.get();
				break;
			}
			case Back:
				return;
				break;


			}

		}
	}


	void mealControl()
	{
		while (1)
		{
			system("cls");
			cout << "[1]Yemeyi Sil" << endl;
			cout << "[2]Butun Yemekleri Sil " << endl;
			cout << "[3]Yemeyin yenilenmesi " << endl;
			cout << "[4]Yemeyinlerin ID ile gosterilmesi" << endl;
			cout << "[5]MENYU " << endl;
			cout << "[6]Istediyiniz yemeyin adini daxil edin " << endl;
			cout << "[7]--GERI--" << endl;

			int choice;
			cout << endl;
			cout << "Secim--> ";
			cin >> choice;



			switch (choice)
			{
			case DeleteMeal:
			{
				try
				{
					int id_d_m;
					cout << "ID Daxil et--> ";
					cin >> id_d_m;
					k.deleteMealById(id_d_m);
					deleteMealNotf();
				}
				catch (Exception ex)
				{
					deleteNotMealNotf();
					ex.print();
				}
				cin.ignore();
				cin.get();
				break;
			}
			case DeleteAllMeal:
			{
				k.deleteAllMeals();
				cout << "\n--MENYU SILINDI--\n";
				cin.ignore();
				cin.get();
				break;
			}
			case UpdateMeal:
			{
				try
				{
					int id_u_m;
					cout << "ID Daxil et--> ";
					cin >> id_u_m;
					k.updateMealById(id_u_m);
					updateMealNotf();
				}
				catch (Exception ex)
				{
					updateNotMealNotf();
					ex.print();
				}
				cin.ignore();
				cin.get();
				break;
			}
			case ShowMealById:
			{
				try
				{
					int id_s_m;
					cout << "ID Daxil et--> ";
					cin >> id_s_m;
					k.showMealById(id_s_m);
				}
				catch (Exception ex)
				{
					ex.print();
				}
				cin.ignore();
				cin.get();
				break;
			}
			case ShowAllMeals:
			{
				try
				{
					k.showAllMeals();

				}
				catch (Exception ex)
				{
					ex.print();
				}
				cin.ignore();
				cin.get();
				break;
			}
			case FindMealById:
			{
				string ss_name;
				cout << "Secdiyiniz yemeyin adini daxil et--> ";
				cin >> ss_name;
				k.findMealByName(ss_name);
				cin.ignore();
				cin.get();
				break;
			}
			case BackMeal:
				return;
				break;
			}
		}

	}

	void showNotf()
	{
		showNotfIngredient();
	}
};

