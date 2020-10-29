//���� ����������� ��������� ����� ����������� ���������
#include <iostream> //����������� ���������� iostream ��� ����� ������ ����������
#include <string> //����������� ���������� string ������ �� ���������� �������

struct MARSH // ��������� ��������� MARSH 
{
	std::string BEGST;	// ������ �������� �� ������������ ������ ����� stdin (�������)
	std::string TERM;	// ������ �������� �� ������������ ������ ����� stdin (�������)
	int NUMER;	// ������ �������� �� ������������ ������ ����� stdin (�������)
};

void add_route(MARSH TRAFIC[], int arraylength) // ������� ��� ����������  ������ � ������ ���������, � ����������� �����������
{
	std::cout << "������� � ���������� ���������� ��� ���������� ������� " << std::endl; // ������������ � ��������� (�������� �� ����� ������ ����������� ����� ������)
	int i;
	for (i = 0 ; i < unsigned(arraylength); i++)
	{
		std::cout << "����� ��������: ";
		std::cin >> TRAFIC[i].NUMER;
		std::cout << "�������� ���������� ������ ��������: ";
		std::cin >> TRAFIC[i].BEGST;
		std::cout << "�������� ��������� ������ ��������: "; 
		std::cin >> TRAFIC[i].TERM;
	}

	TRAFIC[arraylength] = ((sort_increase(TRAFIC, arraylength)));

}


MARSH sort_increase(MARSH TRAFIC[], int arraylength) // ������� ��� ���������� ��������� ������� ������� "��������"
{
	int i;
	int r;
	MARSH arr_temp;

	for (i = 0; i < unsigned(arraylength); i++)
	{
	
		for (r = 0; r < unsigned(arraylength); r++) 
		{
			// ����� ������� �� �������� ����� ������ 
			if (TRAFIC[r].NUMER > TRAFIC[r+1].NUMER)
			{ 
				arr_temp = TRAFIC[r+1];
				TRAFIC[r + 1] = TRAFIC[r];
				TRAFIC[r] = arr_temp;
			}
		}
	}
	return TRAFIC[arraylength];

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
	MARSH n = { "none", "none" };
	
	std::cout << "������� � ���������� ����� ��������: "; // ������������ � ��������� (�������� �� ����� ������ ����������� ����� ������)
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
		std::cout << "����� ��������" << TRAFIC[i].NUMER << std::endl;
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
	show_one_route(TRAFIC, arraylength);
	show_full_route(TRAFIC, arraylength);
	system("pause");				// ��������� ���������� ���������
	return 0;						//  �����  
}