#include "enterdata.h"
#include <QQueue>

EnterData::EnterData(QWidget* parent) : QWidget(parent)
{
    SendInfo = new QPushButton("Start calculation", this);
    BuildFields();

    connect(SendInfo, &QPushButton::clicked, this, &EnterData::GetDataFromFields);
}

void EnterData::GetDataFromFields()
{
    inputs[0]->setText("2.6");
    inputs[1]->setText("1.6");
    inputs[2]->setText("2.2");
    inputs[3]->setText("0.9");
    inputs[4]->setText("3");
    inputs[5]->setText("8");
    inputs[6]->setText("1.2");
    inputs[7]->setText("1.8");
    inputs[8]->setText("1.6");
    inputs[9]->setText("1.4");
    inputs[10]->setText("1.2");
    inputs[11]->setText("1.4");
    inputs[12]->setText("1.2");
    inputs[13]->setText("0.7");
    inputs[14]->setText("75");
    inputs[15]->setText("1");






    for(int i = 0; i < 16; ++i)
    {

        //if(inputs[i]->text().isEmpty())
        //{
          //
            //QMessageBox::critical(this, "Error", "Please, write all number in field");
            //break;
      //  }
        //else
      //  {
            bool IsDouble = true;
            double value = inputs[i]->text().toDouble(&IsDouble);
            if (!IsDouble)
            {
                QMessageBox::critical(this, "Error", "Please, write all double in field");
                break;
            }
            else
            {
                DataFromFields[i] = inputs[i]->text().toDouble();
            }
        //}
    }


    /*        QStringList headerNames = {"λМНАВ", "λПРАВ", "λПМАВ", "λБЖАВ",
                               "α", "β×10", "t×10^4",
                               "κтем", "κвиб", "κпер",
                               "t×10^4", "G×10^2",
                               "t×10^4", "r",
                               "γ", "∆t×10^3"};;
0 1 2 3 5 6 10 13*/

    MakeFinalData();
    MakeFailureRate();

}

