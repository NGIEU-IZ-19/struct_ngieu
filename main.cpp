//���� ����������� ��������� ����� ����������� ���������
#include <iostream> //����������� ���������� iostream ��� ����� ������ ����������
#include <string> //����������� ���������� string ������ �� ���������� �������

struct MARSH // ��������� ��������� MARSH 
{
	std::string BEGST; 
	std::string TERM;
	int NUMER;	// ������ �������� �� ������������ ������ ����� stdin (�������)
};

bool has_only_digits(const std::string check_number) {
	return check_number.find_first_not_of("0123456789") == std::string::npos; // std::string::npos - �� ����� ������
}

void add_route(MARSH TRAFIC[], int arraylength) // ������� ��� ����������  ������ � ������ ���������, � ����������� �����������
{
	int i;
	std::string check_number;
	std::cout << "������� � ���������� ���������� ��� ���������� ������� " << std::endl; // ������������ � ��������� (�������� �� ����� ������ ����������� ����� ������)
	for (i = 0; i < unsigned(arraylength); i++)
	{
		do
		{
			std::cout << "����� �������� (������������� ����� �����): ";
			std::cin >> check_number;
			has_only_digits(check_number);
		} 
		while (has_only_digits(check_number)==false);

		TRAFIC[i].NUMER = atoi(check_number.c_str());
		std::cout << "�������� ���������� ������ ��������: ";
		std::cin >> TRAFIC[i].BEGST;
		std::cout << "�������� ��������� ������ ��������: "; 
		std::cin >> TRAFIC[i].TERM;
	}

	int r;
	MARSH arr_temp;

	for (i = 0; i < unsigned(arraylength); i++)
	{

		for (r = 0; r < unsigned(arraylength); r++)
		{
			// ����� ������� �� �������� ����� ������� ������� ���������� ������
			if (TRAFIC[r].NUMER > TRAFIC[r + 1].NUMER)
			{
				arr_temp = TRAFIC[r + 1];
				TRAFIC[r + 1] = TRAFIC[r];
				TRAFIC[r] = arr_temp;
			}
		}
	}

}


int lineSearch(MARSH TRAFIC[], int requiredKey, int arraylength)			//�������� �����
{
		for (int i = 0; i < arraylength; i++)
		{
			if (TRAFIC[i].NUMER == requiredKey)
				return i ;
		}
		return 0;
}

void show_one_route(MARSH TRAFIC[], int arraylength) // ������� �� ������������ �������� ��� ��������� ������������� ��������
{

	int requiredKey;
	std::cout << "������� � ���������� ����� �������� ��� ���������: "; // ������������ � ��������� (�������� �� ����� ������ ����������� ����� ������)
	std::cin >> requiredKey;

	int m = (lineSearch(TRAFIC, requiredKey, arraylength));

	if (m == 0)
	{
		std::cout << "������� ����������� � �������" << std::endl;
	}
	else 
	{ 
		std::cout << "������ �� ������ �������:" << std::endl;
		std::cout << "����� ��������" << TRAFIC[m].NUMER << std::endl;
		std::cout << "�������� ���������� ������ ��������: " << TRAFIC[m].BEGST << std::endl;
		std::cout << "�������� ��������� ������ ��������: " << TRAFIC[m].TERM << std::endl;
	}
}


void show_full_route(MARSH TRAFIC[], int arraylength) // ������� �� ������������ �������� ��� ��������� ������������� ��������
{

	int i;
	for (i = 0; i < unsigned(arraylength); i++)
	{
		std::cout << "����� ��������:" << TRAFIC[i].NUMER << std::endl;
		std::cout << "�������� ���������� ������ ��������: " << TRAFIC[i].BEGST << std::endl;
		std::cout << "�������� ��������� ������ ��������: " << TRAFIC[i].TERM << std::endl;
	}

}

int main (void)						// ��������� ������� ������� ������� ���������� ����� ����� ��� ���������� (?)
{
	//���� ���������� ����������
	const int arraylength = 8;
	MARSH TRAFIC[arraylength];
	//���� ���������� ����������
	setlocale(LC_ALL, "rus");		// ��������� ������ �������
	add_route(TRAFIC, arraylength); // ����� ������ (�������), �������� ���������� � �������� ������� ����������
	std::cout << "�������� ����� ��������" << std::endl;
	show_one_route(TRAFIC, arraylength);
	std::cout << "����� ������� ������� ���������" << std::endl;
	show_full_route(TRAFIC, arraylength);
	system("pause");				// ��������� ���������� ���������
	return 0;						//  �����  
}