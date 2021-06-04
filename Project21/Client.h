#pragma once
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include"Notification.h"
#include"Exception.h"
using namespace std;


class Ingredient
{
protected:
	string name;
	double fats;
	double protein;
	double carbogydrates;
	int kcal;
	int amount;
	double ingPrice;
	int ing_id;
public:
	static int id;
	Ingredient() = default;
	Ingredient(const string& name, double fats, double protein, double carbogydrates,
		int kcal, double ingPrice, int amount)
	{
		this->ing_id = ++id;
		setName(name);
		setFat(fats);
		setProtein(protein);
		setCarbogydrates(carbogydrates);
		setKcal(kcal);
		setingPrice(ingPrice);
		setAmount(amount);

	}

	Ingredient(const Ingredient& other)
	{
		this->ing_id = other.ing_id;
		setName(other.name);
		setFat(other.fats);
		setProtein(other.protein);
		setCarbogydrates(other.carbogydrates);
		setKcal(other.kcal);
		setingPrice(other.ingPrice);
		setAmount(other.amount);
	}

	string getName() const
	{
		return name;
	}

	void setName(const string& name)
	{
		this->name = name;
	}

	double getFat() const
	{
		return fats;
	}

	void setFat(double fats)
	{
		this->fats = fats;
	}


	double getProtein() const
	{
		return protein;
	}

	void setProtein(double protein)
	{
		this->protein = protein;
	}


	double getCarbogydrates() const
	{
		return carbogydrates;
	}

	void setCarbogydrates(double carbogydrates)
	{
		this->carbogydrates = carbogydrates;
	}


	int getKcal() const
	{
		return kcal;
	}

	void setKcal(int kcal)
	{
		this->kcal = kcal;
	}


	int getAmount() const
	{
		return amount;
	}

	void setAmount(int amount)
	{
		this->amount = amount;
	}

	double getingPrice() const
	{
		return ingPrice;
	}

	void setingPrice(double ingPrice)
	{
		this->ingPrice = ingPrice;
	}


	static int ingredientId()
	{
		return id;
	}

	int getId()
	{
		return ing_id;
	}

	void show() const
	{
		cout << endl;
		cout << "****TERKIB****" << endl << endl;
		cout << "ID: " << ing_id << endl << endl;
		cout << "AD: " << getName() << endl << endl;
		cout << "YAG: " << getFat() << endl << endl;
		cout << "Protein: " << getProtein() << endl << endl;
		cout << "KARBOHIDRAT: " << getCarbogydrates() << endl << endl;
		cout << "Kcal: " << getKcal() << endl << endl;
		cout << "Elavelerin Qiymeti: " << getingPrice() << endl << endl;;
		cout << "Mebleg: " << getAmount() << endl << endl;
	}


	friend ostream& operator<<(ostream& out, const Ingredient& ingredient);
	friend istream& operator>>(istream& in, Ingredient& ingredient);

};

int Ingredient::id = 0;

ostream& operator<<(ostream& out, const Ingredient& ingredient)
{
	out << "Terkib hisseler--> " << endl;
	out << "ID--> " << ingredient.ing_id << endl;
	out << "Yemeyin adi--> " << ingredient.getName() << endl;
	out << "Yag--> " << ingredient.getFat() << endl;
	out << "Protein--> " << ingredient.getProtein() << endl;
	out << "Karbohidratlar--> " << ingredient.getCarbogydrates() << endl;
	out << "Kcal--> " << ingredient.getKcal() << endl;
	out << "Mebleg--> " << ingredient.getAmount() << endl;
	out << "Qiymet--> " << ingredient.getingPrice() << endl;
	return out;
}

istream& operator>>(istream& in, Ingredient& ingredient)
{
	string name;
	double fat, protein, carbohidrat, price;
	int kcal, amount;
	cout << "Yemeyin adi--> ";
	in >> name;
	ingredient.setName(name);
	cout << "Yag-->";
	in >> fat;
	ingredient.setFat(fat);
	cout << "Protein--> ";
	in >> protein;
	ingredient.setProtein(protein);
	cout << "Karbohidratlar-->";
	in >> carbohidrat;
	ingredient.setCarbogydrates(carbohidrat);
	cout << "Mebleg-->";
	in >> amount;
	ingredient.setAmount(amount);
	cout << "Qiymet--> ";
	in >> price;
	ingredient.setingPrice(price);
	++ingredient.id;
	return in;
}


