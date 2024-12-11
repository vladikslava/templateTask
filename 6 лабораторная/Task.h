#pragma once


#include "Itask.h"

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale>
#include <cstring>

using namespace std;

class Task : public Itask
{
protected:
	char* nameTask = nullptr;
	char* deadline = nullptr;
	char* executor = nullptr;
	int flag = 0;
	int timeForTaskGrade = 0;
	int timeForTaskReal = 0;

public:

	enum  Task_Category { ERROR = -1, SUPPORT = 0, NEW = 1 };
	Task_Category category;

	//����������� � �����������
	Task(const char* nameTask, Task_Category category, const char* deadline);

	//������������� ����������� 
	Task(const char* nameTask, Task_Category category, const char* deadline, const char* executor, int flag = 1);

	//��������� �����
	void setName(const char* name);

	//��������� ����� �����
	void setDeadline(const char* date);

	//��������� �����
	void setComplited(bool flag);

	//������������� �������� ���������� ������� 
	virtual int operator+=(int time) override;

	//��������� �������
	void setTimeForTaskGrade(int timeForTaskGrade);

	//��������� �����������
	void setExecutor(const char* nameExecutor);

	//����� �������� ������� ���������� ������
	bool  pointOverdueTask() const;

	//��������� �������� � �������������� ������
	int  getPointOverdueTask() const;

	//����� ���������� �������
	void addTime(int time);

	//��������� �������� �����  
	char* getNameTask() const;

	//��������� ���� �����
	char* getDeadline() const;


	//��������� ����� �����������
	char* getExecutor() const;

	//��������� ����� ���������� ������
	const char* getFlag() const;

	//��������� ����������� �� ������ �������
	int getTimeForTaskGrade() const;

	//��������� ��������� ������
	const char* getCategory() const;

	//��������� �������, ������������ �� ������
	int getTimeForTaskReal() const;

	//����� ������ ���������� � ������ �� ��������
	virtual void showCout() const override;

	virtual ~Task();

};

//������������� �������� <<
ostream& operator << (ostream& out, const Task* task);

//������������� �������� += ��� ������� ������������ �������
double& operator+=(double& sum, const Task& task);

