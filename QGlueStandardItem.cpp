#include "QGlueStandardItem.h"

GlueStandardItem::GlueStandardItem(MonoObject* thisObject, char* text)
	: QStandardItem(text)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);
}
GlueStandardItem::~GlueStandardItem()
{
	mono_gchandle_free (_thisObject); 
}
