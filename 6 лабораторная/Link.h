#pragma once

#include "Itask.h"
#include "Task.h"


class Link :public Task {
	char* linkTask = nullptr;

public:
	//�����������
	Link(const char* name, Task_Category category, const char* deadline, const char* linkTask);

	//��������� ������
	void setLink(const char* link);

	//��������� ������
	const char* getLink() const;

	//�����
	virtual void showCout()const override;

	virtual ~Link();
};
