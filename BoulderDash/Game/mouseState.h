#ifndef MOUSESTATE_H
#define MOUSESTATE_H

namespace BoulderDash
{
	class MouseState
	{
	private:
		bool m_leftButton, m_rightButton;
		int m_x, m_y;
	public:
		MouseState() { }

		MouseState(bool leftButton, bool rightButton, int x, int y)
			: m_leftButton(leftButton), m_rightButton(rightButton), m_x(x), m_y(y)
		{ }

		bool leftButton() const { return m_leftButton; }
		bool rightButton() const { return m_rightButton; }

		int x() const { return m_x; }
		int y() const { return m_y; }
	};
}

#endif