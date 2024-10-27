#include "QGlueScrollBar.h"

GlueScrollBar::GlueScrollBar(MonoObject* thisObject, QWidget *parent) 
	: QScrollBar(parent)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);
}

GlueScrollBar::~GlueScrollBar()
{
	doOnRawDelete(_thisObject);
	mono_gchandle_free (_thisObject); 
}
