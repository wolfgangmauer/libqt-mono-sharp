﻿#include "QGlueProgressBar.h"

GlueProgressBar::GlueProgressBar(MonoObject* thisObject, QWidget* parent)
	: QProgressBar(parent)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);
	_nameSpace = mono_class_get_namespace(mono_object_get_class (mono_gchandle_get_target(_thisObject)));
	connect(this, SIGNAL(updateProgress(int)), this, SLOT(setValue(int)));
	connect(this, SIGNAL(updateMaximum(int)), this, SLOT(setMaximum(int)));
}
void GlueProgressBar::updateProgressValue(int value)
{
	emit updateProgress(value);
}
void GlueProgressBar::updateMaximumValue(int value)
{
	emit updateMaximum(value);
}
GlueProgressBar::~GlueProgressBar()
{
	doOnRawDelete(_thisObject);
	mono_gchandle_free (_thisObject); 
}

#include "QGlueProgressBar.h.moc"
