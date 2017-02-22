/*
void GenesGUI::initGUI()
{
	//General layout of the window
	QHBoxLayout* layout = new QHBoxLayout{ this };

	// left side - just the list
	this->genesList = new QListWidget{};
	// set the selection model
	this->genesList->setSelectionMode(QAbstractItemView::SingleSelection);
	layout->addWidget(this->genesList);

	// right side - gene information + buttons
	QWidget* rightSide = new QWidget{};
	QVBoxLayout* vLayout = new QVBoxLayout{ rightSide };

	// gene information
	QWidget* geneDataWidget = new QWidget{};
	QFormLayout* formLayout = new QFormLayout{ geneDataWidget };
	this->organismEdit = new QLineEdit{};
	this->geneNameEdit = new QLineEdit{};
	this->sequenceEdit = new QTextEdit{};
	formLayout->addRow("&Organism name:", this->organismEdit);
	formLayout->addRow("&Gene name:", this->geneNameEdit);
	formLayout->addRow("&Sequence:", this->sequenceEdit);

	vLayout->addWidget(geneDataWidget);

	// buttons
	QWidget* buttonsWidget = new QWidget{};
	QHBoxLayout* hLayout = new QHBoxLayout{ buttonsWidget };
	this->addGeneButton = new QPushButton("Add Gene");
	this->deleteGeneButton = new QPushButton("Delete Gene");
	hLayout->addWidget(this->addGeneButton);
	hLayout->addWidget(this->deleteGeneButton);

	vLayout->addWidget(buttonsWidget);

	// add everything to the big layout
	layout->addWidget(this->genesList);
	layout->addWidget(rightSide);
}
*/