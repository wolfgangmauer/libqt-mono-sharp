
#include "QGlueTableWidget.h"

GlueTableWidget::GlueTableWidget(MonoObject* thisObject, QWidget *parent) : QTableWidget(parent)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);
	_nameSpace = mono_class_get_namespace(mono_object_get_class (mono_gchandle_get_target(_thisObject)));
	connect(this, SIGNAL(itemSelectionChanged()), this, SLOT(selectionChanged()));
}

GlueTableWidget::~GlueTableWidget()
{
	doOnRawDelete(_thisObject);
	mono_gchandle_free (_thisObject); 
}

void GlueTableWidget::selectionChanged()
{
	auto klass = mono_object_get_class (mono_gchandle_get_target(_thisObject));
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnSelectionChanged", 1);
	if (eventMethod)
	{
		int row = currentRow();
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		void *args [1];
		args[0] = (void*)&row;
		mono_thread_attach (mono_get_root_domain ());
		mono_runtime_invoke(eventMethod, mono_gchandle_get_target(_thisObject), args, NULL);
	}
}

#include "QGlueTableWidget.h.moc"
