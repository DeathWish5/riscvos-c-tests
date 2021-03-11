ARCH ?= riscv64
MODE ?= release
CHAPTER ?=
src_dir := build/$(ARCH)
bin_dir := build/bin
out_dir := target
cmake_build_args := -DARCH=$(ARCH) -DCHAPTER=$(CHAPTER)
ifeq ($(MODE), release)
cmake_build_args += -DCMAKE_BUILD_TYPE=Release
else ifeq ($(MODE), debug)
cmake_build_args += -DCMAKE_BUILD_TYPE=Debug
endif

OBJCOPY := $(ARCH)-linux-musl-objcopy
OBJDUMP := $(ARCH)-linux-musl-objdump
CP := cp
CH_TESTS :=  

binary:
	@mkdir -p build
	@cd build && cmake $(cmake_build_args) .. && make
	@mkdir -p asm
	@$(CP) build/asm/* asm

pre:
	@rm -rf $(out_dir)
	@mkdir -p $(out_dir)/bin/
	@mkdir -p $(out_dir)/elf/

CH2_TESTS := ch2 ch2t
CH3_TESTS_BASE := $(CH2_TESTS) ch3_0 ch3t
CH4_TESTS := ch2 ch3_0 ch4
CH5_TESTS := $(CH4_TESTS) ch5
CH6_TESTS := $(CH5_TESTS) ch6
CH7_TESTS := $(CH6_TESTS) ch7

ifeq ($(CHAPTER), 2)
	CH_TESTS += $(CH2_TESTS)
else ifeq ($(CHAPTER), 3_0)
	CH_TESTS += $(CH3_TESTS_BASE)
else ifeq ($(CHAPTER), 3_1)
	CH_TESTS += ch3_1
else ifeq ($(CHAPTER), 3_2)
	CH_TESTS += ch3_2
else ifeq ($(CHAPTER), 4)
	CH_TESTS += $(CH4_TESTS)
else ifeq ($(CHAPTER), 5)
	CH_TESTS += $(CH5_TESTS)
else ifeq ($(CHAPTER), 6)
	CH_TESTS += $(CH6_TESTS)
else ifeq ($(CHAPTER), 7)
	CH_TESTS += $(CH7_TESTS)
endif

all: binary pre
	@$(foreach t, $(CH_TESTS), cp $(bin_dir)/$(t)* $(out_dir)/bin/;)
	@$(foreach t, $(CH_TESTS), cp $(src_dir)/$(t)* $(out_dir)/elf/;)

clean:
	@rm -rf build target asm
