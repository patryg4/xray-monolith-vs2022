#pragma once

class CBlender_ibl : public IBlender
{
public:
	virtual LPCSTR getComment() { return "IBL!"; }
	virtual BOOL canBeDetailed() { return FALSE; }
	virtual BOOL canBeLMAPped() { return FALSE; }

	virtual void Compile(CBlender_Compile& C);

	CBlender_ibl();
	virtual ~CBlender_ibl();
};