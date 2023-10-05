PROGRAM = ../src/prom.mem

VERILATOR = verilator

LDFLAGS := -LDFLAGS "$(shell sdl2-config --libs)"
CFLAGS := -CFLAGS "$(shell sdl2-config --cflags)"

SRC = RS232R.v \
	bram32bit.v \
	mousem.v \
	PROM.v \
	RS232T.v \
	bram_true2p_2clk.v \
	PS2.v SPI.v cache_controller.v \
	sdram.v \
	RISCVTop.OStation.v \
	VID.OStation.v \
	vqueue.v \
	alu.sv \
	multiplier.v \
	divider.v \
	decoder.sv \
	processor.sv \
	register_file.sv	

all: sim

clean:
	rm -rf obj_dir

sim: top.sv sim_main.cpp $(PROGRAM)
	cp $(PROGRAM) prom.mem
	$(VERILATOR) -cc --exe $(CFLAGS) $(LDFLAGS) --top-module top $(XOSERA_SRC) top.sv sdl_ps2.cpp sim_main.cpp -I../hdl $(SRC) -Wno-PINMISSING -Wno-WIDTH -Wno-CASEINCOMPLETE -Wno-TIMESCALEMOD -Wno-NULLPORT -Wno-MULTIDRIVEN
	$(MAKE) -j 4 -C obj_dir -f Vtop.mk

run: sim
	cp ../src/*.mem .
	obj_dir/Vtop

.PHONY: all clean
