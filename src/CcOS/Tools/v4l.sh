export LDFLAGS='-L/home/coolcow/git/CameraModul/compiler/arm-2009q3/arm-none-linux-gnueabi/libc/lib -L/home/coolcow/git/CameraModul/src/jpeg-9a/.libs'
export LIBS='-ljpeg'
export CC='/home/coolcow/git/CameraModul/compiler/arm-2009q3/bin/arm-none-linux-gnueabi-gcc -march=armv5te'
export CPPFLAGS=-I/home/coolcow/git/CameraModul/src/jpeg-9a
export CXX='/home/coolcow/git/CameraModul/compiler/arm-2009q3/bin/arm-none-linux-gnueabi-g++'
#export CXXCPP=-I/home/coolcow/git/CameraModul/src/jpeg-9a

export ARCH='ARM'
export CROSS_COMPILE=arm-none-linux-gnueabi-
./configure \
--host arm-linux \
--disable-qv4l2 \
--disable-libdvbv5 \
--disable-v4l-utils 
