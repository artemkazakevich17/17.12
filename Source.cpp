#include "setting.h"
#include "header.h"
using namespace sf;
int main() {
	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	window.setFramerateLimit(FPS);
	Game game;
	game.window.setSize(Vector);
	//�������� �������� ����
	//�������
	RectangleShape leftBat, rightBat;

	initleftBat( leftBatColor, leftBatStartPos);
	initrightBat(rightBatColor, rightBatStartPos);
	rightBat.setPosition(WINDOW_WIDTH - batOffset, (WINDOW_HEIGHT - batHeight) / 2);
	float leftBatSpeedY = 0.f;
	float rightBatSpeedY = 0.f;

	//�����
	CircleShape ball(ballRadius);
	ball.setFillColor(ballColor);
	ball.setPosition((WINDOW_WIDTH - 2 * ballRadius) / 2,
		(WINDOW_HEIGHT - 2 * ballRadius) / 2);

	float arr_speed[]{ -5.f, -4.f, -3.f, -2.f, -1.f, 1.f, 2.f, 3.f, 4.f, 5.f };
	float index = rand() % 10;
	float ball_speedx = arr_speed [index];
	index = rand() % 10;
	float ball_speedy = arr_speed [index];
	// C���
	int leftPlayerScore = 0;
	int rightPlayerScore = 0;
	Font font;
	font.loadFromFile("ds-digib.ttf");
	Text leftPlayerScoreText;
	leftPlayerScoreText.setString(std::to_string(leftPlayerScore)); //�������� ������� ��� �����������
	leftPlayerScoreText.setFont(font);
	leftPlayerScoreText.setCharacterSize(64);
	leftPlayerScoreText.setPosition(200.f, 10.f);

	Text rightPlayerScoreText;
	rightPlayerScoreText.setString(std::to_string(rightPlayerScore));
	rightPlayerScoreText.setFont(font);
	rightPlayerScoreText.setCharacterSize(64);
	rightPlayerScoreText.setPosition(550.f, 10.f);


		// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen())
	{
		//1 ������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
		}
		//2 ���������� ��������
		//�����
		//�������� ������
		ball.move(ball_speedx, ball_speedy);
		//�����-����� �� �����
		if (ball.getPosition().x <= 0)
		{
			ballReboundX(ball_speedx, rightPlayerScore,
				rightPlayerScoreText);
			// ������ ����� ����� ���
			rightPlayerScore++;
		}
		//��� ������ �������

		if (ball.getPosition().x >= (WINDOW_WIDTH - 2 * ballRadius))
			ballReboundX(ball_speedx, leftPlayerScore,
				leftPlayerScoreText);
		{
			//��������� �� ��� X ��������� �� ���������������
			ball_speedx = -ball_speedx;
			leftPlayerScore++;
			leftPlayerScoreText.setString(std::to_string
			(leftPlayerScore));
		}
		//�������� ������� ������
		/*//���� ������� W ������
		if (Keyboard::isKeyPressed(Keyboard::W)) {
			leftBatSpeedY = -BAT_SPEED;
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			leftBatSpeedY = BAT_SPEED;
		}
		//������� �������
		leftBat.move(0, leftBatSpeedY);
		// � ����� �� �������� ��������
		leftBatSpeedY = 0;*/
		controlBat(leftBat, leftBatSpeedY, Keyboard::W, Keyboard::S);
		controlBat(rightBatSpeedY, Keyboard::Up,
			Keyboard::Down);


		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			rightBatSpeedY = -BAT_SPEED;
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			rightBatSpeedY = BAT_SPEED;
		}


		//3 ��������� ����
		drawAll(window, leftBat, rightBat, ball, leftPlayerScoreText,
			rightPlayerScoreText);
	}
		return 0;

	
	}