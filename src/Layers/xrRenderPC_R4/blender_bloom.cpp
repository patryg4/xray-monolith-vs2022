#include "stdafx.h"

#include "blender_bloom.h"

CBlender_bloom::CBlender_bloom() { description.CLS = 0; }

CBlender_bloom::~CBlender_bloom()
{
}

void CBlender_bloom::Compile(CBlender_Compile& C)
{
	IBlender::Compile(C);

	switch (C.iElement)
	{
	case 0:
		C.r_Pass("stub_screen_space", "hdr_bloom_0", FALSE, FALSE, FALSE); // Downsample
		C.r_dx10Texture("s_image", r2_RT_generic0);	

		C.r_dx10Sampler("smp_nofilter");
		C.r_dx10Sampler("smp_rtlinear");
		C.r_End();
		break;
	case 1:
		C.r_Pass("stub_screen_space", "hdr_bloom_0", FALSE, FALSE, FALSE); // Downsample
		C.r_dx10Texture("s_image", r2_RT_bloom_0);	

		C.r_dx10Sampler("smp_nofilter");
		C.r_dx10Sampler("smp_rtlinear");
		C.r_End();
		break;
	case 2:
		C.r_Pass("stub_screen_space", "hdr_bloom_1", FALSE, FALSE, FALSE); // Mix
		C.r_dx10Texture("s_bloom_0", r2_RT_bloom_0);	
		C.r_dx10Texture("s_bloom_1", r2_RT_bloom_1);	

		C.r_dx10Sampler("smp_nofilter");
		C.r_dx10Sampler("smp_rtlinear");
		C.r_End();
		break;
	case 3:
		C.r_Pass("stub_screen_space", "hdr_bloom_2", FALSE, FALSE, FALSE); // Blur X
		C.r_dx10Texture("s_image", r2_RT_bloom_2);	

		C.r_dx10Sampler("smp_nofilter");
		C.r_dx10Sampler("smp_rtlinear");
		C.r_End();
		break;   
	case 4:
		C.r_Pass("stub_screen_space", "hdr_bloom_3", FALSE, FALSE, FALSE); // Blur Y
		C.r_dx10Texture("s_image", r2_RT_bloom_3);	

		C.r_dx10Sampler("smp_nofilter");
		C.r_dx10Sampler("smp_rtlinear");
		C.r_End();
		break;                  
	}
}