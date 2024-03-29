-- ==============================================================
-- RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
-- Version: 2019.1
-- Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
-- 
-- ===========================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity multiply_matrices is
port (
    ap_clk : IN STD_LOGIC;
    ap_rst : IN STD_LOGIC;
    ap_start : IN STD_LOGIC;
    ap_done : OUT STD_LOGIC;
    ap_idle : OUT STD_LOGIC;
    ap_ready : OUT STD_LOGIC;
    n : IN STD_LOGIC_VECTOR (15 downto 0);
    a_address0 : OUT STD_LOGIC_VECTOR (6 downto 0);
    a_ce0 : OUT STD_LOGIC;
    a_q0 : IN STD_LOGIC_VECTOR (15 downto 0);
    b_address0 : OUT STD_LOGIC_VECTOR (6 downto 0);
    b_ce0 : OUT STD_LOGIC;
    b_q0 : IN STD_LOGIC_VECTOR (15 downto 0);
    c_address0 : OUT STD_LOGIC_VECTOR (6 downto 0);
    c_ce0 : OUT STD_LOGIC;
    c_we0 : OUT STD_LOGIC;
    c_d0 : OUT STD_LOGIC_VECTOR (15 downto 0) );
end;


architecture behav of multiply_matrices is 
    attribute CORE_GENERATION_INFO : STRING;
    attribute CORE_GENERATION_INFO of behav : architecture is
    "multiply_matrices,hls_ip_2019_1,{HLS_INPUT_TYPE=c,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xc7a100t-csg324-1,HLS_INPUT_CLOCK=10.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=7.180000,HLS_SYN_LAT=-1,HLS_SYN_TPT=none,HLS_SYN_MEM=0,HLS_SYN_DSP=1,HLS_SYN_FF=111,HLS_SYN_LUT=282,HLS_VERSION=2019_1}";
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_const_logic_0 : STD_LOGIC := '0';
    constant ap_ST_fsm_state1 : STD_LOGIC_VECTOR (5 downto 0) := "000001";
    constant ap_ST_fsm_state2 : STD_LOGIC_VECTOR (5 downto 0) := "000010";
    constant ap_ST_fsm_state3 : STD_LOGIC_VECTOR (5 downto 0) := "000100";
    constant ap_ST_fsm_state4 : STD_LOGIC_VECTOR (5 downto 0) := "001000";
    constant ap_ST_fsm_state5 : STD_LOGIC_VECTOR (5 downto 0) := "010000";
    constant ap_ST_fsm_state6 : STD_LOGIC_VECTOR (5 downto 0) := "100000";
    constant ap_const_lv32_0 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000000";
    constant ap_const_lv1_1 : STD_LOGIC_VECTOR (0 downto 0) := "1";
    constant ap_const_lv32_1 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000001";
    constant ap_const_lv1_0 : STD_LOGIC_VECTOR (0 downto 0) := "0";
    constant ap_const_lv32_2 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000010";
    constant ap_const_lv32_3 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000011";
    constant ap_const_lv32_4 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000100";
    constant ap_const_lv32_5 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000101";
    constant ap_const_lv4_0 : STD_LOGIC_VECTOR (3 downto 0) := "0000";
    constant ap_const_lv16_0 : STD_LOGIC_VECTOR (15 downto 0) := "0000000000000000";
    constant ap_const_lv7_0 : STD_LOGIC_VECTOR (6 downto 0) := "0000000";
    constant ap_const_lv16_4 : STD_LOGIC_VECTOR (15 downto 0) := "0000000000000100";
    constant ap_const_lv16_B : STD_LOGIC_VECTOR (15 downto 0) := "0000000000001011";
    constant ap_const_lv4_1 : STD_LOGIC_VECTOR (3 downto 0) := "0001";
    constant ap_const_boolean_1 : BOOLEAN := true;

    signal ap_CS_fsm : STD_LOGIC_VECTOR (5 downto 0) := "000001";
    attribute fsm_encoding : string;
    attribute fsm_encoding of ap_CS_fsm : signal is "none";
    signal ap_CS_fsm_state1 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state1 : signal is "none";
    signal and_ln13_fu_162_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal and_ln13_reg_281 : STD_LOGIC_VECTOR (0 downto 0);
    signal trunc_ln18_fu_168_p1 : STD_LOGIC_VECTOR (6 downto 0);
    signal trunc_ln18_reg_285 : STD_LOGIC_VECTOR (6 downto 0);
    signal i_fu_181_p2 : STD_LOGIC_VECTOR (3 downto 0);
    signal i_reg_294 : STD_LOGIC_VECTOR (3 downto 0);
    signal ap_CS_fsm_state2 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state2 : signal is "none";
    signal mul_ln18_fu_191_p2 : STD_LOGIC_VECTOR (6 downto 0);
    signal mul_ln18_reg_299 : STD_LOGIC_VECTOR (6 downto 0);
    signal icmp_ln14_fu_176_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal zext_ln15_1_fu_200_p1 : STD_LOGIC_VECTOR (6 downto 0);
    signal zext_ln15_1_reg_305 : STD_LOGIC_VECTOR (6 downto 0);
    signal ap_CS_fsm_state3 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state3 : signal is "none";
    signal j_fu_209_p2 : STD_LOGIC_VECTOR (3 downto 0);
    signal j_reg_314 : STD_LOGIC_VECTOR (3 downto 0);
    signal k_fu_228_p2 : STD_LOGIC_VECTOR (3 downto 0);
    signal k_reg_322 : STD_LOGIC_VECTOR (3 downto 0);
    signal ap_CS_fsm_state4 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state4 : signal is "none";
    signal icmp_ln17_fu_223_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal add_ln18_2_fu_244_p2 : STD_LOGIC_VECTOR (6 downto 0);
    signal add_ln18_2_reg_332 : STD_LOGIC_VECTOR (6 downto 0);
    signal a_load_reg_342 : STD_LOGIC_VECTOR (15 downto 0);
    signal ap_CS_fsm_state5 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state5 : signal is "none";
    signal b_load_reg_347 : STD_LOGIC_VECTOR (15 downto 0);
    signal grp_fu_268_p3 : STD_LOGIC_VECTOR (15 downto 0);
    signal ap_CS_fsm_state6 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state6 : signal is "none";
    signal i_0_reg_93 : STD_LOGIC_VECTOR (3 downto 0);
    signal icmp_ln15_fu_204_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal j_0_reg_104 : STD_LOGIC_VECTOR (3 downto 0);
    signal k_0_reg_115 : STD_LOGIC_VECTOR (3 downto 0);
    signal acc_0_reg_126 : STD_LOGIC_VECTOR (15 downto 0);
    signal phi_mul_reg_139 : STD_LOGIC_VECTOR (6 downto 0);
    signal zext_ln18_fu_239_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal zext_ln18_1_fu_254_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal zext_ln20_fu_263_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal icmp_ln13_fu_150_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal icmp_ln13_1_fu_156_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal zext_ln14_fu_172_p1 : STD_LOGIC_VECTOR (15 downto 0);
    signal mul_ln18_fu_191_p0 : STD_LOGIC_VECTOR (3 downto 0);
    signal zext_ln15_fu_196_p1 : STD_LOGIC_VECTOR (15 downto 0);
    signal zext_ln17_fu_215_p1 : STD_LOGIC_VECTOR (15 downto 0);
    signal zext_ln17_1_fu_219_p1 : STD_LOGIC_VECTOR (6 downto 0);
    signal add_ln18_fu_234_p2 : STD_LOGIC_VECTOR (6 downto 0);
    signal add_ln18_1_fu_249_p2 : STD_LOGIC_VECTOR (6 downto 0);
    signal add_ln20_fu_259_p2 : STD_LOGIC_VECTOR (6 downto 0);
    signal ap_NS_fsm : STD_LOGIC_VECTOR (5 downto 0);
    signal mul_ln18_fu_191_p00 : STD_LOGIC_VECTOR (6 downto 0);

    component multiply_matricesbkb IS
    generic (
        ID : INTEGER;
        NUM_STAGE : INTEGER;
        din0_WIDTH : INTEGER;
        din1_WIDTH : INTEGER;
        din2_WIDTH : INTEGER;
        dout_WIDTH : INTEGER );
    port (
        din0 : IN STD_LOGIC_VECTOR (15 downto 0);
        din1 : IN STD_LOGIC_VECTOR (15 downto 0);
        din2 : IN STD_LOGIC_VECTOR (15 downto 0);
        dout : OUT STD_LOGIC_VECTOR (15 downto 0) );
    end component;



