﻿#pragma once
#include <QMainWindow>
#include "QGlueDialog.h"

class GlueMainWindow : public QMainWindow
{
#define BaseClass QMainWindow
#include "internalevents.h"
public:
    GlueMainWindow(MonoObject* thisObject, QWidget *parent = 0, Qt::WindowFlags flags = 0);
    ~GlueMainWindow();
private:
	guint32 _thisObject;
};
