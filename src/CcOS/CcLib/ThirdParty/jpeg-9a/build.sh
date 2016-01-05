export LDFLAGS='-L/home/coolcow/git/CameraModul/compiler/arm-2009q3/arm-none-linux-gnueabi/libc/lib'
export CC='/home/coolcow/git/CameraModul/compiler/arm-2009q3/bin/arm-none-linux-gnueabi-gcc -march=armv5te'
export CXX='/home/coolcow/git/CameraModul/compiler/arm-2009q3/bin/arm-none-linux-gnueabi-g++'
export ARCH='ARM'
export CROSS_COMPILE=arm-none-linux-gnueabi-
./configure \
--host arm-linux
