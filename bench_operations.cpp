/**
 \file 		bench_operations.cpp
 \author	michael.zohner@ec-spride.de
 \copyright	ABY - A Framework for Efficient Mixed-protocol Secure Two-party Computation
 Copyright (C) 2015 Engineering Cryptographic Protocols Group, TU Darmstadt
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU Affero General Public License as published
 by the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Affero General Public License for more details.
 You should have received a copy of the GNU Affero General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>.
 \brief		Benchmark Primitive Operations
 */

//Utility libs
#include "../../abycore/sharing/sharing.h"
#include "../../abycore/circuit/booleancircuits.h"
#include <ENCRYPTO_utils/crypto/crypto.h>
#include <ENCRYPTO_utils/parse_options.h>
#include "../aes/common/aescircuit.h"
//ABY Party class
#include "../../abycore/aby/abyparty.h"
#include <cstring>
int32_t read_test_options(int32_t* argcp, char*** argvp, e_role* role) {

	uint32_t int_role = 0;
	bool useffc = false;

	parsing_ctx options[] =
			{ { (void*) &int_role, T_NUM, "r", "Role: 0/1", true, false }};

	if (!parse_options(argcp, argvp, options,
			sizeof(options) / sizeof(parsing_ctx))) {
		print_usage(*argvp[0], options, sizeof(options) / sizeof(parsing_ctx));
		std::cout << "Exiting" << std::endl;
		exit(0);
	}

	assert(int_role < 2);
	*role = (e_role) int_role;



	//delete options;

	return 1;
}

int main(int argc, char** argv) {

	e_role role;
	uint32_t bitlen = 32, nvals = 31, secparam = 128, nthreads = 1;
	uint16_t port = 7766;
	std::string address = "127.0.0.1";
	int32_t test_op = -1;
	e_mt_gen_alg mt_alg = MT_OT;

	read_test_options(&argc, &argv, &role);

	seclvl seclvl = get_sec_lvl(secparam);
	e_mt_gen_alg mt_alg = MT_OT;
	std::cout <<role<<std::endl;
	uint32_t inputa=5,inputb=6;

	//evaluate the millionaires circuit using Yao
	//test_millionaire_prob_circuit(role, address, port, seclvl, 1, 32,
	//		nthreads, mt_alg, S_YAO);
	//evaluate the millionaires circuit using GMW
	//test_millionaire_prob_circuit(role, address, seclvl, 1, 32,
	//		nthreads, mt_alg, S_BOOL);

	return 0;
}

