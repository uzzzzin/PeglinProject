#include "pch.h"
#include "CTextUI.h"


//CTextUI::CTextUI()
//	: LText(" ")
//{
//}

CTextUI::CTextUI(wstring _Text)
	: wsText(_Text)
{
}

CTextUI::~CTextUI()
{
}

void CTextUI::tick(float _DT)
{
	Super::tick(_DT);
}

void CTextUI::render(HDC _dc)
{

	/*Vec2 vPos = GetRenderPos();
	SetBkMode(_dc, 1);
	SetTextColor(_dc, RGB(255, 255, 255));*/

	//HFONT hFont, oldFont;
	//hFont = CreateFont(14, 0, 0, 0, 700, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH || FF_ROMAN, wText));
	//oldFont = (HFONT)SelectObject(_dc, hFont);
	//SetTextAlign(_dc, TA_CENTER);
	////TextOut(_dc, vPos.x, vPos.y, m_Text.c_str(), m_Text.length());


	//SetBkMode(_dc, TRANSPARENT);
	//SetTextColor(_dc, RGB(255, 255, 255));
	//TextOut(_dc, (int)(REALCENTER.x) + 20, (int)(REALCENTER.y) + 20, wText, 5);
	Super::render(_dc);
}

void CTextUI::OnHovered(Vec2 _vMousePos)
{
	//SetTextColor(_dc, RGB(150, 150, 150));
}

void CTextUI::OnUnHovered(Vec2 _vMousePos)
{
}

void CTextUI::MouseOn(Vec2 _vMousePos)
{
}

void CTextUI::LBtnDown(Vec2 _vMousePos)
{
}

void CTextUI::LBtnUp(Vec2 _vMousePos)
{
}

void CTextUI::LBtnClicked(Vec2 _vMousePos)
{
}
