# Project Name
TARGET = DemoProject1

# Sources
CPP_SOURCES = DemoProject1.cpp

# Library Locations
LIBDAISY_DIR = ../DaisyExamples~/libDaisy/
DAISYSP_DIR = ../DaisyExamples~/DaisySP/

# Core location, and generic Makefile.
SYSTEM_FILES_DIR = $(LIBDAISY_DIR)/core
include $(SYSTEM_FILES_DIR)/Makefile
