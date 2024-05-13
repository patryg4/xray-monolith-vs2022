#pragma once

class CBlender_depth : public IBlender
{
public:
	virtual LPCSTR getComment() { return "depth!"; }
	virtual BOOL canBeDetailed() { return FALSE; }
	virtual BOOL canBeLMAPped() { return FALSE; }

	virtual void Compile(CBlender_Compile& C);

	CBlender_depth();
	virtual ~CBlender_depth();
};