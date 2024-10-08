﻿#include "QGlueFrame.h"

GlueFrame::GlueFrame(MonoObject* thisObject, QWidget* parent) : QFrame(parent)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);
	_nameSpace = mono_class_get_namespace(mono_object_get_class (mono_gchandle_get_target(_thisObject)));
}

GlueFrame::~GlueFrame()
{
	doOnRawDelete(_thisObject);
	mono_gchandle_free (_thisObject); 
}

