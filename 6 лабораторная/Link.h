#pragma once

#include "Itask.h"
#include "Task.h"


class Link :public Task {
	char* linkTask = nullptr;

public:
	//конструктор
	Link(const char* name, Task_Category category, const char* deadline, const char* linkTask);

	//установка ссылки
	void setLink(const char* link);

	//получение ссылки
	const char* getLink() const;

	//вывод
	virtual void showCout()const override;

	virtual ~Link();
};
