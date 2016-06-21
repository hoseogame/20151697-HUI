#pragma once

//Ŭ�������� �ɹ������� ������ִ� ���ÿ� Get, Set�Լ��� ������ش�.
#define CLASS_VARIABLE(type, name) \
	private: \
		type m_##name; \
	public: \
		type get##name() const { return m_##name; } \
		const void set##name(type _name) { m_##name = _name; }