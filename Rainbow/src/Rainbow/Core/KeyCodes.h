#pragma once

namespace Rainbow
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define RAINBOW_KEY_SPACE           ::Rainbow::Key::Space
#define RAINBOW_KEY_APOSTROPHE      ::Rainbow::Key::Apostrophe    /* ' */
#define RAINBOW_KEY_COMMA           ::Rainbow::Key::Comma         /* , */
#define RAINBOW_KEY_MINUS           ::Rainbow::Key::Minus         /* - */
#define RAINBOW_KEY_PERIOD          ::Rainbow::Key::Period        /* . */
#define RAINBOW_KEY_SLASH           ::Rainbow::Key::Slash         /* / */
#define RAINBOW_KEY_0               ::Rainbow::Key::D0
#define RAINBOW_KEY_1               ::Rainbow::Key::D1
#define RAINBOW_KEY_2               ::Rainbow::Key::D2
#define RAINBOW_KEY_3               ::Rainbow::Key::D3
#define RAINBOW_KEY_4               ::Rainbow::Key::D4
#define RAINBOW_KEY_5               ::Rainbow::Key::D5
#define RAINBOW_KEY_6               ::Rainbow::Key::D6
#define RAINBOW_KEY_7               ::Rainbow::Key::D7
#define RAINBOW_KEY_8               ::Rainbow::Key::D8
#define RAINBOW_KEY_9               ::Rainbow::Key::D9
#define RAINBOW_KEY_SEMICOLON       ::Rainbow::Key::Semicolon     /* ; */
#define RAINBOW_KEY_EQUAL           ::Rainbow::Key::Equal         /* = */
#define RAINBOW_KEY_A               ::Rainbow::Key::A
#define RAINBOW_KEY_B               ::Rainbow::Key::B
#define RAINBOW_KEY_C               ::Rainbow::Key::C
#define RAINBOW_KEY_D               ::Rainbow::Key::D
#define RAINBOW_KEY_E               ::Rainbow::Key::E
#define RAINBOW_KEY_F               ::Rainbow::Key::F
#define RAINBOW_KEY_G               ::Rainbow::Key::G
#define RAINBOW_KEY_H               ::Rainbow::Key::H
#define RAINBOW_KEY_I               ::Rainbow::Key::I
#define RAINBOW_KEY_J               ::Rainbow::Key::J
#define RAINBOW_KEY_K               ::Rainbow::Key::K
#define RAINBOW_KEY_L               ::Rainbow::Key::L
#define RAINBOW_KEY_M               ::Rainbow::Key::M
#define RAINBOW_KEY_N               ::Rainbow::Key::N
#define RAINBOW_KEY_O               ::Rainbow::Key::O
#define RAINBOW_KEY_P               ::Rainbow::Key::P
#define RAINBOW_KEY_Q               ::Rainbow::Key::Q
#define RAINBOW_KEY_R               ::Rainbow::Key::R
#define RAINBOW_KEY_S               ::Rainbow::Key::S
#define RAINBOW_KEY_T               ::Rainbow::Key::T
#define RAINBOW_KEY_U               ::Rainbow::Key::U
#define RAINBOW_KEY_V               ::Rainbow::Key::V
#define RAINBOW_KEY_W               ::Rainbow::Key::W
#define RAINBOW_KEY_X               ::Rainbow::Key::X
#define RAINBOW_KEY_Y               ::Rainbow::Key::Y
#define RAINBOW_KEY_Z               ::Rainbow::Key::Z
#define RAINBOW_KEY_LEFT_BRACKET    ::Rainbow::Key::LeftBracket   /* [ */
#define RAINBOW_KEY_BACKSLASH       ::Rainbow::Key::Backslash     /* \ */
#define RAINBOW_KEY_RIGHT_BRACKET   ::Rainbow::Key::RightBracket  /* ] */
#define RAINBOW_KEY_GRAVE_ACCENT    ::Rainbow::Key::GraveAccent   /* ` */
#define RAINBOW_KEY_WORLD_1         ::Rainbow::Key::World1        /* non-US #1 */
#define RAINBOW_KEY_WORLD_2         ::Rainbow::Key::World2        /* non-US #2 */

