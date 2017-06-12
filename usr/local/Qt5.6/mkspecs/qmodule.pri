CONFIG +=  cross_compile compile_examples qpa largefile pcre
QT_BUILD_PARTS += libs
QT_NO_DEFINES =  ALSA CUPS DBUS EGL EGLFS EGL_X11 EVENTFD FONTCONFIG GLIB IMAGEFORMAT_JPEG LIBPROXY NIS OPENGL OPENSSL OPENVG PULSEAUDIO SSL STYLE_GTK XRENDER
QT_QCONFIG_PATH = 
host_build {
    QT_CPU_FEATURES.x86_64 =  mmx sse sse2
} else {
    QT_CPU_FEATURES.arm = 
}
QT_COORD_TYPE = float
QT_LFLAGS_ODBC   = -lodbc
styles += mac fusion windows
DEFINES += QT_NO_MTDEV
DEFINES += QT_NO_LIBUDEV
DEFINES += QT_NO_LIBINPUT
QMAKE_X11_PREFIX = /usr
INCLUDEPATH +=  "/usr/local/tslib/include"
LIBS +=  -L"/usr/local/tslib/lib"
sql-drivers = 
sql-plugins =  sqlite
