#configuration
CONFIG +=  cross_compile shared qpa no_mocdepend release qt_no_framework
host_build {
    QT_ARCH = x86_64
    QT_TARGET_ARCH = arm
} else {
    QT_ARCH = arm
    QMAKE_DEFAULT_LIBDIRS = /usr/local/arm/4.3.2/lib/gcc/arm-none-linux-gnueabi/4.3.2/armv4t /usr/local/arm/4.3.2/arm-none-linux-gnueabi/lib/armv4t /usr/local/arm/4.3.2/lib/gcc/arm-none-linux-gnueabi/4.3.2 /usr/local/arm/4.3.2/lib/gcc /usr/local/arm/4.3.2/arm-none-linux-gnueabi/lib /usr/local/arm/4.3.2/arm-none-linux-gnueabi/libc/armv4t/lib /usr/local/arm/4.3.2/arm-none-linux-gnueabi/libc/armv4t/usr/lib
    QMAKE_DEFAULT_INCDIRS = /usr/local/arm/4.3.2/arm-none-linux-gnueabi/include/c++/4.3.2 /usr/local/arm/4.3.2/arm-none-linux-gnueabi/include/c++/4.3.2/arm-none-linux-gnueabi/armv4t /usr/local/arm/4.3.2/arm-none-linux-gnueabi/include/c++/4.3.2/backward /usr/local/arm/4.3.2/lib/gcc/arm-none-linux-gnueabi/4.3.2/include /usr/local/arm/4.3.2/lib/gcc/arm-none-linux-gnueabi/4.3.2/include-fixed /usr/local/arm/4.3.2/arm-none-linux-gnueabi/include /usr/local/arm/4.3.2/arm-none-linux-gnueabi/libc/usr/include
}
QT_CONFIG +=  minimal-config small-config medium-config large-config full-config no-pkg-config evdev tslib linuxfb accessibility shared qpa reduce_exports clock-gettime clock-monotonic posix_fallocate mremap getaddrinfo ipv6ifname getifaddrs inotify png no-gif freetype harfbuzz zlib iconv concurrent audio-backend release

#versioning
QT_VERSION = 5.6.0
QT_MAJOR_VERSION = 5
QT_MINOR_VERSION = 6
QT_PATCH_VERSION = 0

#namespaces
QT_LIBINFIX = 
QT_NAMESPACE = 

QT_EDITION = OpenSource

QT_COMPILER_STDCXX = 
QT_GCC_MAJOR_VERSION = 4
QT_GCC_MINOR_VERSION = 3
QT_GCC_PATCH_VERSION = 2
