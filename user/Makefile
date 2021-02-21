.DEFAULT_GOAL := ch2

ARCH ?= riscv64
MODE ?= release
src_dir := build/$(ARCH)
bin_dir := build/bin
out_dir := target
cmake_build_args := -DARCH=$(ARCH)
ifeq ($(MODE), release)
cmake_build_args += -DCMAKE_BUILD_TYPE=Release
else ifeq ($(MODE), debug)
cmake_build_args += -DCMAKE_BUILD_TYPE=Debug
endif

OBJCOPY := $(ARCH)-linux-musl-objcopy
OBJDUMP := $(ARCH)-linux-musl-objdump
CP := cp

binary:
	@mkdir -p build
	@cd build && cmake $(cmake_build_args) .. && make -j
	@mkdir -p asm
	@$(CP) build/asm/* asm

CH2_TESTS := ch2 ch2t

ch2: binary
	@rm -rf $(out_dir)
	@mkdir -p $(out_dir)/bin/
	@mkdir -p $(out_dir)/elf/
	@$(foreach t, $(CH2_TESTS), cp $(bin_dir)/$(t)_*.bin $(out_dir)/bin/;)
	@$(foreach t, $(CH2_TESTS), cp $(src_dir)/$(t)_* $(out_dir)/elf/;)

clean:
	@rm -rf build target asm