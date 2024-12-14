#include "enterdata.h"
#include <string>

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
    AvgWorkinghFailure();
    WorkToFailure();
    SetTimer();
    CalculateErrorFreeWork();
    CalculateWorkErrorProb();
    CalculateFailureProbabilities();
    CalculateFailureReliabilityStorage();
    CalculateGeneralErrorFreeWork();
    CalculateFailureGeneralWork();
    CalculateCyclicReliabilityProbabilities();
    CalculateCyclicFailureProbabilities();

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


}

void EnterData::MakeFailureRate()
{
    QVector<double> vec;
    vec.push_back(FinalInputData["λМНАВ"] + FinalInputData["λПРАВ"] + FinalInputData["λПМАВ"] + FinalInputData["λБЖАВ"]);
     MapMakeFailureRate1["λАВ"] = vec[0];
    vec.push_back(MapMakeFailureRate1["λАВ"] * FinalInputData["β"]);
     MapMakeFailureRate1["λАЗ"] = vec[1];
    vec.push_back(MapMakeFailureRate1["λАВ"] * FinalInputData["α"]);
    MapMakeFailureRate1["λПВ"] = vec[2];
    vec.push_back(MapMakeFailureRate1["λПВ"] * FinalInputData["β"]);
    MapMakeFailureRate1["λПЗ"] = vec[3];
    vec.push_back(MapMakeFailureRate1["λАВ"] + MapMakeFailureRate1["λАЗ"]);
    MapMakeFailureRate1["λА"] = vec[4];
    vec.push_back(MapMakeFailureRate1["λПВ"] + MapMakeFailureRate1["λПЗ"]);
    MapMakeFailureRate1["λП"] = vec[5];
    vec.push_back(MapMakeFailureRate1["λАВ"] + MapMakeFailureRate1["λПВ"]);
    MapMakeFailureRate1["λКВ"] = vec[6];
    vec.push_back(MapMakeFailureRate1["λАЗ"] + MapMakeFailureRate1["λПЗ"]);
    MapMakeFailureRate1["λКЗ"] = vec[7];
    vec.push_back(MapMakeFailureRate1["λА"] + MapMakeFailureRate1["λП"]);
    MapMakeFailureRate1["λК"] = vec[8];

    MapMakeFailureRate2["λАВЗб"] = MapMakeFailureRate1["λАВ"] / FinalInputData["G"];
    MapMakeFailureRate2["λАЗЗб"] =  MapMakeFailureRate1["λАЗ"] / FinalInputData["G"];
    MapMakeFailureRate2["λПВЗб"] = MapMakeFailureRate1["λПВ"] / FinalInputData["G"];
    MapMakeFailureRate2["λПЗЗб"] = MapMakeFailureRate1["λПЗ"] / FinalInputData["G"];
    MapMakeFailureRate2["λАЗб"] = MapMakeFailureRate1["λА"] / FinalInputData["G"];
    MapMakeFailureRate2["λПЗб"] = MapMakeFailureRate1["λП"] / FinalInputData["G"];
    MapMakeFailureRate2["λКВЗб"] = MapMakeFailureRate1["λКВ"] / FinalInputData["G"];
    MapMakeFailureRate2["λКЗЗб"] =  MapMakeFailureRate1["λКЗ"] / FinalInputData["G"];
    MapMakeFailureRate2["λКЗб"] = MapMakeFailureRate1["λК"] / FinalInputData["G"];

    double TempMultFor3 = (FinalInputData["κтем"] * FinalInputData["κвиб"]) * FinalInputData["κпер"];

    MapMakeFailureRate3["λАВЕ"] = TempMultFor3 * MapMakeFailureRate1["λАВ"];
    MapMakeFailureRate3["λАЗЕ"] = TempMultFor3 *  MapMakeFailureRate1["λАЗ"];
    MapMakeFailureRate3["λПВЕ"] = TempMultFor3 *  MapMakeFailureRate1["λПВ"];
    MapMakeFailureRate3["λПЗЕ"] = TempMultFor3 * MapMakeFailureRate1["λПЗ"];
    MapMakeFailureRate3["λАЕ"] = TempMultFor3 *  MapMakeFailureRate1["λА"];
    MapMakeFailureRate3["λПЕ"] = TempMultFor3 * MapMakeFailureRate1["λП"];
    MapMakeFailureRate3["λКВЕ"] = TempMultFor3 * MapMakeFailureRate1["λКВ"];
    MapMakeFailureRate3["λКЗЕ"] = TempMultFor3 *   MapMakeFailureRate1["λКЗ"];
    MapMakeFailureRate3["λКЕ"] =  TempMultFor3 * MapMakeFailureRate1["λК"];

    double TempMultFor4 = (1.0 + (FinalInputData["G"] - 1.0) * FinalInputData["r"]) / FinalInputData["G"];

    MapMakeFailureRate4["λАВЦ"] = TempMultFor4 * MapMakeFailureRate1["λАВ"];
    MapMakeFailureRate4["λАЗЦ"] = TempMultFor4 *  MapMakeFailureRate1["λАЗ"];
    MapMakeFailureRate4["λПВЦ"] = TempMultFor4 *  MapMakeFailureRate1["λПВ"];
    MapMakeFailureRate4["λПЗЦ"] = TempMultFor4 * MapMakeFailureRate1["λПЗ"];
    MapMakeFailureRate4["λАЦ"] = TempMultFor4 *  MapMakeFailureRate1["λА"];
    MapMakeFailureRate4["λПЦ"] = TempMultFor4 * MapMakeFailureRate1["λП"];
    MapMakeFailureRate4["λКВЦ"] = TempMultFor4 * MapMakeFailureRate1["λКВ"];
    MapMakeFailureRate4["λКЗЦ"] = TempMultFor4 *   MapMakeFailureRate1["λКЗ"];
    MapMakeFailureRate4["λКЦ"] = TempMultFor4 * MapMakeFailureRate1["λК"];

}
void EnterData::AvgWorkinghFailure()
{

    for (auto it = MapMakeFailureRate1.begin(); it != MapMakeFailureRate1.end(); ++it)
    {
        MapAvgWorkinghFailure[0].insert(it.key(), 1.0 / it.value());
    }
    for (auto it = MapMakeFailureRate2.begin(); it != MapMakeFailureRate2.end(); ++it)
    {
        MapAvgWorkinghFailure[1].insert(it.key(), 1.0 / it.value());
    }
    for (auto it = MapMakeFailureRate3.begin(); it != MapMakeFailureRate3.end(); ++it)
    {
        MapAvgWorkinghFailure[2].insert(it.key(), 1.0 / it.value());
    }
    for (auto it = MapMakeFailureRate4.begin(); it != MapMakeFailureRate4.end(); ++it)
    {
        MapAvgWorkinghFailure[3].insert(it.key(), 1.0 / it.value());
    }

    for (int i = 0; i < 4; ++i)
    {
        QMap<QString, double> updatedMap;
        for (auto it = MapAvgWorkinghFailure[i].begin(); it != MapAvgWorkinghFailure[i].end(); ++it)
        {
            QString updatedKey = it.key();
            if (!updatedKey.isEmpty())
            {
                updatedKey[0] = 'T';
            }
            updatedMap.insert(updatedKey, it.value());
        }
        MapAvgWorkinghFailure[i] = updatedMap;
    }
}

