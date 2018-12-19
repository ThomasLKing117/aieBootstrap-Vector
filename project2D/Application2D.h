#pragma once

#include <Vector2.h>
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

	float m_CoatGuyX, m_CoatGuyY;

	float North;
	float South;
	float East;
	float West;

	float m_timer;

	int op;

	float jumpForce;

	float gravity;
};