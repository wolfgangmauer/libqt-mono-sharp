﻿#pragma once
#include <QStandardItem>
#include "QGlueWidget.h"

class GlueStandardItem : public QStandardItem
{
public:
    GlueStandardItem(MonoObject* thisObject, char* text);
    ~GlueStandardItem();
private:
    guint32 _thisObject;
};
