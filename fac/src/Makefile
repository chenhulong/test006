ifndef CROSS_COMPILE
$(error please back to top dir to make)
endif

LIB_STATIC = libhi_adp.a


SRCS = hi_adp.c        	\
       hi_adp_osd.c    	\
       hi_adp_tuner.c  	\
       hi_adp_uio.c    	\
       hi_adp_hdmi.c   	\
       hi_adp_search.c 	\
       hi_adp_data.c   	\
       hi_adp_demux.c  	\
       hi_adp_eth.c     \
       hi_adp_mpi.c 
#       hi_adp_audio.c  	\

OBJS = $(SRCS:%.c=%.o)

.PHONY:all
all:$(OBJS) $(LIB_STATIC)

$(LIB_STATIC):$(OBJS)
	$(AR) -rc $(LIB_STATIC) $(OBJS)
	-mv $(LIB_STATIC) $(LIB_DIR)


#$<代表所有的依赖目标集(.c)
#$@代表所以的目标集(.o)
$(OBJS): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY:clean
clean:
	-rm -rf *.o
	-rm -f $(LIB_DIR)/$(LIB_STATIC)



