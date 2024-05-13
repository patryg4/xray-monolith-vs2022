#pragma once

class CBlender_bloom : public IBlender
{
public:
	virtual LPCSTR getComment() { return "HDR BLOOM!"; }
	virtual BOOL canBeDetailed() { return FALSE; }
	virtual BOOL canBeLMAPped() { return FALSE; }

	virtual void Compile(CBlender_Compile& C);

	CBlender_bloom();
	virtual ~CBlender_bloom();
};