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
#include <cmath>
#include <QFile>
#include <QTextStream>

class EnterData : public QWidget
{
    Q_OBJECT
private:
    QString PATH = "/home/vitaliy/Cpp/Lb1/Results";
    QPushButton* SendInfo = nullptr;
    QLabel* titleLabels[6];
    QLabel* headers[16];
    QLineEdit* inputs[16];
    double DataFromFields[16];
    QStringList headerNamesGUI = {"λМНАВ", "λПРАВ", "λПМАВ", "λБЖАВ",
                               "α", "β×10", "t×10^4",
                               "κтем", "κвиб", "κпер",
                               "t×10^4", "G×10^2",
                               "t×10^4", "r",
                               "γ", "∆t×10^3"};

    QVector<int> TIMER; // для подальших таблиць
    // 1 table
    QMap<QString, double> FinalInputData;
    //2 table
    QMap<QString, double> MapMakeFailureRate1;
    QMap<QString, double> MapMakeFailureRate2;
    QMap<QString, double> MapMakeFailureRate3;
    QMap<QString, double> MapMakeFailureRate4;
    //3table
    QMap<QString, double> MapAvgWorkinghFailure[4];
    //4 table
    double _worktofailure;
    // 5 table
    QMap<QString, QVector<double>> ErrorFreeWork;
    // 6 table
    QMap<QString, QVector<double>> ErrorProbabilities;
    // 7 table
    QMap<QString, QVector<double>> ReliabilityStorage;
    // 8 table
    QMap<QString, QVector<double>> FailureReliabilityStorage;
    // 9 table
    QMap<QString, QVector<double>> GeneralErrorFreeWork;
    // 11 table
    QMap<QString, QVector<double>> FailureGeneralWork;
    // 12 table
    QMap<QString, QVector<double>> CyclicReliabilityProbabilities;
    // 13 table
    QMap<QString, QVector<double>> CyclicFailureProbabilities;


    void BuildFields();


private slots:
    void GetDataFromFields();

public:
    void MakeFinalData(); // Данные с таблички переделанные +
    void MakeFailureRate(); // таблиця Інтенсивність відмов і збоїв +
    void AvgWorkinghFailure(); // таблиця Середні напрацювання до відмови і збою +
    void WorkToFailure(); // таблиця Напрацювання до відмови +
    void SetTimer();
    void CalculateErrorFreeWork();  //таблиця Ймовірності безпомилкової, безвідмовної і беззбійної роботи і ПК
    void CalculateWorkErrorProb(); // таблиця ймовірності помилкової роботи
    void CalculateReliabilityStorage(); // таблиця Ймовірності безвідмовного зберігання 3
    void CalculateFailureProbabilities(); // таблиця Ймовірності відмови при зберіганні 4
    void CalculateFailureReliabilityStorage(); // таблиця Ймовірності відмови при зберіганні 5
    void CalculateGeneralErrorFreeWork();
    void CalculateFailureGeneralWork();// таблиця Ймовірності помилкової роботи в цілому з урахуванням умов експлуатації 6
    void CalculateCyclicReliabilityProbabilities(); // таблиця Ймовірності безвідмовної роботи і відмови апаратних засобів і ПК при циклічному функціонуванні 7
    void CalculateCyclicFailureProbabilities(); // таблиця Ймовірності помилкової роботи при циклічному функціонуванні 8


    EnterData(QWidget* parent = nullptr);
};
