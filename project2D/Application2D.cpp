#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	m_CoatT = new aie::Texture("./textures/GreenCoat.png");

	m_font = new aie::Font("./font/consolas.ttf", 32);
	
	m_timer = 0;

	m_CoatGuy = { 30, 40};

	North = { 0,  5 };
	South = { 0, -5 };
	East = { 5, 0 };
	West = { -5, 0 };

	op;

	temp = 0;

	return true;
}

void Application2D::shutdown() {
	
	delete m_font;
	delete m_2dRenderer;
	delete m_CoatT;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;

	temp += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	if (input->isKeyDown(aie::INPUT_KEY_A))
	{
		m_CoatGuy += West;
		m_2dRenderer->setUVRect(int(m_timer * 10) % 4 / 4.0f, .25, 1.f / 4, 1.f / 4);
		op = 2;
	}

	if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		m_CoatGuy += East;
		m_2dRenderer->setUVRect(int(m_timer * 10) % 4 / 4.0f, .50, 1.f / 4, 1.f / 4);
		op = 3;
	}

	if (m_CoatGuy.getY() < getWindowHeight() - 680)
	{
		m_CoatGuy += North;
	}

	if (m_CoatGuy.getY() > getWindowHeight() - 40)
	{
		m_CoatGuy += South;
	}

	if (m_CoatGuy.getX() > getWindowWidth() - 30)
	{
		m_CoatGuy += West;
	}

	if (m_CoatGuy.getX() < getWindowWidth() - 1250)
	{
		m_CoatGuy += East;
	}

	switch (op)
	{
	case 2:
		if (input->isKeyUp(aie::INPUT_KEY_A))
		{
			m_2dRenderer->setUVRect(0 / 4.0f, .25, 1.f / 4, 1.f / 4);
		}
		break;

	default:
	case 3:
		if (input->isKeyUp(aie::INPUT_KEY_D))
		{
			m_2dRenderer->setUVRect(0 / 4.0f, .50, 1.f / 4, 1.f / 4);
		}
		break;
	}

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(0, 0);

	// begin drawing sprites
	m_2dRenderer->begin();

	m_2dRenderer->drawSprite(m_CoatT, m_CoatGuy.getX(), m_CoatGuy.getY(), 50, 80, 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}