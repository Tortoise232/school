#include "presenter.h"



void presenter::initGUI()
{
	this->setWindowTitle("~Presenter~");
	QWidget* someObj = new QWidget;
	QFormLayout* mainLay = new QFormLayout{ someObj };
	QLabel* idL = new QLabel{ "ID:" };
	QLabel* textL = new QLabel{ "Text:" };
	QLabel* answerL = new QLabel{ "Answer" };
	QLabel* scoreL = new QLabel{ "Score:" };
	this->idQ = new QLineEdit;
	this->textQ = new QLineEdit;
	this->answerQ = new QLineEdit;
	this->scoreQ = new QLineEdit;
	this->add = new QPushButton{ "Add" };
	this->remove = new QPushButton{ "Remove" };
	mainLay->addRow(idL, idQ);
	mainLay->addRow(textL, textQ);
	mainLay->addRow(answerL, answerQ);
	mainLay->addRow(scoreL, scoreQ);
	mainLay->addRow(add, remove);
	this->list = new QListWidget();
	QGridLayout* sykeLay = new QGridLayout{ this };
	sykeLay->addWidget(someObj,0,0);
	sykeLay->addWidget(list, 0, 1);

}

void presenter::populateList()
{
	this->list->clear();
	std::vector<std::string> vectorQ;
	for (auto ct : this->ctrl.getQuestions())
	{
		vectorQ.push_back(ct.toString());
	}
	while (vectorQ.size() > 0)
	{
		int min = 9999, check;
		for (auto it = vectorQ.begin();it != vectorQ.end(); it++)
		{
			std::size_t aux = it->find(",");
			check = atoi(it->substr(0, aux).c_str());
			if (check < min)
				min = check;
		}
		for (auto it = vectorQ.begin();it != vectorQ.end(); it++)
		{
			std::size_t aux = it->find(",");
			check = atoi(it->substr(0, aux).c_str());
			if (check == min)
			{
				this->list->addItem(QString::fromStdString(*it));
				vectorQ.erase(it);
				break;
			}
		}
	}
}

void presenter::connectSignalSlots()
{
	QObject::connect(this->add, SIGNAL(clicked()), this, SLOT(addHandler()));
	QObject::connect(this->remove, SIGNAL(clicked()), this, SLOT(removeHandler()));
	QObject::connect(this, SIGNAL(change()), this, SLOT(populateList()));
	QObject::connect(this, SIGNAL(close()), this, SLOT(save()));
	QObject::connect(this, SIGNAL(change()), this, SLOT(save()));

}
void presenter::save()
{
	this->ctrl.save();
}
void presenter::addHandler()
{
	int id = this->idQ->text().toInt();
	int score = this->scoreQ->text().toInt();
	std::string name = this->textQ->text().toStdString();
	std::string answer = this->answerQ->text().toStdString();
	try {
		this->ctrl.addQuestion(id, score, name, answer);
	}
	catch (QuestionException e)
	{
		errorGUI* error = new errorGUI(e.what());
		error->show();
	}
	emit(change());
}

void presenter::removeHandler()
{
	std::string question = this->list->selectedItems()[0]->text().toStdString();
	Question theQ = this->ctrl.CSVtoQuestion(question);
	try {
		this->ctrl.removeQuestion(theQ.getID());
	}
	catch (QuestionException e)
	{
		errorGUI* error = new errorGUI(e.what());
		error->show();
	}
	emit(change());
}