void EnterData::BuildFields()
{
    QHBoxLayout* mainLayout = new QHBoxLayout(this);

    QHBoxLayout* LayoutFieldFirst = new QHBoxLayout();
    QHBoxLayout* LayoutFieldIntputFirst = new QHBoxLayout();
    QVBoxLayout* VLayoutFirstGroup = new QVBoxLayout();

    QLabel* titleLabel1 = new QLabel("Інтенсивність відмов ∆З×10^−8", this);
    titleLabel1->setAlignment(Qt::AlignCenter);
    VLayoutFirstGroup->addWidget(titleLabel1);
    for(int i = 0; i <= 3; ++i)
    {
        QLabel* label = new QLabel(headerNamesGUI.at(i), this);
        label->setAlignment(Qt::AlignCenter);
        LayoutFieldFirst->addWidget(label);
        inputs[i] = new QLineEdit(this);
        LayoutFieldIntputFirst->addWidget(inputs[i]);
    }
    VLayoutFirstGroup->addLayout(LayoutFieldFirst);
    VLayoutFirstGroup->addLayout(LayoutFieldIntputFirst);

    QHBoxLayout* LayoutFieldSecond = new QHBoxLayout();
    QHBoxLayout* LayoutFieldIntputSecond = new QHBoxLayout();
    QVBoxLayout* VLayoutSecondGroup = new QVBoxLayout();

    for(int i = 4; i <= 6; ++i)
    {
        QLabel* label = new QLabel(headerNamesGUI.at(i), this);
        label->setAlignment(Qt::AlignCenter);
        LayoutFieldSecond->addWidget(label);
        inputs[i] = new QLineEdit(this);
        LayoutFieldIntputSecond->addWidget(inputs[i]);
    }
    VLayoutSecondGroup->addLayout(LayoutFieldSecond);
    VLayoutSecondGroup->addLayout(LayoutFieldIntputSecond);

    QHBoxLayout* LayoutFieldThird = new QHBoxLayout();
    QHBoxLayout* LayoutFieldIntputThird = new QHBoxLayout();
    QVBoxLayout* VLayoutThirdGroup = new QVBoxLayout();

    QLabel* titleLabel2 = new QLabel("Умови експлуатації", this);
    titleLabel2->setAlignment(Qt::AlignCenter);
    VLayoutThirdGroup->addWidget(titleLabel2);

    for(int i = 7; i <= 9; ++i)
    {
        QLabel* label = new QLabel(headerNamesGUI.at(i), this);
        label->setAlignment(Qt::AlignCenter);
        LayoutFieldThird->addWidget(label);
        inputs[i] = new QLineEdit(this);
        LayoutFieldIntputThird->addWidget(inputs[i]);
    }
    VLayoutThirdGroup->addLayout(LayoutFieldThird);
    VLayoutThirdGroup->addLayout(LayoutFieldIntputThird);

    QHBoxLayout* LayoutFieldFour = new QHBoxLayout();
    QHBoxLayout* LayoutFieldIntputFour = new QHBoxLayout();
    QVBoxLayout* VLayoutFourGroup = new QVBoxLayout();

    QLabel* titleLabel3 = new QLabel("Зберігання", this);
    titleLabel3->setAlignment(Qt::AlignCenter);
    VLayoutFourGroup->addWidget(titleLabel3);

    for(int i = 10; i <= 11; ++i)
    {
        QLabel* label = new QLabel(headerNamesGUI.at(i), this);
        label->setAlignment(Qt::AlignCenter);
        LayoutFieldFour->addWidget(label);
        inputs[i] = new QLineEdit(this);
        LayoutFieldIntputFour->addWidget(inputs[i]);
    }

    VLayoutFourGroup->addLayout(LayoutFieldFour);
    VLayoutFourGroup->addLayout(LayoutFieldIntputFour);



    QHBoxLayout* LayoutFieldFive = new QHBoxLayout();
    QHBoxLayout* LayoutFieldIntputFive = new QHBoxLayout();
    QVBoxLayout* VLayoutFiveGroup = new QVBoxLayout();

    QLabel* titleLabel4 = new QLabel("Циклічна робота", this);
    titleLabel4->setAlignment(Qt::AlignCenter);
    VLayoutFourGroup->addWidget(titleLabel4);

    for(int i = 12; i <= 13; ++i)
    {
        QLabel* label = new QLabel(headerNamesGUI.at(i), this);
        label->setAlignment(Qt::AlignCenter);
        LayoutFieldFive->addWidget(label);
        inputs[i] = new QLineEdit(this);
        LayoutFieldIntputFive->addWidget(inputs[i]);
    }

    VLayoutFiveGroup->addLayout(LayoutFieldFive);
    VLayoutFiveGroup->addLayout(LayoutFieldIntputFive);



    QHBoxLayout* LayoutFieldSix = new QHBoxLayout();
    QHBoxLayout* LayoutFieldIntputSix = new QHBoxLayout();
    QVBoxLayout* VLayoutSixGroup = new QVBoxLayout();

    for(int i = 14; i <= 15; ++i)
    {
        QLabel* label = new QLabel(headerNamesGUI.at(i), this);
        label->setAlignment(Qt::AlignCenter);
        LayoutFieldSix->addWidget(label);
        inputs[i] = new QLineEdit(this);
        LayoutFieldIntputSix->addWidget(inputs[i]);
    }

    VLayoutSixGroup->addLayout(LayoutFieldSix);
    VLayoutSixGroup->addLayout(LayoutFieldIntputSix);




    VLayoutFirstGroup->addLayout(VLayoutSecondGroup);
    VLayoutFirstGroup->addLayout(VLayoutThirdGroup);
    VLayoutFirstGroup->addLayout(VLayoutFourGroup);
    VLayoutFirstGroup->addLayout(VLayoutFiveGroup);
    VLayoutFirstGroup->addLayout(VLayoutSixGroup);
    VLayoutFirstGroup->addWidget(SendInfo);


    mainLayout->addLayout(VLayoutFirstGroup);
}



