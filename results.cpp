#include <QWidget>
#include <QComboBox>
#include <QTextEdit>
#include <QFile>
#include <QTextStream>
#include <QVBoxLayout>

class Results : public QWidget
{
    Q_OBJECT

public:
    Results(QWidget* parent = nullptr);

private slots:
    void onSelectionChanged(int index);

private:
    QComboBox* comboBox;
    QTextEdit* textEdit;

    void loadTableFromFile(const QString& fileName);
};

Results::Results(QWidget* parent) : QWidget(parent)
{
    comboBox = new QComboBox(this);
    textEdit = new QTextEdit(this);

    comboBox->addItem("Початкова таблиця остаточних результатів");
    comboBox->addItem("Інтенсивність відмов і збоїв");
    comboBox->addItem("Середні напрацювання до відмови і збою ");
    comboBox->addItem("Напрацювання до відмови");
    comboBox->addItem("Ймовірності безпомилкової, безвідмовної і беззбійної роботи і ПК");
    comboBox->addItem("Ймовірності помилкової роботи ");
    comboBox->addItem("Ймовірності безвідмовного зберігання");
    comboBox->addItem("Ймовірності відмови при зберіганні");
    comboBox->addItem("Ймовірності безвідмовної роботи і відмови апаратних засобів і ПК в цілому з урахуванням умов експлуатації ");
    comboBox->addItem("Ймовірності помилкової роботи в цілому з урахуванням умов експлуатації");
    comboBox->addItem("Ймовірності безвідмовної роботи і відмови апаратних засобів і ПК при циклічному функціонуванні  ");
    comboBox->addItem("Ймовірності помилкової роботи при циклічному функціонуванні");


    connect(comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onSelectionChanged(int)));
    if(comboBox->currentIndex() == 0)
    {
        loadTableFromFile("/home/vitaliy/Cpp/Lb1/Results/Початкова таблиця остаточних результатів.txt");
    }

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(comboBox);
    layout->addWidget(textEdit);
    setLayout(layout);
}

void Results::onSelectionChanged(int index)
{
    QString PATH = "/home/vitaliy/Cpp/Lb1/Results/";
    QString fileName;
    for(int i = 0; i < 16; ++i)
    {
        if(index == i)
        {
            fileName = PATH + comboBox->itemText(i) + ".txt";
        }
    }

    loadTableFromFile(fileName);
}

void Results::loadTableFromFile(const QString& fileName)
{
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        textEdit->clear();
        textEdit->setText(in.readAll());
        file.close();
    } else {
        textEdit->setText("Не удалось открыть файл.");
    }
}
