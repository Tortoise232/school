
#pragma once

#include "exampoo.h"
	class errorGUI : public QWidget
	{
		Q_OBJECT
	private:
		std::string text;
	public:
		errorGUI(std::string ErrorText)
		{
			this->text = ErrorText;
			this->initGUI();
		};
		void initGUI();
		void connectSignalSlots();
	
		~errorGUI() {};
};

