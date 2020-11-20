BOARD := attinyx4opti
BOARD_CHIP := 84
BOARD_CLOCK := 8internal
TERMINAL_SPEED := 9600

ifeq ($(DEBUG),1)
CPPFLAGS = -DDEBUG=$(DEBUG)
endif

-include tiny.mk
