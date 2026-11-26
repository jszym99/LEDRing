MCU = attiny84a
F_CPU = 8000000UL

# Define the programmer
PROGRAMMER = usbasp

# Define the compiler and flags
CC = avr-gcc
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall $(INCLUDES)

# Define the linker and flags
LDFLAGS = -mmcu=$(MCU)

# Define the avrdude program and flags
AVRDUDE = avrdude
AVRDUDE_FLAGS = -c $(PROGRAMMER) -p t84

#=============================================================================#
# project configuration
#=============================================================================#
DRIVER_DIR = drivers
LIB_DIR = lib
MODULE_DIR = modules

PROJECT = LED_Ring
BUILD_DIR = build

#=============================================================================#
# source files configuration
#=============================================================================#

DRIVERS := $(patsubst %/., %, $(wildcard $(DRIVER_DIR)/*/.))
LIBS := $(patsubst %/., %, $(wildcard $(LIB_DIR)/*/.))
MODULES := $(patsubst %/., %, $(wildcard $(MODULE_DIR)/*/.))

SRCS_DIRS = $(DRIVERS) $(LIBS) $(MODULES)
INC_DIRS = $(DRIVERS) $(LIBS) $(MODULES)

SOURCES   = $(wildcard $(patsubst %, %/*.c, . $(SRCS_DIRS)))

OBJ_DIR = $(BUILD_DIR)/obj

OBJECTS   = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(basename $(SOURCES))))
DEPS   	  = $(addprefix $(OBJ_DIR)/, $(addsuffix .d, $(basename $(SOURCES))))

INCLUDES = $(addprefix -I, $(INC_DIRS))


SRC = $(SOURCES)#main.c $(wildcard drivers/*/*.c)
OBJ = $(patsubst %.c, build/%.o, $(SOURCES))
TARGET = build/$(PROJECT)

# Create the build directory if it doesn't exist
MKDIR_P = mkdir -p

# Compile and link
all: $(TARGET).hex

$(TARGET).hex: $(TARGET).elf
	@avr-objcopy -O ihex -R .eeprom $< $@

$(TARGET).elf: $(OBJECTS)
	@$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# Flash the microcontroller
flash: $(TARGET).hex
	@$(AVRDUDE) $(AVRDUDE_FLAGS) -U flash:w:$<

# Clean up build files
clean:
	rm -f $(OBJECTS) $(TARGET).elf $(TARGET).hex

.PHONY: all flash clean
