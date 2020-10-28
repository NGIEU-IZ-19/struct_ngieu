//Блок подключения библиотек перед выполнением программы
#include <iostream> //Подключение библиотеки iostream для ввода вывода информации
#include <string> //Подключение библиотеки string работы со строковыми данными

struct MARSH // Объявляем структуру MARSH 
{
	std::string BEGST;	// данные беруться из стандартного потока ввода stdin (консоль)
	std::string TERM;	// данные беруться из стандартного потока ввода stdin (консоль)
	std::string	NUMER;
};

void add_route(MARSH TRAFIC[], int arraylength) // разобраться
{
	std::cout << "Введите с клавиатуры информации для заполнения массива " << std::endl; // разобратиься с описанием (передать на вывод данные обработчику ввода вывода)
	int i;
	for (i = 0 ; i < unsigned(arraylength); i++)
	{
		std::cout << "Номер маршрута: ";
		std::cin >> TRAFIC[i].BEGST;
		std::cout << "Название начального пункта маршрута: ";
		std::cin >> TRAFIC[i].BEGST;
		std::cout << "Название конечного пункта маршрута: ";
		std::cin >> TRAFIC[i].BEGST;
	}
	std::cout << std::endl; // завершить вывод из стандартного потока вывода stdout (консоль), т.е. (?)
}


int main (void)							// Объявляем главную функцию которая возвращает целое число при выполнении
{
	//Блок объявления переменных
	const int arraylength = 8;

	MARSH TRAFIC[arraylength];
	//Блок объявления переменных

	setlocale(LC_ALL, "rus"); // установка вывода локации
	add_route(TRAFIC, arraylength); // вызов метода (функции), передача переменных в качестве входных параметров
	system("pause");		 // остановка выполнения программы
	return 0;				//  вывод  
}





