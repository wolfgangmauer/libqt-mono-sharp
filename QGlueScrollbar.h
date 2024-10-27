#pragma once
#include <QScrollbar>

class GlueScrollbar : public QScrollbar
{
public:
    GlueScrollbar(MonoObject* thisObject, QWidget *parent=0);
    ~GlueScrollbar();
private:
    guint32 _thisObject;
};
