#ifndef PANEL_H
#define PANEL_H

#include <QToolBar>

class Panel : public QToolBar
{
    Q_OBJECT
private:
    QAction* CollectData;
    QAction* DrawTables;
public:
    Panel(QWidget* parent = nullptr);

    QAction* GetCollectData();
    QAction* GetDrawTables();
};

#endif // PANEL_H
