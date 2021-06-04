#pragma once
#include"Client.h"
#include"Notification.h"
using namespace std;
double last_price = 0;

enum ClientControl
{
	ShawAllMeals = 1, Detail, Search, Buy, CBack
};

class Order
{
	Kitchen k;
	Stock s;
	vector<Notification> notf;
public:
	Order(Kitchen k, Stock s)
	{
		this->k = k;
		this->s = s;
	}

	void notfAddIng()
	{
		notf.push_back(NotfIngredient("Musteri yeni terkib elave edir "));
	}

	bool checkAmount(int id, int amount)
	{

		Meal item = k.getMealById(id);


		//vector<Meal> item = k.getMealById(id);
		if (id > k.getMeal().size())
		{
			throw Exception("Bu yemek movcud deyil", __FILE__, __LINE__, __TIME__);
		}
		else
		{
			if (amount > item.getAmount())
			{
				return false;
			}
			return true;
		}
	}

	void buyProduct(int id, int amount)
	{
		Meal item = k.getMealById(id);
		last_price = last_price + item.getPrice() * amount;
		item.setAmount(item.getAmount() - amount);
	}

	void addMoreIngredient(int id)
	{
		Ingredient item = s.getIngredientById(id);
		if (item.getId() == NULL || item.getAmount() == 0)
		{
			throw DatabaseException("Bu elaveni etmek mumkun deyil", __FILE__, __LINE__, __TIME__);
		}
		else
		{
			last_price = last_price + item.getingPrice();
			item.setAmount(item.getAmount() - 1);
			notfAddIng();
		}

	}

	void Menu()
	{
		while (1)
		{
			system("cls");


			cout << "\t\t\t\t\t" << char(218); for (int i = 0; i < 25; i++)cout << char(196); cout << char(191) << endl;
			cout << "\t\t\t\t\t" << char(179) << "     [1]MENYU            " << char(179) << endl;
			cout << "\t\t\t\t\t" << char(192); for (int i = 0; i < 25; i++)cout << char(196); cout << char(217) << endl;
			cout << "\t\t\t\t\t" << char(218); for (int i = 0; i < 25; i++)cout << char(196); cout << char(191) << endl;
			cout << "\t\t\t\t\t" << char(179) << "     [2]DETALLI GOSTERIS " << char(179) << endl;
			cout << "\t\t\t\t\t" << char(192); for (int i = 0; i < 25; i++)cout << char(196); cout << char(217) << endl;
			cout << "\t\t\t\t\t" << char(218); for (int i = 0; i < 25; i++)cout << char(196); cout << char(191) << endl;
			cout << "\t\t\t\t\t" << char(179) << "     [3]YEMEYIN AXTARISI " << char(179) << endl;
			cout << "\t\t\t\t\t" << char(192); for (int i = 0; i < 25; i++)cout << char(196); cout << char(217) << endl;
			cout << "\t\t\t\t\t" << char(218); for (int i = 0; i < 25; i++)cout << char(196); cout << char(191) << endl;
			cout << "\t\t\t\t\t" << char(179) << "     [4]ALMAQ            " << char(179) << endl;
			cout << "\t\t\t\t\t" << char(192); for (int i = 0; i < 25; i++)cout << char(196); cout << char(217) << endl;
			cout << "\t\t\t\t\t" << char(218); for (int i = 0; i < 25; i++)cout << char(196); cout << char(191) << endl;
			cout << "\t\t\t\t\t" << char(179) << "     [5]--GERI--         " << char(179) << endl;
			cout << "\t\t\t\t\t" << char(192); for (int i = 0; i < 25; i++)cout << char(196); cout << char(217) << endl;




			int choice;
			cout << endl;
			cout << "\t" << char(218); for (int i = 0; i < 25; i++)cout << char(196); cout << char(191) << endl;
			cout << "\t" << char(179) << "     [!]SECIM            " << char(179) << endl;
			cout << "\t" << char(192); for (int i = 0; i < 25; i++)cout << char(196); cout << char(217) << endl;
			

			//cout << "SECIM--> ";
			cin >> choice;
			switch (choice)
			{
			case ShawAllMeals:
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
			case Detail:
			{
				int id;
				cout << "ID daxil et--> ";
				cin >> id;
				try
				{
					k.getRecipe(id);
				}
				catch (Exception ex)
				{
					ex.print();
				}
				cin.ignore();
				cin.get();
				break;
			}
			case Search:
			{
				string name;
				cout << "Yemeyin adini daxil et--> ";
				cin >> name;
				k.findMealByName(name);
				cin.ignore();
				cin.get();
				break;
			}
			case Buy:
			{

				int id, amount;
				cout << "Yemeyin ID--> ";
				cin >> id;
				while (id > k.getMealSize())
				{
					cout << "Yeniden Daxil Et--> ";
					cin >> id;
				}
				cout << "Mebleg--> ";
				cin >> amount;
				try
				{
					if (checkAmount(id, amount) == true)
					{
						while (1)
						{
							char choice;
							cout << "Yemeyin terkibini artirmaq isteyirsiniz mi? --> y / n ? ";
							cin >> choice;
							try
							{
								if (choice == 121 || choice == 89)
								{
									int i_id;
									cout << "ID--> ";
									cin >> i_id;
									addMoreIngredient(i_id);
								}
								else
								{
									break;
								}
							}
							catch (Exception ex)
							{
								ex.print();
							}

						}
						buyProduct(id, amount);
						cout << "\t" << char(218); for (int i = 0; i < 25; i++)cout << char(196); cout << char(191) << endl;
						cout << "\t" << char(179) << " Tesdiqlendi             " << char(179) << endl;
						cout << "\t" << char(192); for (int i = 0; i < 25; i++)cout << char(196); cout << char(217) << endl;
					
						cout << "Son Odenis--> " << last_price << endl;
						char select;
						int rate;
						cout << "Derecelendirmek istersinizmi--> ? y / n ";
						cin >> select;
						if (select == 89 || select == 121)
						{
							cout << "Derece Daxil Edin [0-9]! ";
							cin >> rate;
							while (rate < 0 || rate>9)
							{
								cout << "Xahis olunur 0-9--> ";
								cin >> rate;
							}
							cout << "Derecelendirmeniz ucun cox sagolun ! Verdiyiniz deyer --> " << rate << endl;
						}

					}
					else
					{
						cout << " ++Metbexde bu yemek catismir++ ";
					}
				}
				catch (Exception ex)
				{
					ex.print();
				}
				cin.ignore();
				cin.get();
				break;
			}
			case ClientControl::CBack:
			{
				return;
			}
			}
		}
	}

};


