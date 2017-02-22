#include "gui.h"

GUI::GUI(QWidget *parent)
	: QWidget(parent)
{
	//ui.setupUi(this);
	this->initGUI();
	this->populateList();
	this->connectSignalSlots();
}

GUI::~GUI()
{

}

void GUI::initGUI()
{
	
	QGridLayout* mainLayout = new QGridLayout{ this };
	this->setLayout(mainLayout);
	QLabel*  taskLabel = new QLabel{ "All tasks:" };
	this->taskList = new QListWidget{};
	this->taskList->setSelectionMode(QAbstractItemView::SingleSelection);
	this->descEdit = new QLineEdit{};
	QLabel*  descLabel = new QLabel{ "Description:" };
	descLabel->setBuddy(this->descEdit);

	this->durEdit = new QLineEdit{};
	QLabel*  durLabel = new QLabel{ "Duration:" };
	durLabel->setBuddy(this->durEdit);

	this->priEdit = new QLineEdit{};
	QLabel*  priLabel = new QLabel{ "Priority:" };
	priLabel->setBuddy(this->priEdit);
	QWidget *firstSide = new QWidget;
	QFormLayout *layout1 = new QFormLayout{ firstSide };
	firstSide->setLayout(layout1);
	layout1->addRow(taskLabel);
	layout1->addRow(this->taskList);
	layout1->addRow(descLabel, this->descEdit);
	layout1->addRow(durLabel, this->durEdit);
	layout1->addRow(priLabel, this->priEdit);


	this->sortButton = new QPushButton{ "Sort" };
	this->filterButton = new QPushButton{ "Filter" };
	QWidget* crudWidget = new QWidget;
	QGridLayout* crudLayout = new QGridLayout{ crudWidget };
	crudLayout->addWidget(this->sortButton, 0, 0);
	crudLayout->addWidget(this->filterButton, 1, 0);
	mainLayout->addWidget(firstSide, 0, 0);
	mainLayout->addWidget(crudWidget, 0, 1);
	
}

void GUI::connectSignalSlots() 
{
	QObject::connect(this->sortButton, SIGNAL(clicked()), this, SLOT(sortButtonHandler()));
	QObject::connect(this->filterButton, SIGNAL(clicked()), this, SLOT(filterButtonHandler()));
	QObject::connect(this, SIGNAL(listchange()), this, SLOT(populateList()));
}

void GUI::populateList() {
	if (this-taskList->count() > 0)
		this->taskList->clear();
	
	for (auto task : this->controler->getVector())
	{
		QString taskString = QString::fromStdString(task.toString());
		this->taskList->addItem(taskString);
	}
		this->taskList->setCurrentRow(0);
};

void GUI::filterButtonHandler()
{
	int aux;
	if (this->taskList->count() > 0)
		this->taskList->clear();
	QString priority = this->priEdit->text();
	aux = priority.toInt();
	aux = this->controler->totalDur(priority.toInt());
	char aux2[10];
	itoa(aux, aux2, 10);
	std::string aux3 = aux2;
	this->priEdit->setText(QString::fromStdString(aux3));
}

void GUI::sortButtonHandler()
{
	this->controler->sortByDuration();
	emit listchange();
}
