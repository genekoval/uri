project = uri
summary = C++ wrapper for the uriparser C library

STD = c++20

library = lib$(project)
$(library).type = shared
define library.libs
 uriparser
endef

install := $(library)
targets := $(install)

include mkbuild/base.mk
