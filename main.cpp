//���� ����������� ��������� ����� ����������� ���������
#include <iostream> //����������� ���������� iostream ��� ����� ������ ����������
#include <string> //����������� ���������� string ������ �� ���������� �������

struct MARSH // ��������� ��������� MARSH 
{
	std::string BEGST;	// ������ �������� �� ������������ ������ ����� stdin (�������)
	std::string TERM;	// ������ �������� �� ������������ ������ ����� stdin (�������)
	std::string	NUMER;
};

void add_route(MARSH TRAFIC[], int arraylength) // �����������
{
	std::cout << "������� � ���������� ���������� ��� ���������� ������� " << std::endl; // ������������ � ��������� (�������� �� ����� ������ ����������� ����� ������)
	int i;
	for (i = 0 ; i < unsigned(arraylength); i++)
	{
		std::cout << "����� ��������: ";
		std::cin >> TRAFIC[i].BEGST;
		std::cout << "�������� ���������� ������ ��������: ";
		std::cin >> TRAFIC[i].BEGST;
		std::cout << "�������� ��������� ������ ��������: ";
		std::cin >> TRAFIC[i].BEGST;
	}
	std::cout << std::endl; // ��������� ����� �� ������������ ������ ������ stdout (�������), �.�. (?)
}


int main (void)							// ��������� ������� ������� ������� ���������� ����� ����� ��� ����������
{
	//���� ���������� ����������
	const int arraylength = 8;

	MARSH TRAFIC[arraylength];
	//���� ���������� ����������

	setlocale(LC_ALL, "rus"); // ��������� ������ �������
	add_route(TRAFIC, arraylength); // ����� ������ (�������), �������� ���������� � �������� ������� ����������
	system("pause");		 // ��������� ���������� ���������
	return 0;				//  �����  
}





