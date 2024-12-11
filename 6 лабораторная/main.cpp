#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale>
#include <cstring>

#include "Task.h"
#include "Link.h"
#include "Itask.h"
#include "TemplateTask.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	

	TemplateTask<int> templateTaskFirst("Отчет", TemplateTask<int>::NEW, "12 декабря", 4);
	templateTaskFirst.setExecutor("Петров.Е.А.");
	templateTaskFirst.setComplited(0);
	templateTaskFirst.showCout();

	TemplateTask<double> templateTaskSecond("Отчет", TemplateTask<double>::ERROR, "15 февраля", 7.8);
	templateTaskSecond.setExecutor("Петров.Е.А.");
	templateTaskSecond.setComplited(1);
	templateTaskSecond.showCout();
	
}
