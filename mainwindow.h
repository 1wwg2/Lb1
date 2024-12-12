#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "enterdata.h"
#include "results.h"
#include "panel.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    EnterData* EnterDataWidget = nullptr;
    QStackedWidget* StackedWidget = nullptr;
    Results* Answ = nullptr;
    Panel* panel = nullptr;
private slots:
    void SelectCollectData();
    void SelectDrawTables();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
