#include "QGlueStandardItemModel.h"

GlueStandardItemModel::GlueStandardItemModel(MonoObject* thisObject, GlueObject* parent)
	: QStandardItemModel(parent)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);
	connect(this, SIGNAL(selectionChanged(const QItemSelection&, const QItemSelection&)), this ,SLOT(onSelectioChanged()));
}

GlueStandardItemModel::GlueStandardItemModel(MonoObject* thisObject, int rows, int cols, GlueObject* parent)
	: QStandardItemModel(rows, cols, parent)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);
}
