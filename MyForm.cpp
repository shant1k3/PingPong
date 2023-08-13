#include "MyForm.h"
#include <random>
using namespace System::Windows::Forms;
int left_y = 425;
int right_y = 325;
int ball_y = 425;
int left_x = 50;
int right_x = 965;
int ball_x = 475.5;
int direction;
bool temp_up;
bool temp_down;
bool check_bot = true;
int direction_x=1, direction_y = 1;

int main()
{
	game::MyForm form;
	Application::Run(% form);

}

System::Void game::MyForm::MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
{
	e->Graphics->FillRectangle(Brushes::Yellow, left_x, left_y, 25, 200);
	e->Graphics->FillRectangle(Brushes::BlueViolet, right_x, right_y, 25, 200);
	e->Graphics->FillEllipse(Brushes::Red, ball_x, ball_y, 50, 50);

}

System::Void game::MyForm::MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	if (e->KeyCode == Keys::Down)
	{
		temp_down = true;
	}
	else if (e->KeyCode == Keys::Up)
	{
		temp_up = true;

	}
}

System::Void game::MyForm::MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	if (e->KeyCode == Keys::Down)
	{
		temp_down = false;
	}
	else if (e->KeyCode == Keys::Up)
	{
		temp_up = false;

	}
	
}

System::Void game::MyForm::timer1_Tick(System::Object^ sender, System::EventArgs^ e)
{
	if (temp_up && right_y>20) right_y -= 20;
	if (temp_down && right_y<600) right_y += 20;
	if (left_y > 20 && check_bot)left_y -= 50;
	else check_bot = false;
	if (left_y < 600 && !check_bot)left_y += 50;
	else check_bot = true;

	if ((ball_x <= left_x + 25 && ball_y <= left_y + 200 && ball_y >= left_y)
		|| (ball_x+50 >= right_x && ball_y + 50 <= right_y + 200 && ball_y + 50 >= right_y))
	{
		//check_ball_x = !check_ball_x;
		direction_x *= -1;
	}
	ball_x += 10 * direction_x;
	if (ball_y <= 0 || ball_y+90 >= Height) 
	{
		//check_ball_y = !check_ball_y;
		direction_y *= -1;
	}
	ball_y += 10 * direction_y;

	if (ball_x<left_x-54 || ball_x>right_x+25) 
	{
		ball_x = 475.5;
		ball_y = 425;
		direction_x *= -1;
		direction_y *= -1;
	}

	Invalidate();
}
