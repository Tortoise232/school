#ifndef SOLUTION_H
#define SOLUTION_H

#include <QtWidgets/QMainWindow>
#include "ui_solution.h"

class Solution : public QMainWindow
{
	Q_OBJECT

public:
	Solution(QWidget *parent = 0);
	~Solution();

private:
	Ui::SolutionClass ui;
};

#endif // SOLUTION_H
