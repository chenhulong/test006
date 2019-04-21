ifndef CROSS_COMPILE
$(error please back to top dir to make)
endif

SRCS =	database.c   \
		graphic.c    \
       	windows.c    \
		window.c     \
		ui_common.c  \
       	ui_general.c \
       	ui_dvb.c     \
       	ui_tuner.c   \
       	ui_panel.c   \
       	ui_update.c  \
       	ui_main.c    \
       	main.c


OBJS = $(SRCS:%.c=%.o)

FT_TARGET=factorytest

.PHONY:all
all:$(FT_TARGET)

$(FT_TARGET): $(SRCS)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
	mv $(FT_TARGET) $(IMG_DIR)/$(FT_TARGET)


.PHONY:clean
clean:
	-rm -f *.o
	-rm -f $(IMG_DIR)/$(FT_TARGET)
