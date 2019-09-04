#!/bin/bash

set -e

# only link libraries we actually use
export GSL_LIBS="-L${PREFIX}/lib -lgsl"

./configure \
	--prefix="${PREFIX}" \
	--enable-help2man \
	--enable-swig-iface \
	--disable-swig-octave \
	--disable-swig-python \
	--disable-python \
	--enable-silent-rules
make -j ${CPU_COUNT}
make -j ${CPU_COUNT} check
make install
