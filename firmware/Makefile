# SDCC compiler name and path.
SDCC=sdcc
# MCU part number.
MCU_NUMBER=STM8S005C6
# MCU clock frequency
FREQ=2000000UL

# STM8 flash utility name and path.
FLASH=stm8flash
# Name of the STM8 programming device.
PROGRAMMER=stlinkv2
# MCU ID for flash utility.
MCU=stm8s005?6

# Linker parameters.
LDFLAGS=--out-fmt-ihx
# Compiler parameters.
CFLAGS=-D $(MCU_NUMBER) -D F_CPU=$(FREQ) -D INLINE_DELAY -D DEBUG_MSG

# Name of the object files.
OBJ=test-port.rel
# Name of the output file.
TARGET=test.ihx
# Name of the fuse configuration file.
FUSE=fuse.bin

# Common object files for STM8 MCU series.     
STD_OBJECTS=util/stm8-systick.rel net/drivers/enc28j60/enc28j60.rel net/drivers/ethernet.rel net/drivers/ipstack.rel \
			net/ethutil.rel net/drivers/dhcp.rel \
			util/stm8-util.rel util/stm8-spi.rel util/stm8-uart.rel util/stm8-dbglog.rel util/stm8-adc.rel

OBJECTS= $(STD_OBJECTS) $(OBJ)

MAP=$(TARGET:.ihx=.map)
LK=$(TARGET:.ihx=.lk)
CDB=$(TARGET:.ihx=.cdb)

SYMBOLS=$(notdir $(OBJECTS:.rel=.sym))
ASMS=$(notdir $(OBJECTS:.rel=.asm))
LISTS=$(notdir $(OBJECTS:.rel=.lst))
RSTS=$(notdir $(OBJECTS:.rel=.rst))

all: $(TARGET)

%.rel: %.c
	$(SDCC) -mstm8 -lstm8 $(CFLAGS) -c $<

$(TARGET): $(OBJECTS)
	$(SDCC) -mstm8 -lstm8 $(LDFLAGS) -o $@ $(notdir $(OBJECTS))

clean:
	rm -f $(notdir $(OBJECTS))
	rm -f $(MAP)
	rm -f $(LK)
	rm -f $(CDB)
	rm -f $(SYMBOLS)
	rm -f $(ASMS)
	rm -f $(LISTS)
	rm -f $(RSTS)
	rm -f $(TARGET)

flash: $(TARGET)
	$(FLASH) -c $(PROGRAMMER) -p $(MCU) -s flash -w $(TARGET)

fuse:
	echo "00 00 FF 80 7F 00 FF 00 FF 00 FF 00 FF 00 FF 00 FF" | xxd -r -p > $(FUSE)

flash-fuse:
	$(FLASH) -c $(PROGRAMMER) -p $(MCU) -s opt -w $(FUSE)
