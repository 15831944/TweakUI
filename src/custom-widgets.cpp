#include "custom-widgets.h"

namespace TweakUI {

  ETwType TW_TYPE_CUBICCURVE;
  ETwType TW_TYPE_VECTOR2;

  namespace CustomWidgets
  {
    ETwType CCubicCurveExt::s_CustomType;

    void CCubicCurveExt::CreateTypes()
    {
      const bool USE_CURVE_PREVIEW = true;

      s_CustomType = (TwType)(TW_TYPE_CUSTOM_BASE + (int)g_TwMgr->m_Customs.size());
      g_TwMgr->m_Customs.push_back(NULL); // increment custom type number


      TwStructMember CubicCurveExtMembers[] = { { "0", s_CustomType, 0, ""},
                                                { "1", s_CustomType, 0, ""},
                                                { "2", s_CustomType, 0, ""},
                                                { "3", s_CustomType, 0, ""},
                                                { "4", s_CustomType, 0, ""},
                                                { "5", s_CustomType, 0, ""},
                                                { "6", s_CustomType, 0, ""},
                                                { "NumPoints", TW_TYPE_INT32, offsetof(CCubicCurveExt, NumPoints), "min=2 max=4" } };

      TW_TYPE_CUBICCURVE = TwDefineStructExt("CUBICCURVE",
                                             CubicCurveExtMembers,
                                             sizeof(CubicCurveExtMembers)/sizeof(CubicCurveExtMembers[0]),
                                             sizeof(CubicCurve),
                                             sizeof(CCubicCurveExt),
                                             &CCubicCurveExt::InitCubicCurve,
                                             &CCubicCurveExt::CopyVarFromExtCB,
                                             &CCubicCurveExt::CopyVarToExtCB,
                                             USE_CURVE_PREVIEW ? CustomTypeSummaryCB :  &CCubicCurveExt::SummaryCB,
                                             CTwMgr::CStruct::s_PassProxyAsClientData,
                                             "A 4-float-encoded cubic bezier-curve");

      if(USE_CURVE_PREVIEW)
      {
        g_TwMgr->m_groupPreviewDrawCB[TW_TYPE_CUBICCURVE] = &CCubicCurveExt::PreviewCB;
      }
    }

    void ANT_CALL CCubicCurveExt::InitCubicCurve(void *_ExtValue, void *_ClientData)
    {
      CCubicCurveExt *ext = static_cast<CCubicCurveExt *>(_ExtValue);
      if(ext)
      {
        ext->NumPoints = 2;
        ext->curve.point0 = vec2(0.f, 0.f);
        ext->curve.point1 = vec2(1.f, 1.f);
        ext->curve.tangent0 = vec2(0.25f, 0.f);
        ext->curve.tangent1 = vec2(0.75f, 1.f);
        ext->m_StructProxy = (CTwMgr::CStructProxy *)_ClientData;

        if( ext->m_StructProxy)
        {
            ext->m_StructProxy->m_CustomDrawCallback = CCubicCurveExt::DrawCB;
            ext->m_StructProxy->m_CustomMouseButtonCallback = CCubicCurveExt::MouseButtonCB;
            ext->m_StructProxy->m_CustomMouseMotionCallback = CCubicCurveExt::MouseMotionCB;
            ext->m_StructProxy->m_CustomMouseLeaveCallback = CCubicCurveExt::MouseLeaveCB;
        }
      }
    }

    void ANT_CALL CCubicCurveExt::CopyVarFromExtCB(void *_VarValue, const void *_ExtValue, unsigned int _ExtMemberIndex, void *_ClientData)
    {
      CubicCurve *cubicCurve = static_cast<CubicCurve*>(_VarValue);
      const CCubicCurveExt *ext = static_cast<const CCubicCurveExt*>(_ExtValue);
      CTwMgr::CMemberProxy *mProxy = static_cast<CTwMgr::CMemberProxy *>(_ClientData);

      (void)_ExtMemberIndex;
      (void)mProxy;

      if(cubicCurve && ext)
      {
        *cubicCurve = ext->curve;
      }
    }

    void ANT_CALL CCubicCurveExt::CopyVarToExtCB(const void *_VarValue, void *_ExtValue, unsigned int _ExtMemberIndex, void *_ClientData)
    {
      const CubicCurve *cubicCurve = static_cast<const CubicCurve*>(_VarValue);
      CCubicCurveExt *ext = static_cast<CCubicCurveExt*>(_ExtValue);
      CTwMgr::CMemberProxy *mProxy = static_cast<CTwMgr::CMemberProxy *>(_ClientData);

      (void)_ExtMemberIndex;
      (void)mProxy;

      if(cubicCurve && ext)
      {
        ext->curve = *cubicCurve;
      }
    }


    void ANT_CALL CCubicCurveExt::SummaryCB(char *_SummaryString, size_t _SummaryMaxLength, const void *_ExtValue, void *_ClientData)
    {
      const CCubicCurveExt *ext = static_cast<const CCubicCurveExt*>(_ExtValue);
      CTwMgr::CMemberProxy *mProxy = static_cast<CTwMgr::CMemberProxy *>(_ClientData);

      (void)mProxy;

      _snprintf(_SummaryString, _SummaryMaxLength, "NumPoints=%i", ext->NumPoints);
    }


    void ANT_CALL CCubicCurveExt::DrawCB(int w, int h, void *_ExtValue, void *_ClientData, TwBar *_Bar, CTwVarGroup *varGrp)
    {
      if(g_TwMgr==nullptr || g_TwMgr->m_Graph==nullptr)
          return;

      CQuaternionExt *ext = static_cast<CQuaternionExt *>(_ExtValue);

      assert( g_TwMgr->m_Graph->IsDrawing() );
      assert( ext!=NULL );

      (void)_ClientData;
      (void)_Bar;

      g_TwMgr->m_Graph->DrawLine(w, 0, 0, h, 0xffffffff, true);

      // draw borders
      g_TwMgr->m_Graph->DrawFrame(0, 0, w, h, 0x40000000);
    }


    bool ANT_CALL CCubicCurveExt::MouseMotionCB(int _MouseX, int _MouseY, int _W, int _H, void *_StructExtValue, void *_ClientData, TwBar *_Bar, CTwVarGroup *varGrp)
    {
    }


    bool ANT_CALL CCubicCurveExt::MouseButtonCB(TwMouseButtonID _Button, bool _Pressed, int _MouseX, int _MouseY, int _W, int _H, void *_StructExtValue, void *_ClientData, TwBar *_Bar, CTwVarGroup *varGrp)
    {
    }


    void ANT_CALL CCubicCurveExt::MouseLeaveCB(void *_StructExtValue, void *_ClientData, TwBar *_Bar)
    {
    }


    void ANT_CALL CCubicCurveExt::PreviewCB(int w, int h, void *_ExtValue, void *_ClientData)
    {
      g_TwMgr->m_Graph->DrawLine(w, 0, 0, h, 0xffffffff, true);
    }


    void createVectorTypes()
    {
      TwStructMember vec2Members[] = { { "x", TW_TYPE_FLOAT, offsetof(vec2, x), "min=0" },
                                       { "y", TW_TYPE_FLOAT, offsetof(vec2, y) }};

      TW_TYPE_VECTOR2 = TwDefineStruct("vec2", vec2Members, sizeof(vec2Members)/sizeof(vec2Members[0]), sizeof(vec2), nullptr, nullptr);
    }


    void createTypes()
    {
      createVectorTypes();
      CCubicCurveExt::CreateTypes();
    }

  }
} // namespace TweakUI
