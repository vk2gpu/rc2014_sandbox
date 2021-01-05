
#CFLAGS = -compiler=sdcc

BTC = ./tools/btc
UPLOAD = ./tools/rc2014-upload.py
TTY_PORT = /dev/ttyACM0

all: hello.com

hello.com: ./src/hello.c
	zcc +cpm -vn $(CFLAGS) -O3 -DWILDCARD ./src/hello.c -create-app -ohello.bin
	$(BTC) HELLO.COM -u1 > HELLO.HEX
	$(UPLOAD) HELLO.HEX > $(TTY_PORT)

clean:
	$(RM) *.com *.i *.asm *.tap *.op* *.o *~ zcc_opt.def *.COM *.HEX *.bin *.def

