SUMMARY = "libray for mono and qt-mono-sharp"
SECTION = "base"
PRIORITY = "optional"
LICENSE = "PD"
LIC_FILES_CHKSUM = "file://monointernal.cpp;firstline=1;endline=1;md5=4e4f8c406c33d91df4a0552f2cdc65fd"

SRC_URI[sha256sum] = "c3573b6d25ea729252e825264fef45ee0375c540f0cd97075979367ed729cc29"

PV = "1.0"

PROVIDES =+ " libqt_mono-sharp"
PACKAGES =+ " libqt_mono-sharp"

inherit pkgconfig
#inherit gitpkgv

SRCREV = "${AUTOREV}"
PV = "0.0.1+git"
PKGV = "0.0.1+git${GITPKGV}"

DEPENDS = "qtbase qttools qtsvg mono"

SRC_URI = "git://github.com/wolfgangmauer/libqt-mono-sharp.git;protocol=http;branch=main"

S = "${WORKDIR}/git"

do_compile() {
    ${CC} -fPIC -c `pkg-config --cflags Qt5Core Qt5Gui Qt5Widgets Qt5Svg mono-2 glib-2.0` monointernal.cpp 
    ${CC} -fPIC -c `pkg-config --cflags Qt5Core Qt5Gui Qt5Widgets Qt5Svg mono-2 glib-2.0` QGlueAction.cpp
    ${CC} -fPIC -c `pkg-config --cflags Qt5Core Qt5Gui Qt5Widgets Qt5Svg mono-2 glib-2.0` QGlueApplication.cpp
    ${CC} -fPIC -c `pkg-config --cflags Qt5Core Qt5Gui Qt5Widgets Qt5Svg mono-2 glib-2.0` QGlueBoxLayout.cpp
    ${CC} -fPIC -c `pkg-config --cflags Qt5Core Qt5Gui Qt5Widgets Qt5Svg mono-2 glib-2.0` QGlueCheckBox.cpp
    ${CC} -fPIC -c `pkg-config --cflags Qt5Core Qt5Gui Qt5Widgets Qt5Svg mono-2 glib-2.0` QGlueComboBox.cpp
    ${CC} -fPIC -c `pkg-config --cflags Qt5Core Qt5Gui Qt5Widgets Qt5Svg mono-2 glib-2.0` QGlueCommandLinkButton.cpp
    ${CC} -fPIC -c `pkg-config --cflags Qt5Core Qt5Gui Qt5Widgets Qt5Svg mono-2 glib-2.0` QGlueDialog.cpp
    ${CC} -fPIC -c `pkg-config --cflags Qt5Core Qt5Gui Qt5Widgets Qt5Svg mono-2 glib-2.0` QGlueFont.cpp
    ${CC} -fPIC -c `pkg-config --cflags Qt5Core Qt5Gui Qt5Widgets Qt5Svg mono-2 glib-2.0` QGlueFrame.cpp
    ${CC} -fPIC -c `pkg-config --cflags Qt5Core Qt5Gui Qt5Widgets Qt5Svg mono-2 glib-2.0` QGlueGridLayout.cpp
    ${CC} -fPIC -c `pkg-config --cflags Qt5Core Qt5Gui Qt5Widgets Qt5Svg mono-2 glib-2.0` QGlueHBoxLayout.cpp
    ${CC} -fPIC -c `pkg-config --cflags Qt5Core Qt5Gui Qt5Widgets Qt5Svg mono-2 glib-2.0` QGlueLabel.cpp
    ${CC} -fPIC -c `pkg-config --cflags Qt5Core Qt5Gui Qt5Widgets Qt5Svg mono-2 glib-2.0` QGlueLayout.cpp
    ${CC} -fPIC -c `pkg-config --cflags Qt5Core Qt5Gui Qt5Widgets Qt5Svg mono-2 glib-2.0` QGlueListView.cpp
    ${CC} -fPIC -c `pkg-config --cflags Qt5Core Qt5Gui Qt5Widgets Qt5Svg mono-2 glib-2.0` QGlueListWidget.cpp
    ${CC} -fPIC -c `pkg-config --cflags Qt5Core Qt5Gui Qt5Widgets Qt5Svg mono-2 glib-2.0` QGlueMainWindow.cpp
    ${CC} -fPIC -c `pkg-config --cflags Qt5Core Qt5Gui Qt5Widgets Qt5Svg mono-2 glib-2.0` QGlueMenu.cpp
    ${CC} -fPIC -c `pkg-config --cflags Qt5Core Qt5Gui Qt5Widgets Qt5Svg mono-2 glib-2.0` QGlueMenuBar.cpp
    ${CC} -fPIC -c `pkg-config --cflags Qt5Core Qt5Gui Qt5Widgets Qt5Svg mono-2 glib-2.0` QGlueModelIndex.cpp
    ${CC} -fPIC -c `pkg-config --cflags Qt5Core Qt5Gui Qt5Widgets Qt5Svg mono-2 glib-2.0` QGlueObject.cpp
    ${CC} -fPIC -c `pkg-config --cflags Qt5Core Qt5Gui Qt5Widgets Qt5Svg mono-2 glib-2.0` QGlueProgressBar.cpp
    ${CC} -fPIC -c `pkg-config --cflags Qt5Core Qt5Gui Qt5Widgets Qt5Svg mono-2 glib-2.0` QGluePushButton.cpp
    ${CC} -fPIC -c `pkg-config --cflags Qt5Core Qt5Gui Qt5Widgets Qt5Svg mono-2 glib-2.0` QGlueScrollArea.cpp
    ${CC} -fPIC -c `pkg-config --cflags Qt5Core Qt5Gui Qt5Widgets Qt5Svg mono-2 glib-2.0` QGlueSizePolicy.cpp
    ${CC} -fPIC -c `pkg-config --cflags Qt5Core Qt5Gui Qt5Widgets Qt5Svg mono-2 glib-2.0` QGlueStandardItemModel.cpp
    ${CC} -fPIC -c `pkg-config --cflags Qt5Core Qt5Gui Qt5Widgets Qt5Svg mono-2 glib-2.0` QGlueSvgWidget.cpp
    ${CC} -fPIC -c `pkg-config --cflags Qt5Core Qt5Gui Qt5Widgets Qt5Svg mono-2 glib-2.0` QGlueTableView.cpp
    ${CC} -fPIC -c `pkg-config --cflags Qt5Core Qt5Gui Qt5Widgets Qt5Svg mono-2 glib-2.0` QGlueTableWidget.cpp
    ${CC} -fPIC -c `pkg-config --cflags Qt5Core Qt5Gui Qt5Widgets Qt5Svg mono-2 glib-2.0` QGlueToolBar.cpp
    ${CC} -fPIC -c `pkg-config --cflags Qt5Core Qt5Gui Qt5Widgets Qt5Svg mono-2 glib-2.0` QGlueToolButton.cpp
    ${CC} -fPIC -c `pkg-config --cflags Qt5Core Qt5Gui Qt5Widgets Qt5UiTools Qt5Svg mono-2 glib-2.0` QGlueUiLoader.cpp
    ${CC} -fPIC -c `pkg-config --cflags Qt5Core Qt5Gui Qt5Widgets Qt5Svg mono-2 glib-2.0` QGlueVBoxLayout.cpp
    ${CC} -fPIC -c `pkg-config --cflags Qt5Core Qt5Gui Qt5Widgets Qt5Svg mono-2 glib-2.0` QGlueWidget.cpp
    ${CC} -shared -Wl,-soname,libqt_mono-sharp.so.0 -o libqt_mono-sharp.so.0.0.0 `pkg-config --libs Qt5Core Qt5Gui Qt5Widgets Qt5UiTools Qt5Svg mono-2 glib-2.0` monointernal.o QGlueAction.o QGlueApplication.o QGlueBoxLayout.o QGlueHBoxLayout.o QGlueListView.o QGlueListWidget.o QGlueMainWindow.o QGlueMenu.o QGlueMenuBar.o QGlueModelIndex.o QGlueObject.o QGlueProgressBar.o QGluePushButton.o QGlueScrollArea.o QGlueSizePolicy.o QGlueStandardItemModel.o QGlueSvgWidget.o QGlueTableView.o QGlueTableWidget.o QGlueToolBar.o QGlueToolButton.o QGlueVBoxLayout.o QGlueWidget.o
}

do_install() {
	install -d ${D}${libdir}
	install -m 755 libqt_mono-sharp.so.0.0.0 ${D}${libdir}/
	ln -s libqt_mono-sharp.so.0.0.0 ${D}${libdir}/libqt_mono-sharp.so.0
	ln -s libqt_mono-sharp.so.0 ${D}${libdir}/libqt_mono-sharp.so
}

FILES:${PN} = "${libdir}"

INSANE_SKIP:${PN} += "ldflags"
