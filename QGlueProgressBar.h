#pragma once
#include <QProgressBar>
#include "QGlueWidget.h"

class GlueProgressBar : public QProgressBar
{
#define BaseClass QProgressBar
#include "internalevents.h"
Q_OBJECT
public:
    GlueProgressBar(MonoObject* thisObject, QWidget* parent = 0);
    ~GlueProgressBar();
    void updateProgressValue(int value);

signals:
    void updateValue(int value);

private:
   	void onpressed();
 	void onreleased();
 	void onclicked(bool checked);
 	void ontoggled(bool checked);
private:
    guint32 _thisObject;
};
