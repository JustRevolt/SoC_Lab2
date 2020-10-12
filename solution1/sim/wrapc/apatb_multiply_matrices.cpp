// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================

#include <systemc>
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <stdint.h>
#include "SysCFileHandler.h"
#include "ap_int.h"
#include "ap_fixed.h"
#include <complex>
#include <stdbool.h>
#include "autopilot_cbe.h"
#include "hls_stream.h"
#include "hls_half.h"
#include "hls_signal_handler.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;


// [dump_struct_tree [build_nameSpaceTree] dumpedStructList] ---------->


// [dump_enumeration [get_enumeration_list]] ---------->


// wrapc file define: "n"
#define AUTOTB_TVIN_n  "../tv/cdatafile/c.multiply_matrices.autotvin_n.dat"
// wrapc file define: "a"
#define AUTOTB_TVIN_a  "../tv/cdatafile/c.multiply_matrices.autotvin_a.dat"
// wrapc file define: "b"
#define AUTOTB_TVIN_b  "../tv/cdatafile/c.multiply_matrices.autotvin_b.dat"
// wrapc file define: "c"
#define AUTOTB_TVOUT_c  "../tv/cdatafile/c.multiply_matrices.autotvout_c.dat"
#define AUTOTB_TVIN_c  "../tv/cdatafile/c.multiply_matrices.autotvin_c.dat"

#define INTER_TCL  "../tv/cdatafile/ref.tcl"

// tvout file define: "c"
#define AUTOTB_TVOUT_PC_c  "../tv/rtldatafile/rtl.multiply_matrices.autotvout_c.dat"

class INTER_TCL_FILE {
	public:
		INTER_TCL_FILE(const char* name) {
			mName = name;
			n_depth = 0;
			a_depth = 0;
			b_depth = 0;
			c_depth = 0;
			trans_num =0;
		}

		~INTER_TCL_FILE() {
			mFile.open(mName);
			if (!mFile.good()) {
				cout << "Failed to open file ref.tcl" << endl;
				exit (1);
			}
			string total_list = get_depth_list();
			mFile << "set depth_list {\n";
			mFile << total_list;
			mFile << "}\n";
			mFile << "set trans_num "<<trans_num<<endl;
			mFile.close();
		}

		string get_depth_list () {
			stringstream total_list;
			total_list << "{n " << n_depth << "}\n";
			total_list << "{a " << a_depth << "}\n";
			total_list << "{b " << b_depth << "}\n";
			total_list << "{c " << c_depth << "}\n";
			return total_list.str();
		}

		void set_num (int num , int* class_num) {
			(*class_num) = (*class_num) > num ? (*class_num) : num;
		}
	public:
		int n_depth;
		int a_depth;
		int b_depth;
		int c_depth;
		int trans_num;

	private:
		ofstream mFile;
		const char* mName;
};

extern "C" void multiply_matrices (
short n,
short a[100],
short b[100],
short c[100]);

