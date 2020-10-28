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
		std::cin >> TRAFIC[i].NUMER;
		std::cout << "�������� ���������� ������ ��������: ";
		std::cin >> TRAFIC[i].BEGST;
		std::cout << "�������� ��������� ������ ��������: "; 
		std::cin >> TRAFIC[i].TERM;
	}
	std::cout << std::endl; // ��������� ����� �� ������������ ������ ������ stdout (�������), �.�. (?)
}

void show_route(MARSH TRAFIC[]) // �����������
{
	int i;
	std::cout << "������� � ���������� ����� ��������: "; // ������������ � ��������� (�������� �� ����� ������ ����������� ����� ������)
	std::cin >> i;
	std::cout << "������ �� ������ �������" << std::endl;
	std::cout << "�������� ���������� ������ ��������: " << TRAFIC[i-1].BEGST << std::endl;
	std::cout << "�������� ��������� ������ ��������: " << TRAFIC[i-1].TERM << std::endl;
	std::cout << "����� ��������" << TRAFIC[i-1].NUMER << std::endl;
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
	show_route(TRAFIC);
	system("pause");		 // ��������� ���������� ���������
	return 0;				//  �����  
}





