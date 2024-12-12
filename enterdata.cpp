#include "EnterData.h"

EnterData::EnterData(QWidget* parent) : QWidget(parent)
{
    SendInfo = new QPushButton("Start calculation", this);
    BuildFields();

    connect(SendInfo, &QPushButton::clicked, this, &EnterData::GetDataFromFields);
}



void EnterData::GetDataFromFields()
{
    for(int i = 0; i < 16; ++i)
          inputs[i]->setText("1.5");

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

    QMap<QString, double> FinalInputData;
    for(int i = 0; i < 16; ++i)
    {
        if(i == 10 && i == 12)
        {
            continue;
        }
        FinalInputData[headerNames[i]] = DataFromFields[i];
    }

        FinalInputData["λМНАВ"] = DataFromFields[0] * pow(10, -8);
        FinalInputData["λПРАВ"] = DataFromFields[1] * pow(10, -8);
        FinalInputData["λПМАВ"] = DataFromFields[2] * pow(10, -8);
        FinalInputData["λБЖАВ"] = DataFromFields[3] * pow(10, -8);
        FinalInputData["α"] = DataFromFields[4];
        FinalInputData["β×10"] = DataFromFields[5] * 10;
        FinalInputData["t×10^4"] = DataFromFields[6] * pow(10,4);
        FinalInputData["κтем"] = DataFromFields[7];
        FinalInputData["κвиб"] = DataFromFields[8];
        FinalInputData["κпер"] = DataFromFields[9];
        FinalInputData["G×10^2"] = DataFromFields[11] * pow(10,2);
        FinalInputData["r"] = DataFromFields[13];
        FinalInputData["γ"] = DataFromFields[14];
        FinalInputData["∆t×10^3"] = DataFromFields[15] * 1000;

        for (auto it = FinalInputData.begin(); it != FinalInputData.end(); ++it) {
            qDebug() << it.key() << ":" << QString::number(it.value(), 'f', 10);
        }

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
        QLabel* label = new QLabel(headerNames.at(i), this);
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
        QLabel* label = new QLabel(headerNames.at(i), this);
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
        QLabel* label = new QLabel(headerNames.at(i), this);
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
        QLabel* label = new QLabel(headerNames.at(i), this);
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
        QLabel* label = new QLabel(headerNames.at(i), this);
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
        QLabel* label = new QLabel(headerNames.at(i), this);
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



void MakeFinalData()
{

}
void MakeFailureRate()
{

}
void AvgWorkinghFailure()
{

}
void WorkToFailure()
{

}
void CalculateErrorFreeWork()
{

}
void CalculateWorkErrorProb()
{

}
void CalculateReliabilityStorage()
{

}
void CalculateFailureProbabilities()
{

}
void CalculateReliabilityStorage()
{

}
void CalculateReliabilityStorage()
{

}
void CalculateCyclicReliabilityProbabilities()
{

}
void CalculateCyclicFailureProbabilities()
{

}
