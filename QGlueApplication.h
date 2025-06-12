#pragma once
#include <QApplication>

//#include <mono/jit/jit.h>
//#include <mono/metadata/assembly.h>
//#include <mono/metadata/class.h>
//#include <mono/metadata/debug-helpers.h>
//#include <mono/metadata/mono-config.h>

#include "QGlueMainWindow.h"

class GlueApplication : public QApplication
{
public:
	GlueApplication(MonoObject*, int&, char**);
	~GlueApplication();

	static void processEvents(QEventLoop::ProcessEventsFlags flags = QEventLoop::AllEvents)
	{
		qWarning() << Q_FUNC_INFO << hasGlib;
		if (!hasGlib) {
	    		g_main_context_iteration(gContext, false);
		}
		QApplication::processEvents(flags);
	}
	static void processEvents(QEventLoop::ProcessEventsFlags flags, int maxtime)
	{
		qWarning() << Q_FUNC_INFO << hasGlib;
		if (!hasGlib) {
	    		g_main_context_iteration(gContext, false);
		}
		QApplication::processEvents(flags, maxtime);
	}
private:
	static _GMainContext *gContext;
	QAbstractEventDispatcher *dispatcher = nullptr;
	static bool hasGlib;
	guint32 _thisObject;
};
