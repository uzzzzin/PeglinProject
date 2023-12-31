#pragma once


#define SINGLETON(ClassType) public:\
								static ClassType* GetInst()\
								{\
									static ClassType inst;\
									return &inst;\
								}\
							 public:\
								 ClassType* operator = (const ClassType& _Origin) = delete;\
							 private:\
								 ClassType();\
								 ClassType(const ClassType& _Origin) = delete;\
							 	 ~ClassType();

#define KEY_CHECK(Key, State) CKeyMgr::GetInst()->GetKeyState(Key) == State
#define DT	CTimeMgr::GetInst()->GetDeltaTime()

#define KEY_TAP(Key) KEY_CHECK(Key, TAP)
#define KEY_PRESSED(Key) KEY_CHECK(Key, PRESSED)
#define KEY_RELEASED(Key) KEY_CHECK(Key, RELEASED)
#define KEY_NONE(Key) KEY_CHECK(Key, NONE)

#define PI	3.14159265348979f

#define GAME_FOLDER MyGame

#define GENERATED_OBJECT(type) typedef type Super;



#define DEBUG_RENDER CEngine::GetInst()->DebugRender()
#define SELECT_PEN(DC, TYPE) FSelectPen tempPenSelect(DC, TYPE)
#define SELECT_BRUSH(DC, hBrush) FSelectBrush tempBrushSelect(DC, hBrush)

#define TILE_SIZE 64

#define CLONE(type) virtual type* Clone() {return new type(*this);}
#define CLONE_DISABLE(type) virtual type* Clone() {return nullptr;}


#define REALCENTER Vec2(800.f, 450.f)





// Key Value
enum KEY
{
	_0,
	_1,
	_2,
	_3,
	_4,
	_5,
	_6,
	_7,
	_8,
	_9,

	NUM0,
	NUM1,
	NUM2,
	NUM3,
	NUM4,
	NUM5,
	NUM6,
	NUM7,
	NUM8,
	NUM9,

	Q,
	W,
	E,
	R,
	T,
	Y,
	U,
	I,
	O,
	P,

	A,
	S,
	D,
	F,
	G,
	H,
	J,
	K,
	L,

	Z,
	X,
	C,
	V,
	B,
	N,
	M,

	TAB,
	LSHIFT,
	LALT,
	LCTRL,
	SPACE,

	ESC,
	ENTER,
	BACK,

	LEFT,
	RIGHT,
	UP,
	DOWN,

	LBTN,
	RBTN,

	KEY_END,
};

enum KEY_STATE
{
	NONE,
	TAP,
	PRESSED,
	RELEASED,
};

enum LAYER
{
	DEFAULT,
	BG,
	TILE,
	PLATFORM,
	PEG,
	ORB,
	FOREST,
	MONSTER,
	PEGLIN,
	PLAYER_PJ,
	MONSTER_PJ,
	WORLD_STATIC,

	UI = 31,
	END = 32,
};


enum TASK_TYPE
{
	// Param1 : Layer Type, Param2 : Object Adress
	CREATE_OBJECT,

	// Param1 : Object Adress
	DELETE_OBJECT,

	// Param1 : LEVEL_TYPE
	LEVEL_CHANGE,
};



enum PEN_TYPE
{
	GREEN_PEN,
	BLUE_PEN,
	RED_PEN,

	PEN_END,
};


enum LOG_LEVEL
{
	LOGLOG,
	WARNING,
	ERR,
};

enum class LEVEL_TYPE
{
	START_LEVEL,
	STAGE_1_LEVEL,
	STAGE_2_LEVEL,
	STAGE_BOSS_LEVEL,
	END_LEVEL,
	BOARD_EDIT_LEVEL,
	END,
};

enum PEG_TYPE
{
	GREY_PEG,
	COIN_PEG,
	CRITICAL_PEG,
	REFRESH_PEG,
	BOMB_PEG,
	SLIMED_GREY_PEG,
	SLIMED_COIN_PEG,

	PEG_TYPE_END
};

enum ORB_TYPE
{
	PEBBALL,
	DAGGORB,
	INFERNORB,
	SPHEAR,
	RUBBORB,

