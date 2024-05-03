
/*
A simple "hello world" example.
Set the screen background color and palette colors.
Then write a message to the nametable.
Finally, turn on the PPU to display video.
*/

#include "neslib.h"
#include <stdio.h>
#include <string.h>

// link the pattern table into CHR ROM
//#link "chr_generic.s"

unsigned char y_pos = 2;

void init()
{
  // set palette colors
  pal_col(0,0x02);	// set screen to dark blue
  pal_col(1,0x14);	// fuchsia
  pal_col(2,0x20);	// grey
  pal_col(3,0x30);	// white
}

void print(unsigned char* string)
{
  vram_adr(NTADR_A(2,y_pos));		// set address
  vram_write(string, strlen(string));	// write bytes to video RAM
  ++y_pos;
}

// main function, run after console reset
void main(void) {

  unsigned char d = 4;
  
  init();
 
  print("VITAL MESSAGE");
  print(" ");
  print("HOW DIFFICULT? (4-10)");

  // enable PPU rendering (turn on screen)
  ppu_on_all();

  // infinite loop
  while (1)
  {
    ppu_wait();
  }
}
