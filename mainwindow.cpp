#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    panel = new Panel(this);
    addToolBar(panel);
    EnterDataWidget = new EnterData(this);
    StackedWidget = new QStackedWidget(this);
    Answ = new  Results(this);
    StackedWidget->addWidget(EnterDataWidget);
    StackedWidget->addWidget(Answ);

    StackedWidget->setCurrentIndex(0);
    setCentralWidget(StackedWidget);

    connect(panel->GetCollectData(), &QAction::triggered, this, &MainWindow::SelectCollectData);
    connect(panel->GetDrawTables(), &QAction::triggered, this, &MainWindow::SelectDrawTables);
}

MainWindow::~MainWindow() {}



void MainWindow::SelectCollectData()
{
    StackedWidget->setCurrentIndex(0);
}

void MainWindow::SelectDrawTables()
{
    StackedWidget->setCurrentIndex(1);
}
