#pragma once

#include <Vector2.h>
#include <Vector3.h>
#include "Application.h"
#include "Renderer2D.h"

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	aie::Texture*		m_CoatT;

	Vector2 m_CoatGuy;

	Vector2 North;
	Vector2 South;
	Vector2 East;
	Vector2 West;

	float m_timer;

	float m_CoatX, m_CoatY;

	float temp;

	int op;
};