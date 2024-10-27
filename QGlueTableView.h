#pragma once
#include <QTableView>
#include <QTableWidget>
#include "QGlueWidget.h"

class GlueTableView : public QTableView
{
#define BaseClass QTableView
#include "internalevents.h"
public:
    explicit GlueTableView(MonoObject* thisObject, QWidget *parent=0);
    ~GlueTableView();
    int move_cursor(int cursorAction, int modifier);
protected:
	void currentChanged(const QModelIndex &current, const QModelIndex &previous) override;
private:
	void onpressed(const QModelIndex &index);
private:
    guint32 _thisObject;
};
