#include "stdafx.h"

#include "blender_depth.h"

CBlender_depth::CBlender_depth() { description.CLS = 0; }

CBlender_depth::~CBlender_depth()
{
}

void CBlender_depth::Compile(CBlender_Compile& C)
{
	IBlender::Compile(C);

	switch (C.iElement)
	{
	case 0:
		C.r_Pass("stub_screen_space", "depth_z_w", FALSE, FALSE, FALSE); 
		C.r_dx10Texture("s_position", r2_RT_P);
		C.r_dx10Sampler("smp_nofilter");
		C.r_End();
		break;
	case 1:
		C.r_Pass("stub_screen_space", "depth", FALSE, FALSE, FALSE); 	
		C.r_dx10Texture("s_position", r2_RT_P);
		C.r_dx10Sampler("smp_nofilter");
		C.r_End();
		break;          
	}
}