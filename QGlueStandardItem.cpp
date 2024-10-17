#include "QGlueStandardItem.h"

GlueStandardItem::GlueStandardItem(MonoObject* thisObject, GlueObject* parent)
	: QStandardItem(parent)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);
}
