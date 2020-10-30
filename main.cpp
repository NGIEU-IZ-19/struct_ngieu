//Блок подключения библиотек перед выполнением программы
#include <iostream> //Подключение библиотеки iostream для ввода вывода информации
#include <string> //Подключение библиотеки string работы со строковыми данными

struct MARSH // Объявляем структуру MARSH 
{
	std::string BEGST; 
	std::string TERM;
	int NUMER;	// данные беруться из стандартного потока ввода stdin (консоль)
};

bool has_only_digits(const std::string check_number) {
	return check_number.find_first_not_of("0123456789") == std::string::npos; // std::string::npos - до конца строки
}

void add_route(MARSH TRAFIC[], int arraylength) // Функция для добавления  данный в массив маршрутов, с последующей сортировкой
{
	int i;
	std::string check_number;
	std::cout << "Введите с клавиатуры информации для заполнения массива " << std::endl; // разобратиься с описанием (передать на вывод данные обработчику ввода вывода)
	for (i = 0; i < unsigned(arraylength); i++)
	{
		do
		{
			std::cout << "Номер маршрута (положительное целое число): ";
			std::cin >> check_number;
			has_only_digits(check_number);
		} 
		while (has_only_digits(check_number)==false);

		TRAFIC[i].NUMER = atoi(check_number.c_str());
		std::cout << "Название начального пункта маршрута: ";
		std::cin >> TRAFIC[i].BEGST;
		std::cout << "Название конечного пункта маршрута: "; 
		std::cin >> TRAFIC[i].TERM;
	}

	int r;
	MARSH arr_temp;

	for (i = 0; i < unsigned(arraylength); i++)
	{

		for (r = 0; r < unsigned(arraylength); r++)
		{
			// Обмен местами по принципу более тяжелый элемент перемещаем вправо
			if (TRAFIC[r].NUMER > TRAFIC[r + 1].NUMER)
			{
				arr_temp = TRAFIC[r + 1];
				TRAFIC[r + 1] = TRAFIC[r];
				TRAFIC[r] = arr_temp;
			}
		}
	}

}


int lineSearch(MARSH TRAFIC[], int requiredKey, int arraylength)			//линейный поиск
{
		for (int i = 0; i < arraylength; i++)
		{
			if (TRAFIC[i].NUMER == requiredKey)
				return i ;
		}
		return 0;
}

void show_one_route(MARSH TRAFIC[], int arraylength) // Функция не возвращающая значений для просмотра определенного маршрута
{

	int requiredKey;
	std::cout << "Введите с клавиатуры номер маршрута для просмотра: "; // разобратиься с описанием (передать на вывод данные обработчику ввода вывода)
	std::cin >> requiredKey;

	int m = (lineSearch(TRAFIC, requiredKey, arraylength));

	if (m == 0)
	{
		std::cout << "Маршрут отсутствует в массиве" << std::endl;
	}
	else 
	{ 
		std::cout << "Данные по вашему запросу:" << std::endl;
		std::cout << "Номер маршрута" << TRAFIC[m].NUMER << std::endl;
		std::cout << "Название начального пункта маршрута: " << TRAFIC[m].BEGST << std::endl;
		std::cout << "Название конечного пункта маршрута: " << TRAFIC[m].TERM << std::endl;
	}
}


void show_full_route(MARSH TRAFIC[], int arraylength) // Функция не возвращающая значений для просмотра определенного маршрута
{

	int i;
	for (i = 0; i < unsigned(arraylength); i++)
	{
		std::cout << "Номер маршрута:" << TRAFIC[i].NUMER << std::endl;
		std::cout << "Название начального пункта маршрута: " << TRAFIC[i].BEGST << std::endl;
		std::cout << "Название конечного пункта маршрута: " << TRAFIC[i].TERM << std::endl;
	}

}

int main (void)						// Объявляем главную функцию которая возвращает целое число при выполнении (?)
{
	//Блок объявления переменных
	const int arraylength = 8;
	MARSH TRAFIC[arraylength];
	//Блок объявления переменных
	setlocale(LC_ALL, "rus");		// установка вывода локации
	add_route(TRAFIC, arraylength); // вызов метода (функции), передача переменных в качестве входных параметров
	std::cout << "Выполним поиск маршрута" << std::endl;
	show_one_route(TRAFIC, arraylength);
	std::cout << "Вывод полного массива маршрутов" << std::endl;
	show_full_route(TRAFIC, arraylength);
	system("pause");				// остановка выполнения программы
	return 0;						//  вывод  
}