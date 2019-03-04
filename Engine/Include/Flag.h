#pragma once

namespace PUN
{
	enum COMPONENT_TYPE
	{
		CT_TRANSFORM,
		CT_RENDERER,
		CT_CAMERA,
		CT_ARM,
		CT_FREECAMERA,
		CT_MATERIAL,
		CT_ANIMATION2D,
		CT_ANIMATION,
		CT_COLLIDER,
		CT_UI,
		CT_TEXT,
		CT_SOUND,
		CT_STAGE2D,
		CT_TILE2D,
		CT_NAVI2D,
		CT_LIGHT,
		CT_LANDSCAPE,
		CT_END
	};

	enum AXIS
	{
		AXIS_X,
		AXIS_Y,
		AXIS_Z,
		AXIS_END
	};

	enum SHADER_TYPE
	{
		ST_VERTEX,
		ST_PIXEL,
		ST_END
	};

	enum CBUFFER_SHADER_TYPE
	{
		CST_VERTEX = 0X1,
		CST_PIXEL = 0X2
	};

	enum CAMERA_TYPE
	{
		CT_PERSPECTIVE,
		CT_ORTHO
	};

	enum RENDER_STATE
	{
		RS_BLEND,
		RS_RASTERIZER,
		RS_DEPTHSTENCIL,
		RS_END
	};

	enum GAME_MODE
	{
		GM_2D,
		GM_3D
	};

	enum ANIMATION2D_TYPE
	{
		A2D_ATLAS,
		A2D_FRAME
	};

	enum ANIMATION_OPTION
	{
		AO_LOOP,
		AO_ONCE_RETURN,
		AO_ONCE_DESTROY,
		AO_ONCE_LAST
	};

	enum COLLIDER_TYPE
	{
		CT_RECT,
		CT_POINT,
		CT_OBB,
		CT_PIXEL,
		CT_SPHERE
	};

	enum COLLISION_CALLBACK_TYPE
	{
		CCT_ENTER,
		CCT_STAY,
		CCT_LEAVE,
		CCT_END
	};

	enum UI_TYPE
	{
		UT_PANEL,
		UT_BUTTON,
		UT_BAR,
		UT_NUMBER,
		UT_TAB,
		UT_SLOT
	};

	enum BUTTON_STATE
	{
		BS_DISABLE,
		BS_NORMAL,
		BS_MOUSEON,
		BS_CLICK,
		BS_END
	};

	enum BAR_DIR
	{
		BD_LEFT,
		BD_RIGHT,
		BD_UP,
		BD_DOWN
	};

	enum TRANSFORM_PARENT_FLAG
	{
		TPF_SCALE = 0X1,
		TPF_ROT = 0X2,
		TPF_POS = 0X4
	};

	enum STAGE2D_TILE_TYPE
	{
		S2D_NONE,
		S2D_RECT,
		S2D_ISOMETRIC
	};

	enum RENDER_GROUP
	{
		RG_LANDSCAPE,
		RG_NORMAL,
		RG_ALPHA1,
		RG_ALPHA2,
		RG_ALPHA3,
		RG_UI,
		RG_HUD,
		RG_END,
		RG_LIGHT
		//RG_LIGHT�� RG_END���� �ڿ� ���� ������
		//RG_LIGHT�Ӽ��� RenderManager�� m_tLightGroup�� �����ϴ��� ���θ� üũ�ϱ� �����̴�.
		//RenderManager�� ������ҵ��� �������� �ִٸ�(���̸鼭 ���ÿ� �׷��� ������Ʈ���) 
		//NORMAL�����׷쿡 ���Խ����ش�.
	};

	enum ASTAR_NODE_DIR
	{
		AND_LT,
		AND_T,
		AND_RT,
		AND_R,
		AND_RB,
		AND_B,
		AND_LB,
		AND_L,
		AND_END
	};

	// Object Collider
	enum OBJECT_COLLISION_TYPE
	{
		OCT_PLAYER,
		OCT_MONSTER,
		OCT_SKILL,
		OCT_NONE
	};

	// Character Tab State
	enum CHARACTER_TAB_STATE
	{
		CTS_NORMAL,
		CTS_CLICK,
		CTS_MOUSEON,
		CTS_DISABLE,
		CTS_END
	};

	// Equip Tab State
	enum EQUIP_TAB_STATE
	{
		ETS_NORMAL,
		ETS_CLICK,
		ETS_MOUSEON,
		ETS_DISABLE,
		ETS_END
	};

	// Inven Tab State
	enum INVEN_TAB_STATE
	{
		ITS_NORMAL,
		ITS_CLICK,
		ITS_MOUSEON,
		ITS_DISABLE,
		ITS_END
	};

	// Club Tab State
	enum CLUB_TAB_STATE
	{
		CLTS_NORMAL,
		CLTS_CLICK,
		CLTS_MOUSEON,
		CLTS_DISABLE,
		CLTS_END
	};

	// Option Tab State
	enum OPTION_TAB_STATE
	{
		OTS_NORMAL,
		OTS_CLICK,
		OTS_MOUSEON,
		OTS_DISABLE,
		OTS_END
	};

	// Team Tab State
	enum TEAM_TAB_STATE
	{
		TTS_NORMAL,
		TTS_CLICK,
		TTS_MOUSEON,
		TTS_DISABLE,
		TTS_END
	};

	// Combo Tab State
	enum COMBO_TAB_STATE
	{
		COTS_NORMAL,
		COTS_CLICK,
		COTS_MOUSEON,
		COTS_DISABLE,
		COTS_END
	};

	// Quick Slot Buttn State
	enum QUICK_SLOT_BUTTON_STATE
	{
		QS_NORMAL,
		QS_CLICK,
		QS_MOUSEON,
		QS_DISABLE,
		QS_END
	};

	// End Button
	enum END_BUTTON_STATE
	{
		EBS_DISABLE,
		EBS_NORMAL,
		EBS_MOUSEON,
		EBS_CLICK,
		EBS_END
	};

	// Light Type
	enum LIGHT_TYPE
	{
		LT_DIR,
		LT_POINT,
		LT_SPOT,
		LT_END
	};

	enum SKEY_TYPE
	{
		SKEY_SHIFT,
		SKEY_CONTROL,
		SKEY_ALT,
		SKEY_END
	};

	enum ACTION_KEY_FUNCTION_TYPE
	{
		AT_PRESS,
		AT_PUSH,
		AT_RELEASE,
		AT_END
	};

	enum KEY_STATE
	{
		KEY_PRESS = 0x1,
		KEY_PUSH = 0x2,
		KEY_RELEASE = 0x4
	};

	enum MOUSE_STATE
	{
		MS_LBUTTON,
		MS_RBUTTON,
		MS_MBUTTON,
		MS_END
	};

	enum SOUND_TYPE
	{
		ST_EFFECT,
		ST_BGM,
		ST_3D,
		ST_MAX,
	};

}