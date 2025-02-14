//This Header severse as the font header. function related to font have been defined here
#pragma once


GLuint base;
GLYPHMETRICSFLOAT gmf[256];

//3D font
void buildFont(int fontIndex)
{
	if (fontIndex == 1) 
	{
		HFONT font;
		base = glGenLists(256);
		font = CreateFont(
			-12, 1, 0, 0,
			FW_DONTCARE,
			FALSE,
			FALSE,
			FALSE,
			OEM_CHARSET, //OEM_CHARSET
			OUT_TT_PRECIS,
			CLIP_DEFAULT_PRECIS,
			ANTIALIASED_QUALITY,
			FF_DONTCARE | DEFAULT_PITCH,
			"American Captain");

		SelectObject(ghdc, font);

		if (bExtrude == FALSE)
		{
			wglUseFontOutlines(ghdc, 0, 256, base, 0.0f, 0.2f, WGL_FONT_POLYGONS, gmf);
		}
		else
		{
			wglUseFontOutlines(ghdc, 0, 256, base, 0.0f, 0.5f, WGL_FONT_POLYGONS, gmf);
		}
		
	}
}



void killFont(void)
{
	glDeleteLists(base, 256);
}



void writeUsingFont(const char* fmt, ...)
{
	float length = 0;
	char text[256];

	va_list ap;

	if (fmt == NULL)
	{
		return;
	}

	va_start(ap, fmt);

	vsprintf(text, fmt, ap);

	va_end(ap);

	for (unsigned int loop = 0; loop < (strlen(text)); loop++)
	{
		length = length + gmf[text[loop]].gmfCellIncX;
	}

	glTranslatef(-length / 2, 0.0f, 0.0f);

	glPushAttrib(GL_LIST_BIT);

	glListBase(base);

	glCallLists(strlen(text), GL_UNSIGNED_BYTE, text);

	glPopAttrib();
}

