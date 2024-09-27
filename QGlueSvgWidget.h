#pragma once
#include <QSvgWidget>
#include "QGlueWidget.h"

class GlueSvgWidget :  public QSvgWidget
{
#define BaseClass QSvgWidget
#include "internalevents.h"
public:
	GlueSvgWidget(MonoObject* thisObject, QWidget* parent = 0);
	~GlueSvgWidget();
private:
	guint32 _thisObject;
};

