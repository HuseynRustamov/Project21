#pragma once
#include<iostream>
#include<fstream>
#include"Client.h"
#include"Notification.h"
using namespace std;
class FileHelper
{
public:
	static string filename;
	static void saveIngredient(Stock stock)
	{
		ofstream fout(filename, ios::app);
		if (fout.is_open())
		{
			fout << "Terkib hissesinin sayi " << stock.getIngredientSize() << endl;
			for (int i = 0; i < stock.getIngredientSize(); i++)
			{
				stock.getIngredientById(i).getId();
			}
		}
		else
		{
			cout << "ERROR!" << endl;
		}
	}

};




