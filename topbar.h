#ifndef TOPBAR_H
#define TOPBAR_H

#include <QWidget>

namespace Ui {
class TopBar;
}

class TopBar : public QWidget
{
    Q_OBJECT

public:
    explicit TopBar(QWidget *parent = nullptr);
    ~TopBar();

private:
    Ui::TopBar *ui;
};

#endif // TOPBAR_H
