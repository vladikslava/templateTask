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

	//������������� ����������� 

	TemplateTask(const char* nameTask, Task_Category category, const char* deadline, const char* executor, int flag) {
		setName(nameTask);
		this->category = category;
		setDeadline(deadline);
		setExecutor(executor);
	}


	//��������� �����

	void setName(const char* name) {
		if (name == nullptr) {
			throw "������� ��������� � �������� ���������";
		}

		int sizeName = strlen(name);
		if (!sizeName) {
			throw "������ �� ����� ���� ������";
		}

		if (nameTask != nullptr) {
			delete nameTask;
			nameTask = nullptr;
		}
		nameTask = new char[sizeName + 1];
		memset(nameTask, 0, sizeof(char) * (sizeName + 1));
		strcpy(nameTask, name);

	}

	//��������� ����� �����

	void setDeadline(const char* date) {
		if (date == nullptr) {
			throw "������� ��������� � �������� ���������";
		}

		int sizeDeadline = strlen(date);
		if (!sizeDeadline) {
			throw "������ �� ����� ���� ������";
		}

		if (date != nullptr) {
			delete deadline;
			deadline = nullptr;
		}
		deadline = new char[sizeDeadline + 1];
		memset(deadline, 0, sizeof(char) * (sizeDeadline + 1));
		strcpy(deadline, date);

	}

	//��������� �����

	void setComplited(bool flag) {
		this->flag = flag;

	}

	//��������� �������

	void setTimeForTaskGrade(typeTime timeForTaskGrade) {
		if (timeForTaskGrade <= 0) {
			throw "������������ ������� �������";
		}
		this->timeForTaskGrade = timeForTaskGrade;
	}

	//��������� �����������

	void setExecutor(const char* nameExecutor) {
		if (nameExecutor == nullptr) {
			throw "������� ��������� � �������� ���������";
		}

		int sizeExecutor = strlen(nameExecutor);
		if (!sizeExecutor) {
			throw "������ �� ����� ���� ������";
		}

		if (executor != nullptr) {
			delete executor;
			executor = nullptr;
		}
		executor = new char[sizeExecutor + 1];
		memset(executor, 0, sizeof(char) * (sizeExecutor + 1));
		strcpy(executor, nameExecutor);

	}

	//����� �������� ������� ���������� ������

	bool pointOverdueTask() const {
		if (timeForTaskReal > timeForTaskGrade) {
			return false;
		}
		else {
			return true;
		}
	}

	//��������� �������� � �������������� ������

	int getPointOverdueTask() const {
		return timeForTaskReal - timeForTaskGrade;
	}


	//����� ���������� �������

	void addTime(typeTime time) {
		if (time <= 0) {
			throw "�������� �������� �������";
		}
		else {
			timeForTaskReal = timeForTaskGrade + time;
		}

	}

	//��������� �������� �����  

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

	//��������� ���� �����

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

	//��������� ����� �����������

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

	//��������� ����� ���������� ������

	const char* getFlag() const {
		if (flag) {
			return "������ �������";
		}
		else {
			return "������ �������";
		}
	}

	//��������� ����������� �� ������ �������

	typeTime getTimeForTaskGrade() const {
		return timeForTaskGrade;
	}

	//��������� ���� ������

	const char* getCategory() const {
		switch (category) {
		case(ERROR): { return "������"; };
		case(SUPPORT): {return "���������"; };
		case(NEW): {return "����� ������"; };
		}
	}

	//��������� �������, ������������ �� ������

	typeTime getTimeForTaskReal() const {
		return timeForTaskReal;
	}

	virtual int operator+=(int time) override {
		timeForTaskReal = time + timeForTaskGrade;
		return timeForTaskReal;
	}

	//����� ������ ���������� � ������ �� ��������

	virtual void showCout() const override{
		cout << endl << "������ '" << getNameTask() << "':" << endl <<
			"��� ������: " << getCategory() << endl <<
			"����������� ������: " << getExecutor() << endl <<
			"������: " << getFlag() << endl <<
			"���� ����� ������: " << getDeadline() << endl <<
			"�� ������ �������� " << getTimeForTaskGrade() << endl;
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

