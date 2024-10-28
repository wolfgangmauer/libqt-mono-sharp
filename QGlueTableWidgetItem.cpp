#include "QGlueTableWidgetItem.h"

GlueTableWidgetItem::GlueTableWidgetItem(MonoObject* thisObject, char* text)
	: QTableWidgetItem(text)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);
}
GlueTableWidgetItem::~GlueTableWidgetItem()
{
	mono_gchandle_free (_thisObject); 
}
