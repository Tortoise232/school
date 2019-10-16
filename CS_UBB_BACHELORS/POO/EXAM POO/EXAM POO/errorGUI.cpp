#include "errorGUI.h"



void errorGUI::initGUI()
{
	this->setWindowTitle("~BAD ERROR POPUP~");
	QFormLayout* main = new QFormLayout{ this };
	QLabel* errorMsg = new QLabel{ this->text.c_str() };
	main->addWidget(errorMsg);
	
}