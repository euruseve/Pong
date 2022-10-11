#define is_down(b) input->buttons[b].is_down
#define pressed(b) (input->buttons[b].is_down && input->buttons[b].is_changed)
#define released(b) (!input->buttons[b].is_down && input->buttons[b].is_changed)

float player_pos_x = 0.f;
float player_pos_y = 0.f;

static void 
simulate_game(Input *input, float dt)
{
	clear_screen(0xf);

	float speed = 50.f;

	if (is_down(BUTTON_UP))
		player_pos_y += speed * dt;

	if (is_down(BUTTON_DOWN))
		player_pos_y -= speed * dt;

	if (is_down(BUTTON_LEFT))
		player_pos_x -= speed * dt;

	if (is_down(BUTTON_RIGHT))
		player_pos_x += speed * dt;


	draw_rect(player_pos_x, player_pos_y, 1, 1, 0xffffff);

}