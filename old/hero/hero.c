#include <stdint.h>
#include <stdio.h>
#include <cx16.h>
#include <cbm.h>
#include "hero.h"

static void vpoke(uint8_t bank, uint16_t address, uint8_t data)
{
    // Set port 0's address.
    VERA.control = 0;
    VERA.address_hi = bank;
    VERA.address = address;
    // Store data through port 0.
    VERA.data0 = data;
}

static void init_player(GameObj *p)
{
	// Set the address to increment with each access.
	// Address bits 12:5
	vpoke(0x1F, p->addr, (p->data_addr >> 5) & 0xFF);

	// Address bits 16:13 (starting at 0x010000) and 8 BPP mode
	VERA.data0 = (1 << 7) | (p->data_addr >> 13);

	// x co-ordinate, bits 7:0
	VERA.data0 = p->x & 0xFF;

	// x co-ordinate, bits 9:8
	VERA.data0 = p->x >> 8;

	// y co-ordinate, bits 7:0
	VERA.data0 = p->y & 0xFF;

	// y co-ordinate, bits 9:8
	VERA.data0 = p->y >> 8;

	// z-depth: in front of layer 1
	VERA.data0 = (3 << 2);

	// 16 pixels for width and height
	VERA.data0 = (1 << 6) | (1 << 4);
}

static void main_loop()
{
  GameObj p;
  p.x = 50;
  p.y = 50;
  p.addr = 0x5000;
  p.data_addr = (0x010000 >> 5) & 0xFF;
	init_player(&p);
}


int main() {
	printf ("start...\n");
	cbm_k_bsout(CH_FONT_UPPER);

  main_loop();

	printf ("end of execution.\n");
	return 0;
}
