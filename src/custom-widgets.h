#ifndef TWEAKUI_CUSTOMWIDGETS_H
#define TWEAKUI_CUSTOMWIDGETS_H

#include <TweakUI.h>
#include <TweakUI/Curve.h>

#include "TwPrecomp.h"
#include "TwMgr.h"

namespace TweakUI {
  namespace CustomWidgets
  {

    struct CCubicCurveExt
    {
      int NumPoints;
      CubicCurve curve;

      CTwMgr::CStructProxy* m_StructProxy;
      static TwType s_CustomType;

      static void CreateTypes();
      static void ANT_CALL InitCubicCurve(void *_ExtValue, void *_ClientData);
      static void ANT_CALL CopyVarFromExtCB(void *_VarValue, const void *_ExtValue, unsigned int _ExtMemberIndex, void *_ClientData);
      static void ANT_CALL CopyVarToExtCB(const void *_VarValue, void *_ExtValue, unsigned int _ExtMemberIndex, void *_ClientData);
      static void ANT_CALL SummaryCB(char *_SummaryString, size_t _SummaryMaxLength, const void *_ExtValue, void *_ClientData);

      static void ANT_CALL DrawCB(int w, int h, void *_ExtValue, void *_ClientData, TwBar *_Bar, CTwVarGroup *varGrp);
      static bool ANT_CALL MouseMotionCB(int _MouseX, int _MouseY, int _W, int _H, void *_StructExtValue, void *_ClientData, TwBar *_Bar, CTwVarGroup *varGrp);
      static bool ANT_CALL MouseButtonCB(TwMouseButtonID _Button, bool _Pressed, int _MouseX, int _MouseY, int _W, int _H, void *_StructExtValue, void *_ClientData, TwBar *_Bar, CTwVarGroup *varGrp);
      static void ANT_CALL MouseLeaveCB(void *_StructExtValue, void *_ClientData, TwBar *_Bar);
    };


    void createTypes();

  }
} // namespace TweakUI

#endif // TWEAKUI_CUSTOMWIDGETS_H
