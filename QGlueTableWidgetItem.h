﻿#pragma once
#include <QTableWidgetItem>
#include "QGlueWidget.h"

class GlueTableWidgetItem : public QTableWidgetItem
{
public:
    GlueTableWidgetItem(MonoObject* thisObject, char* text);
    ~GlueTableWidgetItem();
private:
    guint32 _thisObject;
};
