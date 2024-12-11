#pragma once

#include "Itask.h"

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale>
#include <cstring>

using namespace std;

template<typename typeTime>
class TemplateTask : public Itask
{
protected:
	char* nameTask = nullptr;
	char* deadline = nullptr;
	char* executor = nullptr;
	int flag = 0;
	typeTime timeForTaskGrade = 0;
	typeTime timeForTaskReal = 0;

public:

	enum  Task_Category { ERROR = -1, SUPPORT = 0, NEW = 1 };
	Task_Category category;


	TemplateTask(const char* const nameTask, Task_Category category, const char* deadline, typeTime time) {
		setName(nameTask);
		this->category = category;
		setDeadline(deadline);
		setTimeForTaskGrade(time);
	}

	//перегруженный конструктор 

	TemplateTask(const char* nameTask, Task_Category category, const char* deadline, const char* executor, int flag) {
		setName(nameTask);
		this->category = category;
		setDeadline(deadline);
		setExecutor(executor);
	}


	//установка имени

	void setName(const char* name) {
		if (name == nullptr) {
			throw "Нулевой указатель в качестве аргумента";
		}

		int sizeName = strlen(name);
		if (!sizeName) {
			throw "Строка не может быть пустой";
		}

		if (nameTask != nullptr) {
			delete nameTask;
			nameTask = nullptr;
		}
		nameTask = new char[sizeName + 1];
		memset(nameTask, 0, sizeof(char) * (sizeName + 1));
		strcpy(nameTask, name);

	}

	//установка срока сдачи

	void setDeadline(const char* date) {
		if (date == nullptr) {
			throw "Нулевой указатель в качестве аргумента";
		}

		int sizeDeadline = strlen(date);
		if (!sizeDeadline) {
			throw "Строка не может быть пустой";
		}

		if (date != nullptr) {
			delete deadline;
			deadline = nullptr;
		}
		deadline = new char[sizeDeadline + 1];
		memset(deadline, 0, sizeof(char) * (sizeDeadline + 1));
		strcpy(deadline, date);

	}

	//установка флага

	void setComplited(bool flag) {
		this->flag = flag;

	}

	//установка времени

	void setTimeForTaskGrade(typeTime timeForTaskGrade) {
		if (timeForTaskGrade <= 0) {
			throw "Недопустимое зачение времени";
		}
		this->timeForTaskGrade = timeForTaskGrade;
	}

	//установка исполнителя

	void setExecutor(const char* nameExecutor) {
		if (nameExecutor == nullptr) {
			throw "Нулевой указатель в качестве аргумента";
		}

		int sizeExecutor = strlen(nameExecutor);
		if (!sizeExecutor) {
			throw "Строка не может быть пустой";
		}

		if (executor != nullptr) {
			delete executor;
			executor = nullptr;
		}
		executor = new char[sizeExecutor + 1];
		memset(executor, 0, sizeof(char) * (sizeExecutor + 1));
		strcpy(executor, nameExecutor);

	}

	//метод проверки статуса выполнения работы

	bool pointOverdueTask() const {
		if (timeForTaskReal > timeForTaskGrade) {
			return false;
		}
		else {
			return true;
		}
	}

	//получение сведений о просроченности задачи

	int getPointOverdueTask() const {
		return timeForTaskReal - timeForTaskGrade;
	}


	//метод добавления времени

	void addTime(typeTime time) {
		if (time <= 0) {
			throw "Неверное значение времени";
		}
		else {
			timeForTaskReal = timeForTaskGrade + time;
		}

	}

	//получение значения имени  

	char* getNameTask() const {
		if (nameTask == nullptr) {
			return nullptr;
		}
		int sizeNameTask = strlen(nameTask);
		char* returnNameTask = new char[sizeNameTask + 1];
		memset(returnNameTask, 0, sizeof(char) * (sizeNameTask + 1));
		strcpy(returnNameTask, nameTask);
		return returnNameTask;
	}

	//получение даты сдачи

	char* getDeadline() const {
		if (deadline == nullptr) {
			return nullptr;
		}
		int sizeDeadline = strlen(deadline);
		char* returnDeadline = new char[sizeDeadline + 1];
		memset(returnDeadline, 0, sizeof(char) * (sizeDeadline + 1));
		strcpy(returnDeadline, deadline);
		return returnDeadline;
	}

	//получение имени исполнителя

	char* getExecutor() const {
		if (executor == nullptr) {
			return nullptr;
		}
		int sizeExecutor = strlen(executor);
		char* returnExecutor = new char[sizeExecutor + 1];
		memset(returnExecutor, 0, sizeof(char) * (sizeExecutor + 1));
		strcpy(returnExecutor, executor);
		return returnExecutor;
	}

	//получение флага выполнения задачи

	const char* getFlag() const {
		if (flag) {
			return "Задача открыта";
		}
		else {
			return "Задача закрыта";
		}
	}

	//получение выделенного на задачу времени

	typeTime getTimeForTaskGrade() const {
		return timeForTaskGrade;
	}

	//получение типа задачи

	const char* getCategory() const {
		switch (category) {
		case(ERROR): { return "Ошибка"; };
		case(SUPPORT): {return "Поддержка"; };
		case(NEW): {return "Новая задача"; };
		}
	}

	//получение времени, затраченного на задачу

	typeTime getTimeForTaskReal() const {
		return timeForTaskReal;
	}

	virtual int operator+=(int time) override {
		timeForTaskReal = time + timeForTaskGrade;
		return timeForTaskReal;
	}

	//метод вывода информации о задачи на терминал

	virtual void showCout() const override{
		cout << endl << "Задача '" << getNameTask() << "':" << endl <<
			"Тип задачи: " << getCategory() << endl <<
			"Исполнитель задачи: " << getExecutor() << endl <<
			"Статус: " << getFlag() << endl <<
			"Срок сдачи задачи: " << getDeadline() << endl <<
			"На задачу отведено " << getTimeForTaskGrade() << endl;
	}

	virtual ~TemplateTask() {
		if (nameTask != nullptr) {
			delete nameTask;
			nameTask = nullptr;
		}

		if (deadline != nullptr) {
			delete deadline;
			deadline = nullptr;
		}

		if (executor != nullptr) {
			delete executor;
			executor = nullptr;
		}
	}

};

