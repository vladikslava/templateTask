
#include "Task.h"

//����������� � �����������

Task::Task(const char* nameTask, Task_Category category, const char* deadline) {
	setName(nameTask);
	this->category = category;
	setDeadline(deadline);
}

//������������� ����������� 

Task::Task(const char* nameTask, Task_Category category, const char* deadline, const char* executor, int flag) {
	setName(nameTask);
	this->category = category;
	setDeadline(deadline);
	setExecutor(executor);
}


//��������� �����

void Task::setName(const char* name) {
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

void Task::setDeadline(const char* date) {
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

void Task::setComplited(bool flag) {
	this->flag = flag;

}

//��������� �������

void Task::setTimeForTaskGrade(int timeForTaskGrade) {
	if (timeForTaskGrade <= 0) {
		throw "������������ ������� �������";
	}
	this->timeForTaskGrade = timeForTaskGrade;
}

//��������� �����������

void Task::setExecutor(const char* nameExecutor) {
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

bool Task::pointOverdueTask() const {
	if (timeForTaskReal > timeForTaskGrade) {
		return false;
	}
	else {
		return true;
	}
}

//��������� �������� � �������������� ������

int Task::getPointOverdueTask() const {
	return timeForTaskReal - timeForTaskGrade;
}


//����� ���������� �������

void Task::addTime(int time) {
	if (time <= 0) {
		throw "�������� �������� �������";
	}
	else {
		timeForTaskReal = timeForTaskGrade + time;
	}

}

//��������� �������� �����  

char* Task::getNameTask() const {
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

char* Task::getDeadline() const {
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

char* Task::getExecutor() const {
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

const char* Task::getFlag() const {
	if (flag) {
		return "������ �������";
	}
	else {
		return "������ �������";
	}
}

//��������� ����������� �� ������ �������

int Task::getTimeForTaskGrade() const {
	return timeForTaskGrade;
}

//��������� ���� ������

const char* Task::getCategory() const {
	switch (category) {
	case(ERROR): { return "������"; };
	case(SUPPORT): {return "���������"; };
	case(NEW): {return "����� ������"; };
	}
}

//��������� �������, ������������ �� ������

int Task::getTimeForTaskReal() const {
	return timeForTaskReal;
}

int Task:: operator+=(int time) {
	timeForTaskReal = time + timeForTaskGrade;
	return timeForTaskReal;
}


//����� ������ ���������� � ������ �� ��������

void Task::showCout() const {
	cout << endl << "������ '" << getNameTask() << "':" << endl <<
		"��� ������: " << getCategory() << endl <<
		"����������� ������: " << getExecutor() << endl <<
		"������: " << getFlag() << endl <<
		"���� ����� ������: " << getDeadline() << endl <<
		"�� ������ �������� " << getTimeForTaskGrade() << endl;
}

Task::~Task() {
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

ostream& operator << (ostream& out, const Task* task) {
	out << "������ '" << task->getNameTask() << "':" << endl;
	out << "��� ������: " << task->getCategory() << endl;
	out << "����������� ������: " << task->getExecutor() << endl;
	out << "������: " << task->getFlag() << endl;
	out << "���� ����� ������: " << task->getDeadline() << endl;
	out << "�� ������ �������� " << task->getTimeForTaskGrade() << " �����." << endl;
	//" �����, ���� ��������� �� " << task->getTimeForTaskReal() << endl;

	return out;

}

double& operator+=(double& sum, const Task& task) {

	return sum += task.getTimeForTaskReal();

}

