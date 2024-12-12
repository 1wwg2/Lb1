#include "panel.h"

Panel::Panel(QWidget* parent) : QToolBar(parent)
{
    CollectData = new QAction("Enter data", this);
    DrawTables = new QAction("Check Results", this);

    addAction(CollectData);
    addAction(DrawTables);
}


QAction* Panel::GetCollectData()
{
    return CollectData;
}

QAction* Panel::GetDrawTables()
{
    return DrawTables;
}


