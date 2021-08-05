#include "raylib.h"
#include "BaseCharacter.h"

class Enemy : public BaseCharacter {
public:
    Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture);
    virtual void update(float deltaTime) override;
private:
    
};
