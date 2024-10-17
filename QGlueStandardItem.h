#pragma once
#include <QStandardItem>
#include "QGlueWidget.h"

class GlueStandardItem : public QStandardItem
{
public:
    GlueStandardItem(MonoObject* thisObject, GlueObject* parent=0);

private:
    guint32 _thisObject;
};