void EnterData::WorkToFailure()
{
    _worktofailure = (-1 / MapMakeFailureRate1["λКВ"]) * std::log(FinalInputData["γ"]/100);
}

void EnterData::SetTimer()
{
    for(int i = 0; i <= FinalInputData["t"]; i += 1000)
    {
        TIMER.push_back(i);
    }

}

void EnterData::CalculateErrorFreeWork()
{
    QVector<QString> keys = {"PАВ", "PАЗ", "PПВ", "PПЗ", "PА", "PП", "PКВ", "PКЗ", "PК"};
    for(int i = 0; i < keys.size(); ++i)
    {
        QVector<double> pVector;
        QString tempstr = keys[i];
        double lambda =  MapMakeFailureRate1["λ" + tempstr.removeFirst()];

        for(auto time : TIMER)
        {
            double pValue = std::exp(-lambda * time);
            pVector.push_back(pValue);
        }

        ErrorFreeWork[keys[i]] = pVector;
    }
}

void EnterData::CalculateWorkErrorProb()
{
    QVector<QString> keys = {"QАВ", "QАЗ", "QПВ", "QПЗ", "QА", "QП", "QКВ", "QКЗ", "QК"};

    for(int i = 0; i < keys.size(); ++i)
    {
        QVector<double> qVector;

        QString tempstr = keys[i];
        QVector<double> pVector = ErrorFreeWork["P" + tempstr.removeFirst()];
        for(auto pValue : pVector)
        {
            pValue = 1.0 - pValue;
            qVector.push_back(pValue);
        }

        ErrorProbabilities[keys[i]] = qVector;
    }


}

