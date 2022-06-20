project = uri
summary = C++ wrapper for the uriparser C library

STD = c++20

library = lib$(project)
$(library).type = shared
$(library).libs = uriparser

install := $(library)
targets := $(install)

install.directories = $(include)/$(project)

files = $(include) $(src) Makefile VERSION

include mkbuild/base.mk
