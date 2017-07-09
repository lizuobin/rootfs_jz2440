#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <demoapplication.h>
#include <QXmlStreamReader>
#include <QGridLayout>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void launchApplication(int index);
    void demoFinished();
    void demoStarted();

private slots:


private:
    QList<DemoApplication*> demoList;
    QList<QPushButton *> btnList;
private:
    QGridLayout *mainLayout;
    bool loadConfig(QString configPath);
    void parseDemos(QXmlStreamReader& reader);
};

#endif // WIDGET_H