begin
    multiply_matricesbkb_U1 : component multiply_matricesbkb
    generic map (
        ID => 1,
        NUM_STAGE => 1,
        din0_WIDTH => 16,
        din1_WIDTH => 16,
        din2_WIDTH => 16,
        dout_WIDTH => 16)
    port map (
        din0 => a_load_reg_342,
        din1 => b_load_reg_347,
        din2 => acc_0_reg_126,
        dout => grp_fu_268_p3);





    ap_CS_fsm_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_CS_fsm <= ap_ST_fsm_state1;
            else
                ap_CS_fsm <= ap_NS_fsm;
            end if;
        end if;
    end process;


    acc_0_reg_126_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state6)) then 
                acc_0_reg_126 <= grp_fu_268_p3;
            elsif (((icmp_ln15_fu_204_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state3))) then 
                acc_0_reg_126 <= ap_const_lv16_0;
            end if; 
        end if;
    end process;

    i_0_reg_93_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_lv1_1 = and_ln13_fu_162_p2) and (ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start = ap_const_logic_1))) then 
                i_0_reg_93 <= ap_const_lv4_0;
            elsif (((icmp_ln15_fu_204_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state3))) then 
                i_0_reg_93 <= i_reg_294;
            end if; 
        end if;
    end process;

    j_0_reg_104_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln17_fu_223_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state4))) then 
                j_0_reg_104 <= j_reg_314;
            elsif (((icmp_ln14_fu_176_p2 = ap_const_lv1_0) and (ap_const_lv1_1 = and_ln13_reg_281) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
                j_0_reg_104 <= ap_const_lv4_0;
            end if; 
        end if;
    end process;

    k_0_reg_115_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state6)) then 
                k_0_reg_115 <= k_reg_322;
            elsif (((icmp_ln15_fu_204_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state3))) then 
                k_0_reg_115 <= ap_const_lv4_0;
            end if; 
        end if;
    end process;

    phi_mul_reg_139_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state6)) then 
                phi_mul_reg_139 <= add_ln18_2_reg_332;
            elsif (((icmp_ln15_fu_204_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state3))) then 
                phi_mul_reg_139 <= ap_const_lv7_0;
            end if; 
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state5)) then
                a_load_reg_342 <= a_q0;
                b_load_reg_347 <= b_q0;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln17_fu_223_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state4))) then
                add_ln18_2_reg_332 <= add_ln18_2_fu_244_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start = ap_const_logic_1))) then
                and_ln13_reg_281 <= and_ln13_fu_162_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_lv1_1 = and_ln13_reg_281) and (ap_const_logic_1 = ap_CS_fsm_state2))) then
                i_reg_294 <= i_fu_181_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state3)) then
                j_reg_314 <= j_fu_209_p2;
                    zext_ln15_1_reg_305(3 downto 0) <= zext_ln15_1_fu_200_p1(3 downto 0);
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state4)) then
                k_reg_322 <= k_fu_228_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln14_fu_176_p2 = ap_const_lv1_0) and (ap_const_lv1_1 = and_ln13_reg_281) and (ap_const_logic_1 = ap_CS_fsm_state2))) then
                mul_ln18_reg_299 <= mul_ln18_fu_191_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_lv1_1 = and_ln13_fu_162_p2) and (ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start = ap_const_logic_1))) then
                trunc_ln18_reg_285 <= trunc_ln18_fu_168_p1;
            end if;
        end if;
    end process;
    zext_ln15_1_reg_305(6 downto 4) <= "000";

    ap_NS_fsm_assign_proc : process (ap_start, ap_CS_fsm, ap_CS_fsm_state1, and_ln13_reg_281, ap_CS_fsm_state2, icmp_ln14_fu_176_p2, ap_CS_fsm_state3, ap_CS_fsm_state4, icmp_ln17_fu_223_p2, icmp_ln15_fu_204_p2)
    begin
        case ap_CS_fsm is
            when ap_ST_fsm_state1 => 
                if (((ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start = ap_const_logic_1))) then
                    ap_NS_fsm <= ap_ST_fsm_state2;
                else
                    ap_NS_fsm <= ap_ST_fsm_state1;
                end if;
            when ap_ST_fsm_state2 => 
                if (((ap_const_logic_1 = ap_CS_fsm_state2) and ((icmp_ln14_fu_176_p2 = ap_const_lv1_1) or (ap_const_lv1_0 = and_ln13_reg_281)))) then
                    ap_NS_fsm <= ap_ST_fsm_state1;
                else
                    ap_NS_fsm <= ap_ST_fsm_state3;
                end if;
            when ap_ST_fsm_state3 => 
                if (((icmp_ln15_fu_204_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state3))) then
                    ap_NS_fsm <= ap_ST_fsm_state2;
                else
                    ap_NS_fsm <= ap_ST_fsm_state4;
                end if;
            when ap_ST_fsm_state4 => 
                if (((icmp_ln17_fu_223_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state4))) then
                    ap_NS_fsm <= ap_ST_fsm_state3;
                else
                    ap_NS_fsm <= ap_ST_fsm_state5;
                end if;
            when ap_ST_fsm_state5 => 
                ap_NS_fsm <= ap_ST_fsm_state6;
            when ap_ST_fsm_state6 => 
                ap_NS_fsm <= ap_ST_fsm_state4;
            when others =>  
                ap_NS_fsm <= "XXXXXX";
        end case;
    end process;
    a_address0 <= zext_ln18_fu_239_p1(7 - 1 downto 0);

    a_ce0_assign_proc : process(ap_CS_fsm_state4)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state4)) then 
            a_ce0 <= ap_const_logic_1;
        else 
            a_ce0 <= ap_const_logic_0;
        end if; 
    end process;

    add_ln18_1_fu_249_p2 <= std_logic_vector(unsigned(phi_mul_reg_139) + unsigned(zext_ln15_1_reg_305));
    add_ln18_2_fu_244_p2 <= std_logic_vector(unsigned(phi_mul_reg_139) + unsigned(trunc_ln18_reg_285));
    add_ln18_fu_234_p2 <= std_logic_vector(unsigned(mul_ln18_reg_299) + unsigned(zext_ln17_1_fu_219_p1));
    add_ln20_fu_259_p2 <= std_logic_vector(unsigned(mul_ln18_reg_299) + unsigned(zext_ln15_1_reg_305));
    and_ln13_fu_162_p2 <= (icmp_ln13_fu_150_p2 and icmp_ln13_1_fu_156_p2);
    ap_CS_fsm_state1 <= ap_CS_fsm(0);
    ap_CS_fsm_state2 <= ap_CS_fsm(1);
    ap_CS_fsm_state3 <= ap_CS_fsm(2);
    ap_CS_fsm_state4 <= ap_CS_fsm(3);
    ap_CS_fsm_state5 <= ap_CS_fsm(4);
    ap_CS_fsm_state6 <= ap_CS_fsm(5);

    ap_done_assign_proc : process(and_ln13_reg_281, ap_CS_fsm_state2, icmp_ln14_fu_176_p2)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_state2) and ((icmp_ln14_fu_176_p2 = ap_const_lv1_1) or (ap_const_lv1_0 = and_ln13_reg_281)))) then 
            ap_done <= ap_const_logic_1;
        else 
            ap_done <= ap_const_logic_0;
        end if; 
    end process;


    ap_idle_assign_proc : process(ap_start, ap_CS_fsm_state1)
    begin
        if (((ap_start = ap_const_logic_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            ap_idle <= ap_const_logic_1;
        else 
            ap_idle <= ap_const_logic_0;
        end if; 
    end process;


    ap_ready_assign_proc : process(and_ln13_reg_281, ap_CS_fsm_state2, icmp_ln14_fu_176_p2)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_state2) and ((icmp_ln14_fu_176_p2 = ap_const_lv1_1) or (ap_const_lv1_0 = and_ln13_reg_281)))) then 
            ap_ready <= ap_const_logic_1;
        else 
            ap_ready <= ap_const_logic_0;
        end if; 
    end process;

    b_address0 <= zext_ln18_1_fu_254_p1(7 - 1 downto 0);

    b_ce0_assign_proc : process(ap_CS_fsm_state4)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state4)) then 
            b_ce0 <= ap_const_logic_1;
        else 
            b_ce0 <= ap_const_logic_0;
        end if; 
    end process;

    c_address0 <= zext_ln20_fu_263_p1(7 - 1 downto 0);

    c_ce0_assign_proc : process(ap_CS_fsm_state4)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state4)) then 
            c_ce0 <= ap_const_logic_1;
        else 
            c_ce0 <= ap_const_logic_0;
        end if; 
    end process;

    c_d0 <= acc_0_reg_126;

    c_we0_assign_proc : process(ap_CS_fsm_state4, icmp_ln17_fu_223_p2)
    begin
        if (((icmp_ln17_fu_223_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state4))) then 
            c_we0 <= ap_const_logic_1;
        else 
            c_we0 <= ap_const_logic_0;
        end if; 
    end process;

    i_fu_181_p2 <= std_logic_vector(unsigned(i_0_reg_93) + unsigned(ap_const_lv4_1));
    icmp_ln13_1_fu_156_p2 <= "1" when (signed(n) < signed(ap_const_lv16_B)) else "0";
    icmp_ln13_fu_150_p2 <= "1" when (signed(n) > signed(ap_const_lv16_4)) else "0";
    icmp_ln14_fu_176_p2 <= "1" when (zext_ln14_fu_172_p1 = n) else "0";
    icmp_ln15_fu_204_p2 <= "1" when (zext_ln15_fu_196_p1 = n) else "0";
    icmp_ln17_fu_223_p2 <= "1" when (zext_ln17_fu_215_p1 = n) else "0";
    j_fu_209_p2 <= std_logic_vector(unsigned(j_0_reg_104) + unsigned(ap_const_lv4_1));
    k_fu_228_p2 <= std_logic_vector(unsigned(k_0_reg_115) + unsigned(ap_const_lv4_1));
    mul_ln18_fu_191_p0 <= mul_ln18_fu_191_p00(4 - 1 downto 0);
    mul_ln18_fu_191_p00 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(i_0_reg_93),7));
    mul_ln18_fu_191_p2 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(std_logic_vector(signed('0' &mul_ln18_fu_191_p0) * signed(trunc_ln18_reg_285))), 7));
    trunc_ln18_fu_168_p1 <= n(7 - 1 downto 0);
    zext_ln14_fu_172_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(i_0_reg_93),16));
    zext_ln15_1_fu_200_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(j_0_reg_104),7));
    zext_ln15_fu_196_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(j_0_reg_104),16));
    zext_ln17_1_fu_219_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(k_0_reg_115),7));
    zext_ln17_fu_215_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(k_0_reg_115),16));
    zext_ln18_1_fu_254_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(add_ln18_1_fu_249_p2),64));
    zext_ln18_fu_239_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(add_ln18_fu_234_p2),64));
    zext_ln20_fu_263_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(add_ln20_fu_259_p2),64));
end behav;