class Meal
{
	string name;
	string category;
	double rating;
	double price;
	double tax;
	vector<Ingredient> ingredients;
	int meal_id;
	int amount;
public:
	static int id;
	Meal() = default;
	Meal(const string& name, const string& category, double rating, double price,
		double tax, int amount)
	{
		meal_id = ++id;
		setName(name);
		setCategory(category);
		setRating(rating);
		setPrice(price);
		setTax(tax);
		setAmount(amount);
	}

	string getName() const
	{
		return name;
	}

	void setName(const string& name)
	{
		this->name = name;
	}

	string getCategory() const
	{
		return category;
	}

	void setCategory(const string& category)
	{
		this->category = category;
	}


	double getRating() const
	{
		return rating;
	}

	void setRating(double rating)
	{
		this->rating = rating;
	}

	double getPrice() const
	{
		return price;
	}

	void setPrice(double price)
	{
		this->price = price;
	}

	double getTax() const
	{
		return tax;
	}

	void setTax(double tax)
	{
		this->tax = tax;
	}

	int getAmount() const
	{
		return amount;
	}

	void setAmount(int amount)
	{
		this->amount = amount;
	}




	void addIngredient(Ingredient& ingredient)
	{
		/*for (int i = 0; i < count; i++)
		{
			ingredients.push_back(ingredient);
		}*/
		ingredients.push_back(ingredient);
	}

	void deleteMeal(int id)
	{
		ingredients.erase(ingredients.begin() + id);
	}

	void deleteAll()
	{
		ingredients.clear();
	}

	static int getMealId()
	{
		return id;
	}


	vector<Ingredient> getIngredientById(int id)
	{
		vector<Ingredient> ing;
		for (auto i = ingredients.begin();
			i != ingredients.end(); i++)
		{
			if (id == i->getId())
			{
				return ing;
			}
		}
	}

	void printRecipe()
	{
		for (auto i = ingredients.begin(); i != ingredients.end(); i++)
		{
			i->show();
		}
	}

	friend ostream& operator<<(ostream& out, const Meal& meal);
	friend istream& operator>>(istream& in, Meal& meal);


	void showMeal() const
	{
		cout << "ID:" << meal_id << endl << endl;
		cout << "AD:" << getName() << endl << endl;
		cout << "KATEGORIYA:" << getCategory() << endl << endl;
		cout << "Rating:" << getRating() << endl << endl;
		cout << "QIYMET:" << getPrice() << endl << endl;
		cout << "Tax:" << getTax() << endl << endl;
		cout << "MEBLEG:" << getAmount() << endl << endl;
	}

};
int Meal::id = 0;


ostream& operator<<(ostream& out, const Meal& meal)
{
	out << "ID:" << meal.meal_id << endl << endl;
	out << "Yemeyin adi--> " << meal.getName() << endl << endl;
	out << "Kategoriya--> " << meal.getCategory() << endl << endl;
	out << "Rating--> " << meal.getRating() << endl << endl;
	out << "Qiymet--> " << meal.getPrice() << endl << endl;
	out << "Tax--> " << meal.getTax() << endl << endl;
	out << "Mebleg--> " << meal.getAmount() << endl << endl;
	return out;
}

istream& operator>>(istream& in, Meal& meal)
{
	string name, category;
	double rating, price, tax;
	int amount;
	cout << "Yemeyin adi--> ";
	in >> name;
	meal.setName(name);
	cout << "Kategoriya--> " ;
	in >> category;
	meal.setCategory(category);
	cout << "Reyting--> ";
	in >> rating;
	meal.setRating(rating);
	cout << "Qiymet--> ";
	in >> price;
	meal.setPrice(price);
	cout << "Tax--> ";
	in >> tax;
	meal.setTax(tax);
	cout << "Mebleg--> ";
	in >> amount;
	meal.setAmount(amount);
	return in;
}



class Stock
{
	vector<Ingredient> ingredients;
	vector<NotfIngredient> notf_ingredients;

public:
	Ingredient* ingredient;
	//Stock() = default;
	Stock() :ingredient(nullptr) {}

	Ingredient getIngredientById(int id)
	{
		return ingredients.at(id - 1);
	}

