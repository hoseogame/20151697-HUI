#pragma once

//클래스에서 맴버변수를 만들어주는 동시에 Get, Set함수를 만들어준다.
#define CLASS_VARIABLE(type, name) \
	private: \
		type m_##name; \
	public: \
		type get##name() const { return m_##name; } \
		const void set##name(type _name) { m_##name = _name; }