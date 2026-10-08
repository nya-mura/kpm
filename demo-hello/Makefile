# ifndef TARGET_COMPILE
#     $(error TARGET_COMPILE not set)
# endif
#
ifndef KP_DIR
    KP_DIR = ../KernelPatch
endif


CC = $(TARGET_COMPILE)clang
LD = $(TARGET_COMPILE)ld

TARGET_TRIPLE := --target=aarch64-linux-gnu

INCLUDE_DIRS := . include patch/include linux/include linux/arch/arm64/include linux/tools/arch/arm64/include

INCLUDE_FLAGS := $(foreach dir,$(INCLUDE_DIRS),-I$(KP_DIR)/kernel/$(dir))

CFLAGS := -O2 -Wall \
          -fno-pic \
          -fno-pie \
          -fno-plt \
          -mcmodel=large \
          -fno-stack-protector \
          -nostdinc \
          -nostdlib

all: hello.kpm

objs := hello.o

all: hello.kpm

hello.kpm: ${objs}
	${CC} $(TARGET_TRIPLE) -r -nostdlib -o $@ $^

%.o: %.c
	${CC} $(CFLAGS) $(INCLUDE_FLAGS) -Thello.lds -c -O2 -o $@ $<

.PHONY: clean
clean:
	rm -rf *.kpm
	find . -name "*.o" | xargs rm -f
