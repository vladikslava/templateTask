#include "Link.h"

Link::Link(const char* nameTask, Task_Category category, const char* deadline, const char* linkTask) : Task(nameTask, category, deadline) {
	setLink(linkTask);
}

void Link::setLink(const char* link) {
	if (link == nullptr) {
		throw "Нулевой указатель в качестве аргумента";
	}

	int sizeLink = strlen(link);
	if (!sizeLink) {
		throw "Строка не может быть пустой";
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



//вывод ссылки

void Link::showCout() const {
	cout << endl << "Задача '" << getNameTask() << "':" << endl <<
		"Тип задачи: " << getCategory() << endl <<
		"Исполнитель задачи: " << getExecutor() << endl <<
		"Статус: " << getFlag() << endl <<
		"Срок сдачи задачи: " << getDeadline() << endl <<
		"На задачу отведено " << getTimeForTaskGrade() << endl;

	cout << "для задачи '" << nameTask << "':" << endl
		<< "Ссылка на задачу:" << getLink() << endl;
}

Link::~Link() {
	if (linkTask != nullptr) {
		delete linkTask;
		linkTask = nullptr;
	}
}
