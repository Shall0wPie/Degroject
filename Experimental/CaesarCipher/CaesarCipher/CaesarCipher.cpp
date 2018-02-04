// CaesarCipher.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void crypter(char *str) { //��������
	
	for (int j = 0; j < 2; j++) {                  
		str[0] += (str[1] + str[strlen(str) - 1]); 
		/*���� ��� ��������� �������� � ��������� ���� ��� ��������� ���� �� 1 �������
		  ������� �������� � ����������� �������� ������� ����� � ������
		  �� ��� ������ ����� �� ������ ������ ������� ��������� �����-�� ������,	
		  � �� ����� ���������, ��������?*/                			  
		for (int i = 1; str[i]; i++) {
			if (!str[i + 1]) {
				str[i] += (str[0] + str[i - 1]);
			}
			/*�� �� ����� �� ��� ���������� �������,
			  � (!str[i+1]) ��������� ���� ������ ������ ������ '\0',
			  �� ���� 0, �� ���� false, a ! �����������. Got it?*/    
			else
				str[i] += (str[i + 1] + str[i - 1]); //� ��� ��� �� ����������� ������������
		}
	}
}

void decrypter(char* str) {
	
	int str_l = strlen(str);//���� +�������������
	for (int j = 0; j < 2; j++) {
		str[str_l - 1] -= (str[0] + str[str_l - 2]);//�� �� ��� � ��� �������� ������ � �������� ������� � � ����������
		for (int i = str_l - 2; i >= 0; i--) {
			if (i == 0)
				str[i] -= (str[i + 1] + str[str_l - 1]);
			else
				str[i] -= (str[i + 1] + str[i - 1]);
		}
	}
}

int main()
{
	char str[] = "Random message";
	
	cout << str << endl;
	crypter(str);
	cout << str << endl;
	decrypter(str);
	cout << str << endl;

	system("pause");
    return 0;
}