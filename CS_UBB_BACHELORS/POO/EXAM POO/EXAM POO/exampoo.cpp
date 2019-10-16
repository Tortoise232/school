#include "exampoo.h"

void EXAMPOO::connectSignalSlots()
{
	//QObject::connect(this->answer, SIGNAL(clicked()), this, SLOT(close()));
	QObject::connect(this->answer, SIGNAL(clicked()), this, SLOT(answerHandler()));
	QObject::connect(this,SIGNAL(change()), this, SLOT(populateList()));

}

void EXAMPOO::populateList()
{
	this->list->clear();
	std::vector<std::string> vectorQ;
	for (auto ct : this->ctrl.getQuestions())
	{
		vectorQ.push_back(ct.toStringPart());
	}
	while (vectorQ.size() > 0)
	{
		int max = 0,check;
		for (auto it = vectorQ.begin();it != vectorQ.end(); it++)
		{
			std::size_t aux = it->find(",");
			check = atoi(it->substr(0, aux).c_str());
			if (check > max)
				max = check;	
		}
		for (auto it = vectorQ.begin();it != vectorQ.end(); it++)
		{
			std::size_t aux = it->find(",");
			check = atoi(it->substr(0, aux).c_str());
			if (check == max)
			{
				this->list->addItem(QString::fromStdString(*it));
				vectorQ.erase(it);
				break;
			}
		}
	}
	char scor[10];
	itoa(this->me.getScore(), scor, 10);
	std::string scorStd = scor;
	this->score->setText(QString::fromStdString(scorStd));
}

void EXAMPOO::initGUI()
{
	QFormLayout* mainLay = new QFormLayout{ this };
	this->list = new QListWidget();
	this->list->setSelectionMode(QAbstractItemView::SingleSelection);
	this->answer = new QPushButton("Answer!");
	this->score = new QLineEdit();
	QLabel* scoreLabel = new QLabel("Your score:");
	QLabel* answerLabel = new QLabel("Your answer:");
	scoreLabel->setBuddy(this->score);
	this->text = new QLineEdit();
	answerLabel->setBuddy(this->text);
	mainLay->addWidget(this->list);
	mainLay->addRow(answerLabel, this->text);
	mainLay->addRow(scoreLabel, this->score);
	mainLay->addWidget(this->answer);
}

void EXAMPOO::answerHandler()
{
	std::string question = this->list->selectedItems()[0]->text().toStdString();
	std::size_t aux = question.find(",");
	question = question.substr(aux + 1, question.size());
	aux = question.find(",");
	int id = atoi(question.substr(aux + 1, question.size()).c_str());
	Question actQ = this->ctrl.getRepo().findQuestion(id);
	std::string answer = this->text->text().toStdString();
	if (answer == actQ.getAnswer())
	{
		this->me.setScore(this->me.getScore() + actQ.getScore());
	}
	emit(change());
}