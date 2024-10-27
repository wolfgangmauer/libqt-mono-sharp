#pragma once
#include <QScrollBar>
#include "QGlueWidget.h"

class GlueScrollBar : public QScrollBar
{
public:
    GlueScrollBar(MonoObject* thisObject, QWidget *parent=0);
    ~GlueScrollBar();
private:
    guint32 _thisObject;
};
