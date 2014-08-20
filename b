#!/bin/sh

#set -x

SOURCE_DIR=`pwd`
BUILD_DIR=${BUILD_DIR:-build}
BUILD_TYPE=${BUILD_TYPE:-debug}
INSTALL_DIR=${INSTALL_DIR:-${BUILD_TYPE}-install}
BUILD_NO_EXAMPLES=${BUILD_NO_EXAMPLES:-0}

CPU_CNT=`cat /proc/cpuinfo | grep processor | grep -v grep | wc -l`
CPU_CNT=1

if [ `uname -m`j = "x86_64"j ] ; then
	OS_BITS=64
else
	OS_BITS=32
fi

		mkdir -p $BUILD_DIR/$BUILD_TYPE											\
	&&	cd $BUILD_DIR/$BUILD_TYPE												\
	&&	cmake	-DCMAKE_BUILD_TYPE=$BUILD_TYPE									\
				-DCMAKE_BUILD_NO_EXAMPLES=$BUILD_NO_EXAMPLES					\
				-DCMAKE_INSTALL_PREFIX=$INSTALL_DIR								\
				-DCMAKE_BUILD_BITS=${OS_BITS}									\
				$SOURCE_DIR														\
	&&	make -j${CPU_CNT}														\

