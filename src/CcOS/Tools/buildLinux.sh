# defines
linuxVersion="3.4.35"
file="linux-$linuxVersion.tar.gz"
folder="linux-$linuxVersion"

# rm old build
rm -Rf linux
rm -Rf $folder

# Extract the Kernel
if [ -f "$file" ]
then
	echo "Kernel Source found."
else
	echo "Download Kernel Source."
	wget "https://www.kernel.org/pub/linux/kernel/v3.x/$file"
fi
# Build the required Kernel for target image
tar -xpzf $file -C ./
mv linux-$linuxVersion linux
#cd linux
#cp ../KernelConfig-$li#nuxVersion .config
#export CFLAGS=”-mthumb”#
#export TOOLCHAIN=/toolchain/usr
#export PATH=$PATH:$TOOLCHAIN/bin
#export CC='arm-buildroot-linux-uclibcgnueabihf-gcc -march=armv7'
#export CROSS_COMPILE=arm-buildroot-linux-uclibcgnueabihf-
#make ARCH=arm olddefconfig
#make ARCH=arm CROSS_COMPILE=$CROSS_COMPILE
#cd ..

#echo "Kernel build" >> linuxKernelReady


