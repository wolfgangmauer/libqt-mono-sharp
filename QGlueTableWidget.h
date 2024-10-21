#pragma once
#include <QTableWidget>
#include "QGlueWidget.h"

class GlueTableWidget : public QTableWidget
{
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

