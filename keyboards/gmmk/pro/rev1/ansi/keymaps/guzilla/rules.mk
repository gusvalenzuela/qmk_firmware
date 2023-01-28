VIA_ENABLE = no

DEBOUNCE_TYPE = asym_eager_defer_pk

CONSOLE_ENABLE = yes
COMMAND_ENABLE = yes
RAW_ENABLE = no

RGB_MATRIX_LEDMAPS = yes
UNICODEMAP_ENABLE = yes

WPM_ENABLE = yes
MIDI_ENABLE=yes

# Disabling MouseKey to avoid KVM switch issues
MOUSEKEY_ENABLE = no

COMBO_ENABLE = yes
TAP_DANCE_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes

SRC += utils.c
SRC += guzilla.c
SRC += process_record.c
SRC += encoder.c

ifeq ($(strip $(WPM_ENABLE)), yes)
	SRC += fun.c
endif

ifeq ($(strip $(RGB_MATRIX_LEDMAPS)), yes)
	SRC += rgb_matrix_ledmaps.c
	OPT_DEFS += -DRGB_MATRIX_LEDMAPS_ENABLED
endif
