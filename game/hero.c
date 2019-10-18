#include <stdint.h>
#include <stdio.h>
#include <cx16.h>
#include <cbm.h>

/*
$F0000 - $F001F 	Display composer registers
*/
#define DC_VIDEO_ADDR 0xF0000
#define DC_HSCALE_ADDR = 0xF0001
#define DC_VSCALE_ADDR = 0xF0002
#define DC_BORDER_COLOR_ADDR = 0xF0003
#define DC_HSTART_L_ADDR = 0xF0004
#define DC_HSTOP_L_ADDR = 0xF0005
#define DC_VSTART_L_ADDR = 0xF0006
#define DC_VSTOP_L_ADDR = 0xF0007
#define DC_STARTSTOP_H_ADDR = 0xF008
#define DC_IRQ_LINE_L_ADDR = 0xF0009
#define DC_IRQ_LINE_H_ADDR = 0xF000A

/*
$F2000 - $F200F 	Layer 0 registers
*/
#define Ln_CTRL0 0xF2000
#define Ln_CTRL1 0xF2001
#define Ln_MAP_BASE_L 0xF2002
#define Ln_MAP_BASE_H 0xF2003
#define Ln_TILE_BASE_L 0xF2004
#define Ln_TILE_BASE_H 0xF2005
#define Ln_HSCROLL_L 0xF2006
#define Ln_HSCROLL_H 0xF2007
#define Ln_VSCROLL_L 0xF2008
#define Ln_VSCROLL_H 0xF2009

const uint16_t MAX_X = INT8_MAX;

// static void vreg(uint32_t register_addr, uint8_t data)
// {
// 	uint16_t addr_low = register_addr & 0x00FFFF;
// 	uint8_t addr_hi = (register_addr & 0xFF0000) >> 16;
// 	VERA.control = 0;
// 	VERA.address_hi = addr_hi;
// 	VERA.address = addr_low;
// 	// Store data through port 0
// 	VERA.data0 = data;

// 	printf("vreg -> register_addr: %06x\n", register_addr);
// 	printf("vreg -> address: %04x / address_hi: %2x / data0: %2x\n\n", addr_low, addr_hi, data);
// }

static void vpoke(uint8_t bank, uint16_t address, uint8_t data)
{
	// Set port 0's address.
	VERA.control = 0;
	VERA.address_hi = bank;
	VERA.address = address;
	// Store data through port 0
	VERA.data0 = data;

	printf("vpoke -> bank: 0x%02x / address: 0x%4x / data: 0x%2x\n\n", bank, address, data);
}


int main() {
	uint8_t data = 0;
	uint16_t address = 0;

	cbm_k_bsout(CH_FONT_UPPER);
	vpoke(0xF2, 0x0000, 0xe0);

	while (address <= MAX_X) {
		VERA.data0 = data;
		++data;
		++address;
		//printf("%04x ", address);
	}

	printf ("end of execution.");
	return 0;
}

