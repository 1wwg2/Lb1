#include <QPushButton>
#include <QWidget>
#include <QStringList>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QMessageBox>
#include <QMap>
#include <QString>

class EnterData : public QWidget
{
    Q_OBJECT
private:
    QPushButton* SendInfo = nullptr;
    QLabel* titleLabels[6];
    QLabel* headers[16];
    QLineEdit* inputs[16];
    double DataFromFields[16];
    QStringList headerNames = {"λМНАВ", "λПРАВ", "λПМАВ", "λБЖАВ",
                               "α", "β×10", "t×10^4",
                               "κтем", "κвиб", "κпер",
                               "t×10^4", "G×10^2",
                               "t×10^4", "r",
                               "γ", "∆t×10^3"};

    QVector<int> TIMER; // для подальших таблиць

    void BuildFields();


private slots:
    void GetDataFromFields();

public:
    void MakeFinalData(); // Данные с таблички переделанные
    void MakeFailureRate(); // таблиця Інтенсивність відмов і збоїв
    void AvgWorkinghFailure(); // таблиця Середні напрацювання до відмови і збою
    void WorkToFailure(); // таблиця Напрацювання до відмови
    void CalculateErrorFreeWork();  //таблиця Ймовірності безпомилкової, безвідмовної і беззбійної роботи і ПК
    void CalculateWorkErrorProb(); // таблиця ймовірності помилкової роботи
    void CalculateReliabilityStorage(); // таблиця Ймовірності безвідмовного зберігання 3
    void CalculateFailureProbabilities(); // таблиця Ймовірності відмови при зберіганні 4
    void CalculateReliabilityStorage(); // таблиця Ймовірності відмови при зберіганні 5
    void CalculateReliabilityStorage(); // таблиця Ймовірності помилкової роботи в цілому з урахуванням умов експлуатації 6
    void CalculateCyclicReliabilityProbabilities(); // таблиця Ймовірності безвідмовної роботи і відмови апаратних засобів і ПК при циклічному функціонуванні 7
    void CalculateCyclicFailureProbabilities(); // таблиця Ймовірності помилкової роботи при циклічному функціонуванні 8


    EnterData(QWidget* parent = nullptr);
};