void EnterData::CalculateFailureProbabilities()
{

    QVector<QString> keys = {"PАВЗб", "PАЗЗб", "PПВЗб", "PПЗЗб", "PАЗб", "PПЗб", "PКВЗб", "PКЗЗб", "PКЗб"};
    for(int i = 0; i < keys.size(); ++i)
    {
        QVector<double> pVector;
        QString tempstr = keys[i];
        double lambda =  MapMakeFailureRate2["λ" + tempstr.removeFirst()];

        for(auto time : TIMER)
        {
            double pValue = std::exp(-lambda * time);
            pVector.push_back(pValue);
        }

        ReliabilityStorage[keys[i]] = pVector;
    }
}

void EnterData::CalculateFailureReliabilityStorage()
{

    QVector<QString> keys = {"QАВЗб", "QАЗЗб", "QПВЗб", "QПЗЗб", "QАЗб", "QПЗб", "QКВЗб", "QКЗЗб", "QКЗб"};;

    for(int i = 0; i < keys.size(); ++i)
    {
        QVector<double> qVector;

        QString tempstr = keys[i];
        QVector<double> pVector = ReliabilityStorage["P" + tempstr.removeFirst()];
        for(auto pValue : pVector)
        {
            pValue = 1.0 - pValue;
            qVector.push_back(pValue);
        }

        FailureReliabilityStorage[keys[i]] = qVector;
    }


}

void EnterData::CalculateGeneralErrorFreeWork()
{
    QVector<QString> keys = {"PАВЕ", "PАЗЕ", "PПВЕ", "PПЗЕ", "PАЕ", "PПЕ", "PКВЕ", "PКЗЕ", "PКЕ"};
    for(int i = 0; i < keys.size(); ++i)
    {
        QVector<double> pVector;
        QString tempstr = keys[i];
        double lambda =  MapMakeFailureRate3["λ" + tempstr.removeFirst()];

        for(auto time : TIMER)
        {
            double pValue = std::exp(-lambda * time);
            pVector.push_back(pValue);
        }

        GeneralErrorFreeWork[keys[i]] = pVector;
    }

}


void EnterData::CalculateFailureGeneralWork()
{

    QVector<QString> keys = {"QАВЕ", "QАЗЕ", "QПВЕ", "QПЗЕ", "QАЕ", "QПЕ", "QКВЕ", "QКЗЕ", "QКЕ"};

    for(int i = 0; i < keys.size(); ++i)
    {
        QVector<double> qVector;

        QString tempstr = keys[i];
        QVector<double> pVector = GeneralErrorFreeWork["P" + tempstr.removeFirst()];
        for(auto pValue : pVector)
        {
            pValue = 1.0 - pValue;
            qVector.push_back(pValue);
        }

        FailureGeneralWork[keys[i]] = qVector;
    }

}
void EnterData::CalculateCyclicReliabilityProbabilities()
{

    QVector<QString> keys = {"PАВЦ", "PАЗЦ", "PПВЦ", "PПЗЦ", "PАЦ", "PПЦ", "PКВЦ", "PКЗЦ", "PКЦ"};
    for(int i = 0; i < keys.size(); ++i)
    {
        QVector<double> pVector;
        QString tempstr = keys[i];
        double lambda =  MapMakeFailureRate4["λ" + tempstr.removeFirst()];

        for(auto time : TIMER)
        {
            double pValue = std::exp(-lambda * time);
            pVector.push_back(pValue);
        }

        CyclicReliabilityProbabilities[keys[i]] = pVector;
    }


}
void EnterData::CalculateCyclicFailureProbabilities()
{

    QVector<QString> keys = {"QАВЦ", "QАЗЦ", "QПВЦ", "QПЗЦ", "QАЦ", "QПЦ", "QКВЦ", "QКЗЦ", "QКЦ"};

    for(int i = 0; i < keys.size(); ++i)
    {
        QVector<double> qVector;

        QString tempstr = keys[i];
        QVector<double> pVector = CyclicReliabilityProbabilities["P" + tempstr.removeFirst()];
        for(auto pValue : pVector)
        {
            pValue = 1.0 - pValue;
            qVector.push_back(pValue);
        }

        CyclicFailureProbabilities[keys[i]] = qVector;
    }
    for (auto it = CyclicFailureProbabilities.begin(); it != CyclicFailureProbabilities.end(); ++it)
    {
        //qDebug() << it.key() << ":" << QString::number(it.value(), 'f', 10);
        qDebug() << it.key() << ":" << (it.value());
    }
}