	int getIngredientSize()
	{
		return ingredients.size();
	}

	void increment(int id, int amount)
	{
		if (id > ingredients.size())
		{
			throw DatabaseException("Meblegi artira bilmerik!", __FILE__, __LINE__, __TIME__);
		}
		int new_amount = ingredients[id - 1].getAmount() + amount;
		ingredients[id - 1].setAmount(new_amount);
	}

	void decrement(int id, int amount)
	{
		if (id > ingredients.size() || amount > ingredients[id - 1].getAmount())
		{
			throw DatabaseException("Meblegi azalda bilmerik!", __FILE__, __LINE__, __TIME__);

		}
		int new_amount = ingredients[id - 1].getAmount() - amount;
		ingredients[id - 1].setAmount(new_amount);
	}

	void deleteAllIngredients()
	{
		ingredients.clear();
	}

	void deleteIngredientById(int id)
	{
		if (id > ingredients.size())
		{
			throw DatabaseException("Burada elave yoxdur", __FILE__, __LINE__, __TIME__);
		}
		ingredients.erase(ingredients.begin() + id - 1);
	}

	void addNewIng()
	{

	}

	void addNotfStock()
	{
		//notf_ingredients.push_back(NotfIngredient("text"));

	}
	void findIngredientByName(string name)
	{
		

		for (auto i = ingredients.begin(); i != ingredients.end(); i++)
		{
			if (name == i->getName())
			{
				i->show();
			}
		}


	}




	void deleteNotfIngredient()
	{
		notf_ingredients.push_back(NotfIngredient("Elaveler silindi"));
	}

	void increaseNotf()
	{
		notf_ingredients.push_back(NotfIngredient("Elave artirma--> "));
	}

	void decreaseNotf()
	{
		notf_ingredients.push_back(NotfIngredient("Elave azaltma--> "));
	}

	void showNotfIngredient()
	{
		for (auto i = notf_ingredients.begin();
			i != notf_ingredients.end(); i++)
		{
			i->printMessage();
		}
	}

	void updateIngredientById(int id)
	{
		if (id > ingredients.size())
		{
			throw DatabaseException("Elave yoxdur!", __FILE__, __LINE__, __TIME__);
		}
		string name;
		double fats, protein, carbogydrates;
		int kcal, n;
		while (1)
		{
			cout << "[1]Yemeyin adi " << endl;
			cout << "[2]Yag " << endl;
			cout << "[3]Protein " << endl;
			cout << "[4]Karbohidrat \n";
			cout << "[5]Kcal \n";
			cout << "Hansi hisseni yenilemek isteyirsen? --> ";
			cin >> n;
			while (n < 1 || n>5)
			{
				cout << "Yeniden yoxla" << endl;
				cin >> n;
			}


			switch (n)
			{
			case 1:
				cout << "Adi yenile" << endl;
				cout << "Ad: ";
				cin >> name;
				ingredients[id - 1].setName(name);
				break;
			case 2:
				cout << "Yag yenile " << endl;
				cout << "Yag:";
				cin >> fats;
				ingredients[id - 1].setFat(fats);
				break;
			case 3:
				cout << "Yenile protein:" << endl;
				cout << "Protein:";
				cin >> protein;
				ingredients[id - 1].setProtein(protein);
				break;
			case 4:
				cout << "Yenile karbohidrat:" << endl;
				cout << "Karbohidrat:";
				cin >> carbogydrates;
				ingredients[id - 1].setCarbogydrates(carbogydrates);
				break;
			case 5:
				cout << "Yenile Kcal:" << endl;
				cout << "Kcal:";
				cin >> kcal;
				ingredients[id - 1].setKcal(kcal);
				break;
			}
			char s;
			cout << "Yeniden yenilemek istersiniz mi:y/n ";
			cin >> s;
			if (s != 121 && s != 89)
				return;
		}

	}


	void addIngredient(Ingredient ing)
	{
		ingredients.push_back(ing);
	}

	void showIngredientById(int id)
	{
		if (id > ingredients.size())
		{
			throw DatabaseException("Mehsul movcud deyil", __FILE__, __LINE__, __TIME__);

		}
		ingredients[id - 1].show();
	}

