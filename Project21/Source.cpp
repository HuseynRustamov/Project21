#include<iostream>
#include<Windows.h>
#include<fstream>
using namespace std;
#include"Client.h"
#include"Admin.h"
#include"Order.h"
#include"FileHelper.h"


int main()
{
	Ingredient onion("Onion", 1, 1, 1, 1, 10, 1);
	Ingredient sausage("Sausage", 2, 2, 2, 2, 8, 2);
	Ingredient chesar("Chesar", 3, 3, 3, 3, 7, 6);
	Ingredient olive("Olive", 4, 4, 4, 4, 5, 3);
	Ingredient sause("Sause", 5, 5, 5, 5, 8, 2);

	Stock s;
	s.addIngredient(onion);
	s.addIngredient(sausage);
	s.addIngredient(chesar);
	s.addIngredient(olive);
	s.addIngredient(sause);

	//s.findIngredientByName("doner");
	//s.deleteIngredientById(2);
	//s.increment(2, 3);
	//s.showAllIngredients();
	//s.showIngredientById(2);
	//s.increment(2, 3);
	//s.decrement(2, 3);
	/*s.deleteAllIngredients();
	s.showAllIngredients();*/
	//s.showIngredientById(2);
	//s.updateIngredientById(2);
	//s.showIngredientById(2);

	Meal doner("Doner", "Turkish", 8.5, 15, 2, 10);
	Meal pulov("Pulov", "Milli Yemek", 5.5, 5, 1, 8);
	Meal kabab("Kabab", "50gram", 9.9, 30, 3, 5);

	doner.addIngredient(onion);
	doner.addIngredient(olive);

	pulov.addIngredient(sause);
	pulov.addIngredient(chesar);

	kabab.addIngredient(sausage);
	kabab.addIngredient(onion);

	Kitchen k;
	k.addMeal(doner);
	k.addMeal(pulov);
	k.addMeal(kabab);

	//k.showAllMeals();
	//FileHelper::saveIngredient(s);

	Admin a(s, k);
	Order o(k, s);
	
	int num, select;
	while (1)
	{
		system("cls");
		system("color 17");
		cout << "\t\t\t\t\t" << char(218); for (int i = 0; i < 25; i++)cout << char(196); cout << char(191) << endl;
		cout << "\t\t\t\t\t" << char(179) << "       1.Admin           " << char(179) << endl;
		cout << "\t\t\t\t\t" << char(192); for (int i = 0; i < 25; i++)cout << char(196); cout << char(217) << endl;
		cout << "\t\t\t\t\t" << char(218); for (int i = 0; i < 25; i++)cout << char(196); cout << char(191) << endl;
		cout << "\t\t\t\t\t" << char(179) << "       2.Sifaris         " << char(179) << endl;
		cout << "\t\t\t\t\t" << char(192); for (int i = 0; i < 25; i++)cout << char(196); cout << char(217) << endl;
		cout << "\t\t\t\t\t" << char(218); for (int i = 0; i < 25; i++)cout << char(196); cout << char(191) << endl;
		cout << "\t\t\t\t\t" << char(179) << "       3.Ekrani bagla    " << char(179) << endl;
		cout << "\t\t\t\t\t" << char(192); for (int i = 0; i < 25; i++)cout << char(196); cout << char(217) << endl;
	
		cin >> num;
		while (num != 1 && num != 2 && num != 3)
		{
			cout << "++Yeniden Daxil et++ ";
			cin >> num;
		}


		if (num == 1)
		{
			a.signin();
			while (1)
			{

				system("cls");


				cout << "\t\t\t\t\t" << char(218); for (int i = 0; i < 25; i++)cout << char(196); cout << char(191) << endl;
				cout << "\t\t\t\t\t" << char(179) << " 1.Stok idaresi          " << char(179) << endl;
				cout << "\t\t\t\t\t" << char(192); for (int i = 0; i < 25; i++)cout << char(196); cout << char(217) << endl;
				cout << "\t\t\t\t\t" << char(218); for (int i = 0; i < 25; i++)cout << char(196); cout << char(191) << endl;
				cout << "\t\t\t\t\t" << char(179) << " 2.MENYU                 " << char(179) << endl;
				cout << "\t\t\t\t\t" << char(192); for (int i = 0; i < 25; i++)cout << char(196); cout << char(217) << endl;
				cout << "\t\t\t\t\t" << char(218); for (int i = 0; i < 25; i++)cout << char(196); cout << char(191) << endl;
				cout << "\t\t\t\t\t" << char(179) << " 3.Bildiris gostermek    " << char(179) << endl;
				cout << "\t\t\t\t\t" << char(192); for (int i = 0; i < 25; i++)cout << char(196); cout << char(217) << endl;
				cout << "\t\t\t\t\t" << char(218); for (int i = 0; i < 25; i++)cout << char(196); cout << char(191) << endl;
				cout << "\t\t\t\t\t" << char(179) << " 4.GERI                  " << char(179) << endl;
				cout << "\t\t\t\t\t" << char(192); for (int i = 0; i < 25; i++)cout << char(196); cout << char(217) << endl;

				cin >> select;
				while (select != 1 && select != 2 && select != 3 && select != 4)
				{
					cout << "++Yeniden Daxil et++ ";
					cin >> select;
				}
				if (select == 1)
				{
					a.stockControl();
				}
				else if (select == 2)
				{
					a.mealControl();
				}
				else if (select == 3)
				{
					a.showNotf();
					cin.ignore();
					cin.get();
				}
				else if (select == 4)
				{
					break;
				}
			}
		}
		else if (num == 2)
		{
			while (1)
			{
				int o_num;
				cout << "[1]Sifaris ver " << endl;
				cout << "[2]GERI " << endl;
				cin >> o_num;
				while (o_num != 1 && o_num != 2)
				{
					cout << "++Yeniden daxil et++";
					cin >> o_num;
				}
				if (o_num == 1)
					o.Menu();
				else if (o_num == 2)
					break;
			}
		}
		else if (num == 3)
		{
			system("pause");
			return 0;
		}
	}

	cout << "++Bir muddet sonra++" << endl;

	//system("pause");
	cin.ignore();
	cin.get();
	return 0;
}