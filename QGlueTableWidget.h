#pragma once
#include <QTableWidget>
#include "QGlueWidget.h"

class GlueTableWidget : public QTableWidget
{
    Q_OBJECT
#define BaseClass QTableWidget
#include "internalevents.h"
public:
    GlueTableWidget(MonoObject* thisObject, QWidget *parent=0);
    ~GlueTableWidget();
public slots:
    void selectionChanged();
private:
    guint32 _thisObject;
};

