#pragma once
#include <QScrollBar>

class GlueScrollBar : public QScrollBar
{
public:
    GlueScrollBar(MonoObject* thisObject, QWidget *parent=0);
    ~GlueScrollBar();
private:
    guint32 _thisObject;
};