void EnterData::MakeFinalData()
{

    FinalInputData["λМНАВ"] = DataFromFields[0] * pow(10, -8);
    FinalInputData["λПРАВ"] = DataFromFields[1] * pow(10, -8);
    FinalInputData["λПМАВ"] = DataFromFields[2] * pow(10, -8);
    FinalInputData["λБЖАВ"] = DataFromFields[3] * pow(10, -8);
    FinalInputData["α"] = DataFromFields[4];
    FinalInputData["β"] = DataFromFields[5] * 10;
    FinalInputData["t"] = DataFromFields[6] * pow(10,4);
    FinalInputData["κтем"] = DataFromFields[7];
    FinalInputData["κвиб"] = DataFromFields[8];
    FinalInputData["κпер"] = DataFromFields[9];
    FinalInputData["G"] = DataFromFields[11] * pow(10,2);
    FinalInputData["r"] = DataFromFields[13];
    FinalInputData["γ"] = DataFromFields[14];
    FinalInputData["∆t"] = DataFromFields[15] * 1000;

    // for (auto it = FinalInputData.begin(); it != FinalInputData.end(); ++it) {
    //     qDebug() << it.key() << ":" << QString::number(it.value(), 'f', 10);
    // }

}

void EnterData::MakeFailureRate()
{
    // QMap<QString, double> MapMakeFailureRate1;
    // QMap<QString, double> MapMakeFailureRate2;
    // QMap<QString, double> MapMakeFailureRate3;
    // QMap<QString, double> MapMakeFailureRate4;
    //λАВ λАЗ λПВ λПЗ λА  λП λКВ  λКЗ λК
    QVector<double> vec;
   /* MapMakeFailureRate1["λАВ"] =*/ vec.push_back(FinalInputData["λМНАВ"] + FinalInputData["λПРАВ"] +
        FinalInputData["λПМАВ"] + FinalInputData["λБЖАВ"]);
    MapMakeFailureRate1["λАВ"] = vec[0];
    /*MapMakeFailureRate1["λАЗ"] = */ vec.push_back(MapMakeFailureRate1["λАВ"] * FinalInputData["β"]);

    /*MapMakeFailureRate1["λПВ"] =*/ MapMakeFailureRate1["λАВ"] * FinalInputData["α"];

    /*MapMakeFailureRate1["λПЗ"] =  */MapMakeFailureRate1["λПВ"] * FinalInputData["β"];

    /*MapMakeFailureRate1["λА"] =*/ MapMakeFailureRate1["λАВ"] + MapMakeFailureRate1["λАЗ"];

    MapMakeFailureRate1["λП"] = MapMakeFailureRate1["λПВ"] + MapMakeFailureRate1["λПЗ"];

    MapMakeFailureRate1["λКВ"] = MapMakeFailureRate1["λАВ"] + MapMakeFailureRate1["λПВ"];

    MapMakeFailureRate1["λКЗ"] = MapMakeFailureRate1["λАЗ"] + MapMakeFailureRate1["λПЗ"];

    MapMakeFailureRate1["λК"] = MapMakeFailureRate1["λА"] + MapMakeFailureRate1["λП"];


    for (auto it = MapMakeFailureRate1.begin(); it != MapMakeFailureRate1.end(); ++it) {
        //qDebug() << it.key() << ":" << QString::number(it.value(), 'f', 10);
        qDebug() << it.key() << ":" << (it.value());

    }


}
void EnterData::AvgWorkinghFailure()
{

}
void EnterData::WorkToFailure()
{

}
void EnterData::CalculateErrorFreeWork()
{

}
void EnterData::CalculateWorkErrorProb()
{

}

void EnterData::CalculateFailureProbabilities()
{

}


void EnterData::CalculateCyclicReliabilityProbabilities()
{

}
void EnterData::CalculateCyclicFailureProbabilities()
{

}
