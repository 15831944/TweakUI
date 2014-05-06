#if !defined TW_CURVE_INCLUDED
#define TW_CURVE_INCLUDED

#include <glm/glm.hpp>

namespace TweakUI
{
  typedef glm::vec2 vec2;
  typedef glm::vec3 vec3;
  typedef glm::vec4 vec4;
  typedef glm::ivec2 ivec2;
  typedef glm::ivec3 ivec3;
  typedef glm::ivec4 ivec4;

  struct CubicCurve
  {
    vec2 point0;
    vec2 tangent0;
    vec2 tangent1;
    vec2 point1;
  };

}

#endif