extern "C" void AESL_WRAP_multiply_matrices (
short n,
short a[100],
short b[100],
short c[100])
{
	refine_signal_handler();
	fstream wrapc_switch_file_token;
	wrapc_switch_file_token.open(".hls_cosim_wrapc_switch.log");
	int AESL_i;
	if (wrapc_switch_file_token.good())
	{
		CodeState = ENTER_WRAPC_PC;
		static unsigned AESL_transaction_pc = 0;
		string AESL_token;
		string AESL_num;
		static AESL_FILE_HANDLER aesl_fh;


		// output port post check: "c"
		aesl_fh.read(AUTOTB_TVOUT_PC_c, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_c, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_c, AESL_token); // data

			sc_bv<16> *c_pc_buffer = new sc_bv<16>[100];
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'c', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'c', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					c_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_c, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_c))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: c
				{
					// bitslice(15, 0)
					// {
						// celement: c(15, 0)
						// {
							sc_lv<16>* c_lv0_0_99_1 = new sc_lv<16>[100];
						// }
					// }

					// bitslice(15, 0)
					{
						int hls_map_index = 0;
						// celement: c(15, 0)
						{
							// carray: (0) => (99) @ (1)
							for (int i_0 = 0; i_0 <= 99; i_0 += 1)
							{
								if (&(c[0]) != NULL) // check the null address if the c port is array or others
								{
									c_lv0_0_99_1[hls_map_index].range(15, 0) = sc_bv<16>(c_pc_buffer[hls_map_index].range(15, 0));
									hls_map_index++;
								}
							}
						}
					}

					// bitslice(15, 0)
					{
						int hls_map_index = 0;
						// celement: c(15, 0)
						{
							// carray: (0) => (99) @ (1)
							for (int i_0 = 0; i_0 <= 99; i_0 += 1)
							{
								// sub                    : i_0
								// ori_name               : c[i_0]
								// sub_1st_elem           : 0
								// ori_name_1st_elem      : c[0]
								// output_left_conversion : c[i_0]
								// output_type_conversion : (c_lv0_0_99_1[hls_map_index]).to_uint64()
								if (&(c[0]) != NULL) // check the null address if the c port is array or others
								{
									c[i_0] = (c_lv0_0_99_1[hls_map_index]).to_uint64();
									hls_map_index++;
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] c_pc_buffer;
		}

		AESL_transaction_pc++;
	}
	else
	{
		CodeState = ENTER_WRAPC;
		static unsigned AESL_transaction;

		static AESL_FILE_HANDLER aesl_fh;

		// "n"
		char* tvin_n = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_n);

		// "a"
		char* tvin_a = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_a);

		// "b"
		char* tvin_b = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_b);

		// "c"
		char* tvin_c = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_c);
		char* tvout_c = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_c);

		CodeState = DUMP_INPUTS;
		static INTER_TCL_FILE tcl_file(INTER_TCL);
		int leading_zero;

		// [[transaction]]
		sprintf(tvin_n, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_n, tvin_n);

		sc_bv<16> n_tvin_wrapc_buffer;

		// RTL Name: n
		{
			// bitslice(15, 0)
			{
				// celement: n(15, 0)
				{
					// carray: (0) => (0) @ (0)
					{
						// sub                   : 
						// ori_name              : n
						// sub_1st_elem          : 
						// ori_name_1st_elem     : n
						// regulate_c_name       : n
						// input_type_conversion : n
						if (&(n) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<16> n_tmp_mem;
							n_tmp_mem = n;
							n_tvin_wrapc_buffer.range(15, 0) = n_tmp_mem.range(15, 0);
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_n, "%s\n", (n_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_n, tvin_n);
		}

		tcl_file.set_num(1, &tcl_file.n_depth);
		sprintf(tvin_n, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_n, tvin_n);

		// [[transaction]]
		sprintf(tvin_a, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_a, tvin_a);

		sc_bv<16>* a_tvin_wrapc_buffer = new sc_bv<16>[100];

		// RTL Name: a
		{
			// bitslice(15, 0)
			{
				int hls_map_index = 0;
				// celement: a(15, 0)
				{
					// carray: (0) => (99) @ (1)
					for (int i_0 = 0; i_0 <= 99; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : a[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : a[0]
						// regulate_c_name       : a
						// input_type_conversion : a[i_0]
						if (&(a[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<16> a_tmp_mem;
							a_tmp_mem = a[i_0];
							a_tvin_wrapc_buffer[hls_map_index].range(15, 0) = a_tmp_mem.range(15, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 100; i++)
		{
			sprintf(tvin_a, "%s\n", (a_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_a, tvin_a);
		}

		tcl_file.set_num(100, &tcl_file.a_depth);
		sprintf(tvin_a, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_a, tvin_a);

		// release memory allocation
		delete [] a_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_b, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_b, tvin_b);

		sc_bv<16>* b_tvin_wrapc_buffer = new sc_bv<16>[100];

		// RTL Name: b
		{
			// bitslice(15, 0)
			{
				int hls_map_index = 0;
				// celement: b(15, 0)
				{
					// carray: (0) => (99) @ (1)
					for (int i_0 = 0; i_0 <= 99; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : b[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : b[0]
						// regulate_c_name       : b
						// input_type_conversion : b[i_0]
						if (&(b[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<16> b_tmp_mem;
							b_tmp_mem = b[i_0];
							b_tvin_wrapc_buffer[hls_map_index].range(15, 0) = b_tmp_mem.range(15, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 100; i++)
		{
			sprintf(tvin_b, "%s\n", (b_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_b, tvin_b);
		}

		tcl_file.set_num(100, &tcl_file.b_depth);
		sprintf(tvin_b, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_b, tvin_b);

		// release memory allocation
		delete [] b_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_c, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_c, tvin_c);

		sc_bv<16>* c_tvin_wrapc_buffer = new sc_bv<16>[100];

		// RTL Name: c
		{
			// bitslice(15, 0)
			{
				int hls_map_index = 0;
				// celement: c(15, 0)
				{
					// carray: (0) => (99) @ (1)
					for (int i_0 = 0; i_0 <= 99; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : c[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : c[0]
						// regulate_c_name       : c
						// input_type_conversion : c[i_0]
						if (&(c[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<16> c_tmp_mem;
							c_tmp_mem = c[i_0];
							c_tvin_wrapc_buffer[hls_map_index].range(15, 0) = c_tmp_mem.range(15, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 100; i++)
		{
			sprintf(tvin_c, "%s\n", (c_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_c, tvin_c);
		}

		tcl_file.set_num(100, &tcl_file.c_depth);
		sprintf(tvin_c, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_c, tvin_c);

		// release memory allocation
		delete [] c_tvin_wrapc_buffer;

// [call_c_dut] ---------->

		CodeState = CALL_C_DUT;
		multiply_matrices(n, a, b, c);

		CodeState = DUMP_OUTPUTS;

		// [[transaction]]
		sprintf(tvout_c, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_c, tvout_c);

		sc_bv<16>* c_tvout_wrapc_buffer = new sc_bv<16>[100];

		// RTL Name: c
		{
			// bitslice(15, 0)
			{
				int hls_map_index = 0;
				// celement: c(15, 0)
				{
					// carray: (0) => (99) @ (1)
					for (int i_0 = 0; i_0 <= 99; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : c[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : c[0]
						// regulate_c_name       : c
						// input_type_conversion : c[i_0]
						if (&(c[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<16> c_tmp_mem;
							c_tmp_mem = c[i_0];
							c_tvout_wrapc_buffer[hls_map_index].range(15, 0) = c_tmp_mem.range(15, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 100; i++)
		{
			sprintf(tvout_c, "%s\n", (c_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_c, tvout_c);
		}

		tcl_file.set_num(100, &tcl_file.c_depth);
		sprintf(tvout_c, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_c, tvout_c);

		// release memory allocation
		delete [] c_tvout_wrapc_buffer;

		CodeState = DELETE_CHAR_BUFFERS;
		// release memory allocation: "n"
		delete [] tvin_n;
		// release memory allocation: "a"
		delete [] tvin_a;
		// release memory allocation: "b"
		delete [] tvin_b;
		// release memory allocation: "c"
		delete [] tvout_c;
		delete [] tvin_c;

		AESL_transaction++;

		tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);
	}
}

