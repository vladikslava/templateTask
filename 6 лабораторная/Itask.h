#pragma once

//��������� ��� ������ ���� � ��� ��������� += ��� ���������� ������� ����������
class Itask {
public:
	virtual void showCout() const = 0;
	virtual int operator+=(int count) = 0;
	virtual ~Itask() {};
};
