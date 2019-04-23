/* Verilog netlist generated by SCUBA Diamond (64-bit) 3.9.1.119 */
/* Module Version: 5.7 */
/* C:\lscc\diamond\3.9_x64\ispfpga\bin\nt64\scuba.exe -w -n dcm -lang verilog -synth synplify -bus_exp 7 -bb -arch sa5p00 -type pll -fin 25.00 -fclkop 25 -fclkop_tol 2.0 -fclkos 25 -fclkos_tol 2.0 -phases 0 -fclkos2 100 -fclkos2_tol 10.0 -phases2 0 -fclkos3 100 -fclkos3_tol 10.0 -phases3 225 -phase_cntl STATIC -fb_mode 1 -fdc C:/lscc/diamond/3.9_x64/examples/Oberon_SDRAM/dcm/dcm.fdc  */
/* Wed Feb 21 23:44:26 2018 */


`timescale 1 ns / 1 ps
module dcm (CLKI, CLKOP, CLKOS, CLKOS2, CLKOS3)/* synthesis NGD_DRC_MASK=1 */;
    input wire CLKI;
    output wire CLKOP;
    output wire CLKOS;
    output wire CLKOS2;
    output wire CLKOS3;

    wire REFCLK;
    wire LOCK;
    wire CLKOS3_t;
    wire CLKOS2_t;
    wire CLKOS_t;
    wire CLKOP_t;
    wire scuba_vhi;
    wire scuba_vlo;

    VHI scuba_vhi_inst (.Z(scuba_vhi));

    VLO scuba_vlo_inst (.Z(scuba_vlo));

    defparam PLLInst_0.PLLRST_ENA = "DISABLED" ;
    defparam PLLInst_0.INTFB_WAKE = "DISABLED" ;
    defparam PLLInst_0.STDBY_ENABLE = "DISABLED" ;
    defparam PLLInst_0.DPHASE_SOURCE = "DISABLED" ;
    defparam PLLInst_0.CLKOS3_FPHASE = 6 ;
    defparam PLLInst_0.CLKOS3_CPHASE = 8 ;
    defparam PLLInst_0.CLKOS2_FPHASE = 0 ;
    defparam PLLInst_0.CLKOS2_CPHASE = 5 ;
    defparam PLLInst_0.CLKOS_FPHASE = 0 ;
    defparam PLLInst_0.CLKOS_CPHASE = 23 ;
    defparam PLLInst_0.CLKOP_FPHASE = 0 ;
    defparam PLLInst_0.CLKOP_CPHASE = 23 ;
    defparam PLLInst_0.PLL_LOCK_MODE = 0 ;
    defparam PLLInst_0.CLKOS_TRIM_DELAY = 0 ;
    defparam PLLInst_0.CLKOS_TRIM_POL = "FALLING" ;
    defparam PLLInst_0.CLKOP_TRIM_DELAY = 0 ;
    defparam PLLInst_0.CLKOP_TRIM_POL = "FALLING" ;
    defparam PLLInst_0.OUTDIVIDER_MUXD = "DIVD" ;
    defparam PLLInst_0.CLKOS3_ENABLE = "ENABLED" ;
    defparam PLLInst_0.OUTDIVIDER_MUXC = "DIVC" ;
    defparam PLLInst_0.CLKOS2_ENABLE = "ENABLED" ;
    defparam PLLInst_0.OUTDIVIDER_MUXB = "DIVB" ;
    defparam PLLInst_0.CLKOS_ENABLE = "ENABLED" ;
    defparam PLLInst_0.OUTDIVIDER_MUXA = "DIVA" ;
    defparam PLLInst_0.CLKOP_ENABLE = "ENABLED" ;
    defparam PLLInst_0.CLKOS3_DIV = 6 ;
    defparam PLLInst_0.CLKOS2_DIV = 6 ;
    defparam PLLInst_0.CLKOS_DIV = 24 ;
    defparam PLLInst_0.CLKOP_DIV = 24 ;
    defparam PLLInst_0.CLKFB_DIV = 1 ;
    defparam PLLInst_0.CLKI_DIV = 1 ;
    defparam PLLInst_0.FEEDBK_PATH = "CLKOP" ;
    EHXPLLL PLLInst_0 (.CLKI(CLKI), .CLKFB(CLKOP_t), .PHASESEL1(scuba_vlo), 
        .PHASESEL0(scuba_vlo), .PHASEDIR(scuba_vlo), .PHASESTEP(scuba_vlo), 
        .PHASELOADREG(scuba_vlo), .STDBY(scuba_vlo), .PLLWAKESYNC(scuba_vlo), 
        .RST(scuba_vlo), .ENCLKOP(scuba_vlo), .ENCLKOS(scuba_vlo), .ENCLKOS2(scuba_vlo), 
        .ENCLKOS3(scuba_vlo), .CLKOP(CLKOP_t), .CLKOS(CLKOS_t), .CLKOS2(CLKOS2_t), 
        .CLKOS3(CLKOS3_t), .LOCK(LOCK), .INTLOCK(), .REFCLK(REFCLK), .CLKINTFB())
             /* synthesis FREQUENCY_PIN_CLKOS3="100.000000" */
             /* synthesis FREQUENCY_PIN_CLKOS2="100.000000" */
             /* synthesis FREQUENCY_PIN_CLKOS="25.000000" */
             /* synthesis FREQUENCY_PIN_CLKOP="25.000000" */
             /* synthesis FREQUENCY_PIN_CLKI="25.000000" */
             /* synthesis ICP_CURRENT="5" */
             /* synthesis LPF_RESISTOR="16" */;

    assign CLKOS3 = CLKOS3_t;
    assign CLKOS2 = CLKOS2_t;
    assign CLKOS = CLKOS_t;
    assign CLKOP = CLKOP_t;


    // exemplar begin
    // exemplar attribute PLLInst_0 FREQUENCY_PIN_CLKOS3 100.000000
    // exemplar attribute PLLInst_0 FREQUENCY_PIN_CLKOS2 100.000000
    // exemplar attribute PLLInst_0 FREQUENCY_PIN_CLKOS 25.000000
    // exemplar attribute PLLInst_0 FREQUENCY_PIN_CLKOP 25.000000
    // exemplar attribute PLLInst_0 FREQUENCY_PIN_CLKI 25.000000
    // exemplar attribute PLLInst_0 ICP_CURRENT 5
    // exemplar attribute PLLInst_0 LPF_RESISTOR 16
    // exemplar end

endmodule
