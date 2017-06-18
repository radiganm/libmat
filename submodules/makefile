#!/usr/bin/make -f
## makefile
## Copyright 2016 Mac Radigan
## All Rights Reserved

.PHONY: submodules clean clobber dox dispmodule pre-install post-install update
.DEFAULT_GOAL := post-install

post-install: submodules
	(mkdir -p ../mod; cd ../mod; ln -fs ../submodules/dispmodule/mod/*.mod .)

submodules: dispmodule

dispmodule:
	$(MAKE) -C dispmodule

update:
	git submodule init && git submodule update --recursive --remote

pre-install:

dox:
	$(MAKE) -C $@

clean:

clobber: clean

## *EOF*
