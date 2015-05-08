#
# Makefile for led stuff
#

include $(TOPDIR)/config.mk

LIB   = libperipheral.a
OBJS += led.o
OBJS += wps.o
OBJS += oled.o

all:    $(LIB)
$(LIB): $(START) $(OBJS)
	    $(AR) crv $@ $(OBJS)

#########################################################################

.depend: Makefile $(OBJS:.o=.c)
	     $(CC) -M $(CFLAGS) $(OBJS:.o=.c) > $@

sinclude .depend

#########################################################################