/* Function keys */
#define RAINBOW_KEY_ESCAPE          ::Rainbow::Key::Escape
#define RAINBOW_KEY_ENTER           ::Rainbow::Key::Enter
#define RAINBOW_KEY_TAB             ::Rainbow::Key::Tab
#define RAINBOW_KEY_BACKSPACE       ::Rainbow::Key::Backspace
#define RAINBOW_KEY_INSERT          ::Rainbow::Key::Insert
#define RAINBOW_KEY_DELETE          ::Rainbow::Key::Delete
#define RAINBOW_KEY_RIGHT           ::Rainbow::Key::Right
#define RAINBOW_KEY_LEFT            ::Rainbow::Key::Left
#define RAINBOW_KEY_DOWN            ::Rainbow::Key::Down
#define RAINBOW_KEY_UP              ::Rainbow::Key::Up
#define RAINBOW_KEY_PAGE_UP         ::Rainbow::Key::PageUp
#define RAINBOW_KEY_PAGE_DOWN       ::Rainbow::Key::PageDown
#define RAINBOW_KEY_HOME            ::Rainbow::Key::Home
#define RAINBOW_KEY_END             ::Rainbow::Key::End
#define RAINBOW_KEY_CAPS_LOCK       ::Rainbow::Key::CapsLock
#define RAINBOW_KEY_SCROLL_LOCK     ::Rainbow::Key::ScrollLock
#define RAINBOW_KEY_NUM_LOCK        ::Rainbow::Key::NumLock
#define RAINBOW_KEY_PRINT_SCREEN    ::Rainbow::Key::PrintScreen
#define RAINBOW_KEY_PAUSE           ::Rainbow::Key::Pause
#define RAINBOW_KEY_F1              ::Rainbow::Key::F1
#define RAINBOW_KEY_F2              ::Rainbow::Key::F2
#define RAINBOW_KEY_F3              ::Rainbow::Key::F3
#define RAINBOW_KEY_F4              ::Rainbow::Key::F4
#define RAINBOW_KEY_F5              ::Rainbow::Key::F5
#define RAINBOW_KEY_F6              ::Rainbow::Key::F6
#define RAINBOW_KEY_F7              ::Rainbow::Key::F7
#define RAINBOW_KEY_F8              ::Rainbow::Key::F8
#define RAINBOW_KEY_F9              ::Rainbow::Key::F9
#define RAINBOW_KEY_F10             ::Rainbow::Key::F10
#define RAINBOW_KEY_F11             ::Rainbow::Key::F11
#define RAINBOW_KEY_F12             ::Rainbow::Key::F12
#define RAINBOW_KEY_F13             ::Rainbow::Key::F13
#define RAINBOW_KEY_F14             ::Rainbow::Key::F14
#define RAINBOW_KEY_F15             ::Rainbow::Key::F15
#define RAINBOW_KEY_F16             ::Rainbow::Key::F16
#define RAINBOW_KEY_F17             ::Rainbow::Key::F17
#define RAINBOW_KEY_F18             ::Rainbow::Key::F18
#define RAINBOW_KEY_F19             ::Rainbow::Key::F19
#define RAINBOW_KEY_F20             ::Rainbow::Key::F20
#define RAINBOW_KEY_F21             ::Rainbow::Key::F21
#define RAINBOW_KEY_F22             ::Rainbow::Key::F22
#define RAINBOW_KEY_F23             ::Rainbow::Key::F23
#define RAINBOW_KEY_F24             ::Rainbow::Key::F24
#define RAINBOW_KEY_F25             ::Rainbow::Key::F25

/* Keypad */
#define RAINBOW_KEY_KP_0            ::Rainbow::Key::KP0
#define RAINBOW_KEY_KP_1            ::Rainbow::Key::KP1
#define RAINBOW_KEY_KP_2            ::Rainbow::Key::KP2
#define RAINBOW_KEY_KP_3            ::Rainbow::Key::KP3
#define RAINBOW_KEY_KP_4            ::Rainbow::Key::KP4
#define RAINBOW_KEY_KP_5            ::Rainbow::Key::KP5
#define RAINBOW_KEY_KP_6            ::Rainbow::Key::KP6
#define RAINBOW_KEY_KP_7            ::Rainbow::Key::KP7
#define RAINBOW_KEY_KP_8            ::Rainbow::Key::KP8
#define RAINBOW_KEY_KP_9            ::Rainbow::Key::KP9
#define RAINBOW_KEY_KP_DECIMAL      ::Rainbow::Key::KPDecimal
#define RAINBOW_KEY_KP_DIVIDE       ::Rainbow::Key::KPDivide
#define RAINBOW_KEY_KP_MULTIPLY     ::Rainbow::Key::KPMultiply
#define RAINBOW_KEY_KP_SUBTRACT     ::Rainbow::Key::KPSubtract
#define RAINBOW_KEY_KP_ADD          ::Rainbow::Key::KPAdd
#define RAINBOW_KEY_KP_ENTER        ::Rainbow::Key::KPEnter
#define RAINBOW_KEY_KP_EQUAL        ::Rainbow::Key::KPEqual

#define RAINBOW_KEY_LEFT_SHIFT      ::Rainbow::Key::LeftShift
#define RAINBOW_KEY_LEFT_CONTROL    ::Rainbow::Key::LeftControl
#define RAINBOW_KEY_LEFT_ALT        ::Rainbow::Key::LeftAlt
#define RAINBOW_KEY_LEFT_SUPER      ::Rainbow::Key::LeftSuper
#define RAINBOW_KEY_RIGHT_SHIFT     ::Rainbow::Key::RightShift
#define RAINBOW_KEY_RIGHT_CONTROL   ::Rainbow::Key::RightControl
#define RAINBOW_KEY_RIGHT_ALT       ::Rainbow::Key::RightAlt
#define RAINBOW_KEY_RIGHT_SUPER     ::Rainbow::Key::RightSuper
#define RAINBOW_KEY_MENU            ::Rainbow::Key::Menu