#ifndef RESULTS_H
#define RESULTS_H

#include <QWidget>
#include <QComboBox>
#include <QTextEdit>

class Results : public QWidget
{
    Q_OBJECT

public:
    explicit Results(QWidget* parent = nullptr);

private slots:
    void onSelectionChanged(int index);

private:
    QComboBox* comboBox;
    QTextEdit* textEdit;

    void loadTableFromFile(const QString& fileName);
};

#endif // RESULTS_H
