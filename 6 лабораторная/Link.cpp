#include "Link.h"

Link::Link(const char* nameTask, Task_Category category, const char* deadline, const char* linkTask) : Task(nameTask, category, deadline) {
	setLink(linkTask);
}

void Link::setLink(const char* link) {
	if (link == nullptr) {
		throw "������� ��������� � �������� ���������";
	}

	int sizeLink = strlen(link);
	if (!sizeLink) {
		throw "������ �� ����� ���� ������";
	}

	if (linkTask != nullptr) {
		delete linkTask;
		linkTask = nullptr;
	}
	linkTask = new char[sizeLink + 1];
	memset(linkTask, 0, sizeof(char) * (sizeLink + 1));
	strcpy(linkTask, link);
}

const char* Link::getLink() const {
	return linkTask;
}



//����� ������

void Link::showCout() const {
	cout << endl << "������ '" << getNameTask() << "':" << endl <<
		"��� ������: " << getCategory() << endl <<
		"����������� ������: " << getExecutor() << endl <<
		"������: " << getFlag() << endl <<
		"���� ����� ������: " << getDeadline() << endl <<
		"�� ������ �������� " << getTimeForTaskGrade() << endl;

	cout << "��� ������ '" << nameTask << "':" << endl
		<< "������ �� ������:" << getLink() << endl;
}

Link::~Link() {
	if (linkTask != nullptr) {
		delete linkTask;
		linkTask = nullptr;
	}
}
