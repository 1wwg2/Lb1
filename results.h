#ifndef RESULTS_H
#define RESULTS_H

#include <QWidget>
#include <QLabel>

class Results : public QWidget
{
    Q_OBJECT
private:
    QLabel* label = nullptr;
public:
    Results(QWidget* parent = nullptr);
};

#endif // RESULTS_H
