
/*
	2016.06.12
	Created by PHJ.
*/

#ifndef _PHS_GLYPH_RENDERER_CPP

#define _PHS_GLYPH_RENDERER_CPP

#include "PHsGlyphRenderer.h"

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsRender
	{
		using namespace std;

		FT_Library GlyphRenderer::sFreeTypeLibrary;
		FT_Face GlyphRenderer::sFace;

		Void GlyphRenderer::initializeGlyphRenderer()
		{

		}

		Void GlyphRenderer::finalizeGlyphRenderer()
		{

		}

		Void GlyphRenderer::loadFace(const string &sFacePath)
		{
			//FT_New_Face(GlyphRenderer::sFreeTypeLibrary, sFacePath.c_str(), 0l, &GlyphRenderer::sFace);


		}
	}
}

#endif