	void showAllIngredients()
	{
		

		int counter = 0;
		for (auto i = ingredients.begin();
			i != ingredients.end(); i++)
		{
			i->show();
			++counter;
		}
		if (counter == 0)
		{
			throw DatabaseException("Elave yoxdur", __FILE__, __LINE__, __TIME__);
		}
	}

};


class Kitchen
{
	vector<Meal> meals;
	Stock s;
	int amount;
	vector<NotfIngredient> notf_ingredients;
public:
	Kitchen() :meal(nullptr) {}
	Meal* meal;

	int getAmount() const
	{
		return amount;
	}

	void deleteAllMeals()
	{
		meals.clear();
	}

	void getRecipe(int id)
	{
		if (id > meals.size())
		{
			throw DatabaseException("Menyu movcud deyil", __FILE__, __LINE__, __TIME__);

		}
		meals[id - 1].printRecipe();
	}


	void deleteNotfIngredient()
	{
		notf_ingredients.push_back(NotfIngredient("Yemek silindi"));
	}

	void deleteMealById(int id)
	{
	
		if (id > meals.size())
		{
			throw DatabaseException("Yemek movcud deyil", __FILE__, __LINE__, __TIME__);

		}
		meals.erase(meals.begin() + id - 1);
	}

	void updateMealById(int id)
	{
		if (id > meals.size())
		{
			throw DatabaseException("Yemek movcud deyil", __FILE__, __LINE__, __TIME__);
		}
		string name, category;
		double rating, price, tax;
		int n;
		while (1)
		{
			cout << "[1]Yemeyin Ad " << endl;
			cout << "[2]Kategoriya " << endl;
			cout << "[3]Reyting " << endl;
			cout << "[4]Qiymet \n";
			cout << "[5]Tax \n";
			cout << "Hansi hisseni yenilemek istersiniz?";
			cin >> n;
			while (n < 1 || n>5)
			{
				cout << "Yeniden yoxla" << endl;
				cin >> n;
			}


			switch (n)
			{
			case 1:
				cout << "Adin yenilenmesi " << endl;
				cout << "Ad:";
				cin >> name;
				meals[id - 1].setName(name);
				break;
			case 2:
				cout << "Kategoriya yenilenmesi--> " << endl;
				cout << "kategoriya:";
				cin >> category;
				meals[id - 1].setCategory(category);
				break;
			case 3:
				cout << "Raitingin yenilenmesi:" << endl;
				cout << "Reyting:";
				cin >> rating;
				meals[id - 1].setRating(rating);
				break;
			case 4:
				cout << "Qiymet Yenilenmesi:" << endl;
				cout << "Qiymet:";
				cin >> price;
				meals[id - 1].setPrice(price);
				break;
			case 5:
				cout << "Tax Yenileme :" << endl;
				cout << "Tax:";
				cin >> tax;
				meals[id - 1].setTax(tax);
				break;
			}
			char s;
			cout << "Yeniden yenilemek istersiniz mi:y/n ";
			cin >> s;
			if (s != 121 && s != 89)
				return;
		}

	}

	void findMealByName(string name)
	{
		int counter = 0;
		for (auto i = meals.begin(); i != meals.end(); i++)
		{
			if (name == i->getName())
			{
				i->showMeal();
				++counter;
			}
		}
		if (counter == 0)
			cout << "Burada Yoxdur" << endl;
	}


	void addMeal(Meal meal)
	{
		meals.push_back(meal);
	}

	void showMealById(int id)
	{
		if (id > meals.size())
		{
			throw DatabaseException("Produkt yoxdur", __FILE__, __LINE__, __TIME__);

		}
		meals[id - 1].showMeal();
	}

	void showAllMeals()
	{
		int counter = 0;
		for (auto i = meals.begin();
			i != meals.end(); i++)
		{
			i->showMeal();
			++counter;
		}
		if (counter == 0)
		{
			throw DatabaseException("Movcud deyil", __FILE__, __LINE__, __TIME__);
		}
	}


	Meal getMealById(int id)
	{
		if (id > meals.size())
		{
			throw DatabaseException("Produkt yoxdur", __FILE__, __LINE__, __TIME__);
		}
		else
		{
			return meals.at(id - 1);
		}
	}

	int getMealSize()
	{
		return meals.size();
	}

	vector<Meal> getMeal()
	{
		return meals;
	}
	/*vector<Meal> getVectorMealById(int id)
	{
		return meals.at(id);
	}*/

};




