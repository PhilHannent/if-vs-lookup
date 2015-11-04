#include <QCoreApplication>

#include <iostream>
#include <chrono>

#include <QColor>
#include <QDebug>
#include <QMap>

enum ItemButton {
    Menu,
    Resize,
    Rotate,
    Constrain,
    Link,
    Move,
    Play,
    endEnumType
};

class Timer
{
public:
    Timer() : beg_(clock_::now()) {}
    void reset() { beg_ = clock_::now(); }
    double elapsed() const {
        return std::chrono::duration_cast<second_>
            (clock_::now() - beg_).count(); }

private:
    typedef std::chrono::high_resolution_clock clock_;
    typedef std::chrono::duration<double, std::ratio<1> > second_;
    std::chrono::time_point<clock_> beg_;
};

static QMap<ItemButton, QColor> myColoursDefault() {
    QMap<ItemButton, QColor>map;
    map.insert(ItemButton::Menu, QColor("#ECE9D8"));
    map.insert(ItemButton::Resize, Qt::white);
    map.insert(ItemButton::Rotate, Qt::green);
    map.insert(ItemButton::Constrain, Qt::blue);
    map.insert(ItemButton::Link, QColor("#0088FF"));
    map.insert(ItemButton::Move, QColor("#E83838"));
    map.insert(ItemButton::Play, QColor("#0088FF"));
    return map;
}
static QMap<ItemButton, QColor> myColoursHover() {
    QMap<ItemButton, QColor>map;
    map.insert(ItemButton::Menu, QColor("#DCD5B6"));
    map.insert(ItemButton::Resize, QColor("#F2F0E4"));
    map.insert(ItemButton::Rotate, QColor("#00DC00"));
    map.insert(ItemButton::Constrain, QColor("#414AFF"));
    map.insert(ItemButton::Link, QColor("#0077DC"));
    map.insert(ItemButton::Move, QColor("#DF3131"));
    map.insert(ItemButton::Play, QColor("#0077DC"));
    return map;
}

static const QMap<ItemButton, QColor> m_brushColourDefault = myColoursDefault();
static const QMap<ItemButton, QColor> m_brushColourHover = myColoursHover();

ItemButton m_type = ItemButton::Menu;

QColor brushColourDefault()
{
    if ( m_type == Menu )
    {
        return QColor("#ECE9D8");
    }
    else if ( m_type == Resize )
    {
        return Qt::white;
    }
    else if ( m_type == Rotate )
    {
        return Qt::green;
    }
    else if ( m_type == Constrain )
    {
        return Qt::blue;
    }
    else if ( m_type == Link )
    {
        return QColor("#0088FF");
    }
    else if ( m_type == Move )
    {
        return QColor("#E83838");
    }
    else /*if ( m_type == Play )*/
    {
        return QColor("#0088FF");
    }
}

QColor brushColourHover()
{
    if ( m_type == Menu )
    {
        return QColor("#DCD5B6");
    }
    else if ( m_type == Resize )
    {
        return QColor("#F2F0E4");
    }
    else if ( m_type == Rotate )
    {
        return QColor("#00DC00");
    }
    else if ( m_type == Constrain )
    {
        return QColor("#414AFF");
    }
    else if ( m_type == Link )
    {
        return QColor("#0077DC");
    }
    else if ( m_type == Move )
    {
        return QColor("#DF3131");
    }
    else /*if ( m_type == Play )*/
    {
        return QColor("#0077DC");
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Timer tmr;
    QColor result;
    static int runs = 100000;
    for (int i = 0; i < runs; i++) {
        for (int j = Menu; j < endEnumType; j++) {
            m_type = static_cast<ItemButton>(j);
            result = brushColourDefault();
            result = brushColourHover();
        }
    }
    double t = tmr.elapsed();
    qDebug() << "Elapsed Time for if statements:" << t;
    tmr.reset();
    for (int i = 0; i < runs; i++) {
        for (int j = Menu; j < endEnumType; j++) {
            m_type = static_cast<ItemButton>(j);
            result = m_brushColourDefault[m_type];
            result = m_brushColourHover[m_type];
        }
    }
    t = tmr.elapsed();
    qDebug() << "Elapsed Time for lookup:" << t;

    return a.exec();
}
