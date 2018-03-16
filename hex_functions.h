//////////////////////////////////////////////////
//
//  This work is licensed under the MIT license.
//  
//  You are free to copy, modify and distribute
//  this work freely given that proper attribution
//  is supplied and the author is not held liable.
//  See LICENSE for details.
//  
//  Copyright (c) 2016-2018 David "OmniTroid" Skoland
//
//////////////////////////////////////////////////

#ifndef HEX_OPERATIONS_H
#define HEX_OPERATIONS_H

#include <bitset>
#include <cstdint>
#include <iostream>

namespace omni
{
	char halfword_to_hex_char(unsigned int input);
	std::string int_to_hex(unsigned int input);
}

#endif //HEX_OPERATIONS_H
