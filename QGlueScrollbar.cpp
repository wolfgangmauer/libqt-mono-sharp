#include "QGlueScrollbar.h"

GlueScrollbar::GlueScrollbar(MonoObject* thisObject, QWidget *parent) 
	: QScrollbar(parent)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);
}

GlueCheckBox::~GlueCheckBox()
{
	doOnRawDelete(_thisObject);
	mono_gchandle_free (_thisObject); 
}
