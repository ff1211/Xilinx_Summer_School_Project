/*\
 *  Yes, This Is Another Barcode Reader
 *  Copyright (C) 2013 Quentin SANTOS
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
\*/

#include "qrc_decoder.h"

#include <stdlib.h>

#include "blocks.h"
#include "bch.h"
#include "data.h"


#define pdata(I,J) (pdata[(I)*21 + (J)])
#define large 21
// please, refer to DOCUMENTATION for technical details



void qrc_decoder(byte  pdata[large*large],byte  dataout)
{
	int i;    unsigned char dataout_num=0;

    scanner_t scanner;
    for(i=0;i<21;i++){
                for(int j=0;j<21;j++){
                    scanner.d[i*21+j]=pdata[i*21+j];//(&(scanner.d)+i*21+j));
				}
		}

	// size
	size_t s = 21;
	scanner.s=21;

	// finders

    // version
	size_t v = s - 17;
	v /= 4;
	scanner.v = v;


	// BEGIN format information

	// top-left
	bch_t format1 = 0;
	for (i = 0; i <= 5; i++)
		format1 = 2*format1 + pdata(8,i);
	format1 = 2*format1 + pdata(8,7);
	format1 = 2*format1 + pdata(8,8);
	format1 = 2*format1 + pdata(7,8);
	for (i = 5; i >= 0; i--)
		format1 = 2*format1 + pdata(i,8);
	format1 = bch_decode(bch_format_gen, format1 ^ bch_format_mask);

	// bottom-left and top-right
	bch_t format2 = 0;
	for (i = 1; i <= 7; i++)
		format2 = 2*format2 + pdata(s-i,8);
	for (i = 8; i >= 1; i--)
		format2 = 2*format2 + pdata(8,s-i);
	format2 = bch_decode(bch_format_gen, format2 ^ bch_format_mask);

	// checking validity
	// END format information

	scanner.m = format1 & 0x7; // mask
	scanner.c = code_to_ecl[format1 >> 3]; // Error Correction Level
	// decode data
	scanner.block_cur = 0;
	//for(int k=0;k<20;k++)
//{

        byte enc = get_bits(&scanner, 4);
		size_t len = get_bits(&scanner, lenbits[enc][version_range[v]]);
	//	if (enc == 0) // END
	//	{

	//		break;
	//	}
	//	else
		if (enc == 1) // numeric
		{
			for (; len>=3; len-=3)
			{
				unsigned int c = get_bits(&scanner, 10);
				dataout=(c/100) % 10;
				dataout_num++;
				dataout=(c/ 10) % 10;
				dataout_num++;
				dataout=(c/  1) % 10;
				dataout_num++;
			}
			if (len == 2)
			{
				unsigned int c = get_bits(&scanner, 7);
				dataout=c/10;
				dataout_num++;
				dataout=c%10;
				dataout_num++;
			}
			else if (len == 1)
			{
				unsigned int c = get_bits(&scanner, 4);
				dataout=c;
				dataout_num++;
			}
		}
		else if (enc == 2) // alphanumeric
		{
			for (; len >= 2; len-=2)
			{
				unsigned int c = get_bits(&scanner, 11);
				dataout=charset_alpha[c/45];
				dataout_num++;
				dataout=charset_alpha[c%45];
				dataout_num++;
			}
			if (len == 1)
			{
				unsigned int c = get_bits(&scanner, 6);
				dataout=c;
				dataout_num++;
			}
		}
		else if (enc == 4) // Shift JIS
		{
			for (size_t i = 0; i < len; i++)
			{
				byte c = get_bits(&scanner, 8);
				dataout=c;
				dataout_num++;
			}
		}
	//}
    dataout_num=0;

	//free(scanner.d);
}
