#ifndef NODE_RENDERER_H
#define NODE_RENDERER_H

#include "core/sdlapp.h"

class NodeRenderer
{
    int tagid;

    TextureResource* icon;
    float size;

    float elapsed;
    float fadetime;

    float getAlpha() { return std::min(elapsed/fadetime, 1.0f); }
    vec3f getColour() { return vec3f(1.0, 1.0, 1.0); }

    TextureResource* getIcon() { return icon; }

    bool mouseover;
    bool selected;

public:
    NodeRenderer(int tagid);

    void renderAt(const vec2f& pos);

    void setMouseOver(bool over);
    void setSelected(bool selected);


};

#endif // NODE_RENDERER_H
