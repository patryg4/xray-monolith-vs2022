#pragma once


// r3xx code-path (MRT)
#define		r2_RT_MSAAdepth	"$user$msaadepth"	         // MRT
#define		r2_RT_P				"$user$position"		      // MRT
#define		r2_RT_N				"$user$normal"			      // MRT
#define		r2_RT_albedo		"$user$albedo"			      // MRT

// other
#define		r2_RT_accum			"$user$accum"			// ---	16 bit fp or 16 bit fx

#define		r2_T_envs0			"$user$env_s0"			// ---
#define		r2_T_envs1			"$user$env_s1"			// ---

#define		r2_T_sky0			"$user$sky0"
#define		r2_T_sky1			"$user$sky1"

#define 	r2_RT_sunshafts0	"$user$sun_shafts0"		// first rt
#define		r2_RT_sunshafts1	"$user$sun_shafts1"		// second rt


#define		r2_RT_ssao_temp		"$user$ssao_temp"		//temporary rt for ssao calculation
#define		r2_RT_half_depth	"$user$half_depth"		//temporary rt for ssao calculation

#define		r2_RT_generic0		"$user$generic0"		// ---
#define		r2_RT_generic0_r	"$user$generic0_r"	// ---
#define		r2_RT_generic1		"$user$generic1"		// ---
#define		r2_RT_generic1_r	"$user$generic1_r"	// ---
#define		r2_RT_generic2		"$user$generic2"		// ---	//	Igor: for volumetric lights
#define		r2_RT_generic		"$user$generic"		// ---

#define		r2_RT_smap_surf		"$user$smap_surf"		// --- directional
#define		r2_RT_smap_depth	"$user$smap_depth"		// ---directional
#define		r2_RT_smap_depth_minmax	"$user$smap_depth_minmax"

#define		r2_ds2_fade			"$user$ds2_fade"		// ---

#define		r2_jitter			"$user$jitter_"			// --- dither
#define		r2_jitter_mipped	"$user$jitter_mipped"			// --- dither
#define		r2_sunmask			"sunmask"

#define		r2_RT_secondVP		"$user$viewport2"		// --#SM+#-- +SecondVP+ O?a�eo ea?oe�e� n� �o�?�a� ��?i�?oa

#define		r2_RT_blur_h_2	"$user$blur_h_2"
#define		r2_RT_blur_2		"$user$blur_2"

#define		r2_RT_blur_h_4	"$user$blur_h_4"
#define		r2_RT_blur_4	"$user$blur_4"

#define		r2_RT_blur_h_8	"$user$blur_h_8"
#define		r2_RT_blur_8	"$user$blur_8"

#define		r2_RT_pp_bloom	"$user$pp_bloom"

#define		r2_RT_dof			"$user$dof"
#define		r2_RT_ui			"$user$ui"

#define		r2_RT_smaa_edgetex "$user$smaa_edgetex"
#define		r2_RT_smaa_blendtex "$user$smaa_blendtex"

#define		r2_RT_depth_z_w "$user$depth_z_w"
#define		r2_RT_depth "$user$depth"

#define		r2_RT_ssr_0 "$user$ssr_0"
#define		r2_RT_ssr_1 "$user$ssr_1"
#define		r2_RT_ssr_2 "$user$ssr_2"

#define		r2_RT_bloom_0 "$user$bloom_0"
#define		r2_RT_bloom_1 "$user$bloom_1"
#define		r2_RT_bloom_2 "$user$bloom_2"
#define		r2_RT_bloom_3 "$user$bloom_3"
#define		r2_RT_bloom_4 "$user$bloom_4"


#define		JITTER(a) r2_jitter #a

const float SMAP_near_plane = .1f;

const u32 SMAP_adapt_min = 768;
const u32 SMAP_adapt_optimal = 768;
const u32 SMAP_adapt_max = 1536;

const u32 TEX_jitter = 64;
const u32 TEX_jitter_count = 5; // for HBAO

// deffer
#define		SE_R2_NORMAL_HQ		0	// high quality/detail
#define		SE_R2_NORMAL_LQ		1	// low quality
#define		SE_R2_SHADOW		2	// shadow generation

// spot
#define		SE_L_FILL			0
#define		SE_L_UNSHADOWED		1
#define		SE_L_NORMAL			2	// typical, scaled
#define		SE_L_FULLSIZE		3	// full texture coverage
#define		SE_L_TRANSLUENT		4	// with opacity/color mask

// mask
#define		SE_MASK_SPOT		0
#define		SE_MASK_POINT		1
#define		SE_MASK_DIRECT		2
#define		SE_MASK_ACCUM_VOL	3
#define		SE_MASK_ACCUM_2D	4
#define		SE_MASK_ALBEDO		5

// sun
#define		SE_SUN_NEAR			0
#define		SE_SUN_MIDDLE		1
#define		SE_SUN_FAR			2
#define		SE_SUN_LUMINANCE	3
#define		SE_SUN_NEAR_MINMAX	4
//	For rain R3 rendering
#define		SE_SUN_RAIN_SMAP	5

extern float ps_r2_gloss_factor;
extern float ps_r2_gloss_min;
IC float u_diffuse2s(float x, float y, float z)
{
	float v = (x + y + z) / 3.f;
	return ps_r2_gloss_min + ps_r2_gloss_factor * ((v < 1) ? powf(v, 2.f / 3.f) : v);
}

IC float u_diffuse2s(Fvector3& c) { return u_diffuse2s(c.x, c.y, c.z); }
