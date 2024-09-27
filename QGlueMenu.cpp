#include "QGlueMenu.h"
#include "QGlueWidget.h"

GlueMenu::GlueMenu(MonoObject* thisObject, QWidget* parent)
	: QMenu(parent)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);
	_nameSpace = mono_class_get_namespace(mono_object_get_class (mono_gchandle_get_target(_thisObject)));
	connect(this, &QMenu::triggered, this, &GlueMenu::ontriggered);
	connect(this, &QMenu::hovered, this, &GlueMenu::onhovered);
}

GlueMenu::GlueMenu(MonoObject* thisObject, const QString& text, QWidget* parent)
	: QMenu(text, parent)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);
	_nameSpace = mono_class_get_namespace(mono_object_get_class (mono_gchandle_get_target(_thisObject)));
	connect(this, &QMenu::triggered, this, &GlueMenu::ontriggered);
	connect(this, &QMenu::hovered, this, &GlueMenu::onhovered);
}

GlueMenu::~GlueMenu()
{
	disconnect(this, &QMenu::hovered, this, &GlueMenu::onhovered);
	disconnect(this, &QMenu::triggered, this, &GlueMenu::ontriggered);

	doOnRawDelete(_thisObject);
	mono_gchandle_free (_thisObject); 
}

void GlueMenu::ontriggered(QAction *action)
{
	auto klass = mono_object_get_class (mono_gchandle_get_target(_thisObject));
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnTriggered", 1);
	if (eventMethod)
	{
		void *args [1];
		args[0] = &action;
		mono_thread_attach (mono_get_root_domain ());
		mono_runtime_invoke(eventMethod, mono_gchandle_get_target(_thisObject), args, NULL);
	}
	else
	{
		printf("Can't find OnTriggered\n");
		fflush(stdout);
	}
}

void GlueMenu::onhovered(QAction *action)
{
	auto klass = mono_object_get_class (mono_gchandle_get_target(_thisObject));
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnHovered", 1);
	if (eventMethod)
	{
		void *args [1];
		args[0] = &action;
		mono_thread_attach (mono_get_root_domain ());
		mono_runtime_invoke(eventMethod, mono_gchandle_get_target(_thisObject), args, NULL);
	}
	else
	{
		printf("Can't find OnHovered\n");
		fflush(stdout);
	}
}