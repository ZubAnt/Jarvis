#ifndef WIDGETVERTICALLAYOUT_H
#define WIDGETVERTICALLAYOUT_H

#include <QWidget>
#include <QGridLayout>
#include "settingsbuttonbox.h"

class WidgetVerticalLayout : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetVerticalLayout(QWidget *parent = 0);

   ~WidgetVerticalLayout();
    QLayoutItem *itemAt(int index) const;
    void removeWidget(QWidget *widget);
    void addWidget(DynamicButton *widget);
    void addWidgetWithSettingsButton(SettingsButtonBox *settings);
    void hideWidgets();
    void showWidgets();
    int  count() const;


    QGridLayout *vertLayout;
};

#endif // WIDGETVERTICALLAYOUT_H
