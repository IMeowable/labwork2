using namespace std;
#include <iostream>
#include <sstream>

//Валидация вводимых значений, провеерка на принадлежность к вещественным числам

bool IsDouble(string check_string)
{

	istringstream iss{ (check_string) };
	double f;
	iss >> noskipws >> f;
	if (iss.eof() && !iss.fail() and f > -10)
	{

		return true;
	}
	else
	{

		return false;
	}
}

//функция поиска точки на графике
void find_y(double user_input)

{
	//определение принадлежности графику введенного значения условными операторами
	if (user_input <= -6)
	{
		//уравнение полукруга y = -1 * sqrt(R^2 - x^2)
		//r = 2, центр окружности (-8; 2)
		//(x+8)^2+(y-2)^2 = 4 
		//  (y-2)^2 = 4 - (x+8)^2
		//y = sqrt(4-(x+8))^2) + 2
		cout << "Y:\t" << -sqrt((4 - pow((user_input + 8), 2))) + 2 << endl;;
	}
	if (user_input > -6 && user_input <= -4)
	{
		//на графике фнукция параллельна оси Ox
		cout << "Y:\t" << 2 << endl;;

	}
	if (user_input == 0) {
		cout << "Y:\t" << 0 << endl;;
	}
	if (user_input > -4 && user_input < 2 && user_input != 0)
	{
		//k = -1/2 , функция y = kx + m	
		cout << "Y:\t" << -user_input / 2. << endl;;
	}
	if (user_input >= 2)
	{
		//функция y = kx + m    k = 1 m = -3
		cout << "Y:\t" << user_input - 3. << endl;;
	}
}

//функция итеративного поиска(с шагом 1). С клавиатуры задаются границы поиска.
void cyclic_find()
{
	//получаем границы поиска с клавиатуры
	string check_first;
	string check_second;
	cin >> check_first;
	cout << "Enter 'xn':\n";
	cin >> check_second;
	//проверяем оба ли граничных значения введены корректно
	if (IsDouble(check_first) && IsDouble(check_second))
	{
		double i = stod(check_first);
		cout << i<< endl;
		double last = stod(check_second);
		cout << last << endl;
		//проверяем правильно ли мы указали промежуток(я бы мог сделать ещё шаг справа налево, но лень)
		if (i < last)
		{
			for (i; i <= last; i++)
			{
				//простейше выводим наши значения функции в консоль
				cout << "X:\t"<< i<<"\t";
				find_y(i);

			}
		}
		else cout << "Enter numbers from left to the right" << endl;
	}
	else
	{
		cout << "Wrong, try again" << endl;
	}



}





int main()
{
	while (1)
		cyclic_find();
}
