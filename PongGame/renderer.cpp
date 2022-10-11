static float render_scale = 0.01f;

static void 
clear_screen(u32 color)
{
	u32* pixel = (u32*)render_state.memory;
	for (int y = 0; y < render_state.height; y++)
	{
		for (int x = 0; x < render_state.width; x++)
		{
			*pixel++ = color;
		}
	}
}

static void 
draw_rect_in_pixels(int x1, int y1, int x2, int y2, u32 color)
{
	x1 = clamp(0, x1, render_state.width);
	x2 = clamp(0, x2, render_state.width);
	y1 = clamp(0, y1, render_state.height);
	y2 = clamp(0, y2, render_state.height);

	for (int y = y1; y < y2; y++)
	{
		u32* pixel = (u32*)render_state.memory + x1 + y * render_state.width;
		for (int x = x1; x < x2; x++)
		{
			*pixel++ = color;
		}
	}
}

static void
draw_rect(float x, float y, float half_size_x, float half_size_y, u32 color)
{
	x *= render_state.height * render_scale;
	y *= render_state.height * render_scale;
	half_size_x *= render_state.height * render_scale;
	half_size_y *= render_state.height * render_scale;

	x += render_state.width / 2.f;
	y += render_state.height / 2.f;

	int x1 = x - half_size_x;
	int x2 = x + half_size_x;
	int y1 = y - half_size_y;
	int y2 = y + half_size_y;

	draw_rect_in_pixels(x1, y1, x2, y2, color);
}