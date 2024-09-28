SUMMARY = "libray for mono and qt-mono-sharp"
SECTION = "base"
PRIORITY = "optional"
LICENSE = "PD"
LIC_FILES_CHKSUM = "file://monointernal.cpp;firstline=1;endline=1;md5=4e4f8c406c33d91df4a0552f2cdc65fd"

SRC_URI[sha256sum] = "c3573b6d25ea729252e825264fef45ee0375c540f0cd97075979367ed729cc29"

PV = "1.0"

PROVIDES =+ " libqt-mono-sharp"
PACKAGES =+ " libqt-mono-sharp"

inherit pkgconfig
#inherit gitpkgv

SRCREV = "${AUTOREV}"
PV = "0.0.1+git"
PKGV = "0.0.1+git${GITPKGV}"

DEPENDS = "qtbase qttools qtsvg mono"

SRC_URI = "git://github.com/wolfgangmauer/libqt-mono-sharp.git;protocol=http;branch=main"

S = "${WORKDIR}/git"

do_compile() {
    ${CC} -fPIC -shared -Wl,-soname,libqt-mono-sharp.so.0 -o libqt-mono-sharp.so.0.0.0 `pkg-config --cflags --libs Qt5Core Qt5Gui Qt5Widgets Qt5UiTools Qt5Svg mono-2 glib-2.0` monointernal.cpp QGlueAction.cpp QGlueApplication.cpp QGlueBoxLayout.cpp QGlueHBoxLayout.cpp QGlueListView.cpp QGlueListWidget.cpp QGlueMainWindow.cpp QGlueMenu.cpp QGlueMenuBar.cpp QGlueModelIndex.cpp QGlueObject.cpp QGlueProgressBar.cpp QGluePushButton.cpp QGlueScrollArea.cpp QGlueSizePolicy.cpp QGlueStandardItemModel.cpp QGlueSvgWidget.cpp QGlueTableView.cpp QGlueTableWidget.cpp QGlueToolBar.cpp QGlueToolButton.cpp QGlueVBoxLayout.cpp QGlueWidget.cpp
}

do_install() {
	install -d ${D}${libdir}
	install -m 755 libqt-mono-sharp.so.0.0.0 ${D}${libdir}/
	ln -s libqt-mono-sharp.so.0.0.0 ${D}${libdir}/libqt-mono-sharp.so.0
	ln -s libqt-mono-sharp.so.0 ${D}${libdir}/libqt-mono-sharp.so
}

FILES:${PN} = "${libdir}"

INSANE_SKIP:${PN} += "ldflags"
