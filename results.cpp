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
    // Создаем виджеты
    comboBox = new QComboBox(this);
    textEdit = new QTextEdit(this);

    // Добавляем элементы в выпадающий список
    comboBox->addItem("Таблица 1");
    comboBox->addItem("Таблица 2");

    // Подключаем слот на изменение выбора
    connect(comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onSelectionChanged(int)));

    // Располагаем элементы в вертикальном лейауте
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(comboBox);
    layout->addWidget(textEdit);
    setLayout(layout);
}

void Results::onSelectionChanged(int index)
{
    QString fileName;
    if (index == 0) {
        fileName = "/home/vitaliy/Cpp/Lb1/build/Desktop_Qt_6_7_3-Debug/Ta.txt";  // Замените на путь к файлу для первой таблицы
    } else if (index == 1) {
        fileName = "table2.txt";  // Замените на путь ко второй таблице
    }

    loadTableFromFile(fileName);
}

void Results::loadTableFromFile(const QString& fileName)
{
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        textEdit->clear();
        textEdit->setText(in.readAll());  // Загружаем содержимое файла в QTextEdit
        file.close();
    } else {
        textEdit->setText("Не удалось открыть файл.");
    }
}
