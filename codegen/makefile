#!/usr/bin/make -sf
## makefile
##
## Copyright 2016 Mac Radigan
## All Rights Reserved

.PHONY: generate clean 
.DEFAULT_GOAL := all

all: generate

root = .
#out = $(root)/codegen-out
out = $(root)/..
dox_home = ../submodules/dox

clean:
	rm -Rf $(out)

generate:
	mkdir -p $(out)
	env PYTHONPATH=$(dox_home)/library       \
	  python3 $(dox_home)/dox.py             \
	    -v                                   \
	    -f                                   \
	    -g ./generator/pi.py                 \
	    -I ./include                         \
	    -t ./template                        \
	    -o $(out)

## *EOF*
