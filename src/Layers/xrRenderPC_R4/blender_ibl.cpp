#include "stdafx.h"

#include "blender_ibl.h"

CBlender_ibl::CBlender_ibl() { description.CLS = 0; }

CBlender_ibl::~CBlender_ibl()
{
}

void CBlender_ibl::Compile(CBlender_Compile& C)
{
	IBlender::Compile(C);

	switch (C.iElement)
	{
	case 0:
		C.r_Pass("stub_screen_space", "ibl_ssr_0", FALSE, FALSE, FALSE); // Downsample
		C.r_dx10Texture("s_image", r2_RT_generic0);	
		C.r_dx10Texture("s_position", r2_RT_P);
        C.r_dx10Texture("s_normal", r2_RT_N);
		C.r_dx10Texture("s_diffuse", r2_RT_albedo);
		C.r_dx10Texture("s_accumulator", r2_RT_accum);
		C.r_dx10Texture("env_s0", r2_T_envs0);
		C.r_dx10Texture("env_s1", r2_T_envs1);
		C.r_dx10Texture("sky_s0", r2_T_sky0);
		C.r_dx10Texture("sky_s1", r2_T_sky1);
		C.r_dx10Texture("s_amb_cube", "engine\\amb_cube");
		C.r_dx10Texture("s_blue_noise", "engine\\blue_noise");
		C.r_dx10Texture("s_depth", r2_RT_depth);
		C.r_dx10Texture("s_depth_z_w", r2_RT_depth_z_w);
		C.r_dx10Texture("s_blur_8", r2_RT_blur_8);

		jitter(C);

		C.r_dx10Sampler("smp_nofilter");
		C.r_dx10Sampler("smp_rtlinear");
		C.r_End();
		break;
	case 1:
		C.r_Pass("stub_screen_space", "ibl_ssr_1", FALSE, FALSE, FALSE); // Downsample
		C.r_dx10Texture("s_image", r2_RT_ssr_0);	
		C.r_dx10Texture("s_image_prev", r2_RT_ssr_2);	
		C.r_dx10Texture("s_ibl_0", r2_RT_ssr_0);	
		C.r_dx10Texture("s_position", r2_RT_P);
        C.r_dx10Texture("s_normal", r2_RT_N);
		C.r_dx10Texture("s_diffuse", r2_RT_albedo);
		C.r_dx10Texture("s_accumulator", r2_RT_accum);
		C.r_dx10Texture("env_s0", r2_T_envs0);
		C.r_dx10Texture("env_s1", r2_T_envs1);
		C.r_dx10Texture("sky_s0", r2_T_sky0);
		C.r_dx10Texture("sky_s1", r2_T_sky1);
		C.r_dx10Texture("s_amb_cube", "engine\\amb_cube");
		C.r_dx10Texture("s_blue_noise", "engine\\blue_noise");	
		C.r_dx10Texture("s_depth", r2_RT_depth);
		C.r_dx10Texture("s_depth_z_w", r2_RT_depth_z_w);
		C.r_dx10Texture("s_blur_8", r2_RT_blur_8);

		jitter(C);

		C.r_dx10Sampler("smp_nofilter");
		C.r_dx10Sampler("smp_rtlinear");
		C.r_End();
		break;
	case 2:
		C.r_Pass("stub_screen_space", "ibl_ssr_2", FALSE, FALSE, FALSE); // Mix
		C.r_dx10Texture("s_image", r2_RT_ssr_1);		
		C.r_dx10Texture("s_position", r2_RT_P);
        C.r_dx10Texture("s_normal", r2_RT_N);
		C.r_dx10Texture("s_diffuse", r2_RT_albedo);
		C.r_dx10Texture("s_accumulator", r2_RT_accum);
		C.r_dx10Texture("env_s0", r2_T_envs0);
		C.r_dx10Texture("env_s1", r2_T_envs1);
		C.r_dx10Texture("sky_s0", r2_T_sky0);
		C.r_dx10Texture("sky_s1", r2_T_sky1);
		C.r_dx10Texture("s_amb_cube", "engine\\amb_cube");
		C.r_dx10Texture("s_blue_noise", "engine\\blue_noise");
		C.r_dx10Texture("s_depth", r2_RT_depth);
		C.r_dx10Texture("s_depth_z_w", r2_RT_depth_z_w);
		C.r_dx10Texture("s_blur_8", r2_RT_blur_8);

		jitter(C);

		C.r_dx10Sampler("smp_nofilter");
		C.r_dx10Sampler("smp_rtlinear");
		C.r_End();
		break;            
	}
}