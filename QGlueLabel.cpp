#include "QGlueLabel.h"

GlueLabel::GlueLabel(MonoObject* thisObject, QWidget *parent, Qt::WindowFlags f) 
	: QLabel(parent, f)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);
	_nameSpace = mono_class_get_namespace(mono_object_get_class (mono_gchandle_get_target(_thisObject)));
}

GlueLabel::GlueLabel(MonoObject* thisObject, char* text, QWidget *parent, Qt::WindowFlags f)
	: QLabel(text, parent, f)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);
	_nameSpace = mono_class_get_namespace(mono_object_get_class (mono_gchandle_get_target(_thisObject)));
	connect(this, SIGNAL(updateText(const QString &)), this, SLOT(setText(const QString &)));
}
void GlueLabel::updateTextValue(char* text)
{
	const QString str = QString::fromUtf8(text);
	emit updateText(str);
}
GlueLabel::~GlueLabel()
{
	doOnRawDelete(_thisObject);
	mono_gchandle_free (_thisObject); 
}
#include "QGlueLabel.moc"
