#pragma once
#include <QScrollBar>

class GlueScrollbar : public QScrollBar
{
public:
    GlueScrollbar(MonoObject* thisObject, QWidget *parent=0);
    ~GlueScrollbar();
private:
    guint32 _thisObject;
};
