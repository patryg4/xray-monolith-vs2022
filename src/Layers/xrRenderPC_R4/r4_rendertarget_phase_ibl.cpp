#include "stdafx.h"

void CRenderTarget::phase_ibl()
{
	//Get common data
	u32 Offset = 0;
	float d_Z = EPS_S;
	float d_W = 1.0f;
	u32 C = color_rgba(0, 0, 0, 255);
	FLOAT ColorRGBA[4] = {0.0f, 0.0f, 0.0f, 0.0f};

	//Full resolution
	float w = float(Device.dwWidth);
	float h = float(Device.dwHeight);	

	Fvector2 p0, p1;
	p0.set(0.0f, 0.0f);
	p1.set(1.0f, 1.0f);

	Fmatrix m_previous, m_current;
	{
		static Fmatrix m_saved_viewproj;

		// (new-camera) -> (world) -> (old_viewproj)
		Fmatrix m_invview;
		m_invview.invert(Device.mView);
		m_previous.mul(m_saved_viewproj, m_invview);
		m_current.set(Device.mProject);
		m_saved_viewproj.set(Device.mFullTransform);
	}

/////////////////////////////////////////////////////////////////////////////////
	u_setrt(rt_ibl_0, 0, 0, HW.pBaseZB);
	RCache.set_CullMode(CULL_NONE);
	RCache.set_Stencil(FALSE);
	HW.pContext->ClearRenderTargetView(rt_ibl_0->pRT, ColorRGBA);

	// Fill vertex buffer
	FVF::TL* pv = (FVF::TL*)RCache.Vertex.Lock(4, g_combine->vb_stride, Offset);
	pv->set(0, float(h), d_Z, d_W, C, p0.x, p1.y); pv++;
	pv->set(0, 0, d_Z, d_W, C, p0.x, p0.y); pv++;
	pv->set(float(w), float(h), d_Z, d_W, C, p1.x, p1.y); pv++;
	pv->set(float(w), 0, d_Z, d_W, C, p1.x, p0.y); pv++;
	RCache.Vertex.Unlock(4, g_combine->vb_stride);

	// Draw COLOR
	RCache.set_Element(s_ibl->E[0]);
	RCache.set_c("m_current", m_current); 
	RCache.set_c("m_previous", m_previous);	
	RCache.set_Geometry(g_combine);
	RCache.Render(D3DPT_TRIANGLELIST, Offset, 0, 4, 0, 2);

/////////////////////////////////////////////////////////////////////////////////
	u_setrt(rt_ibl_1, 0, 0, HW.pBaseZB);
	RCache.set_CullMode(CULL_NONE);
	RCache.set_Stencil(FALSE);
	HW.pContext->ClearRenderTargetView(rt_ibl_1->pRT, ColorRGBA);

	// Fill vertex buffer
	pv = (FVF::TL*)RCache.Vertex.Lock(4, g_combine->vb_stride, Offset);
	pv->set(0, float(h), d_Z, d_W, C, p0.x, p1.y); pv++;
	pv->set(0, 0, d_Z, d_W, C, p0.x, p0.y); pv++;
	pv->set(float(w), float(h), d_Z, d_W, C, p1.x, p1.y); pv++;
	pv->set(float(w), 0, d_Z, d_W, C, p1.x, p0.y); pv++;
	RCache.Vertex.Unlock(4, g_combine->vb_stride);

	// Draw COLOR
	RCache.set_Element(s_ibl->E[1]);
	RCache.set_c("m_current", m_current); 
	RCache.set_c("m_previous", m_previous);	
	RCache.set_Geometry(g_combine);
	RCache.Render(D3DPT_TRIANGLELIST, Offset, 0, 4, 0, 2);

/////////////////////////////////////////////////////////////////////////////////
	u_setrt(rt_ibl_2, 0, 0, HW.pBaseZB);
	RCache.set_CullMode(CULL_NONE);
	RCache.set_Stencil(FALSE);
	HW.pContext->ClearRenderTargetView(rt_ibl_2->pRT, ColorRGBA);

	// Fill vertex buffer
	pv = (FVF::TL*)RCache.Vertex.Lock(4, g_combine->vb_stride, Offset);
	pv->set(0, float(h), d_Z, d_W, C, p0.x, p1.y); pv++;
	pv->set(0, 0, d_Z, d_W, C, p0.x, p0.y); pv++;
	pv->set(float(w), float(h), d_Z, d_W, C, p1.x, p1.y); pv++;
	pv->set(float(w), 0, d_Z, d_W, C, p1.x, p0.y); pv++;
	RCache.Vertex.Unlock(4, g_combine->vb_stride);

	// Draw COLOR
	RCache.set_Element(s_ibl->E[2]);
	RCache.set_c("m_current", m_current); 
	RCache.set_c("m_previous", m_previous);	
	RCache.set_Geometry(g_combine);
	RCache.Render(D3DPT_TRIANGLELIST, Offset, 0, 4, 0, 2);        
};