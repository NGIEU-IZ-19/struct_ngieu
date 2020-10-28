//���� ����������� ��������� ����� ����������� ���������
#include <iostream> //����������� ���������� iostream ��� ����� ������ ����������
#include <string> //����������� ���������� string ������ �� ���������� �������

struct MARSH // ��������� ��������� MARSH 
{
	std::string BEGST;	// ������ �������� �� ������������ ������ ����� stdin (�������)
	std::string TERM;	// ������ �������� �� ������������ ������ ����� stdin (�������)
	float NUMER;	// ������ �������� �� ������������ ������ ����� stdin (�������)
};

void add_route(MARSH TRAFIC[], int arraylength) // �����������
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

	std::cout << std::endl; // ��������� ����� �� ������������ ������ ������ stdout (�������), �.�. (?)
}


//�������� �����
int lineSearch(MARSH TRAFIC[], int requiredKey, int arraylength)
{

		for (int i = 0; i < arraylength; i++)
		{
			if (TRAFIC[i].NUMER == requiredKey)
				return i ;
		}

		return 0;

}



void show_route(MARSH TRAFIC[], int arraylength) // �����������
{

	float requiredKey;
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

	std::cout << std::endl;			// ��������� ����� �� ������������ ������ ������ stdout (�������), �.�. (?)
}


int main (void)						// ��������� ������� ������� ������� ���������� ����� ����� ��� ���������� (?)
{
	//���� ���������� ����������
	const int arraylength = 8;
	MARSH TRAFIC[arraylength];
	//���� ���������� ����������

	setlocale(LC_ALL, "rus");		// ��������� ������ �������
	add_route(TRAFIC, arraylength); // ����� ������ (�������), �������� ���������� � �������� ������� ����������
	show_route(TRAFIC, arraylength);			//
	system("pause");				// ��������� ���������� ���������
	return 0;						//  �����  
}





