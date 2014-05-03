#if !defined TW_CURVE_INCLUDED
#define TW_CURVE_INCLUDED

#include <glm/glm.hpp>

namespace TweakUI
{
  typedef glm::vec2 vec2;

  struct CubicCurve
  {
    vec2 point0;
    vec2 tangent0;
    vec2 tangent1;
    vec2 point1;
  };

}

#endif
