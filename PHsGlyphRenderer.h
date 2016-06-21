
/*
	2016.06.12
	Created by PHJ.
*/

#ifndef _PHS_GLYPH_RENDERER_H

#define _PHS_GLYPH_RENDERER_H

#include "PHsCommon.h"

#include <string>

#include <ft2build.h>
#include <freetype/freetype.h>
#include <freetype/ftglyph.h>
#include <freetype/ftoutln.h>
#include <freetype/fttrigon.h>

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsRender
	{
		class GlyphRenderer
		{
		private:
			static FT_Library sFreeTypeLibrary;
			static FT_Face sFace;

		public:
			GlyphRenderer() = delete;
			GlyphRenderer(GlyphRenderer &&sNewGlyphRenderer) = delete;
			GlyphRenderer(const GlyphRenderer &sNewGlyphRenderer) = delete;
			~GlyphRenderer() = delete;

		public:
			GlyphRenderer &operator=(GlyphRenderer &&sNewGlyphRenderer) = delete;
			GlyphRenderer &operator=(const GlyphRenderer &sNewGlyphRenderer) = delete;

			static Void initializeGlyphRenderer();
			static Void finalizeGlyphRenderer();
			static Void loadFace(const std::string &sFacePath);
		};
	}
}

#endif