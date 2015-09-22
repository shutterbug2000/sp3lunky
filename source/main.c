#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <3ds.h>
#include <sf2d.h>

#include "bgCave.h"
#include "sTitleBG_0.h"

int main()
{
	// Set the random seed based on the time
	srand(time(NULL));

	sf2d_init();
	sf2d_set_clear_color(RGBA8(0x40, 0x40, 0x40, 0xFF));


	sf2d_texture *bgCaveTex = sf2d_create_texture_mem_RGBA8(bgCave.pixel_data, bgCave.width, bgCave.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	sf2d_texture *titleTex = sf2d_create_texture_mem_RGBA8(title.pixel_data, title.width, title.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	
	u32 held;
	
//	sf2d_texture_tile32(bgCaveTex);
	
	sf2d_swapbuffers();

	while (aptMainLoop()) {

		hidScanInput();
		held = hidKeysHeld();
		
		sf2d_start_frame(GFX_TOP, GFX_LEFT);
			for(int x = 0; x < 7; x++){
				for(int y = 0; y < 4; y++){
					sf2d_draw_texture(bgCaveTex, x*64, y*64);					
				}
			}

			sf2d_draw_texture(titleTex, 400/2 - (bgCaveTex->width/2 + bgCaveTex->width), 240/2 - bgCaveTex->height/2);
		sf2d_end_frame();

		if (held & KEY_START) {
			break;
		} 
		//else if (held & (KEY_L | KEY_R)) {
		//	sf2d_set_clear_color(RGBA8(rand()%255, rand()%255, rand()%255, 255));
		//}

//		sf2d_start_frame(GFX_TOP, GFX_LEFT);
//			sf2d_draw_texture(bgCaveTex, 0, 0);
//		sf2d_end_frame();

		sf2d_swapbuffers();
	}

	sf2d_free_texture(bgCaveTex);

	sf2d_fini();
	return 0;
}
