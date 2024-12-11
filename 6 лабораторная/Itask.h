#pragma once

//интерфейс для вывода инфы и для оператора += для добавления времени выполнения
class Itask {
public:
	virtual void showCout() const = 0;
	virtual int operator+=(int count) = 0;
	virtual ~Itask() {};
};