	ORB_TYPE_END
};

enum STAGE_STATE
{
	STATE_INIT,
	BEFORE_SHOOT,
	SHOOTING,
	PEGLIN_ATTACK,
	MONSTER_ATTACK,
	PEGLIN_DIE,
	STAGE_CLEAR,

	START_LEVEL_ENTER,
	STAGE_STATE_END

};

enum ENEMY_TYPE
{
	//RED_SLIME,
	//GREEN_SLIME,
	BLUE_SLIME,
	STUMP,
	LARGE_SLIME,
	BOSS_SLIME,

	ENEMY_TYPE_END

};

enum class ENORMAL_MON_STATE
{
	NORMAL_MON_IDLE,
	NORMAL_MON_TRACE,
};

#define CheckPosAndScale Vec2 vPos = GetPos();\
Vec2 vScale = GetScale();\
if (KEY_TAP(KEY::W)) {\
    SetPos({ vPos.x, vPos.y - 1 });\
    wstring buffer = L"";\
    buffer += L"vPos x : " + std::to_wstring(GetPos().x) + L" y: " + std::to_wstring(GetPos().y);\
    CLogMgr::GetInst()->AddLog(FLog{ LOG_LEVEL::ERR, buffer });\
}\
if (KEY_TAP(KEY::S)) {\
    SetPos({ vPos.x, vPos.y + 1 });\
    wstring buffer = L"";\
    buffer += L"vPos x : " + std::to_wstring(GetPos().x) + L" y: " + std::to_wstring(GetPos().y);\
    CLogMgr::GetInst()->AddLog(FLog{ LOG_LEVEL::ERR, buffer });\
}\
if (KEY_TAP(KEY::A)) {\
    SetPos({ vPos.x - 1, vPos.y });\
    wstring buffer = L"";\
    buffer += L"vPos x : " + std::to_wstring(GetPos().x) + L" y: " + std::to_wstring(GetPos().y);\
    CLogMgr::GetInst()->AddLog(FLog{ LOG_LEVEL::ERR, buffer });\
}\
if (KEY_TAP(KEY::D)) {\
    SetPos({ vPos.x + 1, vPos.y });\
    wstring buffer = L"";\
    buffer += L"vPos x : " + std::to_wstring(GetPos().x) + L" y: " + std::to_wstring(GetPos().y);\
    CLogMgr::GetInst()->AddLog(FLog{ LOG_LEVEL::ERR, buffer });\
}\
\
if (KEY_TAP(KEY::UP)) {\
    SetScale({ vScale.x, vScale.y + 0.1f });\
    wstring buffer = L"";\
    buffer += L"vPos x : " + std::to_wstring(GetScale().x) + L" y: " + std::to_wstring(GetScale().y);\
    CLogMgr::GetInst()->AddLog(FLog{ LOG_LEVEL::ERR, buffer });\
}\
if (KEY_TAP(KEY::DOWN)) {\
    SetScale({ vScale.x, vScale.y - 0.1f });\
    wstring buffer = L"";\
    buffer += L"vPos x : " + std::to_wstring(GetScale().x) + L" y: " + std::to_wstring(GetScale().y);\
    CLogMgr::GetInst()->AddLog(FLog{ LOG_LEVEL::ERR, buffer });\
}\
if (KEY_TAP(KEY::LEFT)) {\
    SetScale({ vScale.x - 0.1f, vScale.y });\
    wstring buffer = L"";\
    buffer += L"vPos x : " + std::to_wstring(GetScale().x) + L" y: " + std::to_wstring(GetScale().y);\
    CLogMgr::GetInst()->AddLog(FLog{ LOG_LEVEL::ERR, buffer });\
}\
if (KEY_TAP(KEY::RIGHT)) {\
    SetScale({ vScale.x + 0.1f, vScale.y });\
    wstring buffer = L"";\
    buffer += L"vPos x : " + std::to_wstring(GetScale().x) + L" y: " + std::to_wstring(GetScale().y);\
    CLogMgr::GetInst()->AddLog(FLog{ LOG_LEVEL::ERR, buffer });\
}