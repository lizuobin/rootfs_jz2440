#include "widget.h"
#include <QXmlStreamReader>
#include <QFile>
#include <QDebug>
#include <QGridLayout>
#include <QPushButton>
#include <QDesktopWidget>
#include <QApplication>
#include <QHBoxLayout>
#include <QSpacerItem>

Widget::Widget(QWidget *parent) :
    QWidget(parent)

{
    //无边框
    setWindowFlags(Qt::FramelessWindowHint);
    showFullScreen();
    QPalette palette;
    palette.setColor(QPalette::Background, QColor(0,0,0));

    setPalette(palette);

    QRect screen_size = QApplication::desktop()->screenGeometry();

    const int h = (screen_size.height() - 50) / 3;

    const int btnSize = h;
    mainLayout = new QGridLayout;


    for (int i = 0; i < 12; i++)
    {
        QPushButton *newBtn = new QPushButton;
        btnList.append(newBtn);
        newBtn->setFixedSize(QSize(btnSize, btnSize));
        newBtn->setStyleSheet("background-color:transparent");
        mainLayout->addWidget(newBtn, i / 4 , i % 4);
    }

    QHBoxLayout *horizontalLayout = new QHBoxLayout;
    horizontalLayout->addStretch();
    horizontalLayout->addLayout(mainLayout, 1);
    horizontalLayout->addStretch();

    setLayout(horizontalLayout);

    loadConfig("/usr/local/desktop/config.xml");
}

Widget::~Widget()
{

}

void Widget::launchApplication(int index)
{
    if (index == demoList.size() -1) {
        qApp->quit();
        return;
    }


    QObject::connect(demoList[index], SIGNAL(demoFinished()), this, SLOT(demoFinished()));

    demoList[index]->launch();//调用app
}

void Widget::demoFinished()
{
    show();
    setEnabled(1);
}

void Widget::demoStarted()
{
    setEnabled(0);
    hide();
}


bool Widget::loadConfig(QString configPath)
{
    QFile xmlFile(configPath);

    if (!xmlFile.exists() || (xmlFile.error() != QFile::NoError)) {
        qDebug() << "ERROR: Unable to open config file " << configPath;
        return false;
    }

    xmlFile.open(QIODevice::ReadOnly);
    QXmlStreamReader reader(&xmlFile);
    while (!reader.atEnd()) {
        reader.readNext();

        if (reader.isStartElement()) {
            if (reader.name() == "demos")
                parseDemos(reader);
        }
    }

    if (reader.hasError()) {
       qDebug() << QString("Error parsing %1 on line %2 column %3: \n%4")
                .arg(configPath)
                .arg(reader.lineNumber())
                .arg(reader.columnNumber())
                .arg(reader.errorString());
    }

    return true;
}

void Widget::parseDemos(QXmlStreamReader& reader)
{
    int num = 0;
    while (!reader.atEnd()) {
        reader.readNext();
        if (reader.isStartElement() && reader.name() == "desktop") {
		QXmlStreamAttributes attrs = reader.attributes();
            	QStringRef filename = attrs.value("image");
            	if (!filename.isEmpty()) {
			this->setAutoFillBackground(true);
     			QPalette palette;
     			QPixmap pixmap(filename.toString());
     			palette.setBrush(QPalette::Window, QBrush(pixmap));
     			this->setPalette(palette);
		}
	}
        if (reader.isStartElement() && reader.name() == "example") {
            QXmlStreamAttributes attrs = reader.attributes();
            QStringRef filename = attrs.value("filename");
            if (!filename.isEmpty()) {
                QStringRef name = attrs.value("name");
                QStringRef image = attrs.value("image");
                QStringRef args = attrs.value("args");

                DemoApplication* newDemo = new DemoApplication(
                        filename.toString(),
                        name.isEmpty() ? "Unnamed Demo" : name.toString(),
                        image.toString(),
                        args.toString().split(" "));
                btnList.at(num)->setIcon(QIcon(image.toString()));
                btnList.at(num)->setIconSize(btnList.at(num)->size());
                QObject::connect(btnList.at(num), SIGNAL(clicked(bool)), newDemo, SLOT(launch()));
                QObject::connect(newDemo, SIGNAL(demoStarted()), this, SLOT(demoStarted()));
                QObject::connect(newDemo, SIGNAL(demoFinished()), this, SLOT(demoFinished()));

                demoList.append(newDemo);

                num++;
            }
        } else if(reader.isEndElement() && reader.name() == "demos") {
            return;
        }
    }
}
