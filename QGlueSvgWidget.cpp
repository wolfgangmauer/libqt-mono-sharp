#include "QGlueSvgWidget.h"

GlueSvgWidget::GlueSvgWidget(MonoObject* thisObject, QWidget* parent)
	: QSvgWidget(parent)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);
	_nameSpace = mono_class_get_namespace(mono_object_get_class(mono_gchandle_get_target(_thisObject)));
}
GlueSvgWidget::~GlueSvgWidget()
{
	doOnRawDelete(_thisObject);
	mono_gchandle_free(_thisObject);
}