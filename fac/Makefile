#PD16-factory test makefile
ifndef CROSS_COMPILE
$(error please config CROSS_COMPILE)
endif

PWD = $(shell pwd)
CC=$(CROSS_COMPILE)gcc
AR=$(CROSS_COMPILE)ar 

export CC AR  

INC_DIR = $(PWD)/inc
SRC_DIR = $(PWD)/src
LIB_DIR = $(PWD)/lib
IMG_DIR = $(PWD)/image

CFLAGS += -Wall
CFLAGS += -I $(INC_DIR) -march=armv7-a -mcpu=cortex-a9 -mfloat-abi=softfp -mfpu=vfpv3-d16

#CFLAGS += -Wall -g -march=armv7-a -mcpu=cortex-a9 -mfloat-abi=softfp -mfpu=vfpv3-d16
#CFLAGS += -D_GNU_SOURCE -D_XOPEN_SOURCE=600 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64

ifeq ($(STATIC_LIB), y)
LDFLAGS += -L $(LIB_DIR) -static \
	   -Wl,--start-group -lpthread -lrt \
	   -ldl -lhiflash -lm -lhi_common -lhi_mpi -lhi_ecs -lhigo -lhigoadp \
	   -lfreetype -ltde -lhipng -lhipes -lz -lhijpeg -lhijpegenc -lhi_adp\
	   -lhi_advca -lstbinfo\
	   -Wl,--end-group
else
LDFLAGS += -L $(LIB_DIR) \
	   -Wl,--start-group -lpthread -lrt \
	   -ldl -lhiflash -lm -lhi_common -lhi_mpi -lhi_ecs -lhigo -lhigoadp \
	   -lfreetype -ltde -lhipng -lhipes -lz -lhijpeg -lhijpegenc -lhi_adp\
	   -lhi_advca -lstbinfo\
	   -Wl,--end-group  
endif





#LDFLAGS += -L$(LIB_DIR) \
#	-Wl,--start-group \
#	-lhiadp	\
#	-lpthread -lrt \
#	-Wl,--end-group

export CFLAGS LDFLAGS SRC_DIR INC_DIR LIB_DIR IMG_DIR

#make all
.PHONY:all
all: src prj

#make src files and build libhiadp.a
.PHONY:src
src:
	@echo "Building src, wait..."
	make -C src all
	@echo "Done!"


#make prj files and build factorytest
.PHONY:prj
prj:
	@echo "Building prj, wait..."
	make -C prj all
	@echo "Done!"


#make clean
.PHONY:clean	
clean: src_clean prj_clean

#make src clean
.PHONY:src_clean
src_clean:
	@make -C src clean

#make prj clean
.PHONY:prj_clean	
prj_clean:
	make -C prj clean
