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

	//конструктор с параметрами
	Task(const char* nameTask, Task_Category category, const char* deadline);

	//перегруженный конструктор 
	Task(const char* nameTask, Task_Category category, const char* deadline, const char* executor, int flag = 1);

	//установка имени
	void setName(const char* name);

	//установка срока сдачи
	void setDeadline(const char* date);

	//установка флага
	void setComplited(bool flag);

	//перегруженный оператор добавления времени 
	virtual int operator+=(int time) override;

	//установка времени
	void setTimeForTaskGrade(int timeForTaskGrade);

	//установка исполнителя
	void setExecutor(const char* nameExecutor);

	//метод проверки статуса выполнения работы
	bool  pointOverdueTask() const;

	//получение сведений о просроченности задачи
	int  getPointOverdueTask() const;

	//метод добавления времени
	void addTime(int time);

	//получение значения имени  
	char* getNameTask() const;

	//получение даты сдачи
	char* getDeadline() const;


	//получение имени исполнителя
	char* getExecutor() const;

	//получение флага выполнения задачи
	const char* getFlag() const;

	//получение выделенного на задачу времени
	int getTimeForTaskGrade() const;

	//получение категории задачи
	const char* getCategory() const;

	//получение времени, затраченного на задачу
	int getTimeForTaskReal() const;

	//метод вывода информации о задачи на терминал
	virtual void showCout() const override;

	virtual ~Task();

};

//перегруженный оператор <<
ostream& operator << (ostream& out, const Task* task);

//Перегруженный оператор += для расчета затраченного времени
double& operator+=(double& sum, const Task& task